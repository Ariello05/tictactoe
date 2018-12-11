#include <SFML/Graphics.hpp>
#include "Plansza.h"

int main()
{
	sf::RenderWindow okno(sf::VideoMode(400, 230), "Kolko_I_Krzyzk");

	Plansza plansza;
	
	while (okno.isOpen())
	{
		sf::Event event;
		while (okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				okno.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i position = sf::Mouse::getPosition(okno);
					plansza.aktualizuj(sf::Vector2f(position.x, position.y));
				}
			}
		}


		okno.clear(sf::Color::White);
		plansza.rys_plansza(okno);
		okno.display();
	}

	return 0;
}