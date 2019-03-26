
#pragma once

#include <memory>
#include "layer.h"

class board {
public:
    board();
    board(const board&);
    ~board();

    void add_layer(const layer&);
    void add_layer(const std::string& filename, const std::string& id);

protected:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};