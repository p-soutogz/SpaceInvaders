#pragma once
#include <raylib.h>
#include <iostream>

class bullet{
    private:
    float posX,posY;
    float speed = 7;


    public:
    bullet(float h, float w);
    float getSpeed();
    void draw();
    void update();
    float getPosY() const;

};