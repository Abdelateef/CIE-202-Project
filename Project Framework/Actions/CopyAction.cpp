#include"CopyAction.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"..\Figures\CCircle.h"

CopyAction::CopyAction(ApplicationManager* pApp) :Action(pApp)
{

}

template<typename Base, typename T>
inline bool instanceof(const T* ptr)
{
	return dynamic_cast<const Base*>(ptr) != nullptr;
}

CopyAction::~CopyAction(void)
{

}


void CopyAction::ReadActionParameters() {
	////Get a Pointer to the Input / Output Interfaces
	for(int i = 0; i < 200; i++) {
		pManager->Copied_FigureList[i] = NULL;
	}
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetFigurecount() == 0 ) {
		pOut->PrintMessage("Copy Action : No Figure to Copy!");
	}
		CFigure* FigureList[200];
		pManager->GetFigureList(FigureList);
		for (int i = 0; i < 200; i++) {
			if (FigureList[i] == nullptr) {
				break;
			}
			bool found = 0;
			if (FigureList[i]->IsSelected()) {
				pManager->Copied_FigureList[i] = FigureList[i];
				pManager->SetNumofCopied_Figurelist(pManager->Copied_FigureList[i]);
				found = 1;
			}
			else {
				if (found == 0) {
					pOut->PrintMessage("Copy Action : No Figure Selected!");
				}
			}
		}
		for (int i = 0 ; i <200 ; i++){
			if (pManager->Copied_FigureList[i] != NULL) {
				pOut->PrintMessage("Copy Action : Figure has been copied");
			}
	}
}


void CopyAction::Execute() {
	ReadActionParameters();
}