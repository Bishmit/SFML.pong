#include"Game.h"

int main() {
	sf::Clock clock;
	Game game(0); 
	while (game.isGameRunning()) {
		sf::Time deltaTime = clock.restart(); // Restart the clock and get the elapsed time
		float dtSeconds = deltaTime.asSeconds(); // Convert to seconds
		game.update(dtSeconds); 
		game.render(); 
	}
}