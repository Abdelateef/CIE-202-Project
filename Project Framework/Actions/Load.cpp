#include "Load.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCircle.h"
#include "..\\Figures\CRectangle.h"
#include "..\\Figures\CLine.h"
#include "..\\Figures\CTriangle.h"
#include <fstream>
using namespace std;

Load::Load(ApplicationManager* pApp) :Action(pApp)
{

}

Load::~Load(void)
{

}

template<typename Base, typename T>
inline bool instanceof(const T* ptr)
{
	return dynamic_cast<const Base*>(ptr) != nullptr;
}


void Load::ReadActionParameters()
{
	CFigure* mylist[200];
	pManager->GetFigureList(mylist);
	for (int i = 0; i < 200; i++)
	{
		if (mylist[i]!=nullptr)
		{
			pManager->MakeFigNull(mylist[i]);
		}

	}
	Point Corner1, Corner2, Corner3;
	int x, i = 0, c1 = 0, c2 = 2, c3 = 1, c4 = 3, c5=4, c6=4, c7=5, c8=5,c9=6, arrcounter = 0, r, g, b, test, drawcolourtriangle=7, fillcolourtriangle=8, rf, gf, bf, testf;
	string y;
	int* arr = new int[i];
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Load selected. Please enter file name to load from");
	ifstream infile;
	infile.open(pIn->GetSrting(pOut));
	if (!infile)
	{
		pOut->PrintMessage("unable to open file");
	}
	while (infile >> x)
	{
		arr[i] = x;
		i++;
		arrcounter++;
	}
	for (int i = 0; i < arrcounter ; i++)
	{
		if (arr[i] == 1)
		{
			Corner1.x = arr[c1];
			Corner1.y = arr[c2];
			Corner2.x = arr[c3];
			Corner2.y = arr[c4];
			test = arr[c8];
			b = test % 1000;
			test = test / 1000;
			g = test % 1000;
			test = test / 1000;
			r = test;
			color loaddrawcolour = color(r, g, b);
			GfxInfo circle;
			if (arr[c9] == 190190190)
			{
				circle.isFilled = false;
				
				circle.FillClr = pOut->getCrntFillColor();
			}
			else
			{
				circle.isFilled = true;
				test = arr[c9];
				b = test % 1000;
				test = test / 1000;
				g = test % 1000;
				test = test / 1000;
				r = test;
				color loadfillcolour = color(r, g, b);
				
				circle.FillClr = loadfillcolour;
			}
			
			circle.BorderWdth = pOut->getCrntPenWidth();
			circle.DrawClr = loaddrawcolour;
			
			CCircle* test = new CCircle(Corner1, Corner2, circle);
			pManager->AddFigure(test);
			c1 = c1 + 7;
			c2 = c2 + 7;
			c3 = c3 + 7;
			c4 = c4 + 7;
			c5 = c5 + 7;
			c6 = c6 + 7;
			c7 = c7 + 7;
			c8 = c8 + 7;
			c9 = c9 + 7;
			drawcolourtriangle = drawcolourtriangle + 7;
			fillcolourtriangle = fillcolourtriangle + 7;
			if (c4 > arrcounter)
			{
				break;
			}
		}
		if (arr[i]==2)
		{
			
			Corner1.x = arr[c1];
			Corner1.y = arr[c2];
			Corner2.x = arr[c3];
			Corner2.y = arr[c4];
			test = arr[c8];
			b = test % 1000;
			test = test / 1000;
			g = test % 1000;
			test= test / 1000;
			r = test;
			color loaddrawcolour = color(r, g, b);
			GfxInfo circle;
			circle.isFilled = false;
			circle.BorderWdth = pOut->getCrntPenWidth();
			circle.DrawClr = loaddrawcolour;
			circle.FillClr = pOut->getCrntFillColor();
			CLine* test = new CLine(Corner1, Corner2, circle);
			pManager->AddFigure(test);
			c1 = c1 + 7;
			c2 = c2 + 7;
			c3 = c3 + 7;
			c4 = c4 + 7;
			c5 = c5 + 7;
			c6 = c6 + 7;
			c7 = c7 + 7;
			c8 = c8 + 7;
			drawcolourtriangle = drawcolourtriangle + 7;
			fillcolourtriangle = fillcolourtriangle + 7;
			if (c4 > arrcounter)
			{
				break;
			}
		}
		if (arr[i]==3)
		{
			Corner1.x = arr[c1];
			Corner1.y = arr[c2];
			Corner2.x = arr[c3];
			Corner2.y = arr[c4];
			test = arr[c8];
			b = test % 1000;
			test = test / 1000;
			g = test % 1000;
			test = test / 1000;
			r = test;
			color loaddrawcolour = color(r, g, b);
			GfxInfo circle;
			if (arr[c9]== 190190190)
			{
				circle.isFilled = false;
				circle.BorderWdth = pOut->getCrntPenWidth();
				circle.FillClr = pOut->getCrntFillColor();
			}
			else
			{
				circle.isFilled = true;
				test = arr[c9];
				b = test % 1000;
				test = test / 1000;
				g = test % 1000;
				test = test / 1000;
				r = test;
				color loadfillcolour = color(r, g, b);
				circle.BorderWdth = pOut->getCrntPenWidth();
				circle.FillClr = loadfillcolour;
			}
			circle.DrawClr = loaddrawcolour;
			CRectangle* test = new CRectangle(Corner1, Corner2, circle);
			pManager->AddFigure(test);
			c1 = c1 + 7;
			c2 = c2 + 7;
			c3 = c3 + 7;
			c4 = c4 + 7;
			c5 = c5 + 7;
			c6 = c6 + 7;
			c7 = c7 + 7;
			c8 = c8 + 7;
			c9 = c9 + 7;
			drawcolourtriangle = drawcolourtriangle + 7;
			fillcolourtriangle = fillcolourtriangle + 7;
			if (c4 > arrcounter)
			{
				break;
			}
		}
		if (arr[i]==4)
		{
			Corner1.x = arr[c1];
			Corner1.y = arr[c2];
			Corner2.x = arr[c3];
			Corner2.y = arr[c4];
			Corner3.x = arr[c6];
			Corner3.y = arr[c7];
			test = arr[drawcolourtriangle];
			b = test % 1000;
			test = test / 1000;
			g = test % 1000;
			test = test / 1000;
			r = test;
			color loaddrawcolour = color(r, g, b);
			GfxInfo circle;
			if (arr[fillcolourtriangle] == 190190190)
			{
				circle.isFilled = false;
				circle.BorderWdth = pOut->getCrntPenWidth();
				circle.FillClr = pOut->getCrntFillColor();
			}
			else
			{
				circle.isFilled = true;
				test = arr[fillcolourtriangle];
				b = test % 1000;
				test = test / 1000;
				g = test % 1000;
				test = test / 1000;
				r = test;
				color loadfillcolour = color(r, g, b);
				circle.BorderWdth = pOut->getCrntPenWidth();
				circle.FillClr = loadfillcolour;
			}
			
			
			circle.DrawClr = loaddrawcolour;
			CTriangle* test = new CTriangle(Corner1, Corner2,Corner3, circle);
			pManager->AddFigure(test);
			c1 = c1 + 9;
			c2 = c2 + 9;
			c3 = c3 + 9;
			c4 = c4 + 9;
			c5 = c5 + 9;
			c6 = c6 + 9;
			c7 = c7 + 9;
			c8 = c8 + 9;
			c9 = c9 + 9;
			drawcolourtriangle = drawcolourtriangle + 9;
			fillcolourtriangle = fillcolourtriangle + 9;
			if (c4 > arrcounter)
			{
				break;
			}
		}
	}
	
	
	c1 = 0, c2 = 2, c3 = 1, c4 = 3;
}


void Load::Execute() 
{
	ReadActionParameters();
}