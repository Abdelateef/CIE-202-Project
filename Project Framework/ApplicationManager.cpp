#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddTriaAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddCircAction.h"
#include"Actions\SelectAction.h"
#include "Actions\DeletAction.h"
#include "Actions\ChangeCurrentColors.h"
#include"Actions/CopyAction.h"
#include"Actions/PasteAction.h"
#include"Actions/CutAction.h"
#include "Actions\ChangeFigureColors.h"
#include "Actions/Save.h"
#include "Actions/Load.h"
#include"Actions/PlayActionFigureType.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	int x, y;
	//Ask the input to get the action from the user.
	return pIn->GetUserAction(x,y);
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{

	case DRAW_LINE:
		pAct = new AddLineAction(this);
		break;
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;
	case DRAW_TRI:
		pAct = new AddTriaAction(this);
		break;
	case DRAW_CIRC:
		pAct = new AddCircAction(this);
		break;
	case SELECT:
		pAct = new SelectAction(this);
		break;
	case DEL:
		pAct = new DeletAction(this);
		break;
	case COPY:
		pAct = new CopyAction(this);
		break;
	case CUT:
		pAct = new CutAction(this);
		break;
	case PASTE:
		pAct = new PasteAction(this);
		break;
	case SAVE:
		pAct = new Save(this);
		break;
	case LOAD:
		pAct = new Load(this);
	case Wid_SIZE:
		UI.InterfaceMode = MODE_SIZE;
		pOut->CreateSizeToolBar();
		break;
	case SET_tiny:
		UI.PenWidth = 2;
		pOut->CreateDrawToolBar();
		break;
	case SET_Normal:
		UI.PenWidth = 4;
		pOut->CreateDrawToolBar();
		break;
	case SET_BACK:
		pOut->CreateDrawToolBar();
		break;
	case SET_Large:
		UI.PenWidth = 9;
		pOut->CreateDrawToolBar();
		break;
	case CHNG_DRAW_CLR:
		UI.InterfaceMode = MODE_DRAW_COLOR;
		pAct = new ChangeCurrentColors(this);
		break;
	case TO_PLAY:
		pOut->CreatePlayToolBar();
		break;
	case TO_DRAW:
		pOut->CreateDrawToolBar();
		break;
	case HIDE_UNFILL_SHAPE:
		pAct = new PlayActionFigureType(this);
		break;
	case HIDE_SMAE_COLOR:
		pOut->Createsamecoloredselected_shape();
		break;
	case HIDE_FILL_SHAPE:
		pOut->Createfilledselected_shape();
		break;
	case CHNG_FILL_CLR:
		if (SelectedFig.size() != 0)
		{
			pAct = new ChangeFigureColors(this, MODE_FILL_COLOR);
			break;
		}
		else
		{
			pOut->CreateColorToolBar(0);
			pAct = new ChangeCurrentColors(this);
			break;
		}

	case EXIT:
		///create ExitAction here

		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	///Add your code here to search for a figure given a point x,y	

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}

/////////////////////////////////////////////////////////////////
void  ApplicationManager::GetFigureList(CFigure* FigureListNew[]) {
	for (int i = 0; i < MaxFigCount; i++) {
		FigureListNew[i] = FigList[i];
	}
}


int ApplicationManager::GetFigurecount() {
	return FigCount;
}

/////////////////////////

void ApplicationManager::MakeFigNull(CFigure* fig) {
	bool found = 0;
	for (int i = 0; i < MaxFigCount; i++) {
		if (FigList[i] == fig) {
			FigList[i] = nullptr;
			found = 1;
		}
		if (found && i + 1 != MaxFigCount) {
			FigList[i] = FigList[i + 1];
		}
	}
		FigCount--;
		pOut->ClearDrawArea();
		UpdateInterface();

}
 
int ApplicationManager::GetNUmOfSelectedFig()const
{
	return SelectedFig.size();
}
/////////////////////////////////////////////
CFigure* ApplicationManager::GetSelectedFigure(int i)const
{
	return SelectedFig[i];
}
void ApplicationManager::CansSelectedFigure(CFigure* Figure)
{
	for (int i = 0; i < SelectedFig.size(); i++)
	{
		if (SelectedFig[i] == Figure)
		{
			SelectedFig.erase(SelectedFig.begin() + i);
			break;
		}
	}
}





/////////////////
int ApplicationManager::GetNumOfFigType(string figtype) {
	int cnt = 0;
	for (int i = 0; i < GetFigurecount(); i++) {
		if (figtype == (FigList[i]->GetName())) {
			cnt++;
		}
	}
	return cnt;
}



//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}