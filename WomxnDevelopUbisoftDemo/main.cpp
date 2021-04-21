#include <stdafx.h>

#include <Game/GameDemo.h>
#include "MainLoop.h"

int main(){

    /*
        GameDemo game{};

        game.RunGameLoop();
    */
    
    MainLoop loop{};

    loop.RunGameLoop();
    

    return EXIT_SUCCESS;
}