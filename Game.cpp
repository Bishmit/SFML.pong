#include "Game.h" 

Game::Game(int score) : score(score) {
    initWindow();
    initFontAndText();
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

    ball.update(window, dt);
    ba.update(window);

    if (ball.getShape().getGlobalBounds().intersects(ba.getShapeb1().getGlobalBounds()) ||
        ball.getShape().getGlobalBounds().intersects(ba.getShapeb2().getGlobalBounds())) {
        ball.reverseX(); 
        this->score++;
        text.setString("Score: " + std::to_string(this->score));
        std::cout << score << "\n"; 
    }
}

void Game::render() {
    window->clear();
    ball.render(window);
    ba.render(window);
    window->draw(text); // Render the text
    window->display();
}

void Game::initFontAndText() {
    if (!font.loadFromFile("PixellettersFull.ttf")) {
        std::cout << "Error: Font could not be loaded!" << std::endl;
    }

    text.setFont(font); // Set the font
    text.setString("Score: " + std::to_string(this->score)); // Set the initial text
    text.setCharacterSize(34);
    text.setFillColor(sf::Color::White);
    text.setPosition(30.f, 5.f); // Set the position
}