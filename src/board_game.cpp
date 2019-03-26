
#include "board_game/board_game.h"

#include "communications/communications.h"

struct BoardGame::Impl {};

BoardGame::BoardGame(const std::string& config) : pImpl(std::make_unique<Impl>()) {

}

BoardGame::~BoardGame() {

}

void BoardGame::draw(DrawInterface&) {

}

void BoardGame::update_status(const BoardStatus&) {

}
