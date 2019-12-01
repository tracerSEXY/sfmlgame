#include "EnemyManager.h"

EnemyManager::EnemyManager(sf::RenderWindow *window, sf::Vector2f position)
{
	this->window = window;
	createEnemies(position);

}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::createEnemies(sf::Vector2f position)
{
	for (int i = 0; i < this->size; i++)
	{
		Enemy *temp = new Enemy(this->window, position);
		this->enemies[i] = temp;
	}
}

void EnemyManager::update(float time, sf::Vector2f position)
{

	for (int i = 0; i < this->size; i++)
	{
		Enemy *temp = this->enemies[i];
		temp->animation(time);
		temp->sprite.setPosition(temp->shape.getPosition());
		if (temp->animDeadTime > 3.f)
		{
			temp->animDeadTime = 0;
			temp->dead = false;
			temp->shape.setPosition(rand() % 5000 - 2500, rand() % 5000 - 2500);
		}
		if (!temp->dead)
		{
			if (!this->enemyCollision(temp, time))
			{
				sf::Vector2f distance = position - temp->shape.getPosition();
				float dist = sqrt(pow(distance.x, 2) + pow(distance.y, 2));
				if (dist < 5000)
				{
					float x = position.x - temp->shape.getPosition().x;
					float y = position.y - temp->shape.getPosition().y;
					float angle = atan2(y, x) * 180 / 3.14f;
					temp->shape.setRotation(angle);
				}
				temp->shape.move(500.f * time * cos(temp->shape.getRotation() * 3.14 / 180), 500.f * time * sin(temp->shape.getRotation() * 3.14 / 180));
			}
		}

		temp->draw();
	}
}

bool EnemyManager::enemyCollision(Enemy *enemy, float time)
{
	bool tempc = false;
	for (int i = 0; i < this->size; i++)
	{
		Enemy *temp = this->enemies[i];
		if (temp != enemy && !temp->dead)
		{
			sf::Vector2f distance = enemy->shape.getPosition() - temp->shape.getPosition();
			float dist = sqrt(pow(distance.x, 2) + pow(distance.y, 2));
			if (dist < 100)
			{
				temp->shape.move(-distance * time);
				tempc = true;
			}
		}
	}
	if (tempc)
	{
		return true;
	}
	return false;
}