cmake_minimum_required(VERSION 2.8.12)
project(sword_and_sorcery)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(SOURCES src/layer.cpp src/board.cpp)
# set(HEADERS include/layer.h include/board.h)

add_library(board_tileset ${SOURCES})
set_target_properties(board_tileset PROPERTIES CXX_STANDARD 14)
target_link_libraries(board_tileset PUBLIC CONAN_PKG::rapidxml CONAN_PKG::boost)

target_include_directories(
    board_tileset PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(
    TARGETS board_tileset
    EXPORT board_tileset-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    EXPORT board_tileset-config
    NAMESPACE board_tileset::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/board_tileset)

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/board_tileset)
