#include "Restart.h"


Restart::Restart(sf::Vector2f pozycja, sf::Vector2f wielkosc)
{
	rect.setPosition(pozycja);
	rect.setSize(wielkosc);
	rect.setOutlineThickness(2.0f);
	rect.setOutlineColor(sf::Color::Black);
	rect.setFillColor(sf::Color::White);

	czcionka.loadFromFile("ARIALN.TTF");

	tekst.setFont(czcionka);
	tekst.setColor(sf::Color::Black);
	tekst.setString("RESTART");
	tekst.setScale(sf::Vector2f(0.9f, 1.0f));
	tekst.setPosition(sf::Vector2f(pozycja.x + 5, pozycja.y + 5));
}


Restart::~Restart()
{
}

void Restart::rysuj(sf::RenderWindow & okno)
{
	okno.draw(rect);
	okno.draw(tekst);
}

void Restart::klik(sf::Vector2f pozycja, Plansza & plansza)
{
	if (rect.getGlobalBounds().contains(pozycja))
	{
		plansza.reset();
	}
}
