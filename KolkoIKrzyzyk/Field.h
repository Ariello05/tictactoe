#pragma once
#include <SFML\Graphics.hpp>
#include "Board.h"
using namespace std;
class Field
{
public:
	Field();
	virtual ~Field();

	virtual void draw(sf::RenderWindow & window) = 0;
	virtual void click(sf::Vector2f position, Board & board) = 0;

	string get_ch();
	void reset();

protected:
	string ch;

private:
};

string operator+(Field & l, Field & p);
string operator+(string l, Field & p);
string operator+(Field & l, string p);