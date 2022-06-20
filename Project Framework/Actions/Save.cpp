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
	int c = 0;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("save selected");
	CFigure* mylist[200];
	pManager->GetFigureList(mylist);
	for (int i = 0; i < 200; i++)
	{
		if (mylist[i]!=nullptr)
		{
			c++;
		}

	}
	ofstream file;
	file.open("file1");
	for (int i = 0; i < c; i++)
	{
		file << mylist[i]->x1()<<endl;
		file << mylist[i]->x2()<<endl;
		file << mylist[i]->y1() << endl;
		file << mylist[i]->y2()<<endl;
		file << mylist[i]->GetName() << endl;
	}
	file.close();
}
