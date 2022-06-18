#include "PlayActionFigureType.h"
#include"../ApplicationManager.h"
#include"../Figures/CCircle.h"
#include"../Figures/CLine.h"
#include"../Figures/CRectangle.h"
#include"../Figures/CTriangle.h"

#include"../DEFS.h"

#include"../GUI/Input.h"
#include"../GUI/Output.h"
#include<iostream>
using namespace std;



PlayActionFigureType::PlayActionFigureType(ApplicationManager* pApp) :Action(pApp)
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateUnfilledselected_shape();
}

PlayActionFigureType::~PlayActionFigureType(void)
{}


void PlayActionFigureType::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	if (UI.InterfaceMode == MODE_UNFILL_SHAPES) {
		pOut->PrintMessage("Chose a shape to start play the figure type mode");
		pOut->CreateUnfilledselected_shape();

		int x, y;
		subAction = pIn->GetUserAction(x, y);
	}
}

void PlayActionFigureType::Execute() {
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	setFiguretype();

	if ((pManager->GetFigurecount()) == 0) {
		pOut->PrintMessage("there is no figure are drawn");
		pOut->CreatePlayToolBar();
	}
	else {
		if (pManager->GetNumOfFigType(FigureType) == 0) {
			pOut->PrintMessage("No figure of this type ");
			pOut->CreatePlayToolBar();
		}
		else {
			int CountOFUnfillShape = pManager->GetNumOfFigType(FigureType);
			pOut->PrintMessage("Game started please select unfile" + FigureType + " mode");
			pOut->CreatePlayToolBar();
			const int totalcount = pManager->GetFigurecount();
			const int totall = pManager->GetNumOfFigType(FigureType);
			int succcedcount = 1;
			int wrongcount = 0;
			int j = 0;
			do {
				Input* pIn = pManager->GetInput();
				CFigure* FigureList[200];
				int x, y = 0; // intalize Point clicked
				pIn->GetPointClicked(x, y);
				Point click(x, y);
				pManager->GetFigureList(FigureList);
				for (int i = 0; i < pManager->GetFigurecount(); i++) {
					if (FigureList[i]->GetName() == FigureType) {
						if (FigureList[i]->isWithinMe(click)) {
							FigureTypeList[j] = FigureList[i];
							pOut->PrintMessage("Bravo ....you now selected : " + to_string(succcedcount) + " out of : " + to_string(totall));
							pManager->MakeFigNull(FigureList[i]);
							CountOFUnfillShape--;
							succcedcount++;
							j++;
						}
						else {
							wrongcount++;
							break;

						}
					}

				}

			} while (CountOFUnfillShape != 0);
			if (CountOFUnfillShape == 0) {
				for (int i = 0; i < (succcedcount - 1); i++) {
					if (FigureTypeList[i] != NULL)
						pManager->AddFigure(FigureTypeList[i]);
				}
				pOut->PrintMessage("Pick And Hide : Good job , Correct clicks" + to_string(succcedcount - 1) + ", Wrong clicks : " + to_string(wrongcount));
			}
		}
	}
}

void PlayActionFigureType::setFiguretype() {
	if (subAction == HIDE_CIRC) FigureType = "Circle";
	else if (subAction == HIDE_TRI)FigureType = "Triangle";
	else if (subAction == HIDE_RECT) FigureType = "Rectangle";
	else if (subAction == HIDE_LINE) FigureType = "Line";
}
