#include "CCircle.h"
#include "..\ApplicationManager.h"
#include "..\Actions\Action.h"

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
void CCircle::Drawpastfigures(Output* pOut,Point Click) const {

	Point Corner2New;
	Corner2New.y = Click.y;
	Corner2New.x = Click.x + abs(Corner2.x-Corner1.x);
	pOut->DrawCirc(Click, Corner2New, FigGfxInfo, Selected==false);
}

int CCircle::area()
{
	int x = abs(Corner2.x - Corner1.x);
	int area;
	area = 3.14 * x * x;
	return area;
}

int CCircle::radius()
{
	int x = abs(Corner2.x - Corner1.x);
	return x;
}

CFigure* CCircle::Clone(Point click) {
	Point Corner2New;
	Corner2New.y = click.y;
	Corner2New.x = click.x + abs(Corner2.x - Corner1.x);
	CFigure* Temp = new CCircle(click, Corner2New, FigGfxInfo);
	return Temp;
}

int CCircle::x1()
{
	return Corner1.x;
}

int CCircle::x2()
{
	return Corner2.x;
}

int CCircle::y1()
{
	return Corner1.y;
}

int CCircle::y2()
{
	return Corner2.y;
}

void CCircle::drawloadaction(Output* pOut,int arr[])
{
	Point ncorner1, ncorner2;
	ncorner1.x = arr[0];
	ncorner2.x = arr[1];
	ncorner1.y = arr[2];
	ncorner2.y = arr[3];
	pOut->DrawCirc(ncorner1, ncorner2, FigGfxInfo, Selected == false);
}

int CCircle::thirdcornerx()
{
	return -1;
}

int CCircle::thirdcornery()
{
	return -1;
}

int CCircle::objencoded()
{
	return 1;
}


string CCircle::GetName() {
	return "Circle";
}

GfxInfo& CCircle::GetGfxInfo() {
	return FigGfxInfo;
}

int CCircle::getdrawcolour()
{
	int x = FigGfxInfo.DrawClr.ucRed;
	int y = FigGfxInfo.DrawClr.ucGreen;
	int z = FigGfxInfo.DrawClr.ucBlue;
	int sum = x;
	sum = sum * 1000;
	sum = sum+y;
	sum = sum * 1000;
	sum = sum+z;
	return sum;
}

int CCircle::getfillcolour()
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
