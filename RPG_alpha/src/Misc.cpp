#include "Misc.h"


CMisc::CMisc()
{
}


CMisc::~CMisc()
{
}

void CMisc::createModel(Model model)
{
	for (const auto& node : model.nodes())
	{
		if (!node.material.diffuseTextureName.isEmpty
			&& !TextureAsset::IsRegistered(node.material.diffuseTextureName))
		{
			TextureAsset::Register(node.material.diffuseTextureName,
				node.material.diffuseTextureName, TextureDesc::For3D);
		}
	}
}

void CMisc::drawModel(Model model, Vec3 pos)
{
	for (const auto& node : model.nodes())
	{
		if (node.material.diffuseTextureName.isEmpty)
		{
			node.mesh.translated(pos).draw();
		}
		else
		{
			node.mesh.translated(pos).draw(TextureAsset(node.material.diffuseTextureName));
		}
	}
}