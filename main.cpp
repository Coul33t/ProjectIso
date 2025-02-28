//
// Created by couland-q on 29/03/2022.
//

#include <iostream>

#include "include/engine.h"

int main(int argv, char** args) {
    Engine engine;
    
    if (!engine.init()) {
        return 1;
    }

    engine.run();
    return 0;
}
