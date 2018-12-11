#include "Komorka.h"
#include "Plansza.h"

Komorka::Komorka(sf::Vector2f pozycja, sf::Vector2f wielkosc)
{
	rect.setPosition(pozycja);
	rect.setSize(wielkosc);
	rect.setOutlineThickness(2.5f);
	rect.setOutlineColor(sf::Color::Black);
	rect.setFillColor(sf::Color::White);

	linie[0].setPosition(sf::Vector2f(pozycja.x+ 10, pozycja.y + 5));
	linie[0].setSize(sf::Vector2f(wielkosc.x*1.05f,wielkosc.y/8));
	linie[0].rotate(45);
	linie[0].setOutlineThickness(1.5f);
	linie[0].setOutlineColor(sf::Color::White);
	linie[0].setFillColor(sf::Color::Red);

	linie[1].setPosition(sf::Vector2f(pozycja.x + 5, pozycja.y - 10));
	linie[1].setSize(sf::Vector2f(wielkosc.x*1.05f, wielkosc.y / 8));
	linie[1].rotate(-45);
	linie[1].move(sf::Vector2f(0, wielkosc.y));
	linie[1].setOutlineThickness(1.5f);
	linie[1].setOutlineColor(sf::Color::White);
	linie[1].setFillColor(sf::Color::Red);

	kolo.setPosition(sf::Vector2f(pozycja.x + 5, pozycja.y + 5));
	kolo.setRadius((wielkosc.x+wielkosc.y)/4 - 5);
	kolo.setOutlineThickness(1.5f);
	kolo.setOutlineColor(sf::Color::White);
	kolo.setFillColor(sf::Color::Green);
}


Komorka::~Komorka()
{

}

void Komorka::rysuj(sf::RenderWindow & okno)
{
	okno.draw(rect);
	if (znak == "x")
	{
		okno.draw(linie[0]);
		okno.draw(linie[1]);
	}
	else if (znak == "o")
	{
		okno.draw(kolo);
	}
}

void Komorka::klik(sf::Vector2f pozycja, Plansza & plansza)
{
	if (rect.getGlobalBounds().contains(pozycja))
	{
		if (znak == " ")//jezeli jeszcze nie klikniête
		{
			znak = plansza.spr_znak();
			plansza.zmien_ture();
			//linie[1].setOutlineColor(sf::Color::Blue);
			//linie[0].setOutlineColor(sf::Color::Blue);
		}
	}
}
