#include "Board.h"
#include <cstdlib>
#include <cctype>
#include "Field.h"
#include "Exit.h"
#include "Cell.h"
#include "Restart.h"
#include "Turn.h"

using namespace std;

Board::Board()
{
	index = 0;
	turnNo = 0;
	turnOff = false;
	fields = new Field*[12];

	create_field();

	turn->change_text("Turn X");
	ch = 'x';
}

Board::~Board()
{
	for (int i = 0; i < index; ++i)
	{
		delete fields[i];
	}

	delete[] fields;
	
}

void Board::draw_board(sf::RenderWindow & window)
{
	if (turnOff)
	{
		window.close();
		return;
	}

	for(int i = 0; i < index; ++i)
	{
		fields[i]->draw(window);
	}

}


void Board::end()
{
	turnOff = true;
}

void Board::update(sf::Vector2f position)
{
	for (int i = 0; i < index; ++i)
	{
		fields[i]->click(position, *this);
	}
}

char Board::check_char()
{
	return ch;
}

void Board::change_turn()
{
	if (check_winner())
	{
		if (turnNo >= 9)
		{
			turn->change_text("Draw");
		}
		else if(ch != 'e')
		{
			string s;
			ch = toupper(ch);
			s.push_back(ch);

			turn->change_text("Winner: " + s);
		}
		ch = 'e';

		return;
	}
	
	if (ch == 'o')
	{
		ch = 'x';
		turn->change_text("Turn X");
	}
	else if (ch == 'x')
	{
		ch = 'o';
		turn->change_text("Turn O");
	}
}

void Board::reset()
{
	for (int i = 0; i < index; ++i)
	{
		fields[i]->reset();
	}
	ch = 'x';
	turn->change_text("Turn X");
	turnNo = 0;
}

void Board::create_field()
{
	Cell * k;
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			k = new Cell(sf::Vector2f(60*x + 6 * x + 10, 60*y + 6*y + 10), sf::Vector2f(60, 60));
			fields[index] = k;
			index++;
		}
	}

	Exit * wyj = new Exit(sf::Vector2f(230, 90), sf::Vector2f(110, 50));
	fields[index] = wyj;
	index++;

	Restart * res = new Restart(sf::Vector2f(230, 150), sf::Vector2f(110, 50));
	fields[index] = res;
	index++;

	turn = new Turn(sf::Vector2f(230, 30), sf::Vector2f(110, 60));
	fields[index] = turn;
	index++;
}

bool Board::check_winner()
{
	string ooo = "ooo";
	string xxx = "xxx";

	if (*fields[0] + *fields[4] + *fields[8] == ooo || *fields[0] + *fields[4] + *fields[8] == xxx)
	{
		return true;
	}
	else if (*fields[1] + *fields[4] + *fields[7] == ooo || *fields[1] + *fields[4] + *fields[7] == xxx)
	{
		return true;
	}
	else if (*fields[2] + *fields[4] + *fields[6] == ooo || *fields[2] + *fields[4] + *fields[6] == xxx)
	{
		return true;
	}
	else if (*fields[3] + *fields[4] + *fields[5] == ooo || *fields[3] + *fields[4] + *fields[5] == xxx)
	{
		return true;
	}
	else if (*fields[0] + *fields[1] + *fields[2] == ooo || *fields[0] + *fields[1] + *fields[2] == xxx)
	{
		return true;
	}
	else if (*fields[2] + *fields[5] + *fields[8] == ooo || *fields[2] + *fields[5] + *fields[8] == xxx)
	{
		return true;
	}
	else if (*fields[8] + *fields[7] + *fields[6] == ooo || *fields[8] + *fields[7] + *fields[6] == xxx)
	{
		return true;
	}
	else if (*fields[6] + *fields[3] + *fields[0] == ooo || *fields[6] + *fields[3] + *fields[0] == xxx)
	{
		return true;
	}

	++turnNo;
	if (turnNo > 8)
	{
		return true;
	}
	
	return false;
}


