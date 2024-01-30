#pragma once
#include <SFML/Graphics.hpp>
#include "bat.h"
#include <iostream>

class Player{
public:
    sf::CircleShape circle; 
    float radius;
    sf::Vector2f velocity;

    public:
    Player(float radius = 10.f, const sf::Vector2f& initialVelocity = sf::Vector2f(250.f, 250.f)); // Default values for radius and speed
    void reverseX(); 
    void reverseY();
    void setVelocity(const sf::Vector2f& newVelocity);
    void update(sf::RenderWindow* window, float deltaTime);
    void render(sf::RenderWindow* window);
    sf::CircleShape& getShape() {
        return circle;
    }
    sf::Vector2f get_velocity() {
        return velocity; 
    }
   
};