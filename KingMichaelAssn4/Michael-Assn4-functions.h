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
void popArray(int theList[]);
int * bubbleSortIt(int rdmLst[]);

void bubbleSort(int numTimes, int list[], int first, int last, double &srtAvg);
void showArray(int rdmLst[]);
int * quickSort(int rdmLst[], int first, int last);