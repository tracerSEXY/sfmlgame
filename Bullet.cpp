#include "Bullet.h"

Bullet::Bullet(sf::RenderWindow *window)
{
	this->window = window;
	this->active = false;
	this->lifeTime = 2.f;
	if (!this->texture.loadFromFile("fire.png"))
	{
		// error...
	}
	this->sprite.setTexture(this->texture);
}

Bullet::~Bullet()
{
}

void Bullet::draw()
{
	this->window->draw(this->sprite);
}