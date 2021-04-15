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
#include "PathFollowBehaviour.h"
#include <Path_Finding\MapReader.h>
#include <Path_Finding\MakeNodeGrid.h>
#include "StateMachine.h"
#include "Wander_Circle.h"
#include "Timer.cpp"



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
    int screenWidth = 800;
    int screenHeight = 450;
    int tz = 32;

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

    ResetGraph(&graph[0], &graph[graph.size() - 1]);

    int start = 0;
    int end = 46;

    auto path = dijkstrasSearch(&graph[start], &graph[end]);

    Texture bugs = LoadTexture("textures/bugs.png");

    std::vector<Agent*> agents;//List of agents.
    auto path_behavior = new Behaviours::PathFollowBehaviour(20);
    path_behavior->SetPath(path);//update per second
    /*Agent* player = new Agent(bugs);
    player->AddBehaviour(new InstantKeyboard(20000));
    player->max_speed = 20000;
    agents.push_back(player);*/
    
    //SeekForce* sf = new SeekForce(player);
    //SteeringBehaviour* steering = new SteeringBehaviour(sf);
    
    SeekForce* sfp = new SeekForce()

    //Add bug agents
    StateMachine* sm = new StateMachine();
    for (int i = 0; i < 1; i++) {//Add bugs
        Agent* bug = new Agent(bugs,sm);//Heap allocated.
        bug->initial_frame_y = i % 7 * 2 + 2; //Pick any bug except yellow. could also read from file.
        //bug->AddBehaviour(new Chase(player, 8000));
        bug->AddBehaviour(path_behavior);//Add a path behaviour
        bug->SetPosition({ 100 + 20*i, 100 });
        bug->max_speed = 100 + i * 20;
        
        
        agents.push_back(bug);//iterate through array and remove pointer.
    }
    //These bugs flee from the player.
    //FleeForce* ff = new FleeForce(player);
    //SteeringBehaviour* fleesteering = new SteeringBehaviour(ff);
    //for (int i = 0; i < 10; i++) {
    //    Agent* bug = new Agent(bugs);//Heap allocated.
    //    bug->initial_frame_y = i % 7 * 2 + 1; //Pick any bug except yellow. could also read from file.
    //    //bug->AddBehaviour(new Chase(player, 8000));
    //    bug->AddBehaviour(fleesteering);//Add a steering behaviour
    //    bug->SetPosition({ 100 + 20 * i, 100 });
    //    bug->max_speed = 20 + i * 5;


    //    agents.push_back(bug);
    //}
    
    float deltaTime = 0;

    //--------------------------------------------------------------------------------------

    // Main game loop
    Circle debug_circle;
    //debug_circle = debug_circle.makeCircle(agents[0]->GetPosition(), 50, 0, 360);
    Timer timer(GetTime());
    glm::vec2 target_point_pos = {0,0};
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        deltaTime = GetFrameTime();
        auto p = GetMousePosition();
        p.x = (int)(p.x / tz);
        p.y = (int)(p.y / tz);
        int tileid = p.x + p.y * mp.x;

        bool moused = false;
        if (IsMouseButtonPressed(0)) {
            start = tileid;
        }
        if (IsMouseButtonPressed(1)) {
            end = tileid;
            moused = true;
        }

        if (moused){
            auto p = agents[0]->GetPosition();
            p.x = (int)(p.x / tz);//convert into tile position.
            p.y = (int)(p.y / tz);
            int tileid = p.x + p.y * mp.x;//tileID is the node
            path = dijkstrasSearch(&graph[tileid], &graph[end]);
            path_behavior->SetPath(path);//update per second
        }
       
        for (auto a : agents){
            a->Update(deltaTime,sm);
        }
        //Setup debug circle
        debug_circle.origin = agents[0]->GetPosition();
        if (timer.update_timer(GetTime(),timer.endFrame) == true)//if the timer is fired //double currentTime, int startFrame, int endFrame
        {
            timer.startFrame = timer.reset_Timer(GetTime());
            timer.endFrame = timer.set_endTime(timer.startFrame);
            debug_circle = updateCircle(debug_circle,0, 360, 50,true);//update circle with randomised target point
        }
        debug_circle = updateCircle(debug_circle, 0, 360, 50, false);
        std::cout << "start time" << timer.startFrame << std::endl;
        
        // Draw 
        //----------------------------------------------------------------------------------
        BeginDrawing(); 
        
        mp.Draw();
        DrawPath(path);
        //Draw hovered tile 
        DrawRectangleLines(p.x * tz, p.y * tz, tz, tz, Color{ 64,255,128,255 });
        DrawCircle(debug_circle);
        

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

    UnloadTexture(bugs);
    for (auto a : agents){
        delete a;
    }

    return 0;
}