
#pragma once

#include <string>
#include <memory>

#include "draw_interface.h"
#include "messages/board_status.h"


class BoardGame {
public:
    // Receive XML with all the initial configuration:
    //  - board layers
    //  - broadcast address to listen to
    BoardGame(const std::string& config); 
    ~BoardGame();

    void draw(DrawInterface&);  // Call draw

protected:
    void update_status(const BoardStatus&);  // Receive new status, update

protected:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};
