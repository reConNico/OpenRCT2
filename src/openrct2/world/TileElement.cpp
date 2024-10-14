/*****************************************************************************
 * Copyright (c) 2014-2024 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "TileElement.h"

#include "../Diagnostic.h"
#include "../core/Guard.hpp"
#include "../interface/Window.h"
#include "../object/LargeSceneryEntry.h"
#include "../object/WallSceneryEntry.h"
#include "../ride/Track.h"
#include "Banner.h"
#include "Location.hpp"
#include "Scenery.h"
#include "tile_element/BannerElement.h"
#include "tile_element/EntranceElement.h"
#include "tile_element/Slope.h"
#include "tile_element/TrackElement.h"
#include "tile_element/WallElement.h"

using namespace OpenRCT2;

bool TileElementIsUnderground(TileElement* tileElement)
{
    do
    {
        tileElement++;
        if ((tileElement - 1)->IsLastForTile())
            return false;
    } while (tileElement->GetType() != TileElementType::Surface);
    return true;
}

BannerIndex TileElement::GetBannerIndex() const
{
    switch (GetType())
    {
        case TileElementType::LargeScenery:
        {
            auto* sceneryEntry = AsLargeScenery()->GetEntry();
            if (sceneryEntry == nullptr || sceneryEntry->scrolling_mode == SCROLLING_MODE_NONE)
                return BannerIndex::GetNull();

            return AsLargeScenery()->GetBannerIndex();
        }
        case TileElementType::Wall:
        {
            auto* wallEntry = AsWall()->GetEntry();
            if (wallEntry == nullptr || wallEntry->scrolling_mode == SCROLLING_MODE_NONE)
                return BannerIndex::GetNull();

            return AsWall()->GetBannerIndex();
        }
        case TileElementType::Banner:
            return AsBanner()->GetIndex();
        default:
            return BannerIndex::GetNull();
    }
}

void TileElement::SetBannerIndex(BannerIndex bannerIndex)
{
    switch (GetType())
    {
        case TileElementType::Wall:
            AsWall()->SetBannerIndex(bannerIndex);
            break;
        case TileElementType::LargeScenery:
            AsLargeScenery()->SetBannerIndex(bannerIndex);
            break;
        case TileElementType::Banner:
            AsBanner()->SetIndex(bannerIndex);
            break;
        default:
            LOG_ERROR("Tried to set banner index on unsuitable tile element!");
            Guard::Assert(false);
    }
}

void TileElement::RemoveBannerEntry()
{
    auto bannerIndex = GetBannerIndex();
    auto banner = GetBanner(bannerIndex);
    if (banner != nullptr)
    {
        WindowCloseByNumber(WindowClass::Banner, bannerIndex.ToUnderlying());
        DeleteBanner(banner->id);
    }
}

RideId TileElement::GetRideIndex() const
{
    switch (GetType())
    {
        case TileElementType::Track:
            return AsTrack()->GetRideIndex();
        case TileElementType::Entrance:
            return AsEntrance()->GetRideIndex();
        case TileElementType::Path:
            return AsPath()->GetRideIndex();
        default:
            return RideId::GetNull();
    }
}

void TileElement::ClearAs(TileElementType newType)
{
    Type = 0;
    SetType(newType);
    Flags = 0;
    BaseHeight = kMinimumLandHeight;
    ClearanceHeight = kMinimumLandHeight;
    Owner = 0;
    std::fill_n(Pad05, sizeof(Pad05), 0x00);
    std::fill_n(Pad08, sizeof(Pad08), 0x00);
}
