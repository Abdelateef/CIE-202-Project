#include "AddCircAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager * pApp):Action(pApp)
{}

void AddCircAction::ReadActionParameters()
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at second corner (take care the radius will be the difference in x coordinates of two corners)");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	if (UI.filled_OR_not) //default is not filled
		CircGfxInfo.isFilled = true;
	else
		CircGfxInfo.isFilled = false;
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	CircGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a Circle with the parameters read from the user
	CCircle *R=new CCircle(P1, P2, CircGfxInfo);

	//Add the Line to the list of figures
	pManager->AddFigure(R);
}
