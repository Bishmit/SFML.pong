#include "Player.h"

Player::Player(float radius, const sf::Vector2f& initialVelocity)
    : radius(radius), velocity(initialVelocity)
{
    circle.setFillColor(sf::Color::White);
    circle.setRadius(radius);
    circle.setPosition(300.f, 60.f); // Set initial position
}

void Player::update(sf::RenderWindow* window, float deltaTime) {
    static bool isMoving = false;

    // Check for Enter key press to start the ball movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        isMoving = true;
    }

    // Move the ball only if it's started
    if (isMoving) {
        circle.move(velocity * deltaTime);

        // Collision detection with the walls
        if (circle.getPosition().x - radius <= 0.f || circle.getPosition().x + radius >= window->getSize().x) {
            // Change horizontal direction upon collision with left or right wall
            reverseX(); 
        }
        if (circle.getPosition().y - radius <= 0.f || circle.getPosition().y + radius >= window->getSize().y) {
            // Change vertical direction upon collision with top or bottom wall
            reverseY();
        }
    }
}


void Player::render(sf::RenderWindow* window) {
    window->draw(circle);
}


void Player::reverseX()
{
    velocity.x = -velocity.x;
}

void Player::reverseY()
{
    velocity.y = -velocity.y;
}
