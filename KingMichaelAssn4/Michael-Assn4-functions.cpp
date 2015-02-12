

#include "KingMichael-Assn4-common.h"
#include "Michael-Assn4-functions.h"
#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************
// FUNCTION: Menu
// DESCRIPTION:
// INPUT:
//      Parameters:
//
// OUTPUT: Void
//      Return Val: no returns
// IMPLEMENTED BY: Shawn Michael
//*****************************************************************************

void showMenu()
{
	cout << "\tChoose Two sorts you with to compare: " << endl;
	cout << "\t\tB = Bubble sort\n";
	cout << "\t\tI = Insertion sort\n";
	cout << "\t\tM = Merge sort\n";
	cout << "\t\tQ = Quick sort\n";
	cout << "\t\tE = Exit program\n";
}

//*****************************************************************************
// FUNCTION: getTestRuns
// DESCRIPTION:
// INPUT:
//      Parameters:
//
// OUTPUT: Void
//      Return Val: returns int value
// IMPLEMENTED BY: Shawn Michael
//*****************************************************************************
int getTestRuns()
{
	int numIteration;
	bool validNum;
	cin.clear();
	do {
		
		
		validNum = true;
		cout << endl;
		cout << "\tEnter the number of times to repeat each sort (1 or more):";
		cin >> numIteration;
		if (numIteration <= 0) {
			cout << INVALID_NUM << endl;
			validNum = false;
		}
	} while (!validNum);
	return numIteration;
}



sortType * getUserSort(int &numTimes)
{
	sortType *usrSorts;
	usrSorts = new sortType[MAX_CHOICES];
	
	string userInput;
	
	int selCnt = 0;
	
	char firstChoice = ' ',
		secChoice,
		choice;
	
	cout << "\n\tEnter two letter choices (or EE to exit): ";
	
	if (numTimes > 0) //To clear the cin buffer
	{
		cin.clear();
		cin.ignore(1000, '\n');
	}
		
	getline(cin, userInput);
	
	selCnt = userInput.length();
	
	//Will put isValid loop to control error checking from external function of isValid()
	if (selCnt > 1)
	{
		firstChoice = toupper(userInput[0]);
		secChoice = toupper(userInput[1]);
	}

	else if (selCnt == 1)
		firstChoice = toupper(userInput[0]);
		
	
	choice = firstChoice; //For code reading logic
	
	for (int a = 0; a <= selCnt - 1; a++)
	{
		switch (choice)
		{
		case BBL_SRT:
			usrSorts[a] = BUBBLE;
			break;
		
		case MRG_SRT:
			usrSorts[a] = MERGE;
			break;

		case QCK_SRT:
			usrSorts[a] = QUICK;
			break;

		case INSRT_SRT:
			usrSorts[a] = INSERT;
			break;
		
		case EXIT_SRT:
			usrSorts[a] = EXIT;
			break;
		}
		if (a < selCnt)
			choice = secChoice;
		
	}

	if (choice != EXIT_SRT)
		numTimes = getTestRuns();
	
return usrSorts;
}

//*****************************************************************************
// FUNCTION: bubbleSort
// DESCRIPTION: function performs a selection sort algorithm
// INPUT: static array
//      Parameters: staticArray[] - static random array
//                  length - input value from user for the array size
//
// OUTPUT: void
//      Return Val: void
// CALLS TO: N/A
// IMPLEMENTED BY: Shawn Michael
//*****************************************************************************

void bubbleSort(int numTimes, int list[], int first, int last, double &srtAvg)
{
	static int timeSum = 0;
	int temp,
		iteration,
		index,
		startTime,
		endTime,
		elapsedTime;
	int *aPtr;
	aPtr = list;

	startTime = clock();
	for (iteration = 1; iteration <= last; iteration++){
		for (index = 0; index <= last - iteration; index++) {
			if (list[index + 1] < list[index]){
				temp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}  // end if
		} //end for
	} //end for
	endTime = clock();
	elapsedTime = endTime - startTime;
	timeSum += elapsedTime;
	srtAvg = timeSum / numTimes;

	
}


