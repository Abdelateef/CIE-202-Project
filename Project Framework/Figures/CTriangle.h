#pragma once
#include"CFigure.h"
class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool isWithinMe(Point click);
	virtual void Drawpastfigures(Output* pOut,Point Click) const;
	virtual CFigure* Clone(Point click);
	int area();
	int radius();
	int x1();
	int x2();
	int y1();
	int y2();
	void drawloadaction(Output* pOut,int arr[]);

	virtual string GetName();
};
