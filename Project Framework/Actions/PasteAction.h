#pragma once
#include"Action.h"
#include"CopyAction.h"

class PasteAction : public Action
{
public:
	PasteAction(ApplicationManager* pApp);

	virtual ~PasteAction(void);
	virtual void ReadActionParameters();
	virtual void Execute();
};