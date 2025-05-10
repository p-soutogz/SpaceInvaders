#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include "bullet.h"

class ship 
{
    private:
    float posX,posY;
    float speed = 7;
    
    public:

    ship(float h, float w);
    std::vector<float> getPos();
    float getSpeed();
    void draw();
    void update();
    bullet shot();
    void limitMovement();

};