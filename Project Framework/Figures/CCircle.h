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
};
