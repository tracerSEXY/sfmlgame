#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Weapon.h"
#include "EnemyManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	Player player(&window, 40.f, sf::Vector2f(0.f, 0.f));
	Weapon weapon(&window);
	EnemyManager enemyManager(&window, player.getPosition());
	weapon.enemyManager = &enemyManager;
	sf::View view(window.getDefaultView());
	sf::Clock clock;
	sf::Time elapsed;

	sf::RectangleShape rectangle1(sf::Vector2f(120.f, 120.f));
	rectangle1.setFillColor(sf::Color(50, 0, 50));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}	
			if (event.type == sf::Event::Resized)
			{
				// update the view to the new size of the window
				view.setSize(event.size.width, event.size.height);
				window.setView(view);
			}
			if (event.type == sf::Event::MouseWheelScrolled)
			{
				sf::Vector2f size = view.getSize();
				if (event.mouseWheelScroll.delta > 0)
				{
					view.setSize(size.x * 0.9f, size.y * 0.9f);
					float rat = (size.x * 0.9f) / size.x;
					view.zoom(rat);
				}
				else
				{
					view.setSize(size.x * 1.1f, size.y * 1.1f);
					float rat = (size.x * 1.1f) / size.x;
					view.zoom(rat);
				}
				window.setView(view);
			}
		}

		elapsed = clock.getElapsedTime();

		view.setCenter(player.getPosition());
		window.setView(view);

		window.clear();

		player.update(elapsed.asSeconds());
		weapon.update(elapsed.asSeconds(), player.getPosition(), player.sprite.getRotation());
		enemyManager.update(elapsed.asSeconds(), player.getPosition());
		window.draw(rectangle1);

		clock.restart();
		window.display();
	}

	return 0;
}