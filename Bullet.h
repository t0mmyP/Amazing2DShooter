#ifndef BULLET_H
#define BULLET_H
#include <glm/glm.hpp>
#include <GL/glew.h> 

class Bullet {
public:
    GLuint VAO, VBO;

    glm::vec2 position;
    float speedX, speedY;
    float width, height;
    bool active;
    bool hurtEnemy;

    Bullet(float startX, float startY, float directionX = 0.0f, float directionY = 1.0f,bool hurtEnemy = true )
        : position(startX, startY), speedX(directionX), speedY(directionY), 
        width(30.0f), height(30.0f), active(true),hurtEnemy(hurtEnemy){
    }

    // Bullet movement 
    void update() {
        position += glm::vec2(speedX, speedY);
       
    }

    // Check if the bullet is off-screen
    bool isOffScreen(float screenHeight, float screenWidth) {
        return position.x < 0.0f || position.x > screenWidth || position.y < 0.0f || position.y > screenHeight;
    }


};

#endif
