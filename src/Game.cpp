#include "Game.hpp"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
Game::Game() {
    readSettingFile();
    for(int i = 1; i <= GROUNDROWS; i++) {
        for(int j = 1; j <= GROUNDCOLUMNS; j++) {
            play_ground[i][j] = nullptr;
        }
    }

    for(int i = 1; i <= GROUNDROWS; i++) {
        play_ground_position[i][1].left = GROUND_LEFT_OFFSET;
        play_ground_position[i][1].right = GROUND_LEFT_OFFSET + CELLWITDH;
        play_ground_position[i][1].x = GROUND_LEFT_OFFSET + CELLWITDH / 2;

        play_ground_position[i][1].down = GROUND_UP_OFFSET + i  * CELLHIGHT;
        play_ground_position[i][1].up = GROUND_UP_OFFSET + (i - 1) * CELLHIGHT;
        play_ground_position[i][1].y = GROUND_UP_OFFSET + CELLHIGHT / 2 + (i - 1) * CELLHIGHT;
    }
    for(int j = 2; j <= GROUNDCOLUMNS; j++) {
        for(int i = 1; i <= GROUNDROWS; i++) {
            play_ground_position[i][j].x = play_ground_position[i][j - 1].x + CELLWITDH;
            play_ground_position[i][j].left = play_ground_position[i][j - 1].left + CELLWITDH;
            play_ground_position[i][j].right = play_ground_position[i][j - 1].right + CELLWITDH;
            play_ground_position[i][j].y = play_ground_position[i][j - 1].y;
            play_ground_position[i][j].up = play_ground_position[i][j - 1].up;
            play_ground_position[i][j].down = play_ground_position[i][j - 1].down;
        }
    }

    for( int i = 1 ; i <= GROUNDROWS ; i++){
        lawncleaners[i] = new LawnCleaner(GROUND_LEFT_OFFSET , play_ground_position[i][1].y);
    }

    is_dragging = false;
    icon = new Icon(0, 0);
    hasPlant();
    selected_plant = INVALID;
}

