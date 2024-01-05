//
// Created by couland-q on 29/03/2022.
//

#include <iostream>

#include "include/engine.h"

int main(int argv, char** args) {
    std::cout << "Engine creation" << std::endl;
    Engine engine;
    std::cout << "Engine initialisation" << std::endl;
    engine.init();
    std::cout << "Run engine" << std::endl;
    engine.run();
    return 0;
}
