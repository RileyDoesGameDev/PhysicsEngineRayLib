#pragma once
#include <cstdlib>
#include"raylib.h"
#include <algorithm>

inline float randomf()
{
	return rand() / (float)RAND_MAX;
}

inline float randomf(float max)
{
	return randomf() * max;
}

inline float randomf(float min, float max)
{
	if (min > max) std::swap(min, max);
	return min + (randomf() * (max - min));
}

inline Vector2 randomOnUnitCircle() 
{
	float theta = randomf(0, PI * 2);
	return { cosf(theta), sinf(theta) };
}