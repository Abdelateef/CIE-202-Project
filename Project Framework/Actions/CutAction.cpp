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
	else {
		CFigure* FigureList[200];
		pManager->GetFigureList(FigureList);
		for (int i = 0; i < 200; i++) {
			if (FigureList[i] == nullptr) {
				break;
			}
			if (FigureList[i]->IsSelected()) {
				pManager->Copied_FigureList[i] = FigureList[i];
				pManager->MakeFigNull(FigureList[i]);
			}
		}
		for (int i = 0; i < 200; i++) {
			if (pManager->Copied_FigureList[i] != NULL) {
				pOut->PrintMessage("There is some figure is_cut");
			}
		}
	}
}

void CutAction::Execute() {
	ReadActionParameters();
}