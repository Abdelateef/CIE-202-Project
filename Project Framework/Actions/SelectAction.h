#pragma once
#include"Action.h"

class SelectAction : public Action
{
public:
	SelectAction(ApplicationManager* pApp);

	virtual ~SelectAction(void);
	virtual void ReadActionParameters();
	virtual void Execute();
};