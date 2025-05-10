#include "alien.h"
#include "bullet.h"
#include <vector>



alien::alien(float h, float w){
 this->posX=h;
 this->posY=w;
};
std::vector<float> alien::getPos() {
    return {posX, posY};
};
float alien::getSpeed(){
    return speed;
};
void alien::draw(){
    DrawRectangle((posX),posY,60,40,RED);
};

bool alien::update(){
    posX += speed;
    if(limitMovement()) return true;
    return false;

};

bool alien::isDead(std::vector<bullet>& bullets){
    if(!bullets.empty()){
        for(int i=0; i<bullets.size();i++){
            if(bullets.at(i).getPosX()>this->posX && bullets.at(i).getPosX()<this->posX+60 && bullets.at(i).getPosY()<this->posY+40 && bullets.at(i).getPosY()>this->posY){
                return true;
            }
        }
    }
    
    return false;

};

bool alien::limitMovement(){

    if(posX>800-60){
        return true;
    }
    if(posX<0){
        return true;
    }

    return false;
};

void alien:: changeDirection(){
    this->speed *= -1;
    this->posY += 45;
}

 bullet alien::shot(){
    return bullet (this->posX+30,this->posY);
}

void alien::setPosX(float p){
    this->posX=p;

}
