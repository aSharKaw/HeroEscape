#include "Misc.h"


CMisc::CMisc()
{
	if (!FontManager::Register(L"res/font/PixelMplus12-Regular.ttf"))
	{
		font = Font(30);
		bigFont = Font(50);
		return;
	}
	else
	{
		font = Font(30, L"PixelMplus12");
		bigFont = Font(50, L"PixelMplus12");
	}
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

void CMisc::drawModel(Model model, Vec3 pos, Vec3 rot)
{
	for (const auto& node : model.nodes())
	{
		if (node.material.diffuseTextureName.isEmpty)
		{
			node.mesh.translated(pos).draw();
		}
		else
		{
			node.mesh.translated(pos).rotated(rot).draw(TextureAsset(node.material.diffuseTextureName));
		}
	}
}

void CMisc::saveManager(string saveFileName, string dataName, int value, string dataName2, int value2)
{
	namespace propertyTree = boost::property_tree;

	propertyTree::ptree pt;

	pt.put(dataName, value);
	pt.put(dataName2, value2);


	write_ini(saveFileName, pt);

}

int CMisc::loadManager(string loadFileName, string dataName)
{
	namespace propertyTree = boost::property_tree;

	propertyTree::ptree pt;

	read_ini(loadFileName, pt);

	if (boost::optional<int> value = pt.get_optional<int>(dataName))
	{

		return value.get();
	}
	else
	{
		cout << "ERROR:Not Data." << endl;
	}
}
