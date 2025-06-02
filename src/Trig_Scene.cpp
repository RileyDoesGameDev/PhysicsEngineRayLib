#include "Trig_Scene.h"

void TrigScene::Initialize()
{
	m_camera = new SceneCamera(Vector2{ m_width / 2.0f, m_height / 2.0f });
}

void TrigScene::Update()
{
}
float DegToRad(float degrees) 
{
	return degrees * (PI / 180);
}

float RadToDeg(float radians)
{
	return radians * (180 / PI);
}

float Vector2Length(const Vector2& v)
{
	return sqrt((v.x * v.x) + (v.y * v.y));
}
Vector2 Vector2Normalize(const Vector2& v) 
{
	//float l = Vector2Length(v);
	//if (l == 0) return Vector2{ 0,0 };
	//return Vector2{ v.x / l, v.y / l };
	return Vector2{ 0,0 };
}
void TrigScene::Draw()
{
	m_camera->BeginMode();
	DrawGrid(10, 5, WHITE);
	//this->DrawCircle((Vector2{0,0}),1, RED);
	int steps = 50;
	float radius = 3;
	float rate = 2;
	float time = (float)GetTime() * rate;
	for (int i = 0; i < steps; i++)
	{

		float theta = (i / (float)steps) * (2 * PI); // 0-1
		float x = cos(theta) * radius;
		float y = sin(theta) * radius;
		DrawCircle((Vector2{ x,y }), .25, RED);
	}


	for (float x = -10.0f; x < 10; x += 0.2f)
	{
		float theta = time + (x / 6) * (2 * PI);
		float c = cos(theta) * radius;
		float s = sin(theta) * radius;
		DrawCircle(Vector2{ x, c }, 0.25f, GREEN);
		DrawCircle(Vector2{ x, s }, 0.25, BLUE);

	}

	float theta = time;
	float x = cosf(theta) * radius; 
	float y = sinf(theta) * radius;

	DrawCircle(Vector2{ x, y }, 0.25f, YELLOW);
	float angle = atan2(y, x);



	m_camera->EndMode();
}



void TrigScene::DrawGUI()
{

}
