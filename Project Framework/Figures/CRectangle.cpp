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
	NewCorner1.x = Click.x - ((Corner1.x - Corner2.x) / 2);
	NewCorner1.y = Click.y - ((Corner1.y - Corner2.y) / 2);
	NewCorner2.x = Click.x + ((Corner1.x - Corner2.x) / 2);
	NewCorner2.y = Click.y + ((Corner1.y - Corner2.y) / 2);

	pOut->DrawRect(NewCorner1, NewCorner2, FigGfxInfo, Selected == false);
}

int CRectangle::area()
{
	int x = abs(Corner1.x - Corner2.x);
	int y = abs(Corner1.y - Corner2.y);
	int area;
	area = x * y;
	return area;
}

int CRectangle::radius()
{
	int x = abs(Corner2.x - Corner1.x);
	return x;
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

int CRectangle::x1()
{
	return Corner1.x;
}

int CRectangle::x2()
{
	return Corner2.x;
}

int CRectangle::y1()
{
	return Corner1.y;
}

int CRectangle::y2()
{
	return Corner2.y;
}

void CRectangle::drawloadaction(Output* pOut,int arr[])
{
}

int CRectangle::thirdcornerx()
{
	return -1;
}

int CRectangle::thirdcornery()
{
	return -1;
}


string CRectangle::GetName() {
	return "Rectangle";
}

color CRectangle::Getcolor() {
	if (FigGfxInfo.isFilled)
	return FigGfxInfo.FillClr;
}


GfxInfo& CRectangle::GetGfxInfo() {
	return FigGfxInfo;
}


int CRectangle::objencoded()
{
	return 3;
}

int CRectangle::getdrawcolour()
{
	int x = FigGfxInfo.DrawClr.ucRed;
	int y = FigGfxInfo.DrawClr.ucGreen;
	int z = FigGfxInfo.DrawClr.ucBlue;
	int sum = x;
	sum = sum * 1000;
	sum = sum + y;
	sum = sum * 1000;
	sum = sum + z;
	return sum;
}
int CRectangle::getfillcolour()
{
	int x = FigGfxInfo.FillClr.ucRed;
	int y = FigGfxInfo.FillClr.ucGreen;
	int z = FigGfxInfo.FillClr.ucBlue;
	int sum = x;
	sum = sum * 1000;
	sum = sum + y;
	sum = sum * 1000;
	sum = sum + z;
	return sum;
}
