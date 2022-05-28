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
	virtual void Drawpastfigures(Output* pOut,Point Click) const ;
	virtual CFigure* Clone(Point click) ;

};

#endif