//*****************************************************************************
// FILE NAME: King-Assn4-functions.h
// DESCRIPTION: header file for King-Assn4-functions 
// CLASS/TERM: CS 372, 15S8W1
// DESIGNER: Adam King
//*****************************************************************************

typedef sortType testType;

void processChoices(sortType* userSorts, int numTimes, testType theTests[], double *tstAvg);
void merge(int rdmLst[], int low, int mid, int high);
void mergeSortIt(int rdmLst[], int low, int high);
int * insertSortIt(int rdmLst[], int first, int last);
bool  sortValid(int srtList[]);
void showResults(sortType theTests[], double *tstAvgs);
string getValidInput();
