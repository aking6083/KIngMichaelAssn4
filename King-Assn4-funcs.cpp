#include "KingMichael-Assn4-common.h"
#include "King-Assn4-functions.h"
#include "Michael-Assn4-functions.h"

using namespace std;

typedef sortType testType;

void processChoices(sortType userSorts[], int numTimes, testType theTests[], double tstAvg[])
{
	double *srch0Rslts,
		   *srch1Rslts;

	int *list1,
	    *list2;

	//No need to build both lists into one function, just call the same function twice to init the list.
	list1 = initArray();
	list2 = initArray();

	//Let me know what you think about this///////////////////////////////////////////////////////////////////////////////////////////////
	popArray(list1, list2);


	cout << list1[2] << endl; //For verification that data was loaded.

	for (int a = 0; a <= 2; a++) //Run through the userSort selection array
	{
		switch (userSorts[a])
		{
		case BUBBLE:
			for (int b = 0; b <= numTimes - 1;b++) //Run test x amount of times.
			{ }
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
