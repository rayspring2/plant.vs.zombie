#include "Game.hpp"

Game::Game() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 9; j++) {
            play_ground[i][j] = nullptr;
        }
    }
}
