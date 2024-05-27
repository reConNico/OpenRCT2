/*****************************************************************************
 * Copyright (c) 2014-2024 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once
#include "rct2/Limits.h"

namespace OpenRCT2::Limits
{
    constexpr uint16_t kMaxRidesInPark = 1000;
    constexpr uint16_t kMaxStationsPerRide = 255;
    constexpr uint8_t kCustomerHistorySize = RCT12::Limits::kCustomerHistorySize;
    constexpr uint16_t kMaxGolfHoles = RCT12::Limits::kMaxGolfHoles;
    constexpr uint16_t kMaxHelices = RCT12::Limits::kMaxHelices;
    constexpr uint16_t kMaxInversions = RCT12::Limits::kMaxInversions;
    constexpr uint16_t kMaxTrainsPerRide = 255;
    constexpr uint16_t kMaxCarsPerTrain = 255;
    constexpr const uint16_t kMaxVehicleColours = kMaxTrainsPerRide; // this should really be kMaxTrainsPerRide *
                                                                     // kMaxCarsPerTrain
    // kMaxVehicleColours should be set to kMaxTrainsPerRide or kMaxCarsPerTrain, whichever is higher.
    // Sadly, using std::max() will cause compilation failures when using kMaxVehicleColours as an array size,
    // hence the usage of static asserts.
    static_assert(kMaxVehicleColours >= kMaxTrainsPerRide);
    static_assert(kMaxVehicleColours >= kMaxCarsPerTrain);
    constexpr uint8_t kMaxCircuitsPerRide = 20;
    constexpr uint8_t kMaxAwards = RCT12::Limits::kMaxAwards;
    constexpr uint8_t NumColourSchemes = RCT12::Limits::NumColourSchemes;
    constexpr uint8_t DowntimeHistorySize = RCT2::Limits::DowntimeHistorySize;
    constexpr uint16_t MaxPeepSpawns = 256;
    constexpr uint16_t MaxParkEntrances = 256;
    constexpr uint8_t MaxWaitingTime = RCT12::Limits::MaxWaitingTime;
    constexpr uint8_t CheatsMaxOperatingLimit = 255;
} // namespace OpenRCT2::Limits
