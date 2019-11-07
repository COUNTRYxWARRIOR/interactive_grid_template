
#include <vector>
#include <random>
#include <iostream>

#include "grid.h"
#include "cell.h"

Grid::Grid(int winWidth, int winHeight, int dim, int separate) : 
			distribution(1, 255), nullCell(sf::Color::Black, nullPos, -1) {
	sWidth = winWidth;
	sHeight = winHeight;
	spacing = separate;
	cellDim = dim;
	lMouseDown = false;

	width = sWidth / (dim + spacing);
	height = sHeight / (dim + spacing);

	init_cells();

	sf::Vector2i nullPos = { -1, -1 };
}

void Grid::init_cells() {
	
	int topLeftX = (int) floor((sWidth - (width * (cellDim + spacing) - spacing)) / 2);
	int topLeftY = (int) floor((sHeight - (height * (cellDim + spacing) - spacing)) / 2);
	
	for (int j = 0; j < height; j++) {
		std::vector<Cell> row;

		for (int i = 0; i < width; i++) {
			sf::Vector2i cellPos = {
				topLeftX + (i * (spacing + cellDim)),
				topLeftY + (j * (spacing + cellDim))
			};

			sf::Color randColour = {
				(sf::Uint8) distribution(generator),
				(sf::Uint8) distribution(generator),
				(sf::Uint8) distribution(generator)
			};

			Cell newCell(randColour, cellPos, cellDim);

			row.push_back(newCell);
		}

		board.push_back(row);
		
	}
}

Cell& Grid::get_cell(sf::Vector2i pos) {
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			Cell& currCell = board[j][i];
			if (currCell.collision_occur((sf::Vector2f) mouseLoc)) {
				return currCell;
			}
		}
	}
	
	return nullCell;
}

// Wrapper function for updating grid state
void Grid::update(sf::RenderWindow& window) {
	mouse_pos(window);

	draw(window);
}

void Grid::draw(sf::RenderWindow& window) {

	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			Cell& currCell = board[j][i];
			currCell.set_highlight(false);

			if (currCell.collision_occur((sf::Vector2f) mouseLoc)) {
				currCell.set_highlight(true);
			}
			currCell.draw_cell(window);
		}
	}
}

// Handle input events
void Grid::handle_input(sf::RenderWindow& window, sf::Event event) {

	/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		click_cell();
	}*/

	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Left && !lMouseDown) {
			click_cell();
			lMouseDown = true;
		}
		break;
	case sf::Event::MouseButtonReleased:
		if (event.mouseButton.button == sf::Mouse::Left && lMouseDown) {
			lMouseDown = false;
		}
		break;
	default:
		break;
	}
	
}

// Translate local mouse position to cell and highlight
void Grid::mouse_pos(sf::RenderWindow& window) {
	mouseLoc = sf::Mouse::getPosition(window);

	//std::cout << mouseLoc.x << ":" << mouseLoc.y << " ";
}

void Grid::click_cell() {
	Cell& clickedCell = get_cell(mouseLoc);

	sf::Color newColour = {
		(sf::Uint8) distribution(generator),
		(sf::Uint8) distribution(generator),
		(sf::Uint8) distribution(generator)
	};

	clickedCell.set_colour(sf::Color::Black);
}
