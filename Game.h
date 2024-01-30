#include <SFML/Graphics.hpp>
#include "Player.h"
#include "bat.h"
#include <iostream>

class Game {
private:
    sf::RenderWindow* window;
    sf::Event event;
    Player ball;
    bat ba;
    int score;
    sf::Font font;
    sf::Text text;

    void initWindow();
    void initFontAndText();

public:
    Game(int score);
    ~Game();

    const bool isGameRunning() const;
    void update(float);
    void render();
};