int * bubbleSortIt(int numTimes, int rdmLst[], double &srtAvg)
{
	showArray(rdmLst);
	cout << endl; 
	int cntr = 0,
		num = 0;

	for (int a = 0; a < ARRAY_SIZE; a++)
	{
		for (int b = 0; b <= ARRAY_SIZE - 1; b++)
		{
			if (rdmLst[b] > rdmLst[b+1])
			{
				cntr = rdmLst[b];
				rdmLst[b] = rdmLst[b + 1];
				rdmLst[b + 1] = cntr;

			}
		}
	}
	return rdmLst;
}

//*****************************************************************************
// FUNCTION: qPartition
// DESCRIPTION: function performs a quickSort sort algorithm
// INPUT: static array
//      Parameters: staticArray[] - static random array
//                  length - input value from user for the array size
//
// OUTPUT: void
//      Return Val: void
// CALLS TO: N/A
// IMPLEMENTED BY: Shawn Michael
//*****************************************************************************
int qPartition(int list[], int first, int last)
{
	int pivot,
		index,
		smallIndex,
		temp;

	pivot = (first + last) / 2;

	temp = list[pivot];
	list[pivot] = list[first];
	list[first] = temp;

	pivot = list[first];
	smallIndex = first;

	for (index = first + 1; index <= last; index++){
		if (list[index] < pivot) {
			smallIndex++;

			temp = list[smallIndex];
			list[smallIndex] = list[index];
			list[index] = temp;
		}
	}
	temp = list[first];
	list[first] = list[smallIndex];
	list[smallIndex] = temp;

	return smallIndex;
}


//*****************************************************************************
// FUNCTION: quickSort
// DESCRIPTION: function performs a quickSort sort algorithm
// INPUT: static array
//      Parameters: staticArray[] - static random array
//                  length - input value from user for the array size
//
// OUTPUT: void
//      Return Val: void
// CALLS TO: N/A
// IMPLEMENTED BY: Shawn Michael
//*****************************************************************************
void quickSort(int numTimes, int list[], int first, int last, double &srtAvg)
{
	static int timeSum = 0;
	int pivotLoc,
		startTime,
		endTime,
		elapsedTime;

	startTime = clock();    ///////////////////////////////this might screw with the calculation as it will start a new clock every time this recursive function is called.
	if (first < last){
		pivotLoc = qPartition(list, first, last);
		quickSort(numTimes, list, first, pivotLoc - 1, srtAvg);
		quickSort(numTimes, list, pivotLoc + 1, last, srtAvg);
	}
	endTime = clock();
	elapsedTime = endTime - startTime;
	timeSum += elapsedTime;
	srtAvg = timeSum / numTimes;
}


//*********************************************************************
// FUNCTION: PopArray()
// DESCRIPTION: Function populates a dynamic array with random unsorted
//              integers acquired via two called functions
// INPUT:
// Parameters: int randArray[] - static array to hold random numbers
// OUTPUT:
// Return Val: N/A
// Parameters: int randArray[] - populated and returned to main
// File: N/A
// CALLS TO: Random(),
// IMPLEMENTED BY: Shawn Michael
//**********************************************************************
int* popArray(int theList[])
{
	int counter = 0;	    //counter to control input into static array
	int rNum;				//int variable to hold random number

	//seed to ensure randomized values on each execution
	srand(time(NULL));

	//while statement executes until first array is full
	while (counter != ARRAY_SIZE){

		//function creates random number and duplicate search
		rNum = (rand() % MAX_ARRAY_NUM) + 1;
		theList[counter] = rNum;
		counter++;
	}//end while
	return theList;
}

//*****************************************************************************
// FUNCTION: initArrays
// DESCRIPTION: creates a dynamic array
// INPUT: Array Size
//      Parameters:
// OUTPUT: returns pointer to top of the array[]
//      Return Val: array *ptr
// IMPLEMENTED BY: Shawn Michael
//*****************************************************************************
int * initArray() //Call this twice
{
	int *theList;
	theList = new (nothrow) int[ARRAY_SIZE];
	if (theList != NULL) {
		for (int i = 0; i < ARRAY_SIZE; i++) {
			theList[i] = 0;    // Initialize all elements to NULL
		}  //end for
	} //end if
	else
		cout << "HEAP ERROR creating Array. " << endl;

	return theList;
}
