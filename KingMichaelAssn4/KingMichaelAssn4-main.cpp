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

	showMenu();
	usrSorts = getUserSort(numTimes);
	
	cout << usrSorts[0] << " " << usrSorts[1] << endl;
	
	return 0;
}

