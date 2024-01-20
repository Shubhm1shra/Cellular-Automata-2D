#include "Cellular_Automaton_2D.hpp"

int main(){
    int rows = 200;
    int cols = 200;
    int cell_size = 3;
    
    Cellular_Automaton_2D ca2D(rows, cols, cell_size);

    ca2D.run();

    return 0;
}
