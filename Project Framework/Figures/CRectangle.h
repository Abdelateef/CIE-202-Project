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
	int area();
	int radius();
	virtual CFigure* Clone(Point click) ;
	int x1();
	int x2();
	int y1();
	int y2();
	void drawloadaction(Output* pOut,int arr[]);
<<<<<<< Updated upstream
	int thirdcornerx();
	int thirdcornery();
	


	virtual string GetName();
	virtual color Getcolor();
	GfxInfo& GetGfxInfo();

	int objencoded();

=======
	virtual string GetName();
	virtual color Getcolor();
	GfxInfo& GetGfxInfo();
>>>>>>> Stashed changes
};

#endif