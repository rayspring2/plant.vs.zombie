#include "Game.hpp"

Game::Game() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 9; j++) {
            play_ground[i][j] = nullptr;
        }
    }
    play_ground[0][0] = new PeaShooter(500, 300);  /////////////added just for examine
}

void Game::update(){
    for(int i = 0; i < GROUNDROWS; i++ ){
        for(Plant* p : play_ground[i]){
            if(cellIsEmpty(p))
                continue;
            p->update();
            if(auto attack_plant = dynamic_cast<AttackPlant*>(p))
                addAttackPlantBall(attack_plant);
            //must add:    
            //check for zombie eating plants
            //add sun to sunflowers
            //zombie plant and zombie and shoots collisions
        }
    }
    
    for(Ball* b : balls)
        b->update();
    deleteOutBalls();
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
    for( int i = 0; i < GROUNDROWS ; i++ ){
        for( auto p : play_ground[i] ){
            if(cellIsEmpty(p))
                continue;
            p->render(window);
        }
    }
    for(Ball* b : balls){
        b->render(window);
    }
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