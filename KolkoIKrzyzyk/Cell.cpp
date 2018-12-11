#include "Cell.h"
#include "Board.h"

Cell::Cell(sf::Vector2f position, sf::Vector2f size)
{
	rect.setPosition(position);
	rect.setSize(size);
	rect.setOutlineThickness(2.5f);
	rect.setOutlineColor(sf::Color::Black);
	rect.setFillColor(sf::Color::White);

	lines[0].setPosition(sf::Vector2f(position.x+ 10, position.y + 5));
	lines[0].setSize(sf::Vector2f(size.x*1.05f,size.y/8));
	lines[0].rotate(45);
	lines[0].setOutlineThickness(1.5f);
	lines[0].setOutlineColor(sf::Color::White);
	lines[0].setFillColor(sf::Color::Red);

	lines[1].setPosition(sf::Vector2f(position.x + 5, position.y - 10));
	lines[1].setSize(sf::Vector2f(size.x*1.05f, size.y / 8));
	lines[1].rotate(-45);
	lines[1].move(sf::Vector2f(0, size.y));
	lines[1].setOutlineThickness(1.5f);
	lines[1].setOutlineColor(sf::Color::White);
	lines[1].setFillColor(sf::Color::Red);

	circle.setPosition(sf::Vector2f(position.x + 5, position.y + 5));
	circle.setRadius((size.x+size.y)/4 - 5);
	circle.setOutlineThickness(1.5f);
	circle.setOutlineColor(sf::Color::White);
	circle.setFillColor(sf::Color::Green);
}


Cell::~Cell()
{

}

void Cell::draw(sf::RenderWindow & window)
{
	window.draw(rect);
	if (ch == "x")
	{
		window.draw(lines[0]);
		window.draw(lines[1]);
	}
	else if (ch == "o")
	{
		window.draw(circle);
	}
}

void Cell::click(sf::Vector2f position, Board & board)
{
	if (rect.getGlobalBounds().contains(position))
	{
		if (ch == " ")//if not yet clicked
		{
			ch = board.check_char();
			board.change_turn();
			//lines[1].setOutlineColor(sf::Color::Blue);
			//lines[0].setOutlineColor(sf::Color::Blue);
		}
	}
}
