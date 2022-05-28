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

CFigure* CRectangle::Clone() {
	CFigure* Temp = new CRectangle(Corner1, Corner2, FigGfxInfo);
	return Temp;
}
//void CRectangle::Drawpastefigures(Point click) const {
//	//Point NewCorner1, NewCorner2;
//	//int rectangle_Width = abs(Corner1.x - Corner2.x);
//	//int retangle_Higth = abs(Corner1.y - Corner1.y);
//	//NewCorner1.x = click.x - (rectangle_Width / 2);
//	//NewCorner1.y = click.y - (retangle_Higth / 2);
//	//NewCorner2.x = click.x + (rectangle_Width / 2);
//	//NewCorner2.y = click.y + (retangle_Higth / 2);
//
///*	Output* pOut;
//	pOut->DrawRect(NewCorner1, NewCorner2, FigGfxInfo)*/;
//}