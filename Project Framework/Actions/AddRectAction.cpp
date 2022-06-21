#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
	{
		//Get a Pointer to the Input / Output Interfaces
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();

		pOut->PrintMessage("New Rectangle: Click at first corner");
		bool point1found = false;
		do {
			pIn->GetPointClicked(P1.x, P1.y);//Read 1st corner and store in point P1
			if (P1.y >= UI.ToolBarHeight && P1.y < UI.height - UI.StatusBarHeight) {
				pOut->PrintMessage("New Rectangle: Click at second corner");
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
						point2found = true;
						if (UI.filled_OR_not) //default is not filled
							RectGfxInfo.isFilled = true;
						else
							RectGfxInfo.isFilled = false;
						//get drawing, filling colors and pen width from the interface
						RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
						RectGfxInfo.FillClr = pOut->getCrntFillColor();
						RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();

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
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
