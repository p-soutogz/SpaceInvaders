#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include "bullet.h"

class alien 
{
    private:
    float posX,posY;
    float speed = 2;
    
    public:

    alien(float h, float w);
    std::vector<float> getPos();
    float getSpeed();
    void draw();
    bool update();
    bool isDead(std::vector<bullet>& bullets);
    bullet shot();
    bool limitMovement();
    void changeDirection();
    void setPosX(float p);

};