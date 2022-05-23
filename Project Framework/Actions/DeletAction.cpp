#include"DeletAction.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeletAction::DeletAction(ApplicationManager* pApp) :Action(pApp)
{

}


DeletAction::~DeletAction(void)
{

}
void DeletAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->GetFigurecount() == 0){
		pOut->PrintMessage("No Figure to delete!");
	}
	else {
				CFigure* FigureList[200];
		pManager->GetFigureList(FigureList);
		for (int i = 0; i < 200; i++) {
			if (FigureList[i] == nullptr) {
				break;
			}
			if (FigureList[i]->IsSelected()) {
				pManager->MakeFigNull(FigureList[i]);
			}
		}

	}


}

void DeletAction::Execute() {
	ReadActionParameters();
}