#pragma once
#include<SFML/Graphics.hpp>
class bat
{
public: 
	sf::RectangleShape b1; 
	sf::RectangleShape b2; 
	float speed;
public: 
	bat();
	void updateWallCollision(const sf::RenderWindow* target);
	bool update(const sf::RenderWindow* target);
	void render(sf::RenderWindow* window); 
	sf::RectangleShape& getShapeb1() {
		return b1;
	}
	sf::RectangleShape& getShapeb2() {
		return b2;
	}
	float get_speed() {
		return speed; 
	}
};

