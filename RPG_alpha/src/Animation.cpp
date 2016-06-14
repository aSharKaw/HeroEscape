#include "Animation.h"


CAnimation::CAnimation()
{
	r = 800;
	circle = Circle(400, 400, r);
}


CAnimation::~CAnimation()
{
}

void CAnimation::ringAnime(
	int insideSize, Color insideColor,
	int outsideSize, Color outsideColor, 
	float count, bool close)
{
	if (close)
	{
		circle.drawFrame(insideSize, 0, insideColor);
		circle.drawFrame(0, outsideSize, outsideColor);

		if (count > 0)
		{
			insideSize += (circle.r / (60 * count));
		}
		circle = Circle(400, 400, r);
	}
	else
	{
		insideSize = circle.r;
		circle.drawFrame(insideSize, 0, insideColor);
		circle.drawFrame(0, outsideSize, outsideColor);

		if (count > 0)
		{
			insideSize -= (circle.r / (60 * count));
		}
		circle = Circle(400, 400, r);
	}
	

}