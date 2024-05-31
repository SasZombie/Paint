#include <iostream>
#include <vector>
#include "canvas.hpp"

struct commonShape
{
    Color col;
    Rectangle rec;
};

struct Button : commonShape
{
    bool isSelected = false;
};

struct scrollBar : commonShape
{
    int pozition = 0;
    float size = 10;
};



int main()
{
    float WIDTH = 800, HEIGHT = 600;
    static constexpr Color bacgkrondColor = {47, 54, 51, 0xFF};
    InitWindow(WIDTH, HEIGHT, "Shapez");
    SetTargetFPS(60);
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    
    Button brush, clear;

    Canvas DrawingBoard(0, 0+60, WIDTH, HEIGHT, YELLOW);

    brush.rec = {0, 0, 25, 25};
    brush.col = BLACK;

    std::vector<Rectangle> toBeDrawn;

    clear.rec = {0, 30, 25, 25};
    clear.col = BLACK;

    scrollBar vertical, orizontal;

    vertical.rec = {WIDTH-15, 60, 15, HEIGHT};


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangle(0, 0, WIDTH, 60, bacgkrondColor);
        DrawRectangleRec(brush.rec, brush.col);
        DrawRectangleLines(brush.rec.x, brush.rec.y, brush.rec.width, brush.rec.width, WHITE); 
        DrawRectangleRec(clear.rec, clear.col);
        DrawRectangleLines(clear.rec.x, clear.rec.y, clear.rec.width, clear.rec.width, WHITE); 

        DrawRectangleRec(DrawingBoard.getRec(), DrawingBoard.getColor());
        
        DrawRectangleRec(vertical.rec, GRAY);

        DrawRectangle(vertical.rec.x, vertical.rec.y + vertical.pozition, vertical.rec.width, vertical.size, RED);
        
        for(const Rectangle &r : toBeDrawn)
        {
            DrawRectangleRec(r, BLACK);
        }

        if(CheckCollisionPointRec(GetMousePosition(), brush.rec))
        {
           if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                brush.isSelected = true;
                clear.isSelected = false;
            }
        }

        if(CheckCollisionPointRec(GetMousePosition(), clear.rec))
        {
           if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                toBeDrawn.clear();
            }
        }   

        if (int value = GetMouseWheelMove())
        {
            vertical.pozition = vertical.pozition - value;
            
        }
        

        if(brush.isSelected)
        {
            if(IsMouseButtonDown(MOUSE_LEFT_BUTTON) && (GetMousePosition().y > clear.rec.y + clear.rec.height))
            {              
                toBeDrawn.push_back(Rectangle(GetMousePosition().x, GetMousePosition().y, 20, 20));
            }
            
        }

        EndDrawing();
        if(IsWindowState(FLAG_WINDOW_RESIZABLE))
        {
            WIDTH = GetScreenWidth();
            HEIGHT = GetScreenHeight();    
            vertical.rec = {WIDTH-15, 60, 15, HEIGHT};
        
        }


    }
    CloseWindow();
}