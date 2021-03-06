#include "KingMichael-Assn4-common.h"
#include "King-Assn4-functions.h"
#include "Michael-Assn4-functions.h"

using namespace std;

typedef sortType testType;

void processChoices(sortType* userSorts, int numTimes, testType theTests[], double *tstAvg)
{
	
	if (*userSorts != EXIT)
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
		int * (*quickPtr)(int rdmLst[], int first, int last);
		void(*mergePtr)(int rdmLst[], int start, int end);

		int *list1;

		//No need to build both lists into one function, just call the same function twice to init the list.
		list1 = initArray();

		for (a = 0; a <= numTimes - 1; a++)
		{
			runningAvg = 0;
			//Populate both lists with the same numbers.
			// Gonna have to change this becuase list1 and list2 dont make sense 

			elapsedTime = 0;
			if (userSorts[a] != EXIT)
				cout << "\nStarting Sort " << a + 1 << endl;
			cout << "======================" << endl;
			for (b = 0; b <= MAX_CHOICES - 1; b++) //Run through the userSort selection array
			{
				switch (userSorts[b])
				{
				case BUBBLE:
					popArray(list1);
					bubblePtr = bubbleSortIt;
					startTime = clock();
					list1 = (*bubblePtr) (list1);
					endTime = clock();
					elapsedTime = endTime - startTime;
					bubbleAvg += elapsedTime;
					tstAvg[userSorts[b]] = bubbleAvg / numTimes;
					cout << "Bubble Sort Time " << elapsedTime << endl;
					if (!sortValid(list1))
						cout << "Invalid Bubble Sort\n";
					else
						cout << "Bubble Sort Validated\n";

					break;

				case INSERT:
					popArray(list1);
					insertPtr = insertSortIt;
					startTime = clock();
					list1 = (*insertPtr) (list1, 0, ARRAY_SIZE);
					endTime = clock();
					elapsedTime = endTime - startTime;
					insertAvg += elapsedTime;
					tstAvg[userSorts[b]] = insertAvg / numTimes;
					cout << "Insert Sort Time " << elapsedTime << endl;
					if (!sortValid(list1))
						cout << "Invalid Insert Sort\n";
					else
						cout << "Insert Sort Validated\n";

					break;

				case QUICK:
					popArray(list1);
					quickPtr = quickSort;
					startTime = clock();
					list1 = (*quickPtr) (list1, 0, ARRAY_SIZE);
					endTime = clock();
					elapsedTime = endTime - startTime;
					quickAvg += elapsedTime;
					tstAvg[userSorts[b]] = quickAvg / numTimes;
					cout << "Quick Sort Time " << elapsedTime << endl;
					if (!sortValid(list1))
						cout << "Invalid Quick Sort\n";
					else
						cout << "Quick Sort Validated\n";


					break;

				case MERGE:
					popArray(list1);
					mergePtr = mergeSortIt;
					startTime = clock();
					(*mergePtr) (list1, 0, ARRAY_SIZE);
					endTime = clock();
					elapsedTime = endTime - startTime;
					mergeAvg += elapsedTime;
					tstAvg[userSorts[b]] = mergeAvg / numTimes;
					cout << "Merge Sort Time " << elapsedTime << endl;
					if (!sortValid(list1))
						cout << "Invalid Merge Sort\n";
					else
						cout << "Merge Sort Validated\n";
					break;
				
				default:
					cout << "Invalid Choice\n";
				}// End switch
			}// End a Loop
		}
	}
}

void showArray(int rdmLst[])
{
	for (int a = 0; a <= ARRAY_SIZE - 1; a++)
		cout << rdmLst[a] << endl;

}

void merge(int rdmLst[], int low, int mid, int high)
{
	int h, i, j, k = 0;
	int tmpArray[ARRAY_SIZE + 1];
	h = low;
	i = low;
	j = mid + 1;

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
		for (k = j; k <= high; k++)
		{
			tmpArray[i] = rdmLst[k];
			i++;
		}
	}
	else
	{
		for (k = h; k <= mid; k++)
		{
			tmpArray[i] = rdmLst[k];
			i++;
		}
	}
	for (k = low; k <= high; k++) 
		rdmLst[k] = tmpArray[k];
}

void mergeSortIt(int rdmLst[],int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = low + (high - low) / 2; //This avoids overflow when low, high are too large
		mergeSortIt(rdmLst,low, mid);
		mergeSortIt(rdmLst,mid + 1, high);
		merge(rdmLst, low, mid, high);
	}
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

string getValidInput()
{
	char in1, in2;
	string retStr;
	bool isValid = false, firstValid = false , secValid = false;
	
	do
	{
		cout << "\n\tEnter two letter choices (or EE to exit): ";
		cin >> in1 >> in2;
		in1 = toupper(in1);
		in2 = toupper(in2);

		for (int a = 0; a <= NUM_CHOICES - 1; a++)
		{
			if (in1 == LTR_CHOICES[a])
				firstValid = true;
		}
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
