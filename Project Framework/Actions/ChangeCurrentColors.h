#pragma once
#include "ChangeCurrentColors.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Actions\Action.h"



class ChangeCurrentColors :public Action {
	ActionType ActType2;
public:
	ChangeCurrentColors(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
