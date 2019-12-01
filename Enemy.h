#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy(sf::RenderWindow *window, sf::Vector2f position);
	~Enemy();
	sf::RenderWindow *window;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::CircleShape shape;
	bool dead;
	void draw();
	float animationTime;
	float animDeadTime;
	void animation(float time);

private:

};