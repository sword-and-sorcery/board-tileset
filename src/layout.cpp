//
// Created by Javier G. Sogo on 2019-03-12.
//

#include <map>
#include <iostream>
#include <rapidxml_utils.hpp>
#include <boost/filesystem/path.hpp>
#include "layout.h"

struct layout::Impl {
    std::vector<std::pair<tile_position, std::string>> _tiles;
};

layout::layout() : pImpl(std::make_unique<Impl>()) {}

layout::layout(const layout& other) : pImpl(std::make_unique<Impl>(*other.pImpl)) {
    pImpl->_tiles = other.pImpl->_tiles;
}

layout::~layout() {}

layout layout::load(const std::string& filename, const std::string& id) {
    rapidxml::file<> xmlFile(filename.c_str());
    rapidxml::xml_document<> doc;
    try {
        doc.parse<0>(xmlFile.data());
        auto root = doc.first_node();

        auto layout_node = root->first_node("layout");
        while(layout_node) {
            if (layout_node->first_attribute("id")->value() == id) {
                layout ret;
                auto tile_node = layout_node->first_node("tile");
                while (tile_node) {
                    auto f = [&tile_node](const std::string& attr_id, const std::string& default_value){
                        auto attr = tile_node->first_attribute(attr_id.c_str());
                        if (attr) {
                            return std::string(attr->value());
                        }
                        return default_value;
                    };

                    tile_position position;
                    position.x = atof(f("x", "0").c_str());
                    position.y = atof(f("y", "0").c_str());
                    position.zindex = atoi(f("zindex", "0").c_str());
                    position.rotation = atoi(f("rotate", "0").c_str());

                    ret.add(tile_node->first_attribute("name")->value(), position);

                    // Next tile
                    tile_node = tile_node->next_sibling("tile");
                }
                return ret;
            }
            layout_node = layout_node->next_sibling("layout");
        }
    }
    catch(rapidxml::parse_error & e) {
        std::cerr << "Parse error: " << e.what() << std::endl << "At: " << e.where<char>() << std::endl;
        throw std::runtime_error("Invalid file"); // TODO:
    }
    catch(std::exception& e) {
        // TODO:
        throw e;
    }
    throw std::runtime_error("Not found"); // TODO:
}

void layout::add(const std::string& tile, const tile_position& position) {
    pImpl->_tiles.push_back(std::make_pair(position, tile));
}

const std::vector<std::pair<tile_position, std::string>>& layout::get() const {
    return pImpl->_tiles;
}
