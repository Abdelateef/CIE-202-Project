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

void CLine::Drawpastfigures(Output* pOut,Point Click) const {
	Point NewCorner1, NewCorner2 , MidlePoint;
	MidlePoint.x = ((Corner1.x + Corner2.x) / 2);
	MidlePoint.y = ((Corner1.y + Corner2.y) / 2);
	int pointxdistance, Pointydistance;
	pointxdistance = (MidlePoint.x - Corner1.x);
	Pointydistance = (MidlePoint.y - Corner1.y);
	NewCorner1.x = Click.x - (pointxdistance);
	NewCorner1.y = Click.y - (Pointydistance);
	NewCorner2.x = Click.x + (pointxdistance);
	NewCorner2.y = Click.y + (Pointydistance);

	pOut->DrawLine(NewCorner1, NewCorner2, FigGfxInfo, Selected==false);
}

int CLine::area()
{
	int x = abs(Corner2.x - Corner1.x);

	return x;
}

int CLine::radius()
{
	int x = abs(Corner2.x - Corner1.x);
	return x;
}

CFigure* CLine::Clone(Point click) {
	
	Point NewCorner1, NewCorner2, MidlePoint;
	MidlePoint.x = ((Corner1.x + Corner2.x) / 2);
	MidlePoint.y = ((Corner1.y + Corner2.y) / 2);
	int pointxdistance, Pointydistance;
	pointxdistance = (MidlePoint.x - Corner1.x);
	Pointydistance = (MidlePoint.y - Corner1.y);
	NewCorner1.x = click.x - (pointxdistance);
	NewCorner1.y = click.y - (Pointydistance);
	NewCorner2.x = click.x + (pointxdistance);
	NewCorner2.y = click.y + (Pointydistance);
	
	
	CFigure* Temp = new CLine(NewCorner1, NewCorner2, FigGfxInfo);
	return Temp;
}

int CLine::x1()
{
	return Corner1.x;
}

int CLine::x2()
{
	return Corner2.x;
}

int CLine::y1()
{
	return Corner1.y;
}

int CLine::y2()
{
	return Corner2.y;
}

void CLine::drawloadaction(Output* pOut,int arr[])
{
}

int CLine::thirdcornerx()
{
	return -1;
}

int CLine::thirdcornery()
{
	return -1;
}

int CLine::objencoded()
{
	return 2;
}

string CLine::GetName() {
	return "Line";
}

color CLine::Getcolor() {
	if (FigGfxInfo.isFilled)
	return FigGfxInfo.FillClr;
}


GfxInfo& CLine::GetGfxInfo() {
	return FigGfxInfo;
}

int CLine::getdrawcolour()
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

int CLine::getfillcolour()
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