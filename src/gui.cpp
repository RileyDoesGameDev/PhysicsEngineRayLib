#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "gui.h"
//#include <scene_camera.h>




Body* GUI::GetBodyIntersect(const Vector2& position, bodies_t& bodies,  SceneCamera& camera)
{
    for (auto body : bodies) 
    {
        if (CheckCollisionPointCircle(position, body->position, body->size))
        {
            return body;
        }

    }

	return nullptr;
}

void GUI::Update() 
{
	mouseOverGUI = PhysicsWindowBoxActive && CheckCollisionPointRec(GetMousePosition(), 
        { anchor01.x + 0, anchor01.y + 0, 216, 376 });
	if (IsKeyPressed(KEY_TAB)) PhysicsWindowBoxActive = !PhysicsWindowBoxActive;

}

void GUI::Draw() 
{
    if (PhysicsWindowBoxActive)
    {
        PhysicsWindowBoxActive = !GuiWindowBox(Rectangle { anchor01.x + 0, anchor01.y + 0, 216, 376 }, "Physics");
        GuiSlider(Rectangle { anchor01.x + 8, anchor01.y + 272, 120, 16 }, NULL, NULL, & World::gravity.y, -20, 20);
        GuiLabel(Rectangle { anchor01.x + 8, anchor01.y + 256, 120, 24 }, "World Gravity");
        GuiSliderBar(Rectangle { anchor01.x + 8, anchor01.y + 304, 120, 16 }, NULL, NULL, & World::gravitation, 0, 1);
        GuiSliderBar(Rectangle { anchor01.x + 8, anchor01.y + 336, 120, 16 }, NULL, NULL, & World::springStiffnessMultiplier, 0, 5);
        GuiLabel(Rectangle { anchor01.x + 8, anchor01.y + 288, 120, 24 }, "Gravitation");
        GuiLabel(Rectangle { anchor01.x + 8, anchor01.y + 320, 120, 24 }, "Stiffness");
        GuiToggle(Rectangle { anchor01.x + 136, anchor01.y + 264, 56, 24 }, "Simulate", &World::simulate);
        if (GuiDropdownBox(Rectangle { anchor01.x + 16, anchor01.y + 208, 120, 24 }, "Dynamic;Kinematic;Static", & TypeDropdownBoxActive, TypeDropdownBoxEditMode)) TypeDropdownBoxEditMode = !TypeDropdownBoxEditMode;
        GuiGroupBox(Rectangle{ anchor02.x + 8, anchor02.y + 32, 184, 224 }, "Bodys");
        GuiLabel(Rectangle{ anchor02.x + 16, anchor02.y + 40, 120, 24 }, "Mass");
        GuiSliderBar(Rectangle{ anchor02.x + 16, anchor02.y + 56, 120, 16 }, NULL, NULL, &MassSliderBarValue, 0, 10);
        GuiSliderBar(Rectangle{ anchor02.x + 16, anchor02.y + 88, 120, 16 }, NULL, NULL, &SizeSliderBarValue, 0.1f, 5.0f);
        GuiSliderBar(Rectangle{ anchor02.x + 16, anchor02.y + 120, 120, 16 }, NULL, NULL, &GravityScaleSliderBarValue, 0, 5);
        GuiSliderBar(Rectangle{ anchor02.x + 16, anchor02.y + 152, 120, 16 }, NULL, NULL, &DampingSliderBarValue, 0, 1);
        GuiLabel(Rectangle{ anchor02.x + 16, anchor02.y + 72, 120, 24 }, "Size");
        GuiLabel(Rectangle{ anchor02.x + 16, anchor02.y + 104, 120, 24 }, "Gravity Scale");
        GuiLabel(Rectangle{ anchor02.x + 16, anchor02.y + 136, 120, 24 }, "Damping");
        GuiSliderBar(Rectangle{ anchor02.x + 16, anchor02.y + 184, 120, 16 }, NULL, NULL, &RestitutionSliderBarValue, 0, 1);
        GuiLabel(Rectangle{ anchor02.x + 16, anchor02.y + 168, 120, 24 }, "Restitution");
    }
   

    GuiUnlock();
	


}