#include <SFML/Graphics.hpp>
#include "Player.h"
#include"bat.h"
#include<iostream>

class Game {
private:
    sf::RenderWindow* window;
    sf::Event event;
    Player ball;
    bat ba; 
    void initWindow();
public:
    Game();
    ~Game();
    const bool isGameRunning() const;
    void update(float);
    void render();
    
};
