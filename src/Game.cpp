#include "Game.hpp"

Game::Game() {
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 9; j++) {
            play_ground[i][j] = nullptr;
        }
    }

    for(int i = 1; i <= 5; i++) {
        play_ground_position[i][1].left = 216;
        play_ground_position[i][1].right = 298;
        play_ground_position[i][1].x = 257;

        play_ground_position[i][1].down = 147 + (i - 1) * 94;
        play_ground_position[i][1].up = 53 + (i - 1) * 94;
        play_ground_position[i][1].y = 100 + (i - 1) * 94;
    }
    for(int j = 2; j <= 9; j++) {
        for(int i = 1; i <= 5; i++) {
            play_ground_position[i][j].x = play_ground_position[i][j - 1].x + 82;
            play_ground_position[i][j].left = play_ground_position[i][j - 1].left + 82;
            play_ground_position[i][j].right = play_ground_position[i][j - 1].right + 82;
            play_ground_position[i][j].y = play_ground_position[i][j - 1].y;
            play_ground_position[i][j].up = play_ground_position[i][j - 1].up;
            play_ground_position[i][j].down = play_ground_position[i][j - 1].down;
        }
    }
}

bool in_same_block(Position a, Position b) {
    if(a.y == b.y and a.left <= b.x and b.x < a.right) return true;
    return false;
}

void Game::handler() {
   for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 9; j++) {
            if(play_ground[i][j] == nullptr) continue;
            for(int k = 0; k < zombies.size(); k++) {
                Position zombie_pos;
                zombie_pos.x = zombies[k]->get_row();
                zombie_pos.y = zombies[k]->get_column();
                if(in_same_block(play_ground_position[i][j], zombie_pos)) {
                    cout << "eating timeeeeee";
                    exit(0);
                }
            }
        }
   }
}