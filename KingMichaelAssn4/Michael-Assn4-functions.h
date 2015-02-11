//*****************************************************************************
// FILE NAME: Michael-assn4.h
// DESCRIPTION: This file contains Shawn Michael's function prototypes for
//              assn 4.
// CLASS/TERM: CS 372, 15S8W1
// DESIGNER: Shawn Michael
//*****************************************************************************

//prototypes
//#include "KingMichael-Assn4-common.h"

void showMenu();
sortType * getUserSort(int &numTimes);
int getTestRuns();
int * initArray();
int* popArray(int theList[]);
int * bubbleSortIt(int numTimes, int rdmLst[], double &srtAvg);
int * insertSortIt(int numTimes, int rdmLst, double &srtAvg);
