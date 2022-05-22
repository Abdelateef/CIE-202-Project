#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::isWithinMe(Point click) {

	int x1=Corner1.x;
	int y1=Corner1.y;

	int x2 = Corner2.x;
	int y2 = Corner2.y;


	int x=click.x;
	int y=click.y;

	if (x > x1 && x < x2 && y > y1 && y < y2)
		return true;

	return false;


}