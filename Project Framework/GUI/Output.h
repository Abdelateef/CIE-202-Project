#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void CreateColorToolBar() const; //Creat color tool Bar 
	void CreateSizeToolBar() const; //Create size tool bar
	void Createfillandunfilltoobar(); // creat a selected and unselected tool bar
	void CreateColorToolBar(int) const; //Creat color tool bar 
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearToolBar()const;     //Clear the status bar
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawTria(Point P1, Point P2, Point P3, GfxInfo TriaGfxInfo, bool selected = false) const; // Draw a triangle
	void DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected = false) const;  //Draw a Line 
	void DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected = false) const;  //Draw a Circle

	///Make similar functions for drawing all other figures.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	void ChangeDrawColor(ActionType); //change draw color 
	void ChangeFillColor(ActionType); //change fill color
	void ChangeSize(ActionType);      //change the size 
	void CreateUnfilledselected_shape() const;	//creates Play mode toolbar & menu
	void Createfilledselected_shape() const;
	void Createsamecoloredselected_shape() const;

	~Output();
};

#endif