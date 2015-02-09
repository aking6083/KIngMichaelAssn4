

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


sortType* getUserSort(int &numTimes)
{
	sortType usrSorts[MAX_CHOICES];
	
	string userInput;
	
	char firstChoice,
		secChoice,
		choice;
	cout << "\n\tEnter two letter choices (or EE to exit): ";
	getline(cin, userInput);

	//Will put isValid loop to control error checking from external function of isValid()
	firstChoice = toupper(userInput[0]);
	secChoice = toupper(userInput[1]);
	choice = firstChoice; //For code reading logic
	
	for (int a = 0; a <= MAX_CHOICES - 1; a++)
	{
		switch (choice)
		{
		case 'B':
			usrSorts[a] = BUBBLE;
			break;
		case 'M':
			usrSorts[a] = INSERT;
			break;
		}
		choice = secChoice;

	}
	
	
	

	
	
	return usrSorts;
}