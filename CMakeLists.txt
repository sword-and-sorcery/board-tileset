cmake_minimum_required(VERSION 2.8.12)
project(sword_and_sorcery)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(SOURCES src/layer.cpp src/board.cpp src/board_game.cpp)
# set(HEADERS include/layer.h include/board.h)

add_library(board_game ${SOURCES})
set_target_properties(board_game PROPERTIES CXX_STANDARD 14)
target_link_libraries(board_game PUBLIC CONAN_PKG::core-communications)
target_link_libraries(board_game PRIVATE CONAN_PKG::rapidxml CONAN_PKG::boost)

target_include_directories(
    board_game PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(
    TARGETS board_game
    EXPORT board_game-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    EXPORT board_game-config
    NAMESPACE board_game::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/board_game)

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/board_game)
