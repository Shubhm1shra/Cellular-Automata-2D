#include "Cellular_Automaton_2D.hpp"

/*
g++ Cellular_Automaton_2D.cpp -o main main.cpp -I\"C:\\msys64\\mingw64\\include\" -L\"C:\\msys64\\mingw64\\lib\" -lsfml-graphics -lsfml-window -lsfml-system
*/

// 111000101001101110101010001010010111

int main(){
    Cellular_Automaton_2D ca2D(200, 200, 3);

    ca2D.run();

    return 0;
}