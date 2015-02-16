/*****************************************************************************
// CODE FILENAME: King-Assn4-functions.cpp
// DESCRIPTION: Functions Designed by Adam King.
// CLASS/TERM: CS372 2015 Spring 8 Week 1
// DESIGNER: Adam King
// FUNCTIONS:
// ~Runs the tests and keeps up with the average run times
// void processChoices(sortType* userSorts, int numTimes, testType theTests[],
//					   double *tstAvg);
// void merge(int rdmLst[], int low, int mid, int high); ~merge part of mergesort
// void mergeSortIt(int rdmLst[], int low, int high); ~Merge sort the list
// int * insertSortIt(int rdmLst[], int first, int last); ~Insert Sort the list
// bool  sortValid(int srtList[]); ~is the sort a valid one?
// ~Show the average run times for each test
// void showResults(sortType theTests[], double *tstAvgs);
// string getValidInput(); ~ gets the valid input from user.
//****************************************************************************/

#include "KingMichael-Assn4-common.h"
#include "King-Assn4-functions.h"
#include "Michael-Assn4-functions.h"

using namespace std;

typedef sortType testType;

/******************************************************************************
//  FUNCTION: processChoices
//  DESCRIP:  Gets the sort type from user and runs the test x amount of times
//		      keeping up with the average sort times for each test.
//			  Maybe a little overcomplicated, but I coded with expansion in mind
//            Would like to make it a little more cohesive.
//  INPUT:
//  Parameters: sortType* userSorts ~ array of user selected sorts
//				int numTimes ~ number of times each test will run
//				testType theTests[] ~ array with 2 elements 0-4 that holds the
//									 type tests that are to be run.
//
//  OUTPUT:
//  Parameters: double *tstAvg ~pointer to array that holds each test average
//									 I.E. tstAvg[0] would hold the average for
//									 BUBBLE Sort.

//  Return Val: none
//  CALLS TO: bubbleSortIt(),mergeSortIt(),quikSort(),insertSortIt(),popArray()
//			  initArray()
//  IMPLEMENTED BY:  Adam King
******************************************************************************/
void processChoices(sortType* userSorts, int numTimes, testType theTests[],
	double *tstAvg)
{
	if (*userSorts != EXIT) //If the user doesnt want to exit
	{
		int a = 0, //number of times to run the test
			b = 0, //number of tests to run 
			startTime = 0,
			endTime = 0,
			elapsedTime = 0;

		double runningAvg = 0, // For average calculation
			bubbleAvg = 0,
			insertAvg = 0,
			quickAvg = 0,
			mergeAvg = 0,
			srchRslts = 0;

		//Function pointers.

		int * (*bubblePtr) (int rdmLst[]);
		int * (*insertPtr) (int rmdLst[], int first, int last);
		int * (*quickPtr)(int rdmLst[], int first, int last);
		void(*mergePtr)(int rdmLst[], int start, int end);

		int *list1; //make a list to sort
		int *list2; //make a list to sort
		int *theList;

		/*The requirements doc says make two lists, but I think in-essence we are
		doing the same thing, we only need to init the memory space once, then
		rebuild the list for each test.  I may be missing something though.*/
		list1 = initArray();
		list2 = initArray();
		popArray(list1, list2);

		//Run Tests a number of times
		for (a = 0; a <= numTimes - 1; a++)
		{
			runningAvg = 0;
			elapsedTime = 0;

			if (userSorts[a] != EXIT)
			{
				cout << "\nStarting Sort " << a + 1 << endl;
				cout << "======================" << endl;
			}

			//Run through the userSort selection array
			for (b = 0; b <= MAX_CHOICES - 1; b++)
			{
				switch (userSorts[b])
				{
				case BUBBLE:
					if (!sortValid(list1))
						theList = list1;
					else
						theList = list2;

					bubblePtr = bubbleSortIt; //Function ptr
					startTime = clock(); //On your Marks! GO!
					theList = (*bubblePtr) (theList); //sort the list via function ptr
					endTime = clock();//Stop timing
					elapsedTime = endTime - startTime;
					bubbleAvg += elapsedTime;
					//Store the running average
					tstAvg[userSorts[b]] = bubbleAvg / numTimes;
					cout << "Bubble Sort Time " << elapsedTime << endl;
					//Is sort Valid
					if (!sortValid(theList))
						cout << "Invalid Bubble Sort\n";
					else
						cout << "Bubble Sort Validated\n";
					break;

				case INSERT:
					if (!sortValid(list1))
						theList = list1;
					else
						theList = list2;

					insertPtr = insertSortIt; //Function ptr
					startTime = clock(); //On your Marks! GO!
					//sort the list via function ptr
					theList = (*insertPtr) (theList, 0, ARRAY_SIZE);
					endTime = clock();//Stop timing
					elapsedTime = endTime - startTime;
					insertAvg += elapsedTime;
					//Store the running average
					tstAvg[userSorts[b]] = insertAvg / numTimes;
					cout << "Insert Sort Time " << elapsedTime << endl;
					//Is sort Valid
					if (!sortValid(theList))
						cout << "Invalid Insert Sort\n";
					else
						cout << "Insert Sort Validated\n";
					break;

				case QUICK:
					if (!sortValid(list1))
						theList = list1;
					else
						theList = list2;

					quickPtr = quickSort; //Function ptr
					startTime = clock(); //On your Marks! GO!
					//sort the list via function ptr
					theList = (*quickPtr) (theList, 0, ARRAY_SIZE);
					endTime = clock();//Stop timing
					elapsedTime = endTime - startTime;
					quickAvg += elapsedTime;
					//Store the running average
					tstAvg[userSorts[b]] = quickAvg / numTimes;
					cout << "Quick Sort Time " << elapsedTime << endl;
					//Is sort Valid
					if (!sortValid(theList))
						cout << "Invalid Quick Sort\n";
					else
						cout << "Quick Sort Validated\n";
					break;

				case MERGE:
					if (!sortValid(list1))
						theList = list1;
					else
						theList = list2;

					mergePtr = mergeSortIt; //Function ptr
					startTime = clock(); //On your Marks! GO!
					(*mergePtr) (theList, 0, ARRAY_SIZE);
					endTime = clock();//Stop timing
					elapsedTime = endTime - startTime;
					mergeAvg += elapsedTime;
					//Store the running average
					tstAvg[userSorts[b]] = mergeAvg / numTimes;
					cout << "Merge Sort Time " << elapsedTime << endl;
					//Is sort Valid
					if (!sortValid(theList))
						cout << "Invalid Merge Sort\n";
					else
						cout << "Merge Sort Validated\n";
					break;
				}// End switch
			}// End b Loop
		}// End a Loop
	}

}

