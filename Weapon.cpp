#include "Weapon.h"

Weapon::Weapon(sf::RenderWindow *window)
{
	this->window = window;
	this->createBullets();
	this->shoot = true;
}

Weapon::~Weapon()
{
}

void Weapon::createBullets()
{
	for (int i = 0; i < this->size; i++)
	{
		Bullet *temp = new Bullet(this->window);
		this->bullets[i] = temp;
		this->bulletQueue.push(temp);

	}
}

void Weapon::fire(sf::Vector2f position, float rotation)
{
	if (!this->bulletQueue.empty())
	{
		Bullet *temp = this->bulletQueue.front();
		temp->active = true;
		temp->sprite.setPosition(position);
		temp->sprite.setRotation(rotation);
		temp->rotation = rotation;
		this->bulletQueue.pop();
	}
}

void Weapon::updateBullets(float time)
{
	for (int i = 0; i < this->size; i++)
	{
		Bullet *temp = this->bullets[i];
		if (temp->active)
		{
			if (temp->lifeTime < 0)
			{
				temp->active = false;
				temp->lifeTime = 2.f;
				this->bulletQueue.push(temp);
				continue;
			}
			for (int i = 0; i < this->size; i++)
			{
				Enemy *enemy = this->enemyManager->enemies[i];
				sf::Vector2f hitDistanceVect = enemy->shape.getPosition() - temp->sprite.getPosition();
				float hitDist = sqrt(pow(hitDistanceVect.x, 2) + pow(hitDistanceVect.y, 2));
				if (hitDist < enemy->shape.getRadius())
				{
					if (!enemy->dead)
					{
						enemy->dead = true;
						//enemy->shape.setPosition(rand() % 1000 + 1000, rand() % 1000 + 1000);
						break;
					}
				}
			}
			temp->lifeTime -= time;
			temp->sprite.move(10000.f * time * cos(temp->sprite.getRotation() * 3.14 / 180), 10000.f * time * sin(temp->rotation * 3.14 / 180));
		}
	}
}

void Weapon::drawBullets()
{
	for (int i = 0; i < this->size; i++)
	{
		Bullet *temp = this->bullets[i];
		if (temp->active)
		{
			temp->draw();
		}
	}
}

void Weapon::update(float time, sf::Vector2f position, float rotation)
{
	this->updateBullets(time);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->shoot)
		{
			this->fire(position, rotation);
			this->shoot = false;
		}
		if (this->rate < 0)
		{
			this->rate = 0.1f;
			this->shoot = true;
		}
	}
	this->rate -= time;
	this->drawBullets();
}