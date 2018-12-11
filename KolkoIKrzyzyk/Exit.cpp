#include "Exit.h"
#include "Board.h"

Exit::Exit(sf::Vector2f position, sf::Vector2f size)
{
	rect.setPosition(position);
	rect.setSize(size);
	rect.setOutlineThickness(2.0f);
	rect.setOutlineColor(sf::Color::Black);
	rect.setFillColor(sf::Color::White);

	font.loadFromFile("ARIALN.TTF");

	text.setFont(font);
	text.setColor(sf::Color::Black);
	text.setString("Exit");
	text.setScale(sf::Vector2f(0.9f, 1.0f));
	text.setPosition(sf::Vector2f(position.x + 5, position.y + 5));

}

Exit::~Exit()
{

}

void Exit::draw(sf::RenderWindow & window)
{
	window.draw(rect);
	window.draw(text);
}

void Exit::click(sf::Vector2f position, Board & Board)
{
	if (rect.getGlobalBounds().contains(position))
	{
		Board.end();
	}
}

