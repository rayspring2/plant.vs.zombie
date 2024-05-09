#include "Global.hpp"
#include "System.hpp"
#include "Primary.hpp"

int main(){
	System* game = new System();
	game->run();
	delete game;
}