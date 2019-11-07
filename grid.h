#pragma once

#include <vector>

#include "cell.h"

class Grid
{
private:
	void init_cells();

	void click_cell();
public:
	Grid(int winWidth, int winHeight, int dim, int separate);

	Cell& get_cell(sf::Vector2i pos);

	void update(sf::RenderWindow& window);

	void draw(sf::RenderWindow& window);

	void handle_input(sf::RenderWindow& window, sf::Event event);

	void mouse_pos(sf::RenderWindow& window);

private:
	int width, height;
	int sWidth, sHeight;
	int spacing, cellDim;

	std::vector<std::vector<Cell>> board;

	sf::Vector2i mouseLoc;
	bool lMouseDown;

	std::mt19937 generator;
	std::uniform_int_distribution<int> distribution;

	sf::Vector2i nullPos;
	Cell nullCell;
public:

};