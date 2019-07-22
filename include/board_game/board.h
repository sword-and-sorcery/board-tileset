
#pragma once

#include <memory>
#include <map>
#include "layer.h"

class board {
public:
    board();
    board(const board&);
    ~board();

    void add_layer(const layer&);
    void add_layer(const std::string& filename, const std::string& id, const std::string& tileset);

    const std::map<std::string, std::pair<std::string, layer>>& get_layers() const;
protected:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};