#include <SFML/Graphics.hpp>
#include <random>
#include <stdlib.h>
#include <iostream>

#include "grid.h"

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 800), "IT WORKS!");

	sf::Clock timer;

	auto lastTime = sf::Time::Zero;
	
	Grid board(window.getSize().x, window.getSize().y, 50, 10);

	while(window.isOpen()) {

		sf::Event event;
		

		auto time = timer.getElapsedTime();
		auto elapsed = time - lastTime;
		lastTime = time;


		window.clear();
		board.update(window);
		window.display();
		
		while (window.pollEvent(event)) {

			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				board.handle_input(window, event);
				break;
			case sf::Event::MouseButtonReleased:
				board.handle_input(window, event);
				break;
			case sf::Event::EventType::Closed:
				window.close();
				break;
			default:
				break;
			}
		}
	}

	return 0;
}

