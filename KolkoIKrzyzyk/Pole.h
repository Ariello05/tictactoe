#pragma once
#include <SFML\Graphics.hpp>
#include "Plansza.h"
using namespace std;
class Pole
{
public:
	Pole();
	virtual ~Pole();

	virtual void rysuj(sf::RenderWindow & okno) = 0;
	virtual void klik(sf::Vector2f pozycja, Plansza & plansza) = 0;

	string wez_znak();
	void reset();

protected:
	string znak;

private:
};

string operator+(Pole & l, Pole & p);
string operator+(string l, Pole & p);
string operator+(Pole & l, string p);