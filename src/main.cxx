#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include <box2d/box2d.h>
#include <iostream>

#include "config.hxx"

struct Tile {};
enum class TileType {
    Empty,
    Wall,
};
struct Position {
    size_t x;
    size_t y;
};

static void draw_tile(sf::RenderWindow& window, size_t row, size_t col) {
    namespace ip = InitParameters;

    sf::RectangleShape tile_shape(sf::Vector2f(ip::TileSize, ip::TileSize));
    tile_shape.setPosition(sf::Vector2f(col * (ip::TileSize + ip::TileMargin), row * (ip::TileSize + ip::TileMargin)));
    tile_shape.setFillColor(ip::EmptyTileColor.sf());
    window.draw(tile_shape);
}

static void create_tile_entity(entt::registry& registry, size_t row, size_t col) {
    auto tile_ent = registry.create();
    registry.emplace<Tile>(tile_ent);
    registry.emplace<TileType>(tile_ent, TileType::Empty);
    registry.emplace<Position>(tile_ent, col, row);
}

static void initialize_tiles(sf::RenderWindow& window, entt::registry& registry) {
    namespace ip = InitParameters;

    for (size_t row = 0; row < ip::FieldHeight; row++) {
        for (size_t col = 0; col < ip::FieldWidth; col++) {
            draw_tile(window, row, col);
            create_tile_entity(registry, row, col);
        }
    }
}

static void draw_tiles(sf::RenderWindow& window) {
    namespace ip = InitParameters;

    window.clear(ip::BackgroundColor.sf());
    for (size_t row = 0; row < ip::FieldHeight; row++) {
        for (size_t col = 0; col < ip::FieldWidth; col++) {
            draw_tile(window, row, col);
        }
    }
}


// NEXT STEPS:
// - Create a couple different types of tile with different mechanics
// - Create a player entity
// - Player entity must check for collision with tiles and respond to
//   one with the biggest collision zone
// - Implement player movement (randomly changing directions, moving in
//   random directions)
// - Implement player to player collision (what happens then?)
// - [ARCHITECTURE] Think about how can player actions from the Rust
//   prototype (eat, kill etc.) be implemented here in real time (possibly
//   through collision too).
// - Maybe use EnTT's event system to connect events and behavior.
int main()
{
    // Initialize SFML window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML + EnTT + Box2D");

    // Initialize EnTT registry
    entt::registry registry;

    //// Main loop
    namespace ip = InitParameters;
    window.clear(ip::BackgroundColor.sf());
    initialize_tiles(window, registry);
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        draw_tiles(window);

        window.display();
    }

    return 0;
}
