// FUNCTIONS: Header - Displays program title
//            PopArray - Populates randArray while calling the rand() function
//
// Implementors: Unknown and Shawn Michael
//*****************************************************************************
#include <iostream>     // cin and cout
#include <iomanip>      //setprecion, setw
#include <cstddef>      // used for assigning NULL
#include <string>		//for use of string
#include <cctype>		//for cctype predefined functions
#include <ctime>        // for clock function
using namespace std;

#include "Michael-assn4-funcs.h"    //File for Shawn Michael's functions
#include "Michael-common.h"         //File with common params

int main()
{
    int numIteration;
    char firstChoice,
         secChoice;

    Header();
    do {
        DisplayMenu();
        cout << "\n\tEnter two letter choices (or EE to exit): ";
        cin >> firstChoice >> secChoice;

        firstChoice = toupper(firstChoice);
        secChoice = toupper(secChoice);

        if ((firstChoice != 'E') || (secChoice != 'E')) {
            testing(firstChoice, secChoice);
        } //end if
    }while ((firstChoice != 'E') || (secChoice != 'E'));

    return 0;
}


