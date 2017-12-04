#ifndef MENUDATA_H
#define MENUDATA_H

#include <string>
#include <vector>

////////////////////////////////////////////////////////////
/// \brief A simple class that stores configuration
///   data relating to the appearance of our main menu.
////////////////////////////////////////////////////////////

class MenuData {
public:
	struct MObject {
		int Width;
		int Height;
		int X;
		int Y;
		std::string text;

		MObject(int width, int height, int x, int y, std::string word) :
			Width(width), Height(height), X(x), Y(y), text(word)
		{
		}
	};

	//font used for menus
	std::string m_MenuFontFile;

	//items for the main menu
	std::vector<MObject> m_mainMenuVec;
	std::string m_menuBackgroundFile;

};

#endif
