#pragma once
#include "Pole.h"

using namespace std;
class Tura :public Pole
{
public:
	Tura(sf::Vector2f pozycja, sf::Vector2f wielkosc);
	~Tura();

	virtual void rysuj(sf::RenderWindow & okno);
	virtual void klik(sf::Vector2f pozycja, Plansza & plansza);
	void zmien_tekst(string);

private:
	sf::Text tekst;
	sf::Font czcionka;
};

