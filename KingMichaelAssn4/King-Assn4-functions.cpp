#include "KingMichael-Assn4-common.h"
#include "King-Assn4-functions.h"
#include "Michael-Assn4-functions.h"

using namespace std;

typedef sortType testType;

//tstAvg[0] would be first test and tstAvg[1] would be second test

void processChoices(sortType* userSorts, int numTimes, testType theTests[], double tstAvg[])
{
	
	static int timeSum = 0;
	
	int a = 0,
		b = 0,
		startTime = 0,
		endTime = 0, 
		elapsedTime = 0;
	
	double runningAvg = 0, // For average calculation
			bubbleAvg = 0,
			insertAvg = 0,
			quickAvg = 0,
			mergeAvg = 0,
			srchRslts = 0;
	
	//Dumb function pointer.

	int * (*bubblePtr) (int rdmLst[]);
	int * (*insertPtr) (int rmdLst[], int first, int last);

	int *list1,
	    *list2;
	
	//No need to build both lists into one function, just call the same function twice to init the list.
	list1 = initArray();
	list2 = initArray();
		
	for (a = 0; a <= numTimes - 1; a++)
	{
		runningAvg = 0;
		//Populate both lists with the same numbers.
		popArrays(list1, list2);
		
		elapsedTime = 0;
		if (userSorts[a] != EXIT)
			cout << "Starting Sort " << a + 1 << endl;
		
		for (b = 0; b <= MAX_CHOICES - 1; b++) //Run through the userSort selection array
		{
			switch (userSorts[b])
			{
			case BUBBLE:
				bubblePtr = bubbleSortIt;
				startTime = clock();
				list1 = (*bubblePtr) (list1);
				endTime = clock();
				elapsedTime = endTime - startTime;
				bubbleAvg += elapsedTime;
				tstAvg[userSorts[b]] = bubbleAvg / numTimes;
				if (!sortValid(list1))
					cout << "Invalid Bubble Sort";
				else
					cout << "Bubble Sort Time " << elapsedTime << endl;
					
				
				break;

			case INSERT:
				insertPtr = insertSortIt;
				startTime = clock();
				list2 = (*insertPtr) (list2,0,ARRAY_SIZE);
				endTime = clock();
				elapsedTime = endTime - startTime;
				insertAvg += elapsedTime;
				tstAvg[userSorts[b]] = insertAvg / numTimes;
				if (!sortValid(list2))
					cout << "Invalid Insert Sort";
				else
					cout << "Insert Sort Time " << elapsedTime << endl;
				 tstAvg[a] = runningAvg / numTimes;
				//Insert Search here
				break;

			case QUICK:
				cout << "Quick Search\n";
				//Insert Quick Sort here
				break;

			case MERGE:
				cout << "Merger Search\n";
				//Insert Merge Sort here
				break;
			}// End switch
			
		}// End a Loop
		
	}
	
		
		
		
}



void showArray(int rdmLst[])
{
	for (int a = 0; a <= ARRAY_SIZE - 1; a++)
		cout << rdmLst[a] << endl;

}

int * mergeSortIt(int numTimes, int rdmLst, double &srtAvg)
{

	return NULL;
}

bool  sortValid(int srtList[])
{
	bool validSort = true;
	for (int a = 0; a <= ARRAY_SIZE - 1; a++)
	{
		if (srtList[a] > srtList[a + 1])
		{
			cout << "Invalid Sort! at " << a << endl;
			validSort = false;
		}
			
	}
	return validSort;
}

void showResults(sortType theTests[], double tstAvgs[])
{
	string temp;

	cout << "SORTING RESULTS"
		<< "\n=================\n";
	
	for (int a = 0; a <= MAX_CHOICES - 1;a++)
	{
		cout << sortTypeStr[theTests[a]] << " search average is " << tstAvgs[a] << endl;
	}
}

int * insertSortIt(int rdmLst[], int first, int last)
{
	int i,
		j,
		key;

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
