/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <raylib.h>
#include <glm/glm.hpp>
#include "Agent.h"
#include "KeyboardBehaviour.h"
#include "InstantKeyboard.h"
#include "Chase.h"
#include "SteeringBehaviour.h"
#include "SeekForce.h"

class ManagedTexture
{
    Texture texture;
public:
    ManagedTexture(const char* file){
        UnloadTexture(texture);
    }
    operator Texture()const {
        return texture;
    }
};

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    screenx = screenWidth;
    screeny = screenHeight;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
    SetTargetFPS(60);

    Texture bugs = LoadTexture("textures/bugs.png");

    std::vector<Agent*> agents;//List of agents.
    
    Agent* player = new Agent(bugs);
    player->AddBehaviour(new InstantKeyboard(20000));
    player->max_speed = 20000;
    agents.push_back(player);
    
    SeekForce* sf = new SeekForce(player);
    SteeringBehaviour* steering = new SteeringBehaviour(sf);
    
    //These bugs hunt the player
    for (int i = 0; i < 10; i++) {
        Agent* bug = new Agent(bugs);//Heap allocated.
        bug->initial_frame_y = i % 7 * 2 + 2; //Pick any bug except yellow. could also read from file.
        //bug->AddBehaviour(new Chase(player, 8000));
        bug->AddBehaviour(steering);//Add a steering behaviour
        bug->SetPosition({ 100 + 20*i, 100 });
        bug->max_speed = 100 + i * 20;
        
        
        agents.push_back(bug);
    }
    //These bugs flee from the player.
    FleeForce* ff = new FleeForce(player);
    SteeringBehaviour* fleesteering = new SteeringBehaviour(ff);
    for (int i = 0; i < 10; i++) {
        Agent* bug = new Agent(bugs);//Heap allocated.
        bug->initial_frame_y = i % 7 * 2 + 1; //Pick any bug except yellow. could also read from file.
        //bug->AddBehaviour(new Chase(player, 8000));
        bug->AddBehaviour(fleesteering);//Add a steering behaviour
        bug->SetPosition({ 100 + 20 * i, 100 });
        bug->max_speed = 20 + i * 5;


        agents.push_back(bug);
    }
    
    float deltaTime = 0;

    
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        deltaTime = GetFrameTime();
        
        for (auto a : agents){
            a->Update(deltaTime);
        }
        // Draw 
        //----------------------------------------------------------------------------------
        BeginDrawing(); 

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        for (auto a : agents) {
            a->Draw();
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    UnloadTexture(bugs);
    for (auto a : agents){
        delete a;
    }

    return 0;
}