#pragma once
#include"Action.h"

class CutAction : public Action
{
public:
	CutAction(ApplicationManager* pApp);
	//static function to perform cloning for any desired figure

	virtual ~CutAction(void);
	virtual void ReadActionParameters();
	virtual void Execute();
};