#include "CTriangle.h"
CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Triangle on the screen	
	pOut->DrawTria(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}

bool CTriangle::isWithinMe(Point click) {
	int x = click.x;
	int y = click.y;
	double area_the_draw_triangle = abs(0.5 * ((Corner1.x * (Corner2.y - Corner3.y)) + (Corner2.x * (Corner3.y - Corner1.y)) + (Corner3.x * (Corner1.y - Corner2.y))));
	double area_Triangle_one = abs(0.5 * ((x* (Corner2.y - Corner3.y)) + (Corner2.x * (Corner3.y - y)) + (Corner3.x * (y - Corner2.y))));
	double area_Triangle_two = abs(0.5 * ((Corner1.x * (y - Corner3.y)) + (x * (Corner3.y - Corner1.y)) + (Corner3.x * (Corner1.y - y))));
	double area_Triangle_three = abs(0.5 * ((Corner1.x * (Corner2.y - y)) + (Corner2.x * (y - Corner1.y)) + (x * (Corner1.y - Corner2.y))));

	if (area_the_draw_triangle == (area_Triangle_one + area_Triangle_two + area_Triangle_three)) return true;
	else
		return false;
}

void CTriangle:: Drawpastfigures(Output* pOut,Point Click) const {
	Point NewCorner1, NewCorner2, NewCorner3, MidlePoint;
	NewCorner1 = Click;
	int dispoint2x, dispoint2y, dispoint3x, dispoint3y;
	dispoint2x = (Corner1.x - Corner2.x);
	dispoint3x =( Corner1.x - Corner3.x);

	dispoint2y = (Corner1.y - Corner2.y);
	dispoint3y = (Corner1.y - Corner3.y);

	NewCorner2.x = NewCorner1.x + (dispoint2x);
	NewCorner2.y = NewCorner1.y + (dispoint2y);
	NewCorner3.x = NewCorner1.x - (dispoint3x);
	NewCorner3.y = NewCorner1.y - (dispoint2y);

	pOut->DrawTria(NewCorner1, NewCorner2,NewCorner3, FigGfxInfo, Selected==false);
}

CFigure* CTriangle::Clone(Point click) {
	Point NewCorner1, NewCorner2, NewCorner3, MidlePoint;
	NewCorner1 = click;
	int dispoint2x, dispoint2y, dispoint3x, dispoint3y;
	dispoint2x = (Corner1.x - Corner2.x);
	dispoint3x = (Corner1.x - Corner3.x);

	dispoint2y = (Corner1.y - Corner2.y);
	dispoint3y = (Corner1.y - Corner3.y);

	NewCorner2.x = NewCorner1.x + (dispoint2x);
	NewCorner2.y = NewCorner1.y + (dispoint2y);
	NewCorner3.x = NewCorner1.x - (dispoint3x);
	NewCorner3.y = NewCorner1.y - (dispoint2y);

	CFigure* Temp = new CTriangle(NewCorner1, NewCorner2, NewCorner3, FigGfxInfo);
	return Temp;
}