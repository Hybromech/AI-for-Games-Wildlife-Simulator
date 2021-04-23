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
#pragma once
#include <raylib.h>
#include <glm/glm.hpp>
#include "Agent.h"
#include "KeyboardBehaviour.h"
#include "InstantKeyboard.h"
#include "Chase.h"
#include "Wander.h"
#include "SteeringBehaviour.h"
#include "SeekForce.h"
#include "PathFollowBehaviour.h"
#include <Path_Finding\MapReader.h>
#include <Path_Finding\MakeNodeGrid.h>
#include "StateMachine.h"
#include "Wander_Circle.h"
#include "Timer.cpp"
#include "GameManager.h"
#include "WanderState.h"
#include "ChasePlayerState.h"


Path dijkstrasSearch(Node* startNode, Node* endNode);

void DrawPath(const Path& path) {
    if (path.size() < 2)
        return;

    for (auto j = path.begin(), i = std::next(j); i != path.end(); ++i, ++j) {
        DrawLine((*i)->position.x, (*i)->position.y, (*j)->position.x, (*j)->position.y, Color{ 255,128,64,255 });
    }
}

void ResetGraph(Node* start, Node* end) {
    for (; start != end; ++start) {
        start->gscore = 100000000;
    }
}

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
    int screenWidth = 1920;
    int screenHeight = 1080;
    int tz = 32;
    
    //GameManager::DetectAgent();
    
    screenx = screenWidth;
    screeny = screenHeight;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(75);
    
    auto mp = ReadaMapInfo("D:/Andrew/AIE/Diploma of Digital and Interactive Games/Subjects/AI for Games/AI_Game/Path_Finding/Map.map"); //Load in map.
    mp.tile_atlas = LoadTexture("D:/Andrew/AIE/Diploma of Digital and Interactive Games/Subjects/AI for Games/AI_Game/textures/forest_tiles.png");
    mp.tilesize = tz;

    Rectangle rectarray[] = {
        {0,0,tz,tz},
        {13 * tz,7 * tz,tz,tz},
        {14 * tz,7 * tz,tz,tz},
        {5 * tz, 8 * tz,tz,tz}
    };

    mp.rectanglemap = rectarray; //DJ Bug 4 need to set the rectarry into the mp.rectanglemap 
    float terrain_difficulty[] = { 1,2,4,impassable };
    auto graph = BuildmodeGraph(mp, tz, terrain_difficulty);
    std::cout << "graph size" << graph.size();

    ResetGraph(&graph[0], &graph[graph.size() - 1]);

    int start = 0;
    int end = 46;

    auto path = dijkstrasSearch(&graph[start], &graph[end]);
    std::cout << "path size after search" << path.size();

    Texture bug_texture = LoadTexture("textures/bugs.png");

    std::vector<Agent*> agents;//List of agents.
    

    auto path_behavior = new Behaviours::PathFollowBehaviour(150);//param is speed
    path_behavior->SetPath(path);//update per second
    /*Agent* player = new Agent(bugs);
    player->AddBehaviour(new InstantKeyboard(20000));
    player->max_speed = 20000;
    agents.push_back(player);*/
    
    //SeekForce* sf = new SeekForce(player);
    //SteeringBehaviour* steering = new SteeringBehaviour(sf);
   

    glm::vec2 point{0,0};
    SeekForce* sfp = new SeekForce(point);
    Behaviours::SteeringBehaviour* steering = new Behaviours::SteeringBehaviour(sfp);

    Circle debug_circle;
    Timer timer(GetTime());
    Wander* wander = nullptr;
    Chase* chase = nullptr;
    Chase* chase2 = nullptr;

    //Add bug agents
    //Create new states
    WanderState* wanderState = new WanderState();
    ChasePlayerState* chaseState = new ChasePlayerState();
    StateMachine* sm = new StateMachine();
    GameManager* gameManager = new GameManager(agents);
    Agent* predator_bug = nullptr;
    Agent* prey_bug = nullptr;

    sm->init_currentState(wanderState);

    //Add Predior Bugs
    chase = new Chase(prey_bug, 120);//Target,Speed
    for (int i = 1; i < 2; i++) {//Add bugs
        sm->requestStateChange(chaseState);
        predator_bug = new Agent(bug_texture,sm, gameManager);//Heap allocated.
        predator_bug->ID = i;
        predator_bug->initial_frame_y = 6;//i % 7 * 2 + 2; //Pick any bug except yellow. could also read from file.
        //bug->AddBehaviour(new Chase(player, 8000));
        wander = new Wander(predator_bug, steering, debug_circle, timer);
        predator_bug->AddBehaviour(wander);//Add a path behaviour
        predator_bug->AddBehaviour(chase);
        predator_bug->AddBehaviour(path_behavior);
        predator_bug->SetPosition({ 96, 992 });//({ 100 + 20*i, 100 });
        predator_bug->max_speed = 100 + i * 20; 
        agents.push_back(predator_bug);//iterate through array and remove pointer.
    }
    //Add Prey Bugs white bug
    prey_bug = new Agent(bug_texture, sm, gameManager);
    prey_bug->ID = 0;
    prey_bug->initial_frame_y = 2;
    prey_bug->max_speed = 50;
    
    wander = new Wander(prey_bug, steering, debug_circle, timer);
    chase2 = new Chase(predator_bug, 100);//Target,Speed

    prey_bug->AddBehaviour(wander);
    prey_bug->AddBehaviour(chase2);
    prey_bug->SetPosition({ 928,512 });
    agents.push_back(prey_bug);
    float deltaTime = 0;
    //--------------------------------------------------------------------------------------
    // Main game loop
    glm::vec2 target_point_pos = {0,0};
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        deltaTime = GetFrameTime();
        auto mousePos = GetMousePosition();
        mousePos.x = (int)(mousePos.x / tz);
        mousePos.y = (int)(mousePos.y / tz);
        int tileid = mousePos.x + mousePos.y * mp.x;
        std::cout << "Mouse X = " << mousePos.x << std::endl;
        std::cout << "Mouse Y = " << mousePos.y << std::endl;

        bool moused = false;
        if (IsMouseButtonPressed(0)) {
            start = tileid;
            
        }
        if (IsMouseButtonPressed(1)) {
            end = tileid;
            moused = true;
        }

        if (moused){
            auto bugPos = agents[1]->GetPosition();//preditor bug
            bugPos.x = (int)(bugPos.x / tz);//convert into tile position.
            bugPos.y = (int)(bugPos.y / tz);
            int tileid = bugPos.x + bugPos.y * mp.x;//tileID is the node
            path = dijkstrasSearch(&graph[tileid], &graph[end]);
            path_behavior->SetPath(path);//update per second
        }
       
        //Update all agents
        
        //Draw 
        //----------------------------------------------------------------------------------
        BeginDrawing(); 
        
        mp.Draw();//Draw the map
        DrawPath(path);//Draw the path
        //Draw hovered tile 
        DrawRectangleLines(mousePos.x * tz, mousePos.y * tz, tz, tz, Color{ 64,255,128,255 });
        for (auto a : agents) {
            a->Update(deltaTime, sm);
        }

        ClearBackground(RAYWHITE);

        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

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

    UnloadTexture(bug_texture);
    for (auto a : agents){
        delete a;
    }

    return 0;
}