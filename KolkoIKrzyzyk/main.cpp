#include <SFML/Graphics.hpp>
#include "Board.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 230), "TicTacToe");

	Board board;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i position = sf::Mouse::getPosition(window);
					board.update(sf::Vector2f(position.x, position.y));
				}
			}
		}


		window.clear(sf::Color::White);
		board.draw_board(window);
		window.display();
	}

	return 0;
}