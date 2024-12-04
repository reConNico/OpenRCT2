/*****************************************************************************
 * Copyright (c) 2014-2024 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../core/Imaging.h"
#include "../core/JsonFwd.hpp"
#include "../util/Util.h"
#include "Drawing.h"

#include <string_view>
#include <tuple>

struct Image;

namespace OpenRCT2::Drawing
{
    enum class ImportMode : uint8_t
    {
        Default,
        Closest,
        Dithering,
    };

    enum class ImportFlags : uint8_t
    {
        RLE,
        NoDrawOnZoom,
    };

    enum class Palette : uint8_t
    {
        OpenRCT2,
        KeepIndices,
    };

    struct ImageImportMeta
    {
        ScreenCoordsXY offset{};
        Palette palette = Palette::OpenRCT2;
        uint8_t importFlags = EnumToFlag(ImportFlags::RLE);
        ImportMode importMode = ImportMode::Default;
        ScreenCoordsXY srcOffset{};
        ScreenSize srcSize{};
        int32_t zoomedOffset{};
    };

    /**
     * Imports images to the internal RCT G1 format.
     */
    class ImageImporter
    {
    public:
        struct ImportResult
        {
            G1Element Element{};
            std::vector<uint8_t> Buffer;
        };

        ImportResult Import(const Image& image, ImageImportMeta& meta) const;

    private:
        enum class PaletteIndexType : uint8_t
        {
            Normal,
            PrimaryRemap,
            SecondaryRemap,
            TertiaryRemap,
            Special,
        };

        static std::vector<int32_t> GetPixels(const Image& image, const ImageImportMeta& meta);
        static std::vector<uint8_t> EncodeRaw(const int32_t* pixels, ScreenSize size);
        static std::vector<uint8_t> EncodeRLE(const int32_t* pixels, ScreenSize size);

        static int32_t CalculatePaletteIndex(
            ImportMode mode, int16_t* rgbaSrc, int32_t x, int32_t y, int32_t width, int32_t height);
        static int32_t GetPaletteIndex(const GamePalette& palette, int16_t* colour);
        static bool IsTransparentPixel(const int16_t* colour);
        static bool IsInPalette(const GamePalette& palette, int16_t* colour);
        static bool IsChangablePixel(int32_t paletteIndex);
        static PaletteIndexType GetPaletteIndexType(int32_t paletteIndex);
        static int32_t GetClosestPaletteIndex(const GamePalette& palette, const int16_t* colour);
    };

    // Note: jsonSprite is deliberately left non-const: json_t behaviour changes when const.
    ImageImportMeta createImageImportMetaFromJson(json_t& input);
} // namespace OpenRCT2::Drawing

