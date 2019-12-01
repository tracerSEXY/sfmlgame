#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class EnemyManager
{
public:
	EnemyManager(sf::RenderWindow *window, sf::Vector2f position);
	~EnemyManager();
	sf::RenderWindow *window;
	void createEnemies(sf::Vector2f position);
	void update(float time, sf::Vector2f position);
	int size = 30;
	Enemy* enemies[30];
	bool enemyCollision(Enemy *enemy, float time);

private:

};