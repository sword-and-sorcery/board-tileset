
#pragma once


#include <string>
#include <vector>


enum class board_geom { SQUARE, HEXAGON};

struct tile_position {
    int zindex = 0;
    int rotation = 0;
    float x = 0;
    float y = 0;
};

class layer {

public:
    layer();
    layer(const layer& other);
    ~layer();

    layer& operator=(const layer&);

    static layer load(const std::string& filename, const std::string& id);

    void add(const std::string& tile, const tile_position& position);
    const std::vector<std::pair<tile_position, std::string>>& get() const;
protected:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

