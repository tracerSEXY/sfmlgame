#pragma once
#include <queue>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "EnemyManager.h"

class Weapon
{
public:
	Weapon(sf::RenderWindow *window);
	~Weapon();
	void update(float time, sf::Vector2f position, float rotation);
	void updateBullets(float time);
	void drawBullets();
	void fire(sf::Vector2f position, float rotation);
	sf::RenderWindow *window;
	float rate = 0.1f;
	bool shoot;
	EnemyManager *enemyManager;
	int size = 30;

private:
	Bullet* bullets[30];
	std::queue<Bullet*> bulletQueue;
	void createBullets();
};