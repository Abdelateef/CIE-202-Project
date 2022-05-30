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


void CRectangle::Drawpastfigures(Output* pOut,Point Click) const {
	Point NewCorner1, NewCorner2;
	int rectangle_Width = abs(Corner1.x - Corner2.x);
	int retangle_Higth = abs(Corner1.y - Corner1.y);
	NewCorner1.x = Click.x - (rectangle_Width / 2);
	NewCorner1.y = Click.y - (retangle_Higth / 2);
	NewCorner2.x = Click.x + (rectangle_Width / 2);
	NewCorner2.y = Click.y + (retangle_Higth / 2);

	pOut->DrawRect(NewCorner1, NewCorner2, FigGfxInfo, Selected);
}

CFigure* CRectangle::Clone(Point click) {
	Point NewCorner1, NewCorner2;
	int rectangle_Width = abs(Corner1.x - Corner2.x);
	int retangle_Higth = abs(Corner1.y - Corner1.y);
	NewCorner1.x = click.x - (rectangle_Width / 2);
	NewCorner1.y = click.y - (retangle_Higth / 2);
	NewCorner2.x = click.x + (rectangle_Width / 2);
	NewCorner2.y = click.y + (retangle_Higth / 2);
	CFigure* Temp = new CRectangle(NewCorner1, NewCorner2, FigGfxInfo);
	return Temp;
}