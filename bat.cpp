#include "bat.h"

bat::bat():speed(0.1f)
{
	b1.setSize(sf::Vector2f(20.f, 150.f)); 
	b1.setFillColor(sf::Color::Green); 
	b1.setPosition(0.f, 0.f); 
	b2.setSize(sf::Vector2f(20.f, 150.f));
	b2.setFillColor(sf::Color::Cyan);
	b2.setPosition(580.f, 0.f);
}
void bat::updateWallCollision(const sf::RenderWindow* target)
{
    // for first bat
	
	// Ensure the player stays within the top boundary
	if (this->b1.getGlobalBounds().top <= 0.f) {
		this->b1.setPosition(this->b1.getGlobalBounds().left, 0.f);
	}

	// Ensure the player stays within the bottom boundary
	if (this->b1.getGlobalBounds().top + this->b1.getGlobalBounds().height >= target->getSize().y) {
		this->b1.setPosition(this->b1.getGlobalBounds().left, target->getSize().y - this->b1.getGlobalBounds().height);
	}

	// for 2nd bat

	// Ensure the player stays within the top boundary
	if (this->b2.getGlobalBounds().top <= 0.f) {
		this->b2.setPosition(this->b2.getGlobalBounds().left, 0.f);
	}

	// Ensure the player stays within the bottom boundary
	if (this->b2.getGlobalBounds().top + this->b2.getGlobalBounds().height >= target->getSize().y) {
		this->b2.setPosition(this->b2.getGlobalBounds().left, target->getSize().y - this->b2.getGlobalBounds().height);
	}

}
void bat::update(const sf::RenderWindow* target)
{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			this->b1.move(0, -this->speed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			this->b1.move(0, this->speed);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
			this->b2.move(0, -this->speed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
			this->b2.move(0, this->speed);
		}

		updateWallCollision(target); 
		
}


void bat::render(sf::RenderWindow* target) {
	target->draw(b1);
	target->draw(b2); 
}



