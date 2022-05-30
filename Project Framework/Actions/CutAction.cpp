#include"CutAction.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

CutAction::CutAction(ApplicationManager* pApp) :Action(pApp)
{

}

CutAction::~CutAction(void)
{

}


void CutAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	for (int i = 0; i < 200; i++) {
		pManager->Copied_FigureList[i] = NULL;
	}

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetFigurecount() == 0) {
		pOut->PrintMessage("No Figure to Cut!");
	}
		CFigure* FigureList[200];
		pManager->GetFigureList(FigureList);
		for (int i = 0; i < 200; i++) {
			if (FigureList[i] == nullptr) {
				break;
			}
			bool found = 0;
			if (FigureList[i]->IsSelected()) {
				pManager->Copied_FigureList[i] = FigureList[i];
				pManager->MakeFigNull(FigureList[i]);
				found = 1;
			}
			else {
				if (found == 0) {
					pOut->PrintMessage("No figure selected");
				}
			}
		}
		for (int i = 0; i < 200; i++) {
			if (pManager->Copied_FigureList[i] != NULL) {
				pOut->PrintMessage("Cut Action : Figure has been Cut");
			}
		}
	}


void CutAction::Execute() {
	ReadActionParameters();
}