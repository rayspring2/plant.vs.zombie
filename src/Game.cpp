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
    //play_ground[1][1] = new Walnut(250 , 53);
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
void Game::update(){
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
    if(shooter_time_elapsed.asMilliseconds() >= attack_plant-> getCoolDownTime() *100){
        Ball* new_ball = attack_plant->addBall();
        balls.push_back(new_ball);
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
    for(Zombie* z : zombies) 
        z->render(window);
    
    for(Sun* s : suns){
        s->render(window);
    }
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



