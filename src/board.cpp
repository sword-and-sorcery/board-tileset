
#include "board_game/board.h"

#include <map>


struct board::Impl {
    std::map<std::string, layer> _layers;
};

board::board() : pImpl(std::make_unique<Impl>()) {}

board::board(const board& other) : pImpl(std::make_unique<Impl>(*other.pImpl)) {
    pImpl->_layers = other.pImpl->_layers;
}

board::~board() {}
    
void board::add_layer(const layer&) {}

void board::add_layer(const std::string& filename, const std::string& id) {
    auto [_, inserted] = pImpl->_layers.try_emplace(id, layer::load(filename, id));
}
