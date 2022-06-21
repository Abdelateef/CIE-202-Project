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

	
	CFigure* FigureList[200];
	pManager->GetFigureList(FigureList);

	if (pManager->gettNumofCopied_Figurelist() == 0 || pManager->GetFigurecount() == 0) {
		if (pManager->gettNumofCopied_Figurelist() == 0) {
			pOut->PrintMessage("Paste Figure : NO figure are copied or cut");
		}
		else if (pManager->GetFigurecount() == 0 && pManager->gettNumofCopied_Figurelist() != 0) {
			pOut->PrintMessage("Paste Figure : Clink a point click");
			int x, y = 0;
			pIn->GetPointClicked(x, y);
			Point click(x, y);

			for (int i = 0; i < 200; i++) {

				if (pManager->Copied_FigureList[i] != NULL) {
					CFigure* R = ((pManager->Copied_FigureList[i]));
					CFigure* RR = (pManager->Copied_FigureList[i]->Clone(click));
					R->Drawpastfigures(pOut, click);
					pManager->AddFigure(RR);
				}
			}
			pOut->PrintMessage("Paste Action : Figure has been Pasted");
		}
		else {
			pOut->PrintMessage("Paste Figure : No Figure to paste!");
		}
		}
		else {
			pOut->PrintMessage("Paste Figure : Clink a point click");
			int x, y = 0;
			pIn->GetPointClicked(x, y);
			Point click(x, y);

			for (int i = 0; i < 200; i++) {

				if (pManager->Copied_FigureList[i] != NULL) {
					CFigure* R = ((pManager->Copied_FigureList[i]));
					CFigure* RR = (pManager->Copied_FigureList[i]->Clone(click));
					R->Drawpastfigures(pOut, click);
					pManager->AddFigure(RR);
				}
			}
			pOut->PrintMessage("Paste Action : Figure has been Pasted");
		}
}

	
void PasteAction::Execute() {
	ReadActionParameters();
}