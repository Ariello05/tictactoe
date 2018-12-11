#pragma once
#include "Pole.h"
class Restart :public Pole
{
public:
	Restart(sf::Vector2f pozycja, sf::Vector2f wielkosc);
	~Restart();

	virtual void rysuj(sf::RenderWindow & okno);
	virtual void klik(sf::Vector2f pozycja, Plansza & plansza);

private:
	sf::RectangleShape rect;
	sf::Text tekst;
	sf::Font czcionka;

};

