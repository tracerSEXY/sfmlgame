#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow *window, sf::Vector2f position)
{
	this->window = window;
	this->animationTime = rand() % 3;
	this->animDeadTime = 0.f;
	this->shape.setRadius(50);
	this->shape.setOrigin(50.f, 50.f);
	this->shape.setRotation(rand() % 360);
	this->shape.setFillColor(sf::Color(150, 50, 250));
	this->dead = false;
	this->shape.setPosition(position.x + rand() % 5000 - 2500, position.y + rand() % 5000 - 2500);
}

Enemy::~Enemy()
{
}

void Enemy::draw()
{
	this->window->draw(this->shape);
}

void Enemy::animation(float time)
{
	if (this->dead)
	{
		if (this->animDeadTime >= 0.f && this->animDeadTime < 0.5f)
		{
			this->shape.setFillColor(sf::Color(225, 204, 229));
		}
		else if (this->animDeadTime >= 0.5f && this->animDeadTime < 1.f)
		{
			this->shape.setFillColor(sf::Color(225, 153, 204));
		}
		else if (this->animDeadTime >= 1.f && this->animDeadTime < 1.5f)
		{
			this->shape.setFillColor(sf::Color(225, 102, 178));
		}
		else if (this->animDeadTime >= 1.5f && this->animDeadTime < 2.f)
		{
			this->shape.setFillColor(sf::Color(225, 51, 153));
		}
		else if (this->animDeadTime >= 2.f && this->animDeadTime < 3.f)
		{
			this->shape.setFillColor(sf::Color(225, 0, 127));
		}
		this->animDeadTime += time;
	}
	if (!this->dead)
	{
		if (this->animationTime >= 0.f && this->animationTime < 0.5f)
		{
			this->shape.setFillColor(sf::Color(204, 153, 255));
		}
		else if (this->animationTime >= 0.5f && this->animationTime < 1.f)
		{
			this->shape.setFillColor(sf::Color(178, 102, 255));
		}
		else if (this->animationTime >= 1.f && this->animationTime < 1.5f)
		{
			this->shape.setFillColor(sf::Color(153, 51, 255));
		}
		else if (this->animationTime >= 1.5f && this->animationTime < 2.f)
		{
			this->shape.setFillColor(sf::Color(127, 0, 255));
		}
		else if (this->animationTime >= 2.f)
		{
			this->shape.setFillColor(sf::Color(102, 0, 204));
		}
		this->animationTime += time;
	}
	if (this->animationTime > 2.5f)
	{
		this->animationTime = 0.f;
	}
}