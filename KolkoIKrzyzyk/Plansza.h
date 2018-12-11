#include <iostream>
#pragma once
#include <string>
#include <SFML\Graphics.hpp>

using namespace std;
class Pole;
class Tura;
class Plansza
{
public:
	Plansza();
	~Plansza();

	void rys_plansza(sf::RenderWindow & okno);
	bool spr_wygr();
	void zakoncz();
	void aktualizuj(sf::Vector2f pozycja);
	char spr_znak();
	void zmien_ture();
	void reset();

private:
	void utworz_pola();

	int runda;
	char znak;

	bool wylaczOkno;
	Pole ** pola;
	Tura * tura;

	int indeks;
};
#pragma once
