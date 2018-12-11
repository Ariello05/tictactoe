#include "Pole.h"

Pole::Pole()
{
	znak = " ";
}

Pole::~Pole()
{
}
/*
string Pole::operator+(Pole & p)
{
	return znak + p.znak;
}*/

string Pole::wez_znak()
{
	return znak;
}

void Pole::reset()
{
	znak = " ";
}

string operator+(Pole & l, Pole & p)
{
	return l.wez_znak() + p.wez_znak();
}

string operator+(string l, Pole & p)
{
	return l + p.wez_znak();
}

string operator+(Pole & l, string p)
{
	return l.wez_znak() + p;
}
