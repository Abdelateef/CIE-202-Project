#include "PlayActionFigureType_FillColor.h"
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



PlayActionFigureType_FillColor::PlayActionFigureType_FillColor(ApplicationManager* pApp) :Action(pApp)
{
	Output* pOut = pManager->GetOutput();
	pOut->Createfilledselected_shape();
}
PlayActionFigureType_FillColor::~PlayActionFigureType_FillColor(void)
{}


void PlayActionFigureType_FillColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	if (UI.InterfaceMode == MODE_FILL_SHAPES) {
		pOut->PrintMessage("Chose a shape to start play game");
		pOut->Createfilledselected_shape();

		int x, y;
		
		subAction1 = pIn->GetUserAction(x, y);
		pOut->PrintMessage("Chose a Color of fiile shape to start play game");
		subAction2 = pIn->GetUserAction(x, y);
	}
}

void PlayActionFigureType_FillColor::Execute() {
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	setFiguretype();
	setFigurecolor();

	if ((pManager->GetFigurecount()) == 0) {
		pOut->PrintMessage("there is no figure are drawn");
		pOut->CreatePlayToolBar();
	}
	else {
		if (pManager->GetnumOfFigsametypecolor(FigureType,Figurecolor) == 0) {
			pOut->PrintMessage("No figure of this type ");
			pOut->CreatePlayToolBar();
		}
		else {
			int CountOFUnfillShape = pManager->GetnumOfFigsametypecolor(FigureType,Figurecolor);
			pOut->PrintMessage("Game started please select file " + FigureType + "shape with " + Figurecolorr);
			pOut->CreatePlayToolBar();
			const int totalcount = pManager->GetFigurecount();
			const int totall = pManager->GetnumOfFigsametypecolor(FigureType, Figurecolor);
			int succcedcount = 1;
			int wrongcount = 0;
			int j = 0;
			bool RestartFound = false;
			bool SwitchToDrawModeFound = false;
			do {
				Input* pIn = pManager->GetInput();
				CFigure* FigureList[200];
				int x, y = 0; // intalize Point clicked
				pIn->GetPointClicked(x, y);
				bool ClickFound = false;
				Point click(x, y);
				pManager->GetFigureList(FigureList);
				for (int i = 0; i < pManager->GetFigurecount(); i++) {
					if (FigureList[i]->GetName() == FigureType &&
						FigureList[i]->GetGfxInfo().isFilled == true && 
						Figurecolor.ucRed == FigureList[i]->GetGfxInfo().FillClr.ucRed &&
						Figurecolor.ucGreen == FigureList[i]->GetGfxInfo().FillClr.ucGreen &&
						Figurecolor.ucBlue == FigureList[i]->GetGfxInfo().FillClr.ucBlue) {
						if (FigureList[i]->isWithinMe(click)) {
							FigureTypeList[j] = FigureList[i];
							pOut->PrintMessage("Bravo ....you now selected : " + to_string(succcedcount) + " out of : " + to_string(totall));
							pManager->MakeFigNull(FigureList[i]);
							CountOFUnfillShape--;
							succcedcount++;
							ClickFound = true;
							j++;
							break;
						}
					}
				}
				if (!ClickFound) wrongcount += 1;
				if (click.y >= 0 && click.y < UI.ToolBarHeight && (click.x / UI.MenuItemWidth) == 4) {
					RestartFound = true;
				}
				if (click.y >= 0 && click.y < UI.ToolBarHeight && (click.x / UI.MenuItemWidth) == 0) {
					SwitchToDrawModeFound = true;
				}
			} while (CountOFUnfillShape != 0 && RestartFound == false && SwitchToDrawModeFound == false);
			if (CountOFUnfillShape == 0) {
				for (int i = 0; i < (succcedcount - 1); i++) {
					if (FigureTypeList[i] != NULL)
						pManager->AddFigure(FigureTypeList[i]);
				}
				pOut->PrintMessage("Pick And Hide : Good job , Correct clicks" + to_string(succcedcount - 1) + ", Wrong clicks : " + to_string(wrongcount));
			}
			else if (RestartFound == true) {
				for (int i = 0; i < (succcedcount - 1); i++) {
					if (FigureTypeList[i] != NULL)
						pManager->AddFigure(FigureTypeList[i]);
					pOut->PrintMessage("you had Restart the game ");
				}
			}
			else if (SwitchToDrawModeFound == true) {
				for (int i = 0; i < (succcedcount - 1); i++) {
					if (FigureTypeList[i] != NULL)
						pManager->AddFigure(FigureTypeList[i]);
					pOut->PrintMessage("you had Switch to Draw Mode");
					pOut->CreateDrawToolBar();
				}
			}
		}
	}
}

void PlayActionFigureType_FillColor::setFiguretype() {
	if (subAction1 == HIDE_CIRC) FigureType = "Circle";
	else if (subAction1 == HIDE_TRI)FigureType = "Triangle";
	else if (subAction1 == HIDE_RECT) FigureType = "Rectangle";
	else if (subAction1 == HIDE_LINE) FigureType = "Line";
}

void PlayActionFigureType_FillColor::setFigurecolor() {
		if (subAction2 == SET_BLACK) { Figurecolor = BLACK; Figurecolorr = "Black"; }
		else if (subAction2 == SET_WHITE) { Figurecolor = WHITE; Figurecolorr = "White"; }
		else if (subAction2 == SET_RED) { Figurecolor = RED; Figurecolorr = "Red"; }
		else if (subAction2 == SET_GREEN) { Figurecolor = GREEN; Figurecolorr = "Green"; }
		else if (subAction2 == SET_BLUE) { Figurecolor = BLUE; Figurecolorr = "Blue"; }

}
