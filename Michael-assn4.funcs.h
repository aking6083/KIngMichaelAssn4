//*****************************************************************************
// FILE NAME: Michael-assn4.h
// DESCRIPTION: This file contains Shawn Michael's function prototypes for
//              assn 4.
// CLASS/TERM: CS 372, 15S8W1
// DESIGNER: Shawn Michael
//*****************************************************************************

//prototypes
void showMenu();                                           //done
sortType* getUserSort(sortType sortSel[], int &numTimes);
int getTestRuns();                                         //done
void initArrays(int list1[], int list2[]);                 //done
void popArray(int rdmLst[], int rdmLst2[]);                //done
void bubbleSort(int numTimes, int list[], int first, int last, double &srtAvg); //done
void quickSort(int numTimes, int list[], int first, int last, double &srtAvg);  //done
int qPartition(int list[], int first, int last);  // required for quick sort
