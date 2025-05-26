/*******************************************************************************************
*
*   PhysicsGUI v1.0.0 - Tool Description
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2022 raylib technologies. All Rights Reserved.
*
*   Unauthorized copying of this file, via any medium is strictly prohibited
*   This project is proprietary and confidential unless the owner allows
*   usage in any other form by expresely written permission.
*
**********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "PhysicsGUI");

    // PhysicsGUI: controls initialization
    //----------------------------------------------------------------------------------
    bool WindowBox000Active = true;
    bool DropdownBox007EditMode = false;
    int DropdownBox007Active = 0;
    float SliderBar008Value = 0.0f;
    float SliderBar009Value = 0.0f;
    float SliderBar010Value = 0.0f;
    float SliderBar011Value = 0.0f;
    float SliderBar012Value = 0.0f;
    //----------------------------------------------------------------------------------

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))); 

            // raygui: controls drawing
            //----------------------------------------------------------------------------------
            if (DropdownBox007EditMode) GuiLock();

            if (WindowBox000Active)
            {
                WindowBox000Active = !GuiWindowBox((Rectangle){ 24, 24, 168, 328 }, "SAMPLE TEXT");
                GuiLabel((Rectangle){ 32, 48, 120, 24 }, "Mass");
                GuiLabel((Rectangle){ 32, 88, 120, 24 }, "Size");
                GuiLabel((Rectangle){ 32, 128, 120, 24 }, "Scale");
                GuiLabel((Rectangle){ 32, 168, 120, 24 }, "Damping");
                GuiLabel((Rectangle){ 32, 208, 120, 24 }, "Gravitational Force");
                GuiLabel((Rectangle){ 32, 248, 120, 24 }, "Type");
                if (GuiDropdownBox((Rectangle){ 32, 264, 120, 24 }, "Dynamic;Static;Kinematic", &DropdownBox007Active, DropdownBox007EditMode)) DropdownBox007EditMode = !DropdownBox007EditMode;
            }
            GuiSliderBar((Rectangle){ 32, 64, 120, 16 }, NULL, NULL, &SliderBar008Value, 0, 100);
            GuiSliderBar((Rectangle){ 32, 104, 120, 16 }, NULL, NULL, &SliderBar009Value, 0, 100);
            GuiSliderBar((Rectangle){ 32, 224, 120, 16 }, NULL, NULL, &SliderBar010Value, 0, 100);
            GuiSliderBar((Rectangle){ 32, 184, 120, 16 }, NULL, NULL, &SliderBar011Value, 0, 100);
            GuiSliderBar((Rectangle){ 32, 144, 120, 16 }, NULL, NULL, &SliderBar012Value, 0, 100);
            
            GuiUnlock();
            //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------

