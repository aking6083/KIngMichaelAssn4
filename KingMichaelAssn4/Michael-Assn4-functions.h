//*****************************************************************************
// FILE NAME: Michael-Assn4-functions.h
// DESCRIPTION: This file contains Shawn Michael's function prototypes for
//              assn 4.
// CLASS/TERM: CS 372, 15S8W1
// DESIGNER: Shawn Michael
//*****************************************************************************

//prototypes
void showMenu();
sortType * getUserSort(int &numTimes);
int getTestRuns();
int * initArray();
void popArray(int list1[], int list2[]);
int * bubbleSortIt(int rdmLst[]);
int * quickSort(int rdmLst[], int first, int last);
int qPartition(int list[], int first, int last);
int Random();