/******************************************************************************
//  FUNCTION:merge
//  DESCRIP:merges two lists. for use in mergeSortIt complex algorithm.
//  INPUT:
//  Parameters: int low ~ low index;
//			    int mid ~ middle index;
//				int high ~ high index;
//
//  OUTPUT:
//  Parameters:
//  Return Val:
//  CALLS TO:
//  IMPLEMENTED BY:  Adam King
******************************************************************************/

void merge(int rdmLst[], int low, int mid, int high)
{
	int h, i, j, k = 0;
	static int tmpArray[ARRAY_SIZE]; //Declare the temp array to store values
	h = low; //left items
	i = low; //Temp Position
	j = mid + 1; //Right items

	while ((h <= mid) && (j <= high))
	{
		if (rdmLst[h] <= rdmLst[j])
		{
			tmpArray[i] = rdmLst[h];
			h++;
		}
		else
		{
			tmpArray[i] = rdmLst[j];
			j++;
		}
		i++;
	}
	if (h>mid)
	{
		for (k = j; k <= high; k++) //Left side??
		{
			tmpArray[i] = rdmLst[k];
			i++;
		}
	}
	else
	{
		for (k = h; k <= mid; k++) //Right Side
		{
			tmpArray[i] = rdmLst[k];
			i++;
		}
	}
	for (k = low; k <= high; k++)
		rdmLst[k] = tmpArray[k];
}

