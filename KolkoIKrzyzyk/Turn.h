#pragma once
#include "Field.h"

using namespace std;
class Turn :public Field
{
public:
	Turn(sf::Vector2f position, sf::Vector2f size);
	~Turn();

	virtual void draw(sf::RenderWindow & window);
	virtual void click(sf::Vector2f position, Board & board);
	void change_text(string);

private:
	sf::Text text;
	sf::Font font;
};

