#include <SFML/Graphics.hpp>
#include "include/Game.h"
#include "GameStates/MenuState.h"
#include <cstdlib>
#include <ctime>

//#include "dirent.h"
#include <fstream>
#include <string>
#include <iostream>

int main()
{
    std::cout<<"test"<<std::endl;
    srand( time( NULL ) );
    std::shared_ptr<Game> game;
    game = std::make_shared<Game>() ;
    game->pushState(std::make_shared<MenuState>(game));
    game->gameLoop();
    return 0;
}