#pragma once
#include"Action.h"
#include "../Figures/\CFigure.h"
class PlayActionFigureFillColor : public Action {
private:
	color Figurecolor;
	string Figurecolorr;
	ActionType subAction;
public:
	CFigure* FigureTypeList[200];
	PlayActionFigureFillColor(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~PlayActionFigureFillColor(void);
	void setFiguretype();
};