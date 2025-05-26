#include "vector_scene.h"
#include "body.h"
#include "world.h"
#include "raymath.h"
#include "Gravitation.h"
#include "mathUtils.h"
#include "raygui.h"
#include "raymath.h"
#include "gui.h"

#include <iostream>
void vector_scene::Initialize()
{
	m_camera = new SceneCamera(Vector2{ static_cast<float>(m_width) / 2, m_height / 2.0f });
	m_world = new World();
	m_world->Initialize();

}

void vector_scene::Update()
{
	float dt = GetFrameTime();

	GUI::Update();


	float theta = randomf(0, 360);
	
	if (!GUI::mouseOverGUI && IsMouseButtonPressed(0))
	{
		Vector2 position = m_camera->ScreenToWorld(GetMousePosition());
		Body::Type type = (Body::Type)GUI::TypeDropdownBoxActive;
		std::cout << GUI::TypeDropdownBoxActive << std::endl;
		for (int i = 0; i < 100; i++)
		{
			Body* body = m_world->CreateBody(position, GUI::SizeSliderBarValue, ColorFromHSV(randomf(360), 1, 1));
			float offset = randomf(-180, 180);
			float x = cosf((theta + offset) * DEG2RAD);
			float y = sinf((theta + offset) * DEG2RAD);

			body->velocity = Vector2{ x, y } *randomf(1, 6);
			//body->gravityScale = 0.5f;
			
			body->restitution = GUI::RestitutionSliderBarValue;
			body->gravityScale = GUI::GravityScaleSliderBarValue;
		//	body->mass = MassSlideBarValue;
		}

	}

	// Apply collision

	for (auto body : m_world->GetBodies())
	{
		if (body->position.y < -5)
		{
			body->position.y = -5;
			body->velocity.y *= -body->restitution;
		}

		if (body->position.x < -9)
		{
			body-> position.x = -9;
			body->velocity.x *= -body->restitution;
		}

		if (body->position.x > 9)
		{
			body->position.x = 9;
			body->velocity.x = -body->restitution;
		}
	}

}

void vector_scene::FixedUpdate()
{
	

	m_world->Step(Scene::fixedTimestep);


}

void vector_scene::Draw()
{
	m_camera->BeginMode();

	DrawGrid(10, 5, GRAY);

	m_world->Draw(*this);

	m_camera->EndMode();
}

void vector_scene::DrawGUI()
{

	GUI::Draw();
	
}
