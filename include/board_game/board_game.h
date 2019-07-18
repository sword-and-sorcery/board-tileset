
#pragma once

#include <string>
#include <memory>

#include "draw_interface.h"


class BoardGame {
public:
    // Receive XML with all the initial configuration:
    //  - board layers
    //  - broadcast address to listen to
    BoardGame(float width, float height);
    ~BoardGame();

    void subscribe_to(const std::string& connection);

    void add_layer(const std::string& filename, const std::string& id);
    void draw(const std::string& tileset, DrawInterface&);  // Call draw

protected:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};
