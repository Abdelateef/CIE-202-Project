#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	static int objcount ;
	static int starship;
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	objcount++;
	starship++;
	objnumbers = starship;
	ID = objcount;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
void CFigure::changewedith(int n) {
	FigGfxInfo.BorderWdth = n;
}

int CFigure :: objcountreturn()
{
	return ID;
}

int CFigure:: counterfig()
{
	return objnumbers;
}
