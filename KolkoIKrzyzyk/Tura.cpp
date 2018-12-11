#include "Tura.h"


Tura::Tura(sf::Vector2f pozycja, sf::Vector2f wielkosc)
{
	czcionka.loadFromFile("ARIALN.TTF");

	tekst.setFont(czcionka);
	tekst.setColor(sf::Color::Black);
	tekst.setString("RESTART");
	tekst.setScale(sf::Vector2f(0.9f, 1.0f));
	tekst.setPosition(sf::Vector2f(pozycja.x + 5, pozycja.y + 5));
}


Tura::~Tura()
{
}

void Tura::rysuj(sf::RenderWindow & okno)
{
	okno.draw(tekst);
}

void Tura::klik(sf::Vector2f pozycja, Plansza & plansza)
{
}

void Tura::zmien_tekst(string str)
{
	tekst.setString(str);
}
