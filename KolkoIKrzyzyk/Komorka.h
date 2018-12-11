#pragma once
#include "Pole.h"
#include "Plansza.h"

class Komorka :public Pole
{
public:
	Komorka(sf::Vector2f pozycja, sf::Vector2f wielkosc);
	~Komorka();

	virtual void rysuj(sf::RenderWindow & okno);
	virtual void klik(sf::Vector2f pozycja, Plansza & plansza);

private:
	sf::RectangleShape rect;
	sf::RectangleShape linie[2];
	sf::CircleShape kolo;
};

