//*****************************************************************************
// FILE NAME: Michael-assn4.h
// DESCRIPTION: This file contains Shawn Michael's function prototypes for
//              assn 4.
// CLASS/TERM: CS 372, 15S8W1
// DESIGNER: Shawn Michael
//*****************************************************************************

void showMenu();
sortType * getUserSort(int &numTimes);
int getTestRuns();
int * initArray();
void popArrays(int theList1[], int theList2[]);
int * bubbleSortIt(int rdmLst[]);
int * quickSort(int rdmLst[], int first, int last);