#pragma once
#include <vector>
#include "Bullet.h"
#include "Player.h";
#include <glm/glm.hpp>
#include <GL/glew.h> 
#include <random>



class Enemy {
public:

	GLuint VAO, VBO;

	glm::vec2 position;
	float speed;
	float width, height;
	bool isAlive;
	

	Enemy(float startX, float startY)
		: position(startX,startY), speed(0.5f), width(30.0f), height(30.0f), isAlive(true) {}


	void update() {
		std::random_device rd;
		std::mt19937 gen(rd()); // Mersenne Twister engine
		std::uniform_int_distribution<int> dist(-25,25);

		static int changeDirectionCounter = 0;
		static int changeDirectionInterval = 60;  // Change direction every 60 frames

		// Move the enemy randomly at first
		if (changeDirectionCounter >= changeDirectionInterval) {
			float randX = dist(gen);
			float randY = dist(gen);

			

			position += glm::vec2(randX * speed, randY * speed);

			// Reset counter and randomize the interval for a more natural feel
			changeDirectionCounter = 0;
			changeDirectionInterval = 60 + rand() % 120;  // Randomize next change interval
		}

		changeDirectionCounter++;

		if (position.x < 0.0f) position.x = 0.0f;
		if (position.x > 1920 - width) position.x = 1920.0f - width;  // Assuming screen width of 800
		if (position.y < 0.0f) position.y = 0.0f;
		if (position.y > 1080 - height) position.y = 1080.0f - height; // Assuming screen height of 600
	

	}

	bool checkCollisionBullet(const Bullet& bullet) {

			return (bullet.position.x < position.x + width && bullet.position.x + bullet.width > position.x &&
			bullet.position.y < position.y + height && bullet.position.y + bullet.height > position.y);
	}
	
	bool checkCollisionPlayer(Player& other) {

		return (other.position.x < position.x + width && other.position.x + other.width > position.x &&
			other.position.y < position.y + height && other.position.y + other.height > position.y);
	}

	bool checkCollisionEnemy(Enemy& other) {

		return (other.position.x < position.x + width && other.position.x + other.width > position.x &&
			other.position.y < position.y + height && other.position.y + other.height > position.y);
	}


	Bullet shootAtPlayer(glm::vec2 playerPosition) {
		glm::vec2 direction = playerPosition - position;
		float length = glm::length(direction);
		if (length != 0) {
			direction /= length;  // Normalize the direction vector
		}
		return Bullet(position.x + height * 2, position.y + width * 2, direction.x , direction.y, false);

	}

};
