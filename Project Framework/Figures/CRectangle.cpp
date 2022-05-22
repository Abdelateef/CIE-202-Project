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

	int refrancepointx = Corner1.x;
	int refrancepointy = Corner1.y;

	int deltaxranglex = Corner2.x - refrancepointx;
	int deltaytrangey = Corner2.y - refrancepointy;


	int newx = click.x;
	int newy = click.y;



	int deltaxranglenewx = newx - refrancepointx;
	int deltaytrangenewy = newy - refrancepointy;

	if (deltaxranglenewx < 0)
	{
		deltaxranglenewx = refrancepointx;
	}

	if (deltaytrangenewy < 0)
	{
		deltaytrangenewy = refrancepointy;
	}

	if (deltaxranglenewx <= deltaxranglex && deltaytrangenewy <= deltaytrangey) return true;
	else
		return false;
}