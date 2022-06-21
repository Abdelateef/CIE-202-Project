#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	int objcount = 0;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	//select/unselect the figure
	int counter();
	bool IsSelected() const;	//check whether fig is selected
	virtual int area() = 0;
	virtual int radius() = 0;
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual void Drawpastfigures(Output* pOut,Point Click) const = 0;
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void changewedith(int n);
	virtual int x1() = 0;
	virtual int x2() = 0;
	virtual int y1() = 0;
	virtual int y2() = 0;
	virtual void drawloadaction(Output* pOut,int arr[]) = 0;
	virtual int objencoded() = 0;

	int objcountreturn();
	virtual int thirdcornerx()=0;
	virtual int thirdcornery()=0;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure

	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar

	virtual CFigure* Clone(Point click) = 0;

	virtual bool isWithinMe(Point click) = 0;
	// Gets graphical info of the figures drawn

	virtual string GetName() = 0;
	// Gets the figure name

		/*A function to return gfx of a figure*/
	virtual GfxInfo& GetGfxInfo() = 0;
	virtual int getdrawcolour() = 0; // returns the value of the draw colours
	virtual int getfillcolour() = 0; // returns the value fill colours
};

#endif