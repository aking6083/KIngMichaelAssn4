//*****************************************************************************
// FILE NAME: King-Assn4-functions.h
// DESCRIPTION:
// CLASS/TERM: CS 372, 15S8W1
// DESIGNER:
//*****************************************************************************
//#include "KingMichael-Assn4-common.h"

bool validChoice(string userInput);
void processChoices(sortType userSorts[], int numTimes, sortType theTests[],
//					double tstAvg[]);
int * mergeSortIt(int numTimes, int rdmLst, double &srtAvg);
int * quickSort(int numTimes, int rdmLst, double &srtAvg);
bool  sortValid(int srtList[]);
void showResults(sortType theTests[], double tstAvgs[]);
