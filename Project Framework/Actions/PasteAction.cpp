#include"PasteAction.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <iostream>  
#include<string>

PasteAction::PasteAction(ApplicationManager* pApp) :Action(pApp)
{

}


PasteAction::~PasteAction(void)
{

}
void PasteAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int x,y=0;
	pIn->GetPointClicked(x, y);
	Point click(x, y);
	CFigure* FigureList[200];
	pManager->GetFigureList(FigureList);

	for (int i = 0; i <200 ; i++) {

		if (pManager->Copied_FigureList[i] != NULL) {
			CFigure* R = (pManager->Copied_FigureList[i]);
			R->Drawpastefigures(click);
		}
	}
	string Outputt = to_string(pManager->GetFigurecount());
	pOut->PrintMessage(Outputt);
}
void PasteAction::Execute() {
	ReadActionParameters();
}