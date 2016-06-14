#pragma once
#include <Siv3D.hpp>

class CAnimation
{
public:
	CAnimation();
	~CAnimation();

	//void spriteAnime();
	void ringAnime(
		int insideSize, Color insideColor, 
		int outsideSize, Color outsideColor, 
		float count, bool close);

private:

	Circle circle;
	float r;
};

