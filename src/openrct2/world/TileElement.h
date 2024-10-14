/*****************************************************************************
 * Copyright (c) 2014-2024 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../Identifiers.h"
#include "../ride/RideTypes.h"
#include "../ride/Station.h"
#include "Footpath.h"
#include "tile_element/TileElementType.h"

struct Banner;
struct CoordsXY;
struct LargeSceneryEntry;
struct SmallSceneryEntry;
struct WallSceneryEntry;
struct PathAdditionEntry;
struct FootpathEntry;
class LargeSceneryObject;
class TerrainSurfaceObject;
class TerrainEdgeObject;
class FootpathObject;
class FootpathSurfaceObject;
class FootpathRailingsObject;
enum class RideColourScheme : uint8_t;
namespace OpenRCT2
{
    enum class TrackElemType : uint16_t;
}

constexpr uint8_t MAX_ELEMENT_HEIGHT = 255;
constexpr uint8_t OWNER_MASK = 0b00001111;
constexpr uint8_t kTileElementSize = 16;

#pragma pack(push, 1)

struct TileElement;
struct SurfaceElement;
struct PathElement;
struct TrackElement;
struct SmallSceneryElement;
struct LargeSceneryElement;
struct WallElement;
struct EntranceElement;
struct BannerElement;

struct TileElementBase
{
    uint8_t Type;            // 0
    uint8_t Flags;           // 1. Upper nibble: flags. Lower nibble: occupied quadrants (one bit per quadrant).
    uint8_t BaseHeight;      // 2
    uint8_t ClearanceHeight; // 3
    uint8_t Owner;           // 4

    void Remove();

    TileElementType GetType() const;
    void SetType(TileElementType newType);

    Direction GetDirection() const;
    void SetDirection(Direction direction);
    Direction GetDirectionWithOffset(uint8_t offset) const;

    bool IsLastForTile() const;
    void SetLastForTile(bool on);
    bool IsGhost() const;
    void SetGhost(bool isGhost);
    bool IsInvisible() const;
    void SetInvisible(bool on);

    uint8_t GetOccupiedQuadrants() const;
    void SetOccupiedQuadrants(uint8_t quadrants);

    int32_t GetBaseZ() const;
    void SetBaseZ(int32_t newZ);

    int32_t GetClearanceZ() const;
    void SetClearanceZ(int32_t newZ);

    uint8_t GetOwner() const;
    void SetOwner(uint8_t newOwner);

    template<typename TType> const TType* as() const
    {
        if constexpr (std::is_same_v<TType, TileElement>)
            return reinterpret_cast<const TileElement*>(this);
        else
            return GetType() == TType::ElementType ? reinterpret_cast<const TType*>(this) : nullptr;
    }

    template<typename TType> TType* as()
    {
        if constexpr (std::is_same_v<TType, TileElement>)
            return reinterpret_cast<TileElement*>(this);
        else
            return GetType() == TType::ElementType ? reinterpret_cast<TType*>(this) : nullptr;
    }

    const SurfaceElement* AsSurface() const;
    SurfaceElement* AsSurface();
    const PathElement* AsPath() const;
    PathElement* AsPath();
    const TrackElement* AsTrack() const;
    TrackElement* AsTrack();
    const SmallSceneryElement* AsSmallScenery() const;
    SmallSceneryElement* AsSmallScenery();
    const LargeSceneryElement* AsLargeScenery() const;
    LargeSceneryElement* AsLargeScenery();
    const WallElement* AsWall() const;
    WallElement* AsWall();
    const EntranceElement* AsEntrance() const;
    EntranceElement* AsEntrance();
    const BannerElement* AsBanner() const;
    BannerElement* AsBanner();
};

/**
 * Map element structure
 * size: 0x10
 */
struct TileElement : public TileElementBase
{
    uint8_t Pad05[3];
    uint8_t Pad08[8];

    void ClearAs(TileElementType newType);

    RideId GetRideIndex() const;

    void SetBannerIndex(BannerIndex newIndex);
    void RemoveBannerEntry();
    BannerIndex GetBannerIndex() const;
};
static_assert(sizeof(TileElement) == 16);

struct SurfaceElement : TileElementBase
{
    static constexpr TileElementType ElementType = TileElementType::Surface;

private:
    uint8_t Slope;
    uint8_t WaterHeight;
    uint8_t GrassLength;
    uint8_t Ownership;
    uint8_t SurfaceStyle;
    uint8_t EdgeObjectIndex;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
    uint8_t Pad0B[5];
#pragma clang diagnostic pop

public:
    uint8_t GetSlope() const;
    void SetSlope(uint8_t newSlope);

