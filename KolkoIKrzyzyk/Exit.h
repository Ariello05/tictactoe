#pragma once
#include "Field.h"
#include "Board.h"

class Exit :public Field
{
public:
	Exit(sf::Vector2f position, sf::Vector2f size);
	~Exit();

	virtual void draw(sf::RenderWindow & window);
	virtual void Exit::click(sf::Vector2f position, Board & board);

private:
	sf::RectangleShape rect;
	sf::Text text;
	sf::Font font;
};

