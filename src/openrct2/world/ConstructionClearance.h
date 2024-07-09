/*****************************************************************************
 * Copyright (c) 2014-2024 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../actions/GameActionResult.h"
#include "Map.h"

#include <cstdint>

struct TileElement;
struct CoordsXY;
struct CoordsXYRangedZ;
class QuarterTile;

using CLEAR_FUNC = int32_t (*)(TileElement** tile_element, const CoordsXY& coords, uint8_t flags, money64* price);

// Used when calling MapCanConstructWithClearAt();
// This assumes that the caller has already done the check on the element it wants to place,
// as this function can only check the element the player wants to build through.
enum class CreateCrossingMode
{
    none,
    trackOverPath,
    pathOverTrack,
};

int32_t MapPlaceNonSceneryClearFunc(TileElement** tile_element, const CoordsXY& coords, uint8_t flags, money64* price);
int32_t MapPlaceSceneryClearFunc(TileElement** tile_element, const CoordsXY& coords, uint8_t flags, money64* price);

struct ConstructClearResult
{
    uint8_t GroundFlags{ 0 };
};

[[nodiscard]] GameActions::Result MapCanConstructWithClearAt(
    const CoordsXYRangedZ& pos, CLEAR_FUNC clearFunc, QuarterTile quarterTile, uint8_t flags,
    CreateCrossingMode crossingMode = CreateCrossingMode::none, bool isTree = false);

[[nodiscard]] GameActions::Result MapCanConstructAt(const CoordsXYRangedZ& pos, QuarterTile bl);

void MapGetObstructionErrorText(TileElement* tileElement, GameActions::Result& res);
