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
    int leftscore, rightscore; 
    sf::Font font;
    sf::Text text;

    void initWindow();
    void initFontAndText();

    void ScoreBoardLeftBat();

    void ScoreBoardRightBat();

public:
    Game(int leftscore = 0, int rightscore = 0);
    ~Game();

    const bool isGameRunning() const;
    void update(float);
    void render();
};