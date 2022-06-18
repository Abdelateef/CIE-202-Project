#pragma once
#include"Action.h"

class Load : public Action
{
public:
	Load(ApplicationManager* pApp);
	//static function to perform cloning for any desired figure

	virtual ~Load(void);
	virtual void ReadActionParameters();
	virtual void Execute();
};