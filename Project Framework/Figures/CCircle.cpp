#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a Circle on the screen	
	pOut->DrawCirc(Corner1, Corner2, FigGfxInfo, Selected);
}


bool CCircle::isWithinMe(Point click)
{
	int radius = Corner1.x - Corner2.x;
	
	int calc = (click.x - Corner1.x) * (click.x - Corner1.x) + (click.y - Corner1.y)* (click.y - Corner1.y);

	if (calc<(radius*radius))
	{
		return true;
	}
	else
	{
		return false;
	}
}
