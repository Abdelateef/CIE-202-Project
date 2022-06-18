#pragma once
#include"Action.h"
#include "../Figures/\CFigure.h"
class PlayActionFigureType : public Action {
private:
	string FigureType;
	ActionType subAction;
public:
	CFigure* FigureTypeList[200];
	PlayActionFigureType(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~PlayActionFigureType(void);
	void setFiguretype();
};