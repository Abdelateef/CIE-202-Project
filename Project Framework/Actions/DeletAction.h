#pragma once
#include"Action.h"

class DeletAction : public Action
{
public:
	DeletAction(ApplicationManager* pApp);

	virtual ~DeletAction(void);
	virtual void ReadActionParameters();
	virtual void Execute();
};