#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Line on the screen	
	pOut->DrawLine(Corner1, Corner2, FigGfxInfo, Selected);
}



bool CLine::isWithinMe(Point click)
{

	int newx = click.x;
	int newy = click.y;

	double m1 = (Corner1.x - Corner2.x) / (Corner1.y - Corner2.y);

	double m2 = (Corner1.x - newx) / (Corner1.y - newy);


	if (m1 == m2) return true;
	else
		return false;
}

CFigure* CLine::Clone() {
	CFigure* Temp = new CLine(Corner1, Corner2, FigGfxInfo);
	return Temp;
}


//void CLine::Drawpastefigures(Point click) const {
//
//}
