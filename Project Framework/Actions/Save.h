#pragma once

#include "Action.h"

//Add Circle Action class
class Save : public Action
{
public:
	Save(ApplicationManager* pApp);
	
	virtual ~Save(void);
	
	virtual void ReadActionParameters();
	
	
	virtual void Execute() ;
	
};