/******************************************************************************
//  FUNCTION:mergeSortIt
//  DESCRIP: Recursive function to merge sort list
//  INPUT:
//  Parameters: int low ~ low Index to start sort
//              int high ~ high Index to start sort
//  OUTPUT:
//  Parameters: int rdmLst[] ~ the sorted list
//  Return Val:
//  CALLS TO:  merge(),mergeSortIt()
//  IMPLEMENTED BY:  Adam King
******************************************************************************/
void mergeSortIt(int rdmLst[], int low, int high)
{
	int mid = 0;

	if (low < high)
	{
		//Get middle index
		mid = low + (high - low) / 2; //This may avoid overflow if numbers are
		// too large
		mergeSortIt(rdmLst, low, mid); //Sort bottom or left
		mergeSortIt(rdmLst, mid + 1, high); //Sort top or right
		merge(rdmLst, low, mid, high); //Merge them
	}
}

/******************************************************************************
//  FUNCTION:sortValid
//  DESCRIP:Runs through sorted list ensuring list is sorted in ascending order
//  INPUT:
//  Parameters: srtList[]
//
//  OUTPUT:
//  Parameters:
//  Return Val: validSort ~ true if list is sorted correctly
//  CALLS TO:
//  IMPLEMENTED BY:  Adam King
******************************************************************************/
bool  sortValid(int srtList[])
{
	bool validSort = true;
	for (int a = 0; a <= ARRAY_SIZE - 1; a++)
	{
		if (srtList[a] > srtList[a + 1])
		{
			validSort = false;
		}
	}
	return validSort;
}

/******************************************************************************
//  FUNCTION: showResults
//  DESCRIP:shows the results stored in tstAvgs
//  INPUT:
//  Parameters: sortType theTests[] ~ the tests that were run
//              double * tstAvgs ~ array of stored results
//
//  OUTPUT:
//  Parameters:
//  Return Val:
//  CALLS TO:
//  IMPLEMENTED BY:  Adam King
******************************************************************************/
void showResults(sortType theTests[], double *tstAvgs)
{
	string temp;

	cout << "\nSORTING RESULTS"
		<< "\n=================\n";

	for (int z = 0; z <= NUM_CHOICES - 1; z++)
	{
		if (tstAvgs[z])
		{
			cout << SORT_TYPE_STR[z] << " Sort " << tstAvgs[z] << " clock ticks on average \n";

		}
	}
	cout << endl;
}

/******************************************************************************
//  FUNCTION:insertSortIt
//  DESCRIP: performs insert sort on passed list
//  INPUT:
//  Parameters:rdmLst[] ~ the random list
//			   int first ~ index to start with
//			   int last ~ index to end with
//  OUTPUT:
//  Parameters:
//  Return Val: int rdmLst[] ~ the sorted list
//  CALLS TO:
//  IMPLEMENTED BY:  Adam King
******************************************************************************/
int * insertSortIt(int rdmLst[], int first, int last)
{
	int i = 0,
		j = 0,
		key = 0;

	for (j = 1; j <= last; j++)
	{
		key = rdmLst[j];

		// insert list[j] into sorted sequence
		i = j - 1;
		while ((i >= 0) && (rdmLst[i] > key)){
			rdmLst[i + 1] = rdmLst[i];
			i--;
		}
		rdmLst[i + 1] = key;
	}
	return rdmLst;
}

/******************************************************************************
//  FUNCTION:getValidInput
//  DESCRIP:Get the validated menu choice from user
//  INPUT:
//  Parameters: none
//
//  OUTPUT:
//  Parameters:
//  Return Val: string retStr ~ the validated menu choices
//  CALLS TO:
//  IMPLEMENTED BY:  Adam King
******************************************************************************/
string getValidInput()
{
	char in1, in2;
	string retStr;
	bool isValid = false, firstValid = false, secValid = false;

	do
	{
		cout << "\n\tEnter two letter choices (or EE to exit): ";
		cin >> in1 >> in2;
		in1 = toupper(in1);
		in2 = toupper(in2);

		//Check first letter
		for (int a = 0; a <= NUM_CHOICES - 1; a++)
		{
			if (in1 == LTR_CHOICES[a])
				firstValid = true;
		}
		//Check second letter
		for (int a = 0; a <= NUM_CHOICES - 1; a++)
		{
			if (in2 == LTR_CHOICES[a])
				secValid = true;
		}


		if (firstValid && secValid)
		{
			isValid = true;
			retStr = in1;
			retStr += in2;

		}
		else
			cout << "Invalid Choice\n";

	} while (!isValid);

	return retStr;
}