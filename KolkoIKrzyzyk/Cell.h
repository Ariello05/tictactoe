#pragma once
#include "Field.h"
#include "Board.h"

class Cell :public Field
{
public:
	Cell(sf::Vector2f position, sf::Vector2f size);
	~Cell();

	virtual void draw(sf::RenderWindow & window);
	virtual void click(sf::Vector2f position, Board & board);

private:
	sf::RectangleShape rect;
	sf::RectangleShape lines[2];
	sf::CircleShape circle;
};

