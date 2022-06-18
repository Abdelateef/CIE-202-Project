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
	
	CFigure* mylist = nullptr;
	int x, arr[4], i = 0;
	/*pManager->GetFigureList(mylist);*/
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("load selected");
	ifstream infile;
	infile.open("D:\\github c++\\CIE-202-Project\\Project Framework\\file1");
	if (!infile)
	{
		pOut->PrintMessage("unable to open file");
	}
	while (infile >> x)
	{
		arr[i] = x;
		i++;
	}
	Point Corner1, Corner2;
	Corner1.x = arr[0];
	Corner1.y = arr[2];
	Corner2.x = arr[1];
	Corner2.y = arr[3];
	GfxInfo circle;
	CCircle* test = new CCircle(Corner1, Corner2, circle);
	pManager->AddFigure(test);
	pOut->DrawCirc(Corner1, Corner2, circle);
	infile.close();
}


void Load::Execute() 
{
	ReadActionParameters();
}