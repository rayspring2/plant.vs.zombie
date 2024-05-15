
#ifndef GLOBAL_INCLUDE
#define GLOBAL_INCLUDE
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <filesystem>
#include <random>
#include <chrono>
#include <fstream> 
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;
namespace fs = filesystem;


const int FRAME_RATE = 144;

const string FILE_ERROR = "file not found\n";
const string BG_PATH = "files/pic/bg1.png";
const string ZM_PATH = "files/pic/gameover.png";

const string FONT_PATH = "files/font/HouseofTerrorRegular.otf";
const string FONT_NOT_FOUND = "font can not load\n";
const string PIC_NOT_FOUND = "picture not found\n";
const string NORMAL_WALNUT_PATH = "files/pic/walnut/normal_walnut.png";
const string CRACKED_WALNUT_PATH = "files/pic/walnut/cracked_walnut.png";
const string VERY_CRACKED_WALNUT_PATH = "files/pic/walnut/very_cracked_walnut.png";
const string SETTING_PATH = "setting.txt";
const string SETTING_DELIMITER = "*";
const string LOADING_ERROR = "file currupted! not found\n";

const float WIDTH = 1400.0f;
const float HEIGHT = 600.0f;

const int GROUNDROWS = 5;
const int GROUNDCOLUMNS = 9;
const int GROUND_LEFT_OFFSET = 216;
const int GROUND_UP_OFFSET = 53;
const int CELLWITDH = 82;
const int CELLHIGHT = 94;
const int TWO = 2;
const int ONE = 1;
const int ZERO = 0;
struct Position {
    int up, down, left, right, x, y;
};
enum PlantType{
	PEASHOOTER,
	SNOWPEA,
	SUNFLOWER,
	WALNUT,
	KERNELPULT,
	INVALID
};

enum ItemState {
    LOADING ,
	AVAILABLE ,
	UNAVAILABLE
};


#endif