#include "bullet.h"
#include <vector>

bullet::bullet(float h, float w){
    this->posX=h;
    this->posY=w;
   };

   float bullet::getSpeed(){
       return speed;
   };
   void bullet::draw(){
       DrawCircle(posX,posY,5,WHITE);
   };
   
   void bullet::update(){
       posY += -speed;

   };
    float bullet::getPosY() const{
        return posY;
    }
    float bullet::getPosX() const{
        return posX;
    }
 