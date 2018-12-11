#include "plansza.h"
#include <cstdlib>
#include <cctype>
#include "Pole.h"
#include "Wyjscie.h"
#include "Komorka.h"
#include "Restart.h"
#include "Tura.h"

using namespace std;

Plansza::Plansza()
{
	indeks = 0;
	runda = 0;
	wylaczOkno = false;
	pola = new Pole*[12];

	utworz_pola();

	tura->zmien_tekst("Tura X");
	znak = 'x';
}

Plansza::~Plansza()
{
	for (int i = 0; i < indeks; ++i)
	{
		delete pola[i];
	}

	delete[] pola;
	
}

void Plansza::rys_plansza(sf::RenderWindow & okno)
{
	if (wylaczOkno)
	{
		okno.close();
		return;
	}

	for(int i = 0; i < indeks; ++i)
	{
		pola[i]->rysuj(okno);
	}

}


void Plansza::zakoncz()
{
	wylaczOkno = true;
}

void Plansza::aktualizuj(sf::Vector2f pozycja)
{
	for (int i = 0; i < indeks; ++i)
	{
		pola[i]->klik(pozycja, *this);
	}
}

char Plansza::spr_znak()
{
	return znak;
}

void Plansza::zmien_ture()
{
	if (spr_wygr())
	{
		if (runda >= 9)
		{
			tura->zmien_tekst("Remis");
		}
		else if(znak != 'e')
		{
			string s;
			znak = toupper(znak);
			s.push_back(znak);

			tura->zmien_tekst("Wygral " + s);
		}
		znak = 'e';

		return;
	}
	
	if (znak == 'o')
	{
		znak = 'x';
		tura->zmien_tekst("Tura X");
	}
	else if (znak == 'x')
	{
		znak = 'o';
		tura->zmien_tekst("Tura O");
	}
}

void Plansza::reset()
{
	for (int i = 0; i < indeks; ++i)
	{
		pola[i]->reset();
	}
	znak = 'x';
	tura->zmien_tekst("Tura X");
	runda = 0;
}

void Plansza::utworz_pola()
{
	Komorka * k;
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			k = new Komorka(sf::Vector2f(60*x + 6 * x + 10, 60*y + 6*y + 10), sf::Vector2f(60, 60));
			pola[indeks] = k;
			indeks++;
		}
	}

	Wyjscie * wyj = new Wyjscie(sf::Vector2f(230, 90), sf::Vector2f(110, 50));
	pola[indeks] = wyj;
	indeks++;

	Restart * res = new Restart(sf::Vector2f(230, 150), sf::Vector2f(110, 50));
	pola[indeks] = res;
	indeks++;

	tura = new Tura(sf::Vector2f(230, 30), sf::Vector2f(110, 60));
	pola[indeks] = tura;
	indeks++;
}

bool Plansza::spr_wygr()
{
	string ooo = "ooo";
	string xxx = "xxx";

	if (*pola[0] + *pola[4] + *pola[8] == ooo || *pola[0] + *pola[4] + *pola[8] == xxx)
	{
		return true;
	}
	else if (*pola[1] + *pola[4] + *pola[7] == ooo || *pola[1] + *pola[4] + *pola[7] == xxx)
	{
		return true;
	}
	else if (*pola[2] + *pola[4] + *pola[6] == ooo || *pola[2] + *pola[4] + *pola[6] == xxx)
	{
		return true;
	}
	else if (*pola[3] + *pola[4] + *pola[5] == ooo || *pola[3] + *pola[4] + *pola[5] == xxx)
	{
		return true;
	}
	else if (*pola[0] + *pola[1] + *pola[2] == ooo || *pola[0] + *pola[1] + *pola[2] == xxx)
	{
		return true;
	}
	else if (*pola[2] + *pola[5] + *pola[8] == ooo || *pola[2] + *pola[5] + *pola[8] == xxx)
	{
		return true;
	}
	else if (*pola[8] + *pola[7] + *pola[6] == ooo || *pola[8] + *pola[7] + *pola[6] == xxx)
	{
		return true;
	}
	else if (*pola[6] + *pola[3] + *pola[0] == ooo || *pola[6] + *pola[3] + *pola[0] == xxx)
	{
		return true;
	}

	++runda;
	if (runda > 8)
	{
		return true;
	}
	
	return false;
}