constexpr OpenRCT2::Drawing::GamePalette StandardPalette = { {
    // 0 (Unused/Transparent)
    { 0, 0, 0, 255 },

    // 1 - 9 (Misc. e.g. font, water, chain lift)
    { 1, 1, 1, 255 },
    { 2, 2, 2, 255 },
    { 3, 3, 3, 255 },
    { 4, 4, 4, 255 },
    { 5, 5, 5, 255 },
    { 6, 6, 6, 255 },
    { 7, 7, 7, 255 },
    { 8, 8, 8, 255 },
    { 9, 9, 9, 255 },

    // 10 - 21 (Grey)
    { 35, 35, 23, 255 },
    { 51, 51, 35, 255 },
    { 67, 67, 47, 255 },
    { 83, 83, 63, 255 },
    { 99, 99, 75, 255 },
    { 115, 115, 91, 255 },
    { 131, 131, 111, 255 },
    { 151, 151, 131, 255 },
    { 175, 175, 159, 255 },
    { 195, 195, 183, 255 },
    { 219, 219, 211, 255 },
    { 243, 243, 239, 255 },

    // 22 - 33 (Olive)
    { 0, 47, 51, 255 },
    { 0, 59, 63, 255 },
    { 11, 75, 79, 255 },
    { 19, 91, 91, 255 },
    { 31, 107, 107, 255 },
    { 47, 123, 119, 255 },
    { 59, 139, 135, 255 },
    { 79, 155, 151, 255 },
    { 95, 175, 167, 255 },
    { 115, 191, 187, 255 },
    { 139, 207, 203, 255 },
    { 163, 227, 223, 255 },

    // 34 - 45 (Light Brown)
    { 7, 43, 67, 255 },
    { 11, 59, 87, 255 },
    { 23, 75, 111, 255 },
    { 31, 87, 127, 255 },
    { 39, 99, 143, 255 },
    { 51, 115, 159, 255 },
    { 67, 131, 179, 255 },
    { 87, 151, 191, 255 },
    { 111, 175, 203, 255 },
    { 135, 199, 219, 255 },
    { 163, 219, 231, 255 },
    { 195, 239, 247, 255 },

    // 46 - 57 (Yellow, also used for tertiary remap)
    { 0, 27, 71, 255 },
    { 0, 43, 95, 255 },
    { 0, 63, 119, 255 },
    { 7, 83, 143, 255 },
    { 7, 111, 167, 255 },
    { 15, 139, 191, 255 },
    { 19, 167, 215, 255 },
    { 27, 203, 243, 255 },
    { 47, 231, 255, 255 },
    { 95, 243, 255, 255 },
    { 143, 251, 255, 255 },
    { 195, 255, 255, 255 },

    // 58 - 69 (Indian Red)
    { 0, 0, 35, 255 },
    { 0, 0, 79, 255 },
    { 7, 7, 95, 255 },
    { 15, 15, 111, 255 },
    { 27, 27, 127, 255 },
    { 39, 39, 143, 255 },
    { 59, 59, 163, 255 },
    { 79, 79, 179, 255 },
    { 103, 103, 199, 255 },
    { 127, 127, 215, 255 },
    { 159, 159, 235, 255 },
    { 191, 191, 255, 255 },

    // 70 - 81 (Grass Green)
    { 19, 51, 27, 255 },
    { 23, 63, 35, 255 },
    { 31, 79, 47, 255 },
    { 39, 95, 59, 255 },
    { 43, 111, 71, 255 },
    { 51, 127, 87, 255 },
    { 59, 143, 99, 255 },
    { 67, 155, 115, 255 },
    { 75, 171, 131, 255 },
    { 83, 187, 147, 255 },
    { 95, 203, 163, 255 },
    { 103, 219, 183, 255 },

    // 82 - 93 (Olive Green)
    { 27, 55, 31, 255 },
    { 35, 71, 47, 255 },
    { 43, 83, 59, 255 },
    { 55, 99, 75, 255 },
    { 67, 111, 91, 255 },
    { 79, 135, 111, 255 },
    { 95, 159, 135, 255 },
    { 111, 183, 159, 255 },
    { 127, 207, 183, 255 },
    { 147, 219, 195, 255 },
    { 167, 231, 207, 255 },
    { 191, 247, 223, 255 },

    // 94 - 105 (Green)
    { 0, 63, 15, 255 },
    { 0, 83, 19, 255 },
    { 0, 103, 23, 255 },
    { 0, 123, 31, 255 },
    { 7, 143, 39, 255 },
    { 23, 159, 55, 255 },
    { 39, 175, 71, 255 },
    { 63, 191, 91, 255 },
    { 87, 207, 111, 255 },
    { 115, 223, 139, 255 },
    { 143, 239, 163, 255 },
    { 179, 255, 195, 255 },

    // 106 - 117 (Tan)
    { 19, 43, 79, 255 },
    { 27, 55, 99, 255 },
    { 43, 71, 119, 255 },
    { 59, 87, 139, 255 },
    { 67, 99, 167, 255 },
    { 83, 115, 187, 255 },
    { 99, 131, 207, 255 },
    { 115, 151, 215, 255 },
    { 131, 171, 227, 255 },
    { 151, 191, 239, 255 },
    { 171, 207, 247, 255 },
    { 195, 227, 255, 255 },

    // 118 - 129 (Indigo)
    { 55, 19, 15, 255 },
    { 87, 43, 39, 255 },
    { 103, 55, 51, 255 },
    { 119, 67, 63, 255 },
    { 139, 83, 83, 255 },
    { 155, 99, 99, 255 },
    { 175, 119, 119, 255 },
    { 191, 139, 139, 255 },
    { 207, 159, 159, 255 },
    { 223, 183, 183, 255 },
    { 239, 211, 211, 255 },
    { 255, 239, 239, 255 },

    // 130 - 141 (Blue)
    { 111, 27, 0, 255 },
    { 151, 39, 0, 255 },
    { 167, 51, 7, 255 },
    { 187, 67, 15, 255 },
    { 203, 83, 27, 255 },
    { 223, 103, 43, 255 },
    { 227, 135, 67, 255 },
    { 231, 163, 91, 255 },
    { 239, 187, 119, 255 },
    { 243, 211, 143, 255 },
    { 251, 231, 175, 255 },
    { 255, 247, 215, 255 },

    // 142 - 153 (Sea Green)
    { 15, 43, 11, 255 },
    { 23, 55, 15, 255 },
    { 31, 71, 23, 255 },
    { 43, 83, 35, 255 },
    { 59, 99, 47, 255 },
    { 75, 115, 59, 255 },
    { 95, 135, 79, 255 },
    { 119, 155, 99, 255 },
    { 139, 175, 123, 255 },
    { 167, 199, 147, 255 },
    { 195, 219, 175, 255 },
    { 223, 243, 207, 255 },

    // 154 - 165 (Purple)
    { 95, 0, 63, 255 },
    { 115, 7, 75, 255 },
    { 127, 15, 83, 255 },
    { 143, 31, 95, 255 },
    { 155, 43, 107, 255 },
    { 171, 63, 123, 255 },
    { 187, 83, 135, 255 },
    { 199, 103, 155, 255 },
    { 215, 127, 171, 255 },
    { 231, 155, 191, 255 },
    { 243, 195, 215, 255 },
    { 255, 235, 243, 255 },

    // 166 - 177 (Red)
    { 0, 0, 63, 255 },
    { 0, 0, 87, 255 },
    { 0, 0, 115, 255 },
    { 0, 0, 143, 255 },
    { 0, 0, 171, 255 },
    { 0, 0, 199, 255 },
    { 0, 7, 227, 255 },
    { 0, 7, 255, 255 },
    { 67, 79, 255, 255 },
    { 115, 123, 255, 255 },
    { 163, 171, 255, 255 },
    { 215, 219, 255, 255 },

    // 178 - 189 (Orange)
    { 0, 39, 79, 255 },
    { 0, 51, 111, 255 },
    { 0, 63, 147, 255 },
    { 0, 71, 183, 255 },
    { 0, 79, 219, 255 },
    { 0, 83, 255, 255 },
    { 23, 111, 255, 255 },
    { 51, 139, 255, 255 },
    { 79, 163, 255, 255 },
    { 107, 183, 255, 255 },
    { 135, 203, 255, 255 },
    { 163, 219, 255, 255 },

    // 190 - 201 (Water Blue)
    { 47, 51, 0, 255 },
    { 55, 63, 0, 255 },
    { 67, 75, 0, 255 },
    { 79, 87, 0, 255 },
    { 99, 107, 7, 255 },
    { 119, 127, 23, 255 },
    { 143, 147, 43, 255 },
    { 163, 167, 71, 255 },
    { 187, 187, 99, 255 },
    { 207, 207, 131, 255 },
    { 231, 231, 171, 255 },
    { 255, 255, 207, 255 },

    // 202 - 213 (Pink, also used for secondary remap)
    { 27, 0, 63, 255 },
    { 51, 0, 103, 255 },
    { 63, 11, 123, 255 },
    { 79, 23, 143, 255 },
    { 95, 31, 163, 255 },
    { 111, 39, 183, 255 },
    { 143, 59, 219, 255 },
    { 171, 91, 239, 255 },
    { 187, 119, 243, 255 },
    { 203, 151, 247, 255 },
    { 223, 183, 251, 255 },
    { 239, 215, 255, 255 },

    // 214 - 225 (Brown)
    { 0, 19, 39, 255 },
    { 7, 31, 55, 255 },
    { 15, 47, 71, 255 },
    { 31, 63, 91, 255 },
    { 51, 83, 107, 255 },
    { 75, 103, 123, 255 },
    { 107, 127, 143, 255 },
    { 127, 147, 163, 255 },
    { 147, 171, 187, 255 },
    { 171, 195, 207, 255 },
    { 195, 219, 231, 255 },
    { 223, 243, 255, 255 },

    // 226 (Extra grey)
    { 75, 75, 55, 255 },

    // 227 - 229 (Extra yellows)
    { 0, 183, 255, 255 },
    { 0, 219, 255, 255 },
    { 0, 255, 255, 255 },

    // 230 - 234 (Water waves)
    { 135, 143, 39, 255 },
    { 123, 131, 27, 255 },
    { 95, 103, 7, 255 },
    { 87, 95, 0, 255 },
    { 111, 119, 15, 255 },

    // 235 - 249 (Water sparkles)
    { 255, 255, 199, 255 },
    { 227, 227, 155, 255 },
    { 175, 175, 83, 255 },
    { 151, 155, 51, 255 },
    { 203, 203, 123, 255 },

    // 240 - 242 (Extra grey)
    { 91, 91, 67, 255 },
    { 107, 107, 83, 255 },
    { 123, 123, 99, 255 },

    // Old 243 - 245, changed to nice shade remap below
    // { 47, 47, 47, 255 },
    // { 47, 47, 47, 255 },
    // { 47, 71, 87, 255 },

    // 243 to 254 (Primary remap)
    { 47, 51, 111, 255 },
    { 47, 55, 131, 255 },
    { 51, 63, 151, 255 },
    { 51, 67, 171, 255 },
    { 47, 75, 191, 255 },
    { 43, 79, 211, 255 },
    { 35, 87, 231, 255 },
    { 31, 95, 255, 255 },
    { 39, 127, 255, 255 },
    { 51, 155, 255, 255 },
    { 63, 183, 255, 255 },
    { 75, 207, 255, 255 },

    // 255 (Used in a small number of cases for pure white)
    { 255, 255, 255, 255 },
} };
