/*****************************************************************************
 * Copyright (c) 2014-2024 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "MapChangeSizeAction.h"

#include "../Context.h"
#include "../GameState.h"
#include "../drawing/IDrawingEngine.h"
#include "../ui/UiContext.h"
#include "../ui/WindowManager.h"
#include "../windows/Intent.h"
#include "../world/Park.h"

MapChangeSizeAction::MapChangeSizeAction(const TileCoordsXY& targetSize)
    : _targetSize(targetSize)
{
}

uint16_t MapChangeSizeAction::GetActionFlags() const
{
    return GameAction::GetActionFlags() | GameActions::Flags::AllowWhilePaused;
}

void MapChangeSizeAction::Serialise(DataSerialiser& stream)
{
    GameAction::Serialise(stream);
    stream << DS_TAG(_targetSize);
}

GameActions::Result MapChangeSizeAction::Query() const
{
    if (_targetSize.x > kMaximumMapSizeTechnical || _targetSize.y > kMaximumMapSizeTechnical)
    {
        return GameActions::Result(GameActions::Status::InvalidParameters, STR_CANT_INCREASE_MAP_SIZE_ANY_FURTHER, STR_NONE);
    }
    if (_targetSize.x < kMinimumMapSizeTechnical || _targetSize.y < kMinimumMapSizeTechnical)
    {
        return GameActions::Result(GameActions::Status::InvalidParameters, STR_CANT_DECREASE_MAP_SIZE_ANY_FURTHER, STR_NONE);
    }
    return GameActions::Result();
}

GameActions::Result MapChangeSizeAction::Execute() const
{
    auto& gameState = OpenRCT2::GetGameState();
    // Expand map
    while (_targetSize.x > gameState.MapSize.x)
    {
        gameState.MapSize.x++;
        MapExtendBoundarySurfaceX();
    }
    while (_targetSize.y > gameState.MapSize.y)
    {
        gameState.MapSize.y++;
        MapExtendBoundarySurfaceY();
    }

    // Shrink map
    if (_targetSize.x < gameState.MapSize.x || _targetSize.y < gameState.MapSize.y)
    {
        gameState.MapSize = _targetSize;
        MapRemoveOutOfRangeElements();
    }

    auto* ctx = OpenRCT2::GetContext();
    auto uiContext = ctx->GetUiContext();
    auto* windowManager = uiContext->GetWindowManager();
    ParkCalculateSize();

    windowManager->BroadcastIntent(Intent(INTENT_ACTION_MAP));
    GfxInvalidateScreen();
    return GameActions::Result();
}

void MapChangeSizeAction::AcceptParameters(GameActionParameterVisitor& visitor)
{
    visitor.Visit("targetSizeX", _targetSize.x);
    visitor.Visit("targetSizeY", _targetSize.y);
}
