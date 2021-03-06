#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction(int& X, int& Y) const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case SWITCH_PLAY: return TO_PLAY;
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_TRIA: return DRAW_TRI;
			case ITM_LINE:return DRAW_LINE;
			case ITM_SELECT:return SELECT;
			case ITM_DELET: return DEL;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_SAVE: return SAVE;
			case ITM_Load: return LOAD;
			case ITM_EXIT: return EXIT;
			case ITM_COLOR:return CHNG_DRAW_CLR;
			case FILL_CLR: return CHNG_FILL_CLR;
			case ITM_SIZE: return Wid_SIZE;
		


			default: return EMPTY;	//A click on empty place in desgin toolbar
			}

			
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_DRAW_COLOR){
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_BLACK: return SET_BLACK;
			case ITM_WHITE: return SET_WHITE;
			case ITM_RED: return SET_RED;
			case ITM_GREEN: return SET_GREEN;
			case ITM_BLUE:return SET_BLUE;
			case ITM_BACK:return BACK;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
	}
	else if (UI.InterfaceMode == MODE_FILL_COLOR) {
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_BLACK: return SET_BLACK;
			case ITM_WHITE: return SET_WHITE;
			case ITM_RED: return SET_RED;
			case ITM_GREEN: return SET_GREEN;
			case ITM_BLUE:return SET_BLUE;
			case ITM_BACK:return BACK;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
	}
	else	//GUI is in PLAY mode
	{
		if (UI.InterfaceMode == MODE_PLAY) {

			if (y >= 0 && y < UI.ToolBarHeight)
			{
				//Check whick Menu item was clicked
				//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case SWITCH_DRAW: return TO_DRAW;
				case UNFILL_SHAPES_MODE:return HIDE_UNFILL_SHAPE;
				case COLOR_SHAPES_MODE: return HIDE_SMAE_COLOR;
				case FILL_SHAPES_MODE: return HIDE_FILL_SHAPE;
				case RESTART: return RESTART_GAME;

				default: return EMPTY;
				}
			}
			if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			{
				return DRAWING_AREA;
			}

			//[3] User clicks on the status bar
			return STATUS;
		}
		else if (UI.InterfaceMode == MODE_SMAME_COLOR_SHAPES) {
			if (y >= 0 && y < UI.ToolBarHeight)
			{
				//Check which Menu item was clicked
				//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case ITM_BLACK: return SET_BLACK;
				case ITM_WHITE: return SET_WHITE;
				case ITM_RED: return SET_RED;
				case ITM_GREEN: return SET_GREEN;
				case ITM_BLUE:return SET_BLUE;
				case ITM_BACK:return BACK;
				default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}
		}
		else  if (UI.InterfaceMode == MODE_SIZE)
		{
			if (y >= 0 && y < UI.ToolBarHeight)
			{
				//Check which Menu item was clicked
				//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case ITM_TINY: return SET_tiny;
				case ITM_NORMAL: return SET_Normal;
				case ITM_LARGE: return SET_Large;
				case ITM_BACKKKK:return SET_BACK;
				default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}
		}

		else if (UI.InterfaceMode == MODE_UNFILL_SHAPES) {
			if (y >= 0 && y < UI.ToolBarHeight)
			{
				//Check which Menu item was clicked
				//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case ITM_LINEE: return HIDE_LINE;
				case ITM_SQUAREE: return HIDE_RECT;
				case ITM_CIRCLEE: return HIDE_CIRC;
				case ITM_TRIANGLEE: return HIDE_TRI;
				case ITM_BACKK:return BACK;
				default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}
		}



		else if (UI.InterfaceMode == MODE_FILL_SHAPES) {
			if (y >= 0 && y < UI.ToolBarHeight)
			{
				//Check which Menu item was clicked
				//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case ITM_LINEEE: return HIDE_LINE;
				case ITM_SQUAREEE: return HIDE_RECT;
				case ITM_CIRCLEEE: return HIDE_CIRC;
				case ITM_TRIANGLEEE: return HIDE_TRI;
				case ITM_BLACKK: return SET_BLACK;
				case ITM_WHITEE: return SET_WHITE;
				case ITM_REDD: return SET_RED;
				case ITM_GREENN: return SET_GREEN;
				case ITM_BLUEE:return SET_BLUE;
				case ITM_BACKKK:return BACK;

				default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}
		}

	}
}
/////////////////////////////////

Input::~Input()
{
}
