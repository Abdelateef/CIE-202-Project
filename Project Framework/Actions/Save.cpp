#include "Save.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <fstream>




Save::Save(ApplicationManager* pApp): Action(pApp)
{

}

Save::~Save(void)
{

}

void Save::ReadActionParameters()
{
	
}

void Save::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("save selected");
	CFigure* mylist[200];
	pManager->GetFigureList(mylist);
	ofstream file;
	file.open("file1");
	for (int i = 0; i < 1; i++)
	{
		file << mylist[i]->x1();
		file << mylist[i]->x2();
		file << mylist[i]->y1();
		file << mylist[i]->y2();
	}
	file.close();
}
