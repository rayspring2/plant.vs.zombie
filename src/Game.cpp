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
    play_ground[1][1] = new PeaShooter(500, 300);  /////////////added just for examine
    
    play_ground[1][2] = new SnowPea(300, 700);  /////////////added just for examine
    
    play_ground[1][4] = new PeaShooter(400, 200);  /////////////added just for examine
    
    play_ground[1][6] = new SnowPea(200, 300);  /////////////added just for examine
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
    for(auto z: zombies)
        z -> update();
    for(Ball* b : balls)
        b->update();
    genZombie();
    updatePlayGround();
    checkEating();
    //must add:
    //check for zombie eating plants
    //add sun to sunflowers
    //zombie plant and zombie and shoots collisions
    
}


void Game::addAttackPlantBall(AttackPlant* attack_plant){
    Time shooter_time_elapsed = attack_plant -> getShootTimeElapsed();
    if(shooter_time_elapsed.asMilliseconds() >= attack_plant-> getCoolDownTime() *100){
        Ball* new_ball = attack_plant->addBall();
        balls.push_back(new_ball);
    }
}

void Game::render(RenderWindow &window){
    for( int i = 1; i < GROUNDROWS ; i++ ){
        for( int j=1 ;j<GROUNDCOLUMNS ;j++){ //auto p : play_ground[i] 
            if(cellIsEmpty(play_ground[i][j]))
                continue;
            play_ground[i][j]->render(window);
        }
    }
    for(Ball* b : balls){
        b->render(window);
    }
    for(int i = 0; i < zombies.size(); i++) zombies[i]->render(window);
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


