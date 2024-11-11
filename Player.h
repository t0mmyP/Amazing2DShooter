#pragma once
#include <vector>
#include "Bullet.h"
#include <glm/glm.hpp>
#include <GL/glew.h> 


class Player {
public:

	GLuint VAO, VBO;
	glm::vec2 position;
	float speed;
	float width, height;
	glm::vec2 direction;
	bool isAlive;

	Player(float startX, float startY);


	void move(float deltaX, float deltaY, int screenWidth, int screenHeight);

	Bullet shoot();

	bool checkCollisionBullet(const Bullet& bullet);
};

	