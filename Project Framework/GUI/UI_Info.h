#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_DRAW_COLOR, // Draw color mode 
	MODE_FILL_COLOR, // Fill color mode
	MODE_UNFILL_SHAPES, // Play unfill shape play Mode
	MODE_SMAME_COLOR_SHAPES, // Play same color play Mode
	MODE_FILL_SHAPES,       // Play fill shape play Mode
	MODE_SIZE              //Change the size 
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	SWITCH_PLAY,
	ITM_LINE,		// Line item in menu
	ITM_RECT,		//Recangle item in menu
	ITM_CIRC,		//Circle item in menu
	ITM_TRIA,		//Triangle item in menu
	ITM_SELECT,		// Select item in menu
	ITM_DELET,		// Delete item in Menu
	ITM_COPY,		// Copy item in Menu
	ITM_CUT,		// Cut item in Menu 
	ITM_PASTE,		// Paste item in Menu
	ITM_SAVE,       // Save item in menu
	ITM_Load,       // load item in menu
	ITM_EXIT,		//Exit item
	ITM_COLOR,      // color item
	FILL_CLR,       // fill item 
	ITM_SIZE,       // change width size
	DRAW_ITM_COUNT	//no. of menu items ==> This should be the last line in this enum
			//Switch to play mode	

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	SWITCH_DRAW,
	UNFILL_SHAPES_MODE,
	COLOR_SHAPES_MODE,
	FILL_SHAPES_MODE,
	RESTART,
	
	PLAY_ITM_COUNT

};

enum Unfill_shap {
	ITM_LINEE,
	ITM_SQUAREE,
	ITM_CIRCLEE,
	ITM_TRIANGLEE,
	ITM_BACKK,

	UNFILL_ITM_COUNT
};


enum fill_shap {
	ITM_LINEEE,
	ITM_SQUAREEE,
	ITM_CIRCLEEE,
	ITM_TRIANGLEEE,
	ITM_BLACKK,
	ITM_WHITEE,
	ITM_REDD,
	ITM_GREENN,
	ITM_BLUEE,
	ITM_BACKKK,

	FILL_ITM_COUNT
};


enum SetSize
{
	ITM_TINY,
	ITM_NORMAL,
	ITM_LARGE,
	ITM_BACKKKK,
	SIZE_ITM_COUNT
};
enum SetColor
{
	ITM_BLACK,
	ITM_WHITE,
	ITM_RED,
	ITM_GREEN,
	ITM_BLUE,
	ITM_BACK,
	COLOR_ITM_COUNT
};


__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	bool filled_OR_not; // To know if the shape is filled or not 
	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif