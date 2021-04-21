#include <stdafx.h>

#include <Game/GameDemo.h>
#include "Game/MainLoop.h"

int main(){
    /*
        GameDemo game{};
        game.RunGameLoop();
    */
    
    MainLoop loop{};
    loop.RunGameLoop();
    
    return EXIT_SUCCESS;
}