#include "KingMichael-Assn4-common.h"
#include "King-Assn4-functions.h"
#include "Michael-Assn4-functions.h"

using namespace std;

typedef sortType testType;

void processChoices(sortType* userSorts, int numTimes, testType theTests[], double tstAvg[])
{
	static int timeSum = 0;
	
	int startTime = 0,
		endTime = 0, 
		elapsedTime = 0;

	double srchRslts = 0;
	
	//Dumb function pointer.

	int * (*bubblePtr) (int rdmLst[]);


	int *list1,
	    *list2;
	
	//No need to build both lists into one function, just call the same function twice to init the list.
	list1 = initArray();
	list2 = initArray();

	
	
	//Populate both lists with the same numbers.
	popArrays(list1, list2);
	
	for (int a = 0; a <= numTimes - 1; a++)
	{
		if (userSorts[a] != EXIT)
			cout << "Starting Sort " << a + 1 << endl;
		
		for (int b = 0; b <= MAX_CHOICES - 1; b++) //Run through the userSort selection array
		{
			
			switch (userSorts[b])
			{
			case BUBBLE:


				cout << "Bubble Sort";
				bubblePtr = bubbleSortIt;
				startTime = clock();
				list1 = (*bubblePtr) (list1);
				endTime = clock();
				elapsedTime = endTime - startTime;

				if (!sortValid(list1))
					cout << "Invalid Bubble Sort";
				else
					cout << "Bubble Sort Time " << elapsedTime << endl;
							
				//Bubble Search Here	
				break;

			case INSERT:
				cout << "Insert Search\n";
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
			}
		}
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