#pragma once

#include "raylib.h"
#include "world.h"
#include "scene.h"
class GUI
{
public:
	static void Update();
	static void Draw();
	static struct Body* GetBodyIntersect(const Vector2& position, bodies_t& bodies,  SceneCamera& camera);


public:

	inline static bool mouseOverGUI = false;

   inline static Vector2 anchor01 = { 24, 104 };
   inline static Vector2 anchor02 = { 24, 104 };

   inline static bool PhysicsWindowBoxActive = true;
   inline static bool TypeDropdownBoxEditMode = false;
   inline static int TypeDropdownBoxActive = 0;
   inline static float GravitySliderValue = 1.0f;
   inline static float MassSliderBarValue = 1.0f;
   inline static float SizeSliderBarValue = 1.0f;
   inline static float GravityScaleSliderBarValue = 1.0f;
   inline static float DampingSliderBarValue = 1.0f;
   inline static float RestitutionSliderBarValue = 1.0f;
   inline static float GravitationSliderBarValue = 0.0f;
   inline static float StiffnessSliderBarValue = 0.0f;
   inline static bool SimulateToggleActive = true;
};