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

    menu = new Menu(0, 0);
    selected_plant = INVALID;
}

bool Game :: inBackGround(Vector2i position) {
    int x = position.x;
    int y = position.y;
    if(216 <= x and x <= 954 and 53 <= y and y <= 523) return true;
    return false;
}

pair<int, int> Game ::findPlayGroundBlock(Vector2f plant_position) {
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 9; j++) {
            if(play_ground_position[i][j].up <= plant_position.y and plant_position.y <= play_ground_position[i][j].down and
            play_ground_position[i][j].left <= plant_position.x and plant_position.x <= play_ground_position[i][j].right and play_ground[i][j] == nullptr) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

void Game::update(RenderWindow &window){
    menu->update();
    for(int i = 1; i <= GROUNDROWS; i++ ){
        for(int j = 1; j <= 9; j++){
            if(cellIsEmpty(play_ground[i][j]))
                continue;
            play_ground[i][j]->update();
            if(auto attack_plant = dynamic_cast<AttackPlant*>(play_ground[i][j]))
                addAttackPlantBall(attack_plant);
            //must add:
            //check for zombie eating plants
            //add sun to sunflowers
            //zombie plant and zombie and shoots collisions
        }
    }
    for(Ball* b : balls) {
        b->update();
    }
    deleteOutBalls();

    if(moved_plant != nullptr and is_drag) {
        Vector2i pos = Mouse::getPosition(window);
        moved_plant->update(pos);
        pair<int, int> new_position = findPlayGroundBlock(moved_plant->getPos());
        if(new_position != pair<int, int>(-1, -1)) {
            play_ground[new_position.first][new_position.second] = moved_plant;
            play_ground[new_position.first][new_position.second]->setPos(Vector2f((float)play_ground_position[new_position.first][new_position.second].x,
            (float)play_ground_position[new_position.first][new_position.second].y));

            moved_plant = nullptr;
            is_valid = 1;
        }
    }

}


void Game::addAttackPlantBall(AttackPlant* attack_plant){
    Time shooter_time_elapsed = attack_plant -> getShootTimeElapsed();
    if(shooter_time_elapsed.asMilliseconds() >= 600){
        Ball* new_ball = attack_plant->addBall();
        balls.push_back(new_ball);
        attack_plant->resetShootTime();
    }
}

void Game::render(RenderWindow &window){
    for(int i = 1; i <= GROUNDROWS; i++){
        for(int j = 1; j <= 9; j++){
            if(cellIsEmpty(play_ground[i][j]))
                continue;
            play_ground[i][j]->render(window);
        }
    }
    for(Ball* b : balls){
        b->render(window);
    }
    menu->render(window);
}

void Game::plantRequeset(RenderWindow &window) {
    if (selected_plant == INVALID) {
        selected_plant = menu->checkMouse(window);
        return;
    }
    PlantType new_selected_plant = menu->checkMouse(window);
    if (new_selected_plant != INVALID) {
        selected_plant = new_selected_plant;
        return;
    }
    Vector2i mouse_position = Mouse :: getPosition(window);
    pair <int,int>location = findPlayGroundBlock((Vector2f) mouse_position);
    if (location == pair<int, int>(-1,-1)) {
        selected_plant = INVALID;
        return;
    }
    Plant* planting;
    if(selected_plant == PEASHOOTER) {
        planting = new PeaShooter(200, 200);
    }
    else if(selected_plant == SNOWPEA) {
        planting = new SnowPea(200, 200);
    }
    else if(selected_plant == SUNFLOWER) {
        planting = new SunFlower(200, 200);
    }
    else if(selected_plant == WALNUT) {
        planting = new Walnut(200, 200);
    }
    menu->resetCooldown(selected_plant);
    play_ground[location.first][location.second] = planting;
    play_ground[location.first][location.second]->setPos(Vector2f((float)play_ground_position[location.first][location.second].x,
        (float)play_ground_position[location.first][location.second].y));
    // check box !
    //
    // PlantType plant_type = menu->checkMouse(window);
	// if(moved_plant != nullptr and is_drag == true) moved_plant->handleMousePress();
    // if(plant_type == PEASHOOTER) {
    //     moved_plant = new PeaShooter(200, 200);
	//     is_drag = true;
    //     is_valid = 0;
    // }
    // else if(plant_type == SNOWPEA) {
    //     moved_plant = new SnowPea(200, 200);
	//     is_drag = true;
    //     is_valid = 0;
    // }
    // else if(plant_type == SUNFLOWER) {
    //     moved_plant = new SunFlower(200, 200);
	//     is_drag = true;
    //     is_valid = 0;
    // }
    // else if(plant_type == WALNUT) {
    //     moved_plant = new Walnut(200, 200);
	//     is_drag = true;
    //     is_valid = 0;
    // }
    // menu->isValidRequset(is_valid);
}

void Game::deleteOutBalls(){
    vector <Ball*> trash;
    for(Ball* b : balls){
        if( b->isOut()){
            trash.push_back(b);
        }
    }
    balls.erase(remove_if(balls.begin(), balls.end(),
        [](auto p){ return p->isOut(); }), balls.end());
    for (auto p : trash){
        delete p;
    }
}
void Game::handleCollision(){

}

bool Game::cellIsEmpty(Plant* p){
    if(p == nullptr)
        return 1;
    return 0;
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