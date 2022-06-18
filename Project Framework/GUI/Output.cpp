#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;

	UI.DrawColor = MAROON;	//Drawing color
	UI.FillColor = GREY;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = SNOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 5;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar()const
{
	GfxInfo gfxInfo;
	Point P1, P2;
	P1.x = 0; P1.y = 0;
	P2.x = UI.width; P2.y = UI.ToolBarHeight;
	gfxInfo.DrawClr = WHITE;	//any color for border
	gfxInfo.FillClr = WHITE;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled

	DrawRect(P1, P2, gfxInfo, false);
}

/////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	ClearToolBar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_LINE] =  "images\\MenuItems\\Menu_Line.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_TRIA] = "images\\MenuItems\\Menu_Tria.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_DELET] = "images\\MenuItems\\Menu_Delet.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Menu_Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_COLOR] = "images\\MenuItems\\Menu_Color.jpg";
	MenuItemImages[FILL_CLR] = "images\\MenuItems\\Menu_fillc.jpg";
	MenuItemImages[SWITCH_PLAY] = "images\\MenuItems\\Menu_Play_Mode.jpg";
<<<<<<< Updated upstream
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save-icon-file-save-icon-disc-icon-save-icon-file-save-icon-disc-icon-vector-icon-124470168.jpg";
	MenuItemImages[ITM_Load] = "images\\MenuItems\\images (1).jpg";
	
=======
	MenuItemImages[ITM_SIZE] = "images\\MenuItems\\size.jpg";
>>>>>>> Stashed changes
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateColorToolBar() const
{
	ClearToolBar();
	///TODO: write code to create Play mode menu
	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\white.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_BACK] = "images\\MenuItems\\back.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateColorToolBar(int a) const
{
	if (a == 1)
		UI.InterfaceMode = MODE_DRAW_COLOR;
	else
		UI.InterfaceMode = MODE_FILL_COLOR;
	ClearToolBar();
	///TODO: write code to create Play mode menu
	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\white.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_BACK] = "images\\MenuItems\\back.jpg";


	//Draw menu item one image at a time
	for (int i = 0; i < COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	//Draw a line under the toolbar
	//pWind->SetPen(RED, 3);
	//pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
/////////////////////////////////////////////////////////////////////////////////////////////
void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	ClearToolBar();

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[SWITCH_DRAW] = "images\\MenuItems\\Menu_Draw_Mode.jpg";
	MenuItemImages[UNFILL_SHAPES_MODE] = "images\\MenuItems\\Menu_unfillied_shape.jpg";
	MenuItemImages[COLOR_SHAPES_MODE] = "images\\MenuItems\\Menu_Color_shapes.jpg";
	MenuItemImages[FILL_SHAPES_MODE] = "images\\MenuItems\\Menu_filles_shapes.jpg";
	MenuItemImages[START] = "images\\MenuItems\\Menu_startgame.jpg";
	MenuItemImages[RESTART] = "images\\MenuItems\\Menu_Restart.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

////////////////////////////////////////////////////////////

void Output::CreateUnfilledselected_shape() const
{
	UI.InterfaceMode = MODE_UNFILL_SHAPES;
	ClearToolBar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
		

	string MenuItemImages[UNFILL_ITM_COUNT];
	MenuItemImages[ITM_LINEE] = "images\\MenuItems\\Menu_Unfill_Line.jpg";
	MenuItemImages[ITM_SQUAREE] = "images\\MenuItems\\Menu_Unfill_Square.jpg";
	MenuItemImages[ITM_CIRCLEE] = "images\\MenuItems\\Menu_Unfill_Circle.jpg";
	MenuItemImages[ITM_TRIANGLEE] = "images\\MenuItems\\Menu_Unfill_Triangle.jpg";
	MenuItemImages[ITM_BACKK] = "images\\MenuItems\\back.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < UNFILL_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateSizeToolBar() const
{
	UI.InterfaceMode = MODE_SIZE;
	ClearToolBar();
	///TODO: write code to create Play mode menu
	string MenuItemImages[SIZE_ITM_COUNT];
	MenuItemImages[ITM_TINY] = "images\\MenuItems\\tiny.jpg";
	MenuItemImages[ITM_NORMAL] = "images\\MenuItems\\normal.jpg";
	MenuItemImages[ITM_LARGE] = "images\\MenuItems\\InkedCopy.jpg";
	MenuItemImages[ITM_BACKKKK] = "images\\MenuItems\\back.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < SIZE_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	//Draw a line under the toolbar
}
//////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////
void Output::Createsamecoloredselected_shape() const
{
	UI.InterfaceMode = MODE_SMAME_COLOR_SHAPES;
	ClearToolBar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\white.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_BACK] = "images\\MenuItems\\back.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}



///////////////////////////////////////////////////
void Output::Createfilledselected_shape() const
{
	UI.InterfaceMode = MODE_FILL_SHAPES;
	ClearToolBar();
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[FILL_ITM_COUNT];
	MenuItemImages[ITM_LINEEE] = "images\\MenuItems\\Menu_Unfill_Line.jpg";
	MenuItemImages[ITM_SQUAREEE] = "images\\MenuItems\\Menu_Unfill_Square.jpg";
	MenuItemImages[ITM_CIRCLEEE] = "images\\MenuItems\\Menu_Unfill_Circle.jpg";
	MenuItemImages[ITM_TRIANGLEEE] = "images\\MenuItems\\Menu_Unfill_Triangle.jpg";
	MenuItemImages[ITM_BLACKK] = "images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_WHITEE] = "images\\MenuItems\\white.jpg";
	MenuItemImages[ITM_REDD] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_GREENN] = "images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_BLUEE] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_BACKKK] = "images\\MenuItems\\back.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < FILL_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}


void Output::DrawTria(Point P1, Point P2, Point P3, GfxInfo TriaGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriaGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriaGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriaGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriaGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);


}



void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (LineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LineGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawCirc(Point P1, Point P2 , GfxInfo CircGfxInfo, bool selected) const {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawCircle(P1.x, P1.y, (P2.x-P1.x), style);
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ChangeDrawColor(ActionType ActType2)
{
	
	switch (ActType2)
	{
	case SET_BLACK:
		UI.DrawColor = BLACK;
		CreateDrawToolBar();
		break;
	case SET_BLUE:
		UI.DrawColor = BLUE;
		CreateDrawToolBar();
		break;
	case SET_WHITE:
		UI.DrawColor = WHITE;
		CreateDrawToolBar();
		break;
	case SET_RED:
		UI.DrawColor = RED;
		CreateDrawToolBar();
		break;
	case SET_GREEN:
		UI.DrawColor = GREEN;
		CreateDrawToolBar();
		break;

	}
}

//////////////////////////////////////////////////////////////////////////////////////////
void Output::ChangeFillColor(ActionType ActType3)
{

	UI.filled_OR_not = true;
	switch (ActType3)
	{
	case SET_BLACK:
		UI.FillColor = BLACK;
		CreateDrawToolBar();
		break;
	case SET_BLUE:
		UI.FillColor = BLUE;
		CreateDrawToolBar();
		break;
	case SET_WHITE:
		UI.FillColor = WHITE;
		CreateDrawToolBar();
		break;
	case SET_RED:
		UI.FillColor = RED;
		CreateDrawToolBar();
		break;
	case SET_GREEN:
		UI.FillColor = GREEN;
		CreateDrawToolBar();
		break;
	case EMPTY:
		UI.filled_OR_not = false;
		CreateDrawToolBar();
		break;
	case DRAWING_AREA:
		UI.filled_OR_not = false;
		CreateDrawToolBar();
		break;


	}
}


