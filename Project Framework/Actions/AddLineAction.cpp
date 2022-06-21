#include "AddLineAction.h"
#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager * pApp):Action(pApp)
{}

void AddLineAction::ReadActionParameters()
{	
		//Get a Pointer to the Input / Output Interfaces
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();

		pOut->PrintMessage("New Line: Click at first corner");
		bool point1found = false;
		do {
			pIn->GetPointClicked(P1.x, P1.y);//Read 1st corner and store in point P1
			if (P1.y >= UI.ToolBarHeight && P1.y < UI.height - UI.StatusBarHeight) {
				pOut->PrintMessage("New Line: Click at second corner");
				point1found = true;
			}
			else {
				pOut->PrintMessage("point one is out of Drawing area range , please reenter point one");
			}
			if (point1found == true) {
				bool point2found = false;
				do
				{
					pIn->GetPointClicked(P2.x, P2.y);//Read 2nd corner and store in point P2
					if (P2.y >= UI.ToolBarHeight && P2.y < UI.height - UI.StatusBarHeight) {
						//Read 2nd corner and store in point P2
						point2found = true;
						if (UI.filled_OR_not) //default is not filled
							LineGfxInfo.isFilled = true;
						else
							LineGfxInfo.isFilled = false;
						//get drawing, filling colors and pen width from the interface
						LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
						LineGfxInfo.FillClr = pOut->getCrntFillColor();
						LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();

						pOut->ClearStatusBar();
					}
					else {
						pOut->PrintMessage("point two is out of Drawing area range , please reenter point two");
					}

				} while (point2found == false);
			}
		} while (point1found == false);
}

//Execute the action
void AddLineAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CLine *R=new CLine(P1, P2, LineGfxInfo);

	//Add the Line to the list of figures
	pManager->AddFigure(R);
}
