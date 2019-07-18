
#include "board_game/board_game.h"
#include "board_game/layer.h"
#include "communications/communications.h"
#include "messages/board_status.pb.h"
#include "tileset_glfw/textures.h"

struct BoardGame::Impl {
    float width, height;
    std::map<std::string, layer> _layers;

    std::function<void (const sword_and_sorcery::BoardStatus&)> _update_callback;
};

BoardGame::BoardGame(float width, float height) : pImpl(std::make_unique<Impl>()) {
    pImpl->width = width;
    pImpl->height = height;
}

BoardGame::~BoardGame() {

}

void BoardGame::subscribe_to(const std::string& connection) {
    pImpl->_update_callback = [this](const sword_and_sorcery::BoardStatus& status) {
        for (auto& layer: status.layers()) {
            auto it = pImpl->_layers.find(layer.id());
            if (it != pImpl->_layers.end()) {
                for (auto& tile: layer.tiles()) {
                    // it->second.move(tile.id(), tile_position())  // TODO:
                }
            }
        }
    };
    Address address{};
    subscribe(address, pImpl->_update_callback);
}

void BoardGame::add_layer(const std::string& filename, const std::string& id) {
    auto [_, inserted] = pImpl->_layers.try_emplace(id, layer::load(filename, id));
}

void BoardGame::draw(const std::string& tileset_id, DrawInterface&) {
    for (const auto& [_, layer]: pImpl->_layers) {
        for (const auto& [tile_id, tile_position]: layer.get()) {
            // TODO: I cannot do this each time!!
            int width, height;
            auto texture = opengl::get_texture(tileset_id, tile_id, width, height);

            
        }
    }
}
