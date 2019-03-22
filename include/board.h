
#pragma once

#include <memory>
#include "layer.h"

class board {
public:
    board();
    ~board();
    
    void add_layer(const layer&);

protected:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};