void Game :: hasPlant() {
    if(hasPeashooter) icon->addItem(PEASHOOTER, peashooterCooldown, "files/pic/PeashooterMenu.png", 100);
    if(hasSnowpea) icon->addItem(SNOWPEA, snowpeaCooldown, "files/pic/SnowpeaMenu.png", 175);
    if(hasSunflower) icon->addItem(SUNFLOWER, sunflowerCooldown, "files/pic/SunflowerMenu.png", 50);
    if(hasWalnut) icon->addItem(WALNUT, walnutCooldown, "files/pic/WalnutMenu.png", 50);
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

void Game::readSettingFile(){
    ifstream setting_file(SETTING_PATH);
    string input;
    while(setting_file >> input){
        if(input == SETTING_DELIMITER){
            setting_file >> input;
            if(input == GAME_SETTING_KEYWORD){
                break;
            }
        }
    }
    int value;
    setting_file >> input >> value;
    if(input == GAME_ZOMBIE_START_X)
        ZOMBIE_START_X = value;
    else
        cerr << LOADING_ERROR;
    
    setting_file >> input >> value;
    if( input == GAME_ZOMBIE_GENERATE_PERIOD)
        ZOMBIE_GENERATE_PERIOD = value;
    else    cerr << LOADING_ERROR;
    
    setting_file >> input >> value;
    if( input == GAME_SUN_FALLDOWN_SPEED)
        SUN_FALLDOWN_SPEED = value;
    else    
        cerr << LOADING_ERROR;
    
    setting_file >> input >> value;
    if( input == GAME_SUN_GENERATE_PERIOD)
        SUN_GENERATE_PERIOD = value;
    else
        cerr << LOADING_ERROR;
    
    setting_file >> input >> value;
    if( input == GAME_HAS_PEASHOOTER)
        hasPeashooter = value;
    else    
        cerr << LOADING_ERROR;
    
    setting_file >> input >> value;
    if( input == GAME_HAS_SNOWPEA)
        hasSnowpea = value;
    else    
        cerr << LOADING_ERROR;
    

    setting_file >> input >> value;
    if( input == GAME_HAS_WALNUT)
        hasWalnut = value;
    else    
        cerr << LOADING_ERROR;
    

    setting_file >> input >> value;
    if( input == GAME_HAS_SUNFLOWER)
        hasSunflower = value;
    else
        cerr << LOADING_ERROR;

    setting_file >> input >> value;
    if( input == GAME_PEASHOOTER_COOLDOWN)
        peashooterCooldown = value;
    else
        cerr << LOADING_ERROR;

    setting_file >> input >> value;
    if( input == GAME_SNOWPEA_COOLDOWN)
        snowpeaCooldown = value;
    else
        cerr << LOADING_ERROR;

    setting_file >> input >> value;
    if( input == GAME_WALNUT_COOLDOWN)
        sunflowerCooldown = value;
    else
        cerr << LOADING_ERROR;

    setting_file >> input >> value;
    if( input == GAME_SUNFLOWER_COOLDOWN)
        walnutCooldown = value;
    else
        cerr << LOADING_ERROR;

}

void Game::genZombie(){
	Time elapsed = clock.getElapsedTime();
	if(elapsed.asMilliseconds() >= ZOMBIE_GENERATE_PERIOD ) {
		clock.restart();
		int x = rng() % GROUNDROWS;
		int zombie_row_position = play_ground_position[x + ONE][ONE].up;
		int type_of_zombie = rng() % ZMOBIETYPESCNT;
		if(type_of_zombie) {
			HairMetal* zm = new HairMetal(ZOMBIE_START_X , zombie_row_position - HAIRMETAL_OFFSET_Y_POSITION, x + ONE);
			zombies.push_back(zm);
		}
		else {
			NormalZombie* zm = new NormalZombie(ZOMBIE_START_X , zombie_row_position, x + ONE);
			zombies.push_back(zm);
		}
	}
}
void Game::update(RenderWindow &window){
    icon->update();
    handleCollision();
    handleSunCollect(window);
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
    for(int i = 1; i <= GROUNDROWS ; i++){
        if(lawncleaners[i] == nullptr )
            continue;
        lawncleaners[i]->update();
    }
    genSun();
    genZombie();
    updatePlayGround();
    checkEating();
}


void Game::addAttackPlantBall(AttackPlant* attack_plant){
    Time shooter_time_elapsed = attack_plant -> getShootTimeElapsed();
    if(shooter_time_elapsed.asMilliseconds() >= attack_plant-> getCoolDownTime() * SPEED_COOLDOWN){
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
    for(int i = 1; i <= GROUNDROWS ; i++){
        if(lawncleaners[i] == nullptr )
            continue;
        lawncleaners[i]->render(window);
    }

    for(Ball* b : balls){
        b->render(window);
    }
    for(Zombie* z : zombies)
        z->render(window);

    for(Sun* s : suns){
        s->render(window);
    }

    icon->render(window);
}

bool Game :: isGameOver() {
    for(int i = 0; i < zombies.size(); i++) {
        if(zombies[i]->getGameover()) {
            return true;
        }
    }
    return false;
}

void Game :: plantRequest(RenderWindow &window) {
    moved_plant->handleMousePress();
    icon->turnOffBorder();
    Vector2i mouse_pos = Mouse::getPosition(window);
    Vector2f target(static_cast<float>(mouse_pos.x) - moved_plant->getWidth() / 2, static_cast<float>(mouse_pos.y) - moved_plant->getHeight() /2);
    moved_plant->setPos(target);
    is_dragging = false;
    pair<int, int> new_position = findPlayGroundBlock(target);
    if(new_position != INVALID_POSITION) {
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

void Game :: createRequest(RenderWindow &window) {
    PlantType plant_type = icon->checkMouse(window);
    if(plant_type == PEASHOOTER) {
        moved_plant = new PeaShooter(TEMP_POSITION, TEMP_POSITION);
    }
    else if(plant_type == SNOWPEA) {
        moved_plant = new SnowPea(TEMP_POSITION, TEMP_POSITION);
    }
    else if(plant_type == SUNFLOWER) {
        moved_plant = new SunFlower(TEMP_POSITION, TEMP_POSITION);
    }
    else if(plant_type == WALNUT) {
        moved_plant = new Walnut(TEMP_POSITION, TEMP_POSITION);
    }
    else return;
    is_dragging = true;
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
    for(int i = 1; i <= GROUNDROWS ; i++){
        LawnCleaner* lc = lawncleaners[i];
        if (lc == nullptr )
            continue;
        if( lc -> isOut() ){
            lawncleaners[i] = nullptr;
        }
        for(auto z : zombies){
            if(lc->getRect().intersects(z->getRect()) && i == z-> getRow()){
                lc->move();
                z->die();
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
        for(int i = 1; i <= GROUNDROWS; i++) {
            for(int j = 1; j <= GROUNDCOLUMNS; j++) {
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
        Sun* new_sun = sun_flower->makeSun(sun_flower->getPos());
        suns.push_back(new_sun);
    }
}

void Game::genSun(){
    Time shooter_time_elapsed = sun_clock.getElapsedTime();
    if(shooter_time_elapsed.asMilliseconds() >= SUN_GENERATE_PERIOD ){
        sun_clock.restart();
        Sun* new_sun = new Sun(GROUND_LEFT_OFFSET + rng() % CELLWITDH * GROUNDCOLUMNS , 0 , SUN_FALLDOWN_SPEED );
        suns.push_back(new_sun);
    }
}

void Game::handleSunCollect(RenderWindow &window) {
    vector<Sun*> trash;
    Vector2i mouse_pos = sf::Mouse::getPosition(window);
    int suns_collected = 0;
    for (auto s : suns) {
        if (s->can_collect(Vector2f(mouse_pos.x,mouse_pos.y))) {
            suns_collected++;
            trash.push_back(s);
        }
    }
    for (auto s : trash) {
        suns.erase(remove(suns.begin(), suns.end(), s), suns.end());
        delete s;
    }
    icon->increase_money(suns_collected * 25);
}


