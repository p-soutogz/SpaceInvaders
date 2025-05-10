#include <raylib.h>
#include <iostream>
#include "ship.h"
#include "bullet.h"
#include "alien.h"
#include <vector>
#include <algorithm>

using namespace std;

void initAliens(std::vector<alien>& aliens){
    for(int i = 0; i<3; i++){
        for(int j = 0; j<8; j++){
            aliens.push_back(alien(0+j*80,0+i*60));
        }
    }
}

void drawBullets(std::vector<bullet>& bullets){
    if(bullets.empty()) return;
    for(int i =0; i<bullets.size();i++){
        bullets.at(i).draw();
    }
}
void updateBullets(std::vector<bullet>& bullets){
    if(bullets.empty()) return;
    for(int i =0; i<bullets.size();i++){
        bullets.at(i).update();
    }
    bullets.erase(
        std::remove_if(bullets.begin(), bullets.end(),
            [](const bullet& b)->bool {
                return b.getPosY() < 0;
            }),
        bullets.end()
    );
}
void drawAliens(std::vector<alien>& aliens){
    if(aliens.empty()) return;
    for(int i =0; i<aliens.size();i++){
        aliens.at(i).draw();
    }
}
void updateAliens(std::vector<alien>& aliens,std::vector<bullet>& bullets){
    bool b=false;
    if(aliens.empty()) return;
    for(int i =0; i<aliens.size();i++){
        if(aliens.at(i).update()) b=true;
    }
    aliens.erase(
        std::remove_if(aliens.begin(), aliens.end(),
            [& bullets](alien& b)->bool {
                return b.isDead(bullets);
            }),
        aliens.end()
    );
    if(b){
        for(int i =0; i<aliens.size();i++){
            aliens.at(i).changeDirection();
        }
    }
}





int main()
{
    const int width =  800;
    const int height = 1200;
    InitWindow(width,height,"Space Invaders");
    ship player((width+60)/2,height-40);
    std::vector<bullet> bullets;
    std::vector<alien> aliens;
    initAliens(aliens);
    double timer=-1;
    double shootingTime=0.5;

    SetTargetFPS(60);

    while(WindowShouldClose() == false){

        BeginDrawing();

        ClearBackground(BLACK);

        player.draw();
        drawBullets(bullets);
        drawAliens(aliens);

        player.update();
        updateBullets(bullets);
        updateAliens(aliens,bullets);
        

        if(IsKeyDown(KEY_SPACE) && (GetTime()-timer)>shootingTime){
            bullets.push_back(player.shot());
            timer = GetTime();
        }


        EndDrawing();


    }

    CloseWindow();
    return 0;
}