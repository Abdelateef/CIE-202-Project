#include "AddTriaAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriaAction::AddTriaAction(ApplicationManager * pApp):Action(pApp)
{}

void AddTriaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");
	bool point1found = false;
	do {
		pIn->GetPointClicked(P1.x, P1.y);//Read 1st corner and store in point P1
		if (P1.y >= UI.ToolBarHeight && P1.y < UI.height - UI.StatusBarHeight) {
			pOut->PrintMessage("New Triangle: Click at second corner");
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
					pOut->PrintMessage("New Triangle: Click at third corner");
					point2found = true;
				}
				else {
					pOut->PrintMessage("point two is out of Drawing area range , please reenter point two");
				}
				if (point2found == true) {
					bool point3found = false;
					do {
						pIn->GetPointClicked(P3.x, P3.y);//Read 2nd corner and store in point P3
						if (P3.y >= UI.ToolBarHeight && P3.y < UI.height - UI.StatusBarHeight) {
							point3found = true;
							if (UI.filled_OR_not) //default is not filled
								TriaGfxInfo.isFilled = true;
							else
								TriaGfxInfo.isFilled = false;
							//get drawing, filling colors and pen width from the interface
							TriaGfxInfo.DrawClr = pOut->getCrntDrawColor();
							TriaGfxInfo.FillClr = pOut->getCrntFillColor();
							TriaGfxInfo.BorderWdth = pOut->getCrntPenWidth();

							pOut->ClearStatusBar();
						}
						else {
							pOut->PrintMessage("point three is out of Drawing area range , please reenter point three");
						}
					} while (point3found == false);
				}
			} while (point2found == false);
		}
	} while (point1found == false);

}

//Execute the action
void AddTriaAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Triangle with the parameters read from the user
	CTriangle* R = new CTriangle(P1, P2, P3, TriaGfxInfo);

	//Add the Triangle to the list of figures
	pManager->AddFigure(R);
}
