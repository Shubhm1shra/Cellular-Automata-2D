#include "Cellular_Automaton_2D.hpp"

Cellular_Automaton_2D::Cellular_Automaton_2D(int rows, int cols, int cell_size) : m_rows(rows), m_cols(cols), m_cell_size(cell_size){
    initialize();
}

Cellular_Automaton_2D::~Cellular_Automaton_2D() = default;

void Cellular_Automaton_2D::run(){

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) window.close();
        }
        
        window.clear();

        drawScreen();
        window.display();
        sf::sleep(sf::milliseconds(50));

        state = getNextState();
    }
}

void Cellular_Automaton_2D::initialize(){
    window.create(sf::VideoMode(m_cols * m_cell_size, m_rows * m_cell_size), "Game of Life!");
    window.setVerticalSyncEnabled(true);

    rect.setSize(sf::Vector2f(m_cell_size, m_cell_size));

    state = getRandomScreen();
}

char Cellular_Automaton_2D::getnextState(int row, int col){
    int statePos = row * m_cols + col;
    
    int checkPos[8];
    checkPos[0] = statePos - m_cols - 1;
    checkPos[1] = statePos - m_cols;
    checkPos[2] = statePos - m_cols + 1;
    checkPos[3] = statePos - 1;
    checkPos[4] = statePos + 1;
    checkPos[5] = statePos + m_cols - 1;
    checkPos[6] = statePos + m_cols;
    checkPos[7] = statePos + m_cols + 1;

    int aliveCount = 0;

    for(int i = 0; i < 8; i++){
        if(checkPos[i] < 0 || checkPos[i] >= state.size()) continue;
        if(state[checkPos[i]] == '1') aliveCount++;
    }

    // Rule-Set :-
    // '1' -> aliveCount < 2 or > 2 -> '0'
    // '0' -> aliveCount = 3 -> '1'

    if(state[statePos] == '1' && (aliveCount < 2 || aliveCount > 3)) return '0';
    if(state[statePos] == '0' && aliveCount == 3) return '1';
    return state[statePos];
}

std::string Cellular_Automaton_2D::getNextState(){
    std::string nextState;

    for(int row = 0; row < m_rows; row++){
        for(int col = 0; col < m_cols; col++){
            nextState += getnextState(row, col);
        }
    }

    return nextState;
}

std::string Cellular_Automaton_2D::getRandomScreen(){
    std::string result;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for(int i = 0; i < m_rows * m_cols; i++) result += std::to_string(std::rand() % 2);

    return result;
}

void Cellular_Automaton_2D::drawScreen(){
    if(state.size() != m_rows * m_cols) return;

    for(int col = 0; col < m_cols; col++){
        for(int row = 0; row < m_rows; row++){
            if(state[row * m_cols + col] == '1') rect.setFillColor(sf::Color::White);
            else rect.setFillColor(sf::Color::Black);

            rect.setPosition(sf::Vector2f(col * m_cell_size, row * m_cell_size));

            window.draw(rect);
        }
    }
}