#include "ship.h"
#include "bullet.h"
#include <vector>



ship::ship(float h, float w){
 this->posX=h;
 this->posY=w;
};
std::vector<float> ship::getPos() {
    return {posX, posY};
};
float ship::getSpeed(){
    return speed;
};
void ship::draw(){
    DrawRectangle((posX),posY,60,40,BLUE);
};

void ship::update(){
    if(IsKeyDown(KEY_LEFT)){
        posX += -speed;
    }
    if(IsKeyDown(KEY_RIGHT)){
        posX += speed;
    }
    limitMovement();
};

void ship::limitMovement(){

    if(posX>800-60){
        posX=800-60;
    }
    if(posX<0){
        posX=0;
    }
};

 bullet ship::shot(){
    return bullet (this->posX+30,this->posY);
}
