#pragma once
#include <Siv3D.hpp>

class CMisc
{
public:
	CMisc();
	~CMisc();

	void createModel(Model model);
	void drawModel(Model model, Vec3 pos);
};

