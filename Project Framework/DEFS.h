#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle


	HIDE_LINE,		//Hide Line
	HIDE_RECT,		//Hide Rectangle
	HIDE_TRI,		//Hide Triangle
	HIDE_CIRC,		//Hide Circle



	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	DEL,			//Delete a figure(s)
	COPY,			//Copy a Figure (s)
	CUT,			// Cut a figure (s)
	PASTE,			// Paste a Figure (s)
	MOVE,			//Move a figure(s)
	RESIZE,			//Resize a figure(s)
	ROTATE,			//Rotate a figure(s)
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	UNDO,			//Undo the actions
	REDO,			//Redo the actions
	SELECT,			//Select action
	EXIT,			//Exit the application


	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode

	///TODO: Add more action types (if needed)
	SET_BLACK,        //Set the Black color 
	SET_WHITE,        //Set the White color 
	SET_RED,         //Set the Red color 
	SET_GREEN,       //Set the Green color 
	SET_BLUE,        // Set the Blue color 
	BACK,            // Back to the tool bar 

	/////////////// PLAY MODE Actions
	HIDE_UNFILL_SHAPE,
	HIDE_SMAE_COLOR,
	HIDE_FILL_SHAPE,
	START_GAME,
	RESTART_GAME,
};

struct Point	//To be used for figures points
{
	int x,y;
	Point(int xx, int yy) {
		x = xx;
		y = yy;
	}

	Point() {
	}
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif