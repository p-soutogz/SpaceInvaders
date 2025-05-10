#include <raylib.h>
#include <iostream>
#include "ship.h"
#include "bullet.h"
#include <vector>
#include <algorithm>

using namespace std;


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

int main()
{
    const int width =  800;
    const int height = 1200;
    InitWindow(width,height,"Space Invaders");
    ship player((width+60)/2,height-40);
    std::vector<bullet> bullets;
    double timer=-1;
    double shootingTime=0.5;

    SetTargetFPS(60);

    while(WindowShouldClose() == false){

        BeginDrawing();

        ClearBackground(BLACK);

        player.draw();
        drawBullets(bullets);

        player.update();
        updateBullets(bullets);

        if(IsKeyDown(KEY_SPACE) && (GetTime()-timer)>shootingTime){
            bullets.push_back(player.shot());
            timer = GetTime();
        }


        EndDrawing();


    }

    CloseWindow();
    return 0;
}