//*****************************************************************************
// FILE NAME: King-Assn4-functions.h
// DESCRIPTION: 
// CLASS/TERM: CS 372, 15S8W1
// DESIGNER: 
//*****************************************************************************
//#include "KingMichael-Assn4-common.h"
typedef sortType testType;

void validChoice(string userInput);
void processChoices(sortType* userSorts, int numTimes, testType theTests[], double *tstAvg);
int * mergeSortIt(int numTimes, int rdmLst, double &srtAvg);
int * quickSort(int numTimes, int rdmLst, double &srtAvg);
int * insertSortIt(int rdmLst[], int first, int last);
bool  sortValid(int srtList[]);
void showResults(sortType theTests[], double *tstAvgs);