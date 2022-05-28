#ifndef CRECT_H
#define CRECT_H
#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool isWithinMe(Point click);
	virtual CFigure* Clone();
	//virtual void Drawpastefigures(Point click) const;
};

#endif