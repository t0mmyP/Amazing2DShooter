#include "Player.h"
#include <iostream>

Player::Player(float startX, float startY)
	: position(startX, startY), speed(5.0f), width(30.0f), height(30.0f), isAlive(true) {}


void Player::move(float deltaX, float deltaY, int screenWidth, int screenHeight){
	direction = glm::vec2(deltaX, deltaY);
	position += glm::vec2(deltaX * speed, deltaY * speed);

	if (position.x < 0) position.x = 0;
	if (position.x > screenWidth - width) position.x = screenWidth - width;
	if (position.y < 0) position.y = 0;
	if (position.y > screenHeight - height) position.y = screenHeight - height;

}

Bullet Player::shoot() {
	return Bullet(position.x + height / 2, position.y + height / 2, direction.x * 30, direction.y * 30);
}


bool Player::checkCollisionBullet(const Bullet& bullet) {

	return (bullet.position.x < position.x + width && bullet.position.x + bullet.width > position.x &&
		bullet.position.y < position.y + height && bullet.position.y + bullet.height > position.y);
}

