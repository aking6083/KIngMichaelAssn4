// KingMichaelAssn4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KingMichael-Assn4-common.h"
#include "Michael-Assn4-functions.h"
#include "King-Assn4-functions.h"

int main(int argc, char* argv[])
{
	int numTimes = 0;
	sortType *usrSorts;
	double *srtAvgs = 0;
			
	do
	{
		showMenu();
		usrSorts = getUserSort(numTimes);
		cout << usrSorts[0] << endl;
		cout << usrSorts[1] << endl;
		processChoices(usrSorts, numTimes, usrSorts, srtAvgs);


	} while (*usrSorts != EXIT);
	
	return 0;
}

