#include "KingMichael-Assn4-common.h"
#include "King-Assn4-functions.h"
#include "Michael-Assn4-functions.h"

using namespace std;

typedef sortType testType;

void processChoices(sortType* userSorts, int numTimes, testType theTests[], double tstAvg[])
{
	double srchRslts = 0;
	
	//Dumb function pointer.

	int * (*bubblePtr) (int numTimes, int rdmLst[], double &srtAvg);


	int *list1,
	    *list2;
	
	//No need to build both lists into one function, just call the same function twice to init the list.
	list1 = initArray();
	list2 = initArray();

	//Populate both lists with the same numbers.
	popArrays(list1, list2);
	
	cout << list1[2] << endl; //For verification that data was loaded.
	cout << list2[2] << endl;

	for (int a = 0; a <= MAX_CHOICES-1; a++) //Run through the userSort selection array
	{
		//We can run and time our sorts from here.  
		switch (userSorts[a])
		{
		case BUBBLE:
			bubblePtr = bubbleSortIt;
			list1 = (*bubblePtr) (1, list1, srchRslts);
			
			//Bubble Search Here	
		break;

		case INSERT:
			//Insert Search here
			break;

		case QUICK:
			//Insert Quick Sort here
			break;

		case MERGE:
			//Insert Merge Sort here
			break;
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