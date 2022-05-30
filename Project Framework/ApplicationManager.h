#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include <vector>
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];//Pointers to Input and Output classes
	vector <CFigure*> SelectedFig; //Pointer to the selected figure
	Input *pIn;
	Output *pOut;
	CFigure* application_clipboard[200];

public:	

	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	CFigure* Copied_FigureList[200]; // copiedlist;
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void CansSelectedFigure(CFigure*);
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure* GetSelectedFigure(int)const;
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output

	////////////////////////////////////////////////////////////////
	void GetFigureList(CFigure* FigureListNew[]); ////Get Figure List

	int GetFigurecount(); ///// Getfigure count
	void MakeFigNull(CFigure* fig);
	int GetNUmOfSelectedFig()const; 
	void UpdateInterface() const;	//Redraws all the drawing window	

};

#endif