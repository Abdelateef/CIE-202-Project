#include"SelectAction.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"


#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{
}


SelectAction::~SelectAction(void)
{

}
void SelectAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	int x, y = 0; // intalize Point clicked
	pIn->GetPointClicked(x, y);
	Point click(x, y);
	CFigure* FigureList[200];
	pManager->GetFigureList(FigureList);
	
	
	for (int i = 0; i < 200; i++) {
		// If there is a figures inside the drawing area, proceed
		if (FigureList[i] != nullptr) {

			if (FigureList[i]->isWithinMe(click)) {
				
				pOut->PrintMessage("Figure: Selected");
			}
			else {
				pOut->PrintMessage("Figure: Selecteddvfkdfvkpf");
			}
		}
	}
}

void SelectAction::Execute() {
	ReadActionParameters();
}