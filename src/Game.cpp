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
    icon = new Icon(0, 0);
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

void Game::update(){
    icon->update();
    handleCollision();
    removeDeadZombies();
    deleteUnvalidBalls();
    deleteDeadSuns();
    for(auto z: zombies)
        z -> update();
    for(Ball* b : balls)
        b->update();
    for(Sun* s:suns){
        s->update();
    }
    genSun();
    genZombie();
    updatePlayGround();
    checkEating();
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
    for( int i = 1; i <= GROUNDROWS ; i++ ){
        for( int j=1 ;j<= GROUNDCOLUMNS ;j++){
            if(cellIsEmpty(play_ground[i][j]))
                continue;
            play_ground[i][j]->render(window);
        }
    }
    for(Ball* b : balls){
        b->render(window);
    }
    icon->render(window);
    for(Zombie* z : zombies)
        z->render(window);
    
    for(Sun* s : suns){
        s->render(window);
    }
}

void Game :: plantRequest(RenderWindow &window) {
    moved_plant->handleMousePress();
    icon->turnOffBorder();
    Vector2i mouse_pos = Mouse::getPosition(window);
    Vector2f target(static_cast<float>(mouse_pos.x) - moved_plant->getWidth() / 2, static_cast<float>(mouse_pos.y) - moved_plant->getHeight() /2);
    moved_plant->setPos(target);
    is_dragging = false;
    pair<int, int> new_position = findPlayGroundBlock(target);
    if(new_position != pair<int, int>(-1, -1)) {
        play_ground[new_position.first][new_position.second] = moved_plant;
        play_ground[new_position.first][new_position.second]->setPos(Vector2f((float)play_ground_position[new_position.first][new_position.second].x,
        (float)play_ground_position[new_position.first][new_position.second].y));
        moved_plant = nullptr;
    }
    else {
        moved_plant = nullptr;
        return;
    }
    icon->isValidRequset();
}

bool Game :: checkGameOver() {
    for(int i = 0; i < zombies.size(); i++) {
        if(zombies[i]->getGameOverStatus()) {
            return true;
        }
    }
    return false;
}

void Game :: createRequest(RenderWindow &window) {
    PlantType plant_type = icon->checkMouse(window);
    if(plant_type == PEASHOOTER) {
        moved_plant = new PeaShooter(200, 200);
    }
    else if(plant_type == SNOWPEA) {
        moved_plant = new SnowPea(200, 200);
    }
    else if(plant_type == SUNFLOWER) {
        moved_plant = new SunFlower(200, 200);
    }
    else if(plant_type == WALNUT) {
        moved_plant = new Walnut(200, 200);
    }
    else return;
    is_dragging = true;
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
    for(auto b : balls){
        for(auto z : zombies){
            if( b -> getRect().intersects(z->getRect()) && z->getRow() == b->getRow()){
                z->hit(b->getDamageValue());
                b->collide();
                if(auto icy_ball = dynamic_cast<BallIcy*> (b)){
                    z->reduceSpeed();
                }
            }
        }
    }
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

void Game::checkEating() {
    for(Zombie* z : zombies ) {
        z -> mode = WALKING;
        for(int i = 1; i <= 5; i++) {
            for(int j = 1; j <= 9; j++) {
                if(cellIsEmpty( play_ground[i][j] ) )
                    continue;
                if(play_ground[i][j]->getRect().intersects(z->getRect()) && (i == z->getRow()) ) {
                    z -> mode = EATING;
                    if( z -> isReadytoHit())
                        play_ground[i][j]->hit(z->getDamageValue());
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

void Game::deleteDeadSuns(){
    vector <Sun*> trash;
    for(Sun* s : suns){
        if( !s->isAlive()){
            trash.push_back(s);

        }
    }
    suns.erase(remove_if(suns.begin(), suns.end(), 
        [](Sun* p){ return !p->isAlive() ; }), suns.end());
    
    for (auto p : trash){
        delete p;
    }
}

void Game::updatePlayGround(){
    deleteDeadPlants();
    for( int i = 1; i <= GROUNDROWS ; i++ ){
        for( int j = 1 ;j<= GROUNDCOLUMNS ;j++){
            if(cellIsEmpty(play_ground[i][j]))
                continue;
            play_ground[i][j]->update();
            if(auto attack_plant = dynamic_cast<AttackPlant*>(play_ground[i][j]))
                addAttackPlantBall(attack_plant);
            if(auto sun_flower = dynamic_cast<SunFlower*>(play_ground[i][j])){
               addSunflowerSun(sun_flower);
            }
        }
    }
}

void Game::deleteDeadPlants(){
    for( int i = 1; i <= GROUNDROWS ; i++ ){
        for( int j = 1 ; j<= GROUNDCOLUMNS ;j++){
            if(cellIsEmpty(play_ground[i][j]) )
                continue;
            if(!play_ground[i][j]->isAlive()){
                delete play_ground[i][j];
                play_ground[i][j] = nullptr;
            }
        }
    }
}

void Game::addSunflowerSun(SunFlower* sun_flower){
    Time shooter_time_elapsed = sun_flower -> getShootTimeElapsed();
    if(shooter_time_elapsed.asMilliseconds() >= sun_flower-> getCoolDownTime() *100){
        Sun* new_sun = sun_flower->makeSun();
        suns.push_back(new_sun);
    }
}

void Game::genSun(){
    Time shooter_time_elapsed = sun_clock.getElapsedTime();
    if(shooter_time_elapsed.asSeconds() >= 10 ){
        sun_clock.restart();
        Sun* new_sun = new Sun(100 + rng() % 1000 , 0 , -10 );
        suns.push_back(new_sun);
    }
}