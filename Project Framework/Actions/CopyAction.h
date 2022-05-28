#pragma once
#include"Action.h"

class CopyAction : public Action
{
public:
	CopyAction(ApplicationManager* pApp);
	//static function to perform cloning for any desired figure
	virtual ~CopyAction(void);
	virtual void ReadActionParameters();
	virtual void Execute();
};