    ObjectEntryIndex GetSurfaceObjectIndex() const;
    TerrainSurfaceObject* GetSurfaceObject() const;
    void SetSurfaceObjectIndex(ObjectEntryIndex newStyle);

    ObjectEntryIndex GetEdgeObjectIndex() const;
    TerrainEdgeObject* GetEdgeObject() const;
    void SetEdgeObjectIndex(ObjectEntryIndex newStyle);

    bool CanGrassGrow() const;
    uint8_t GetGrassLength() const;
    void SetGrassLength(uint8_t newLength);
    void SetGrassLengthAndInvalidate(uint8_t newLength, const CoordsXY& coords);
    void UpdateGrassLength(const CoordsXY& coords);

    uint8_t GetOwnership() const;
    void SetOwnership(uint8_t newOwnership);

    int32_t GetWaterHeight() const;
    void SetWaterHeight(int32_t newWaterHeight);

    uint8_t GetParkFences() const;
    void SetParkFences(uint8_t newParkFences);

    bool HasTrackThatNeedsWater() const;
    void SetHasTrackThatNeedsWater(bool on);
};
static_assert(sizeof(SurfaceElement) == 16);

struct PathElement : TileElementBase
{
    static constexpr TileElementType ElementType = TileElementType::Path;

private:
    ObjectEntryIndex SurfaceIndex;  // 5
    ObjectEntryIndex RailingsIndex; // 7
    uint8_t Additions;              // 9 (0 means no addition)
    uint8_t EdgesAndCorners;        // 10 (edges in lower 4 bits, corners in upper 4)
    uint8_t Flags2;                 // 11
    uint8_t SlopeDirection;         // 12
    union
    {
        uint8_t AdditionStatus; // 13, only used for litter bins
        RideId rideIndex;       // 13
    };
    ::StationIndex StationIndex; // 15

public:
    ObjectEntryIndex GetLegacyPathEntryIndex() const;
    const FootpathObject* GetLegacyPathEntry() const;
    void SetLegacyPathEntryIndex(ObjectEntryIndex newIndex);
    bool HasLegacyPathEntry() const;

    ObjectEntryIndex GetSurfaceEntryIndex() const;
    const FootpathSurfaceObject* GetSurfaceEntry() const;
    void SetSurfaceEntryIndex(ObjectEntryIndex newIndex);

    ObjectEntryIndex GetRailingsEntryIndex() const;
    const FootpathRailingsObject* GetRailingsEntry() const;
    void SetRailingsEntryIndex(ObjectEntryIndex newIndex);

    const PathSurfaceDescriptor* GetSurfaceDescriptor() const;
    const PathRailingsDescriptor* GetRailingsDescriptor() const;

    uint8_t GetQueueBannerDirection() const;
    void SetQueueBannerDirection(uint8_t direction);

    bool IsSloped() const;
    void SetSloped(bool isSloped);

    bool HasJunctionRailings() const;
    void SetJunctionRailings(bool hasJunctionRailings);

    Direction GetSlopeDirection() const;
    void SetSlopeDirection(Direction newSlope);

    RideId GetRideIndex() const;
    void SetRideIndex(RideId newRideIndex);

    ::StationIndex GetStationIndex() const;
    void SetStationIndex(::StationIndex newStationIndex);

    bool IsWide() const;
    void SetWide(bool isWide);

    bool IsQueue() const;
    void SetIsQueue(bool isQueue);
    bool HasQueueBanner() const;
    void SetHasQueueBanner(bool hasQueueBanner);

    bool IsBroken() const;
    void SetIsBroken(bool isBroken);

    bool IsBlockedByVehicle() const;
    void SetIsBlockedByVehicle(bool isBlocked);

    uint8_t GetEdges() const;
    void SetEdges(uint8_t newEdges);
    uint8_t GetCorners() const;
    void SetCorners(uint8_t newCorners);
    uint8_t GetEdgesAndCorners() const;
    void SetEdgesAndCorners(uint8_t newEdgesAndCorners);

    bool HasAddition() const;
    uint8_t GetAddition() const;
    ObjectEntryIndex GetAdditionEntryIndex() const;
    const PathAdditionEntry* GetAdditionEntry() const;
    void SetAddition(uint8_t newAddition);
    void SetAdditionEntryIndex(ObjectEntryIndex entryIndex);

