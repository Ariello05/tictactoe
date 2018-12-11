#include "Field.h"

Field::Field()
{
	ch = " ";
}

Field::~Field()
{
}
/*
string Field::operator+(Field & p)
{
	return ch + p.ch;
}*/

string Field::get_ch()
{
	return ch;
}

void Field::reset()
{
	ch = " ";
}

string operator+(Field & l, Field & p)
{
	return l.get_ch() + p.get_ch();
}

string operator+(string l, Field & p)
{
	return l + p.get_ch();
}

string operator+(Field & l, string p)
{
	return l.get_ch() + p;
}
