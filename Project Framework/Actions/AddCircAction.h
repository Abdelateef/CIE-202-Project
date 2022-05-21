#pragma once

#include "Action.h"

//Add Circle Action class
class AddCircAction : public Action
{
private:
	Point P1, P2; //Circle Corners
	GfxInfo CircGfxInfo;
public:
	AddCircAction(ApplicationManager *pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();
	
	//Add Circle to the ApplicationManager
	virtual void Execute() ;
	
};