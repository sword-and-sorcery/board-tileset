
#pragma once

#include <string>
#include <memory>
#include <functional>

#include "messages/board_status.pb.h"
#include "board.h"

class BoardGame {
public:
    // Receive XML with all the initial configuration:
    //  - board layers
    //  - broadcast address to listen to

    //BoardGame(float width, float height);
    //void subscribe_to(const std::string& connection);

    void add_layer(const std::string& filename, const std::string& id);

    BoardGame(const std::string& config, board&);
    ~BoardGame();

    void draw(std::function<void (const std::string& tileset, const std::string& tile, const tile_position& position)>& draw);  // Call draw

protected:
    void update_status(const sword_and_sorcery::BoardStatus&);  // Receive new status, update

protected:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};
