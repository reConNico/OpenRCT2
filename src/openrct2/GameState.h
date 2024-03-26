/*****************************************************************************
 * Copyright (c) 2014-2024 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "Cheats.h"
#include "Date.h"
#include "Editor.h"
#include "Limits.h"
#include "interface/ZoomLevel.h"
#include "management/Award.h"
#include "management/Finance.h"
#include "management/NewsItem.h"
#include "ride/Ride.h"
#include "ride/RideRatings.h"
#include "scenario/Scenario.h"
#include "util/Util.h"
#include "world/Banner.h"
#include "world/Climate.h"
#include "world/Location.hpp"
#include "world/Park.h"

#include <array>
#include <chrono>
#include <memory>
#include <unordered_map>
#include <vector>

namespace OpenRCT2
{
    class Park;

    struct GameState_t
    {
        ::OpenRCT2::Park Park{};
        uint32_t CurrentTicks{};
        ::OpenRCT2::Date Date;
        uint64_t ParkFlags;
        uint16_t ParkRating;
        money64 ParkEntranceFee;
        std::vector<CoordsXYZD> ParkEntrances;
        uint32_t ParkSize;
        int16_t ParkRatingCasualtyPenalty;
        money64 ParkValue;
        money64 ParkValueHistory[FINANCE_GRAPH_SIZE];
        money64 CompanyValue;
        // The total profit for the entire scenario that precedes the current financial table.
        money64 HistoricalProfit;
        money64 ConstructionRightsPrice;
        money64 CurrentExpenditure;
        money64 CurrentProfit;
        uint8_t ParkRatingHistory[kParkRatingHistorySize];
        uint32_t GuestsInParkHistory[32];
        ClimateType Climate;
        ClimateState ClimateCurrent;
        ClimateState ClimateNext;
        uint16_t ClimateUpdateTimer;
        money64 Cash;
        money64 CashHistory[FINANCE_GRAPH_SIZE];
        money64 InitialCash;
        money64 GuestInitialCash;
        uint8_t GuestInitialHappiness;
        uint8_t GuestInitialHunger;
        uint8_t GuestInitialThirst;
        uint8_t GuestChangeModifier;
        uint32_t NextGuestNumber;
        uint32_t NumGuestsInPark;
        uint32_t NumGuestsHeadingForPark;
        uint32_t NumGuestsInParkLastWeek;
        money64 WeeklyProfitAverageDividend;
        uint64_t TotalAdmissions;
        money64 TotalIncomeFromAdmissions;
        money64 TotalRideValueForMoney;
        uint16_t WeeklyProfitAverageDivisor;
        money64 WeeklyProfitHistory[FINANCE_GRAPH_SIZE];
        Objective ScenarioObjective;
        uint16_t ScenarioParkRatingWarningDays;
        money64 ScenarioCompletedCompanyValue;
        money64 ScenarioCompanyValueRecord;
        money64 BankLoan;
        uint8_t BankLoanInterestRate;
        money64 MaxBankLoan;
        money64 ExpenditureTable[EXPENDITURE_TABLE_MONTH_COUNT][EnumValue(ExpenditureType::Count)];
        random_engine_t ScenarioRand;
        TileCoordsXY MapSize;
        money64 LandPrice;

        ::EditorStep EditorStep;

        SCENARIO_CATEGORY ScenarioCategory;
        std::string ScenarioName;
        std::string ScenarioDetails;
        std::string ScenarioCompletedBy;

        std::vector<Banner> Banners;
        Entity_t Entities[MAX_ENTITIES]{};
        // Ride storage for all the rides in the park, rides with RideId::Null are considered free.
        std::array<Ride, OpenRCT2::Limits::MaxRidesInPark> Rides{};
        ::RideRatingUpdateStates RideRatingUpdateStates;
        std::vector<TileElement> TileElements;

        std::vector<ScenerySelection> RestrictedScenery;

        std::vector<PeepSpawn> PeepSpawns;
        uint8_t PeepWarningThrottle[16];

        News::ItemQueues NewsItems;

        uint16_t GrassSceneryTileLoopPosition;
        CoordsXY WidePathTileLoopPosition;

        colour_t StaffHandymanColour;
        colour_t StaffMechanicColour;
        colour_t StaffSecurityColour;
        uint64_t SamePriceThroughoutPark{};

        uint8_t ResearchFundingLevel;
        uint8_t ResearchPriorities;
        uint16_t ResearchProgress;
        uint8_t ResearchProgressStage;
        uint8_t ResearchExpectedMonth;
        uint8_t ResearchExpectedDay;
        std::optional<ResearchItem> ResearchLastItem;
        std::optional<ResearchItem> ResearchNextItem;

        std::vector<ResearchItem> ResearchItemsUninvented;
        std::vector<ResearchItem> ResearchItemsInvented;
        uint8_t ResearchUncompletedCategories;

        ScreenCoordsXY SavedView;
        uint8_t SavedViewRotation;
        ZoomLevel SavedViewZoom;

        ObjectEntryIndex LastEntranceStyle;

        std::vector<Award> CurrentAwards;

        /**
         * Probability out of 65535, of gaining a new guest per game tick.
         * new guests per second = 40 * (probability / 65535)
         * With a full park rating, non-overpriced entrance fee, less guests than the suggested maximum and four positive
         * awards, approximately 1 guest per second can be generated (+60 guests in one minute).
         */
        int32_t GuestGenerationProbability;
        /**
         * In a difficult guest generation scenario, no guests will be generated if over this value.
         */
        uint32_t SuggestedGuestMaximum;

        CheatsState Cheats;
    };

    GameState_t& GetGameState();

    void gameStateInitAll(GameState_t& gameState, const TileCoordsXY& mapSize);
    void gameStateTick();
    void gameStateUpdateLogic();

} // namespace OpenRCT2
