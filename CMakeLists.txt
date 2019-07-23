cmake_minimum_required(VERSION 2.8.12)
project(sword_and_sorcery)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(SOURCES src/layer.cpp src/board_game.cpp src/board.cpp)
file(GLOB HEADERS include/board_game/*)

add_library(board_game ${SOURCES} ${HEADERS})
set_target_properties(board_game PROPERTIES CXX_STANDARD 17)
target_link_libraries(board_game PUBLIC CONAN_PKG::core-communications CONAN_PKG::core-messages)
target_link_libraries(board_game PRIVATE CONAN_PKG::rapidxml CONAN_PKG::boost CONAN_PKG::ui-tileset-glfw)

target_include_directories(
    board_game PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(TARGETS board_game
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(FILES ${HEADERS}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/board_game
        PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ WORLD_READ)