    bool AdditionIsGhost() const;
    void SetAdditionIsGhost(bool isGhost);

    uint8_t GetAdditionStatus() const;
    void SetAdditionStatus(uint8_t newStatus);

    bool ShouldDrawPathOverSupports() const;
    void SetShouldDrawPathOverSupports(bool on);

    bool IsLevelCrossing(const CoordsXY& coords) const;
};
static_assert(sizeof(PathElement) == 16);

struct SmallSceneryElement : TileElementBase
{
    static constexpr TileElementType ElementType = TileElementType::SmallScenery;

private:
    ObjectEntryIndex entryIndex; // 5
    uint8_t age;                 // 7
    uint8_t Colour[3];           // 8
    uint8_t Flags2;              // B
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
    uint8_t Pad0B[4];
#pragma clang diagnostic pop

public:
    ObjectEntryIndex GetEntryIndex() const;
    void SetEntryIndex(ObjectEntryIndex newIndex);
    const SmallSceneryEntry* GetEntry() const;
    uint8_t GetAge() const;
    void SetAge(uint8_t newAge);
    void IncreaseAge(const CoordsXY& sceneryPos);
    uint8_t GetSceneryQuadrant() const;
    void SetSceneryQuadrant(uint8_t newQuadrant);
    colour_t GetPrimaryColour() const;
    void SetPrimaryColour(colour_t colour);
    colour_t GetSecondaryColour() const;
    void SetSecondaryColour(colour_t colour);
    colour_t GetTertiaryColour() const;
    void SetTertiaryColour(colour_t colour);
    bool NeedsSupports() const;
    void SetNeedsSupports();
    void UpdateAge(const CoordsXY& sceneryPos);
};
static_assert(sizeof(SmallSceneryElement) == 16);

struct LargeSceneryElement : TileElementBase
{
    static constexpr TileElementType ElementType = TileElementType::LargeScenery;

private:
    ObjectEntryIndex EntryIndex;
    ::BannerIndex BannerIndex;
    uint8_t SequenceIndex;
    uint8_t Colour[3];
    uint8_t Flags2;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
    uint8_t pad[2];
#pragma clang diagnostic pop

public:
    ObjectEntryIndex GetEntryIndex() const;
    void SetEntryIndex(ObjectEntryIndex newIndex);
    const LargeSceneryEntry* GetEntry() const;
    const LargeSceneryObject* GetObject() const;

    uint8_t GetSequenceIndex() const;
    void SetSequenceIndex(uint8_t newIndex);

    colour_t GetPrimaryColour() const;
    void SetPrimaryColour(colour_t colour);
    colour_t GetSecondaryColour() const;
    void SetSecondaryColour(colour_t colour);
    colour_t GetTertiaryColour() const;
    void SetTertiaryColour(colour_t colour);

    Banner* GetBanner() const;
    ::BannerIndex GetBannerIndex() const;
    void SetBannerIndex(::BannerIndex newIndex);

    bool IsAccounted() const;
    void SetIsAccounted(bool isAccounted);
};
static_assert(sizeof(LargeSceneryElement) == 16);

#pragma pack(pop)

enum
{
    SURFACE_ELEMENT_HAS_TRACK_THAT_NEEDS_WATER = (1 << 6),
};

enum
{
    TILE_ELEMENT_DIRECTION_WEST,
    TILE_ELEMENT_DIRECTION_NORTH,
    TILE_ELEMENT_DIRECTION_EAST,
    TILE_ELEMENT_DIRECTION_SOUTH
};

enum
{
    TILE_ELEMENT_FLAG_GHOST = (1 << 4),
    TILE_ELEMENT_FLAG_INVISIBLE = (1 << 5),
    TILE_ELEMENT_FLAG_LAST_TILE = (1 << 7)
};

enum
{
    ELEMENT_IS_ABOVE_GROUND = 1 << 0,
    ELEMENT_IS_UNDERGROUND = 1 << 1,
    ELEMENT_IS_UNDERWATER = 1 << 2,
};

enum
{
    MAP_ELEM_TRACK_SEQUENCE_GREEN_LIGHT = (1 << 7),
};

constexpr uint8_t kTileElementQuadrantMask = 0b11000000;
constexpr uint8_t kTileElementTypeMask = 0b00111100;
constexpr uint8_t kTileElementDirectionMask = 0b00000011;
constexpr uint8_t kTileElementOccupiedQuadrantsMask = 0b00001111;

bool TileElementIsUnderground(TileElement* tileElement);
