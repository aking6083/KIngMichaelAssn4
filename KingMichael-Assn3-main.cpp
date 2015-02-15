#include "KingMichael-Assn4-common.h"
#include "Michael-Assn4-functions.h"
#include "King-Assn4-functions.h"

int main(int argc, char* argv[])
{
	int numTimes = 0;
	sortType *usrSorts;
	double *srtAvgs = 0;
	srtAvgs = new double[NUM_CHOICES];
	
	do
	{
		for (int a = 0; a <= NUM_CHOICES; a++)
			srtAvgs[a] = 0;
		
		showMenu();
		usrSorts = getUserSort(numTimes);
		processChoices(usrSorts, numTimes, usrSorts, srtAvgs);
		if (*usrSorts != EXIT)
			showResults(usrSorts, srtAvgs);
	} while (*usrSorts != EXIT);
	
	return 0;
}
