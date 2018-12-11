#include "Turn.h"


Turn::Turn(sf::Vector2f position, sf::Vector2f size)
{
	font.loadFromFile("ARIALN.TTF");

	text.setFont(font);
	text.setColor(sf::Color::Black);
	text.setString("RESTART");
	text.setScale(sf::Vector2f(0.9f, 1.0f));
	text.setPosition(sf::Vector2f(position.x + 5, position.y + 5));
}


Turn::~Turn()
{
}

void Turn::draw(sf::RenderWindow & window)
{
	window.draw(text);
}

void Turn::click(sf::Vector2f position, Board & Board)
{
}

void Turn::change_text(string str)
{
	text.setString(str);
}
