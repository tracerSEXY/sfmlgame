#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(sf::RenderWindow *window, float radius, sf::Vector2f position);
	~Player();
	void update(float time);
	void draw();
	float getMouseAngle();
	sf::Vector2f getPosition();
	float radius;
	sf::RenderWindow *window;
	sf::Texture texture;
	float speed = 500.f;
	sf::Sprite sprite;

private:

};