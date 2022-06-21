#include"SelectAction.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{
}

template<typename Base, typename T>
inline bool instanceof(const T* ptr)
{
	return dynamic_cast<const Base*>(ptr) != nullptr;
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
	if (click.y >= UI.ToolBarHeight && click.y < UI.height - UI.StatusBarHeight) {
		for (int i = 0; i < 200; i++) {
			// If there is a figures inside the drawing area, proceed
			if (FigureList[i] != nullptr) {

				if (FigureList[i]->isWithinMe(click))
				{
					if (instanceof<CCircle>(FigureList[i]))
					{
						if (FigureList[i]->IsSelected() == true)
						{
							FigureList[i]->SetSelected(false);
							break;
						}
						pOut->PrintMessage("Circle selected ID is " + to_string(FigureList[i]->objcountreturn()) + " area is " + to_string(FigureList[i]->area()) + " radius is " + to_string(FigureList[i]->radius()));
						FigureList[i]->SetSelected(true);
					}
					else if (instanceof<CTriangle>(FigureList[i]))
					{
						if (FigureList[i]->IsSelected() == true)
						{
							FigureList[i]->SetSelected(false);
							break;
						}
						pOut->PrintMessage("triangle selected    ID is " + to_string(FigureList[i]->objcountreturn()) + " area is " + to_string(FigureList[i]->area()));

					}
					else if (instanceof<CRectangle>(FigureList[i]))
					{

						if (FigureList[i]->IsSelected() == true)
						{
							FigureList[i]->SetSelected(false);
							break;
						}
						pOut->PrintMessage("Rectangle selected || ID is " + to_string(FigureList[i]->objcountreturn()) + " area is " + to_string(FigureList[i]->area()));

					}
					else if (instanceof<CLine>(FigureList[i]))
					{
						if (FigureList[i]->IsSelected() == true)
						{
							FigureList[i]->SetSelected(false);
							break;
						}
						pOut->PrintMessage("Line selected || ID is " + to_string(FigureList[i]->objcountreturn()) + " length is " + to_string(FigureList[i]->area()));

					}
					FigureList[i]->SetSelected(true);

					break;
				}

				else {
					for (int i = 0; i < 200; i++)
					{
						if (FigureList[i] != nullptr)
						{
							if (FigureList[i]->IsSelected() == true)
							{
								break;
							}
							else
							{
								pOut->PrintMessage("Please select a figure");
								FigureList[i]->SetSelected(false);
							}
						}

					}


				}
			}
		}
	}
}


void SelectAction::Execute() {
	ReadActionParameters();
}