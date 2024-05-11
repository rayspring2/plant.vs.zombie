#include "Game.hpp"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

void Game::genZombie(){
	Time elapsed = clock.getElapsedTime();
	if(elapsed.asSeconds() >= 1) {
		clock.restart();
		int x = rng() % 5;
		int zombie_row_position = play_ground_position[x + 1][1].up;
		int type_of_zombie = rng() % 2;
		if(type_of_zombie) {
			HairMetal* zm = new HairMetal(1000, zombie_row_position);
			zombies.push_back(zm);
		}
		else {
			NormalZombie* zm = new NormalZombie(1000, zombie_row_position);
			zombies.push_back(zm);
		}
	}
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

    handleCollision();
    removeDeadZombies();
    deleteUnvalidBalls();
    for(auto z: zombies)
        z -> update();
    for(Ball* b : balls)
        b->update();
    genZombie();
    updatePlayGround();
    checkEating();

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
    if(shooter_time_elapsed.asMilliseconds() >= attack_plant-> getCoolDownTime() *100){
        Ball* new_ball = attack_plant->addBall();
        balls.push_back(new_ball);
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
    // if (selected_plant == INVALID) {
    //     selected_plant = menu->checkMouse(window);
    //     return;
    // }
    // PlantType new_selected_plant = menu->checkMouse(window);
    // if (new_selected_plant != INVALID) {
    //     selected_plant = new_selected_plant;
    //     return;
    // }
    // Vector2i mouse_position = Mouse :: getPosition(window);
    // pair <int,int>location = findPlayGroundBlock((Vector2f) mouse_position);
    // if (location == pair<int, int>(-1,-1)) {
    //     selected_plant = INVALID;
    //     return;
    // }
    // Plant* planting;
    // if(selected_plant == PEASHOOTER) {
    //     planting = new PeaShooter(200, 200);
    // }
    // else if(selected_plant == SNOWPEA) {
    //     planting = new SnowPea(200, 200);
    // }
    // else if(selected_plant == SUNFLOWER) {
    //     planting = new SunFlower(200, 200);
    // }
    // else if(selected_plant == WALNUT) {
    //     planting = new Walnut(200, 200);
    // }
    // menu->resetCooldown(selected_plant);
    // play_ground[location.first][location.second] = planting;
    // play_ground[location.first][location.second]->setPos(Vector2f((float)play_ground_position[location.first][location.second].x,
    //     (float)play_ground_position[location.first][location.second].y));
    // check box !
    //
    PlantType plant_type = menu->checkMouse(window);
	if(moved_plant != nullptr and is_drag == true) moved_plant->handleMousePress();
    if(plant_type == PEASHOOTER) {
        moved_plant = new PeaShooter(200, 200);
	    is_drag = true;
        is_valid = 0;
    }
    else if(plant_type == SNOWPEA) {
        moved_plant = new SnowPea(200, 200);
	    is_drag = true;
        is_valid = 0;
    }
    else if(plant_type == SUNFLOWER) {
        moved_plant = new SunFlower(200, 200);
	    is_drag = true;
        is_valid = 0;
    }
    else if(plant_type == WALNUT) {
        moved_plant = new Walnut(200, 200);
	    is_drag = true;
        is_valid = 0;
    }
    menu->isValidRequset(is_valid);
}

void Game::deleteUnvalidBalls(){
    vector <Ball*> trash;
    for(Ball* b : balls){
        if( b->isOut() || b->isCollided()){
            trash.push_back(b);
        }
    }
    balls.erase(remove_if(balls.begin(), balls.end(),
        [](auto p){ return p->isOut() || p->isCollided(); }), balls.end());
    for (auto p : trash){
        delete p;
    }
}

void Game::handleCollision(){
    for(auto b : balls){
        for(auto z : zombies){
            if( b -> getRect().intersects(z->getRect())){
                z->hit(b->getDamageValue());
                b->collide();
            }
        }
    }
}

bool Game::cellIsEmpty(Plant* p){
    if(p == nullptr)
        return 1;
    return 0;
}


void Game::checkEating() {
    for(Zombie* z : zombies ) {
        z -> mode = "walking";
        for(int i = 1; i <= 5; i++) {
            for(int j = 1; j <= 9; j++) {
                if(cellIsEmpty( play_ground[i][j] ) )
                    continue;
                if(play_ground[i][j]->getRect().intersects(z->getRect()) ) {
                    z -> mode = "eating";
                    if( z -> isReadytoHit()){
                        play_ground[i][j]->hit(z->getDamageValue());
                        cerr << play_ground[i][j]->getHealth() <<endl;
                    }
                }
            }
        }
    }
}


void Game::removeDeadZombies(){
    vector <Zombie*> trash;
    for(Zombie* z : zombies){
        if( !z->isAlive()){
            trash.push_back(z);
        }
    }
    zombies.erase(remove_if(zombies.begin(), zombies.end(), 
        [](auto p){ return !p->isAlive() ; }), zombies.end());
    
    for (auto p : trash){
        delete p;
    }
}

void Game::updatePlayGround(){
    deleteDeadPlants();
    for( int i = 1; i < GROUNDROWS ; i++ ){
        for( int j = 1 ;j<GROUNDCOLUMNS ;j++){
            if(cellIsEmpty(play_ground[i][j]))
                continue;
            play_ground[i][j]->update();
            if(auto attack_plant = dynamic_cast<AttackPlant*>(play_ground[i][j]))
                addAttackPlantBall(attack_plant);
        }
    }
}

void Game::deleteDeadPlants(){
    for( int i = 1; i < GROUNDROWS ; i++ ){
        for( int j = 1 ; j<GROUNDCOLUMNS ;j++){
            if(cellIsEmpty(play_ground[i][j]) )
                continue;
            if(!play_ground[i][j]->isAlive()){
                delete play_ground[i][j];
                play_ground[i][j] = nullptr; 
            }
        }
    }
}


