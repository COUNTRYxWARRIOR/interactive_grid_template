
#include "SFML\Graphics.hpp"

#include "cell.h"

Cell::Cell (sf::Color normCol, sf::Vector2i sPosition, int dim) {
	defColour = normCol;
	pos = sPosition;
	active = false;
	width = dim;

	square.setFillColor(defColour);
	square.setPosition((sf::Vector2f) pos);
	sf::Vector2f dims = { (float) dim, (float) dim };

	square.setSize(dims);
}

// Used for mouse highlighting
void Cell::set_highlight(bool state) {
	active = state;
}

// Draw cell on screen
void Cell::draw_cell(sf::RenderWindow& window) {
	if (active) {
		// Highlighted
		square.setOutlineThickness(floor(width * 0.1f));
		square.setOutlineColor(sf::Color::Blue);
	} else {
		square.setOutlineThickness(0.f);
	}

	square.setFillColor(defColour);
	window.draw(square);
}

bool Cell::collision_occur(sf::Vector2f obj) {
	return (
		(obj.x >= pos.x) && (obj.x <= pos.x + width) &&
		(obj.y >= pos.y) && (obj.y <= pos.y + width)
		);
}

void Cell::set_colour(sf::Color colour) {
	defColour = colour;
	
}