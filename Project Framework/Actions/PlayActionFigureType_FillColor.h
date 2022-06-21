#pragma once
#include"Action.h"
#include "../Figures/\CFigure.h"
class PlayActionFigureType_FillColor : public Action {
private:
	color Figurecolor;
	string Figurecolorr;
	string FigureType;
	ActionType subAction1;
	ActionType subAction2;
public:
	CFigure* FigureTypeList[200];
	PlayActionFigureType_FillColor(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~PlayActionFigureType_FillColor(void);
	void setFiguretype();
	void setFigurecolor();
};