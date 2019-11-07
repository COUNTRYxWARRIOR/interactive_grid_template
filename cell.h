#pragma once

#include "SFML\Graphics.hpp"

class Cell
{
public:
	Cell(sf::Color normalCol, sf::Vector2i sPosition, int dim);

	void set_highlight(bool state);

	void draw_cell(sf::RenderWindow& window);

	bool collision_occur(sf::Vector2f obj);

	void set_colour(sf::Color colour);

private:
	bool active;
	int width;
	sf::Color defColour;
	sf::Vector2i pos;
	sf::RectangleShape square;
};