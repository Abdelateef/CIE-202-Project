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
	CFigure* Copied_FigureList =NULL ;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetFigurecount() == 0 ) {
		pOut->PrintMessage("No Figure to Copy!");
	}
	else {

		CFigure* FigureList[200];
		pManager->GetFigureList(FigureList);
		for (int i = 0; i < 200; i++) {
			if (FigureList[i] == nullptr) {
				break;
			}
			if (FigureList[i]->IsSelected()) {
				Copied_FigureList = FigureList[i];
				pManager->MakeFigNull(FigureList[i]);
			}
		}
		if (Copied_FigureList != NULL) {
			pOut->PrintMessage("There is some figure is_cut");
	}
	}
}

void CutAction::Execute() {
	ReadActionParameters();
}