#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(sf::RenderWindow *window);
	~Bullet();
	sf::RenderWindow *window;
	bool active;
	float lifeTime;
	sf::Sprite sprite;
	sf::Texture texture;
	void draw();
	float rotation;
	sf::Vector2f direction;

private:

};