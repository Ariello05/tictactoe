#include "Wyjscie.h"
#include "Plansza.h"

Wyjscie::Wyjscie(sf::Vector2f pozycja, sf::Vector2f wielkosc)
{
	rect.setPosition(pozycja);
	rect.setSize(wielkosc);
	rect.setOutlineThickness(2.0f);
	rect.setOutlineColor(sf::Color::Black);
	rect.setFillColor(sf::Color::White);

	czcionka.loadFromFile("ARIALN.TTF");

	tekst.setFont(czcionka);
	tekst.setColor(sf::Color::Black);
	tekst.setString("WYJSCIE");
	tekst.setScale(sf::Vector2f(0.9f, 1.0f));
	tekst.setPosition(sf::Vector2f(pozycja.x + 5, pozycja.y + 5));

}

Wyjscie::~Wyjscie()
{

}

void Wyjscie::rysuj(sf::RenderWindow & okno)
{
	okno.draw(rect);
	okno.draw(tekst);
}

void Wyjscie::klik(sf::Vector2f pozycja, Plansza & plansza)
{
	if (rect.getGlobalBounds().contains(pozycja))
	{
		plansza.zakoncz();
	}
}

