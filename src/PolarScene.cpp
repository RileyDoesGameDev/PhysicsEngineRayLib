#include "PolarScene.h"
#include "Polar.h"
#include <list>
void PolarScene::Initialize()
{
	m_camera = new SceneCamera(Vector2{ m_width / 2.0f, m_height / 2.0f });
}






float rate = 2;


void PolarScene::Draw()
{
	float time = (float)GetTime() * rate;
	m_camera->BeginMode();
	float maxAngle = 10 * 2 * PI;
	Vector2 previousPoint = { 0 };
	
	for (float i = 0.1f; i < maxAngle; i+= 0.1f) 
	{
		Polar p;
		//float theta = time + (i / 6) * (2 * PI);
		p.angle = i;
		p.radius = 0 + (.5 * i);
		
		Vector2 point = (Vector2)p;

		
		if (i > 1)
		{
			DrawLine(previousPoint, point,2, BLUE);
			
		}

		previousPoint = point;
		
		//DrawCircle(point , 0.1f, BLUE);
	
	}


	float size = 1;

	for (float i = 0.1f; i < maxAngle; i += 0.1f)
	{
		Polar p;
		p.angle = i;
		p.radius = size * (1 + cos(i));

		Vector2 point = (Vector2)p;
		if (i > 1)
		{
			//DrawLine(previousPoint, point, 2, RED);
			
		}
		
	//	DrawCircle(point,0.01f , RED);
		previousPoint = point;
	}


	float a = 1;
	float b = 2;

	for (float i = 0.1f; i < maxAngle; i += 0.1f)
	{
		Polar p;
		float theta = time + (i / 6) * (2 * PI);
		p.angle = i;

		p.radius = a + (b * cos(i));


		Vector2 point = (Vector2)p;

	
		
		if (i > 1)
		{
		//DrawLine(previousPoint, point, 2, GREEN);

		}

		//	DrawCircle(point,0.01f , RED);
		previousPoint = point;
	}

	size = 2;
	float k = 2;

	for (float i = 0.1f; i < maxAngle; i += 0.1f)
	{
		Polar p;
		float theta = time + (i / 6) * (2 * PI);
		p.angle = i;
		
		p.radius = size * cos(k * i);
		Vector2 point = (Vector2)p;

		

		if (i > 1)
		{
			//DrawLine(previousPoint, point, 2,YELLOW);

		}

		//	DrawCircle(point,0.01f , RED);
		previousPoint = point;
	}

	a = 1;
	b = 10;

	for (float i = 0.1f; i < maxAngle; i += 0.1f)
	{
		Polar p;
		//float theta = time;//time + (i / 6) * (2 * PI);

		p.angle = i;
		int k = 5;

		p.radius = a / (1.5 + sin(k * i));

		Vector2 point = (Vector2)p;
		// point.x *= cosf(theta) * p.radius;
		// point.y *= cosf(theta) * p.radius;
		
		if (i > 1)
		{
			DrawLine(previousPoint, point, 2, GREEN);

		}

			//DrawCircle(point,0.1f , RED);
		previousPoint = point;
	}




	m_camera->EndMode();
}




void PolarScene::DrawGUI()
{

}
