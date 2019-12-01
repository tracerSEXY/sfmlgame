#include "Player.h"

Player::Player(sf::RenderWindow *window, float radius, sf::Vector2f position)
{
	this->window = window;
	this->radius = radius;
	this->sprite.setOrigin(radius, radius);
	this->sprite.setPosition(position);
	if (!this->texture.loadFromFile("player1.png"))
	{
		// error...
	}
	this->sprite.setTexture(this->texture);
}

Player::~Player()
{

}

void Player::update(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->sprite.move(this->speed * time, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->sprite.move(-this->speed * time, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->sprite.move(0.f, -this->speed * time);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->sprite.move(0.f, this->speed * time);
	}
	this->sprite.setRotation(this->getMouseAngle());
	this->draw();
}

void Player::draw()
{
	this->window->draw(this->sprite);
}

sf::Vector2f Player::getPosition()
{
	return this->sprite.getPosition();
}

float Player::getMouseAngle()
{
	sf::Vector2f mousepos = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
	sf::Vector2f playerpos = this->getPosition();
	float x = mousepos.x - playerpos.x;
	float y = mousepos.y - playerpos.y;
	float angle = atan2(y, x) * 180 / 3.14f;
	return angle;
}