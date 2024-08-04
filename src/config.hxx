#pragma once
#include <cstdint>
#include <SFML/Graphics/Color.hpp>

struct SimColor {
    uint16_t r;
    uint16_t g;
    uint16_t b;
    constexpr SimColor(uint16_t r, uint16_t g, uint16_t b) : r(r), g(g), b(b) {}

    sf::Color sf() const {
        return sf::Color(r, g, b);
    }
};

namespace InitParameters {
    constexpr uint64_t TileSize = 40;
    constexpr uint16_t TileMargin = 3;

    constexpr uint16_t FieldWidth = 29;
    constexpr uint16_t FieldHeight = 16;

    constexpr SimColor BackgroundColor(43, 43, 43);
    constexpr SimColor EmptyTileColor(80, 80, 80);

};