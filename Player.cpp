#include "Player.h"

Player::Player(float radius, const sf::Vector2f& initialVelocity)
    : radius(radius), velocity(initialVelocity)
{
    circle.setFillColor(sf::Color::White);
    circle.setRadius(radius);
    circle.setPosition(300.f, 60.f); // Set initial position
}

void Player::update(sf::RenderWindow* window, float deltaTime) {
    if (GameoverShits(window)) {
        circle.move(velocity * deltaTime);
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

void Player::setVelocity(const sf::Vector2f& newVelocity) {
    velocity = newVelocity;
}


bool Player::GameoverShits(sf::RenderWindow *window) {
    if (circle.getPosition().y - radius <= 0.f || circle.getPosition().y + radius >= window->getSize().y) {
        // Change vertical direction upon collision with top or bottom wall
        reverseY();
        return true; 
    }
    if (circle.getPosition().x - radius <= 0.f || circle.getPosition().x + radius >= window->getSize().x - 20) {
        postGameOverStuffs(window); 
        return false;
    }
}

void Player::postGameOverStuffs(sf::RenderWindow *window) {
   // circle.setPosition(300.f, 60.f); 
    if (!b.update(window)) {
        float new_speed = b.get_speed();
        new_speed = 0.f;
        b.getShapeb1().setPosition(0.f, 0.f);
        std::cout << "rokkiyo hai" << "\n";
        b.getShapeb2().setPosition(0.f, 580.f);
    }
}

