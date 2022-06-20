#include "Load.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCircle.h"
#include "..\\Figures\CRectangle.h"
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
	Point Corner1, Corner2;
	int x, i = 0, c1 = 0, c2 = 2, c3 = 1, c4 = 3, arrcounter = 0;
	int* arr = new int[i];
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("load selected");
	ifstream infile;
	infile.open("file1");
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
	for (int i = 0; i < arrcounter; i++)
	{
		Corner1.x = arr[c1];
		Corner1.y = arr[c2];
		Corner2.x = arr[c3];
		Corner2.y = arr[c4];
		GfxInfo circle;
		circle.isFilled = false;
		circle.BorderWdth = pOut->getCrntPenWidth();
		circle.DrawClr = pOut->getCrntDrawColor();
		circle.FillClr = pOut->getCrntFillColor();
		CCircle* test = new CCircle(Corner1, Corner2, circle);
		pManager->AddFigure(test);
		c1 = c1 + 4;
		c2 = c2 + 4;
		c3 = c3 + 4;
		c4 = c4 + 4;
		if (c4>arrcounter)
		{
			break;
		}
	}
	c1 = 0, c2 = 2, c3 = 1, c4 = 3;
}


void Load::Execute() 
{
	ReadActionParameters();
}