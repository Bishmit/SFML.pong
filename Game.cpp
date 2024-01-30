#include "Game.h" 

Game::Game() { 
    initWindow();
}

Game::~Game() {
    delete window;
}

void Game::initWindow() {
    window = new sf::RenderWindow(sf::VideoMode(600, 600), "Spacemothfaka");
}

const bool Game::isGameRunning() const {
    return window->isOpen();
}

void Game::update(float dt) {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
    }
    ball.update(window,dt);
    ba.update(window); 

    if (ball.getShape().getGlobalBounds().intersects(ba.getShapeb1().getGlobalBounds()) ||
        ball.getShape().getGlobalBounds().intersects(ba.getShapeb2().getGlobalBounds())){
        ball.reverseX();
        //ball.reverseY(); 
     }
}

void Game::render() {
    window->clear();
    ball.render(window);
    ba.render(window); 
    window->display();
}


