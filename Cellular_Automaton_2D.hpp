#include <SFML/Graphics.hpp>

class Cellular_Automaton_2D{
public:
    Cellular_Automaton_2D(int rows, int cols, int cell_size);
    ~Cellular_Automaton_2D();

    void run();

private:
    int m_rows, m_cols, m_cell_size;
    std::string state;

    sf::RenderWindow window;
    sf::RectangleShape rect;

    void initialize();

    char getnextState(int row, int col);
    std::string getNextState();
    std::string getRandomScreen();

    void drawScreen();
};