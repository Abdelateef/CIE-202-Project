#pragma once

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CCircle(Point ,Point , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool isWithinMe(Point click);
	virtual void Drawpastfigures(Output* pOut,Point Click) const;
	virtual CFigure* Clone(Point click);
	
};
