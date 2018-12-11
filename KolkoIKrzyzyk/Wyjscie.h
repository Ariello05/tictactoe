#pragma once
#include "Pole.h"
#include "Plansza.h"

class Wyjscie :public Pole
{
public:
	Wyjscie(sf::Vector2f pozycja, sf::Vector2f wielkosc);
	~Wyjscie();

	virtual void rysuj(sf::RenderWindow & okno);
	virtual void Wyjscie::klik(sf::Vector2f pozycja, Plansza & plansza);

private:
	sf::RectangleShape rect;
	sf::Text tekst;
	sf::Font czcionka;
};

