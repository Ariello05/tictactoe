#include <iostream>
#pragma once
#include <string>
#include <SFML\Graphics.hpp>

using namespace std;
class Field;
class Turn;
class Board
{
public:
	Board();
	~Board();

	void draw_board(sf::RenderWindow & window);
	bool check_winner();
	void end();
	void update(sf::Vector2f position);
	char check_char();
	void change_turn();
	void reset();

private:
	void create_field();

	int turnNo;
	char ch;

	bool turnOff;
	Field ** fields;
	Turn * turn;

	int index;
};
#pragma once
