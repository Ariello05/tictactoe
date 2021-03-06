#pragma once
#include "Field.h"
class Restart :public Field
{
public:
	Restart(sf::Vector2f position, sf::Vector2f size);
	~Restart();

	virtual void draw(sf::RenderWindow & window);
	virtual void click(sf::Vector2f position, Board & board);

private:
	sf::RectangleShape rect;
	sf::Text text;
	sf::Font font;

};

