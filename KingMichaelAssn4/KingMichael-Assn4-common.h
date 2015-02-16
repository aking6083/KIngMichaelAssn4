//*****************************************************************************
// FILE NAME: KingMichael-Assn4-common.h
// DESCRIPTION: Our common stuff
// CLASS/TERM: CS 372, 15S8W1
// DESIGNER: Shawn Michael & Adam King
//*****************************************************************************

#include "stdafx.h"
#include <iomanip>
#include <iostream>      //cin and cout
#include <cstddef>       // used for assigning NULL
#include <cctype>	     //for cctype predefined functions
#include <ctime>			//for time seed in srand function
#include <cstdlib>			//for c standard library predefined functions
#include <string>

using namespace std;

enum sortType { BUBBLE, INSERT, MERGE, QUICK, EXIT, NONE };
const int NUM_CHOICES = 5;
const char LTR_CHOICES [NUM_CHOICES] = { 'B', 'I', 'M', 'Q', 'E' };
const string SORT_TYPE_STR[NUM_CHOICES] = { "Bubble", "Insert", "Merge", "Quick" };

const char BBL_SRT = 'B';
const char MRG_SRT = 'M';
const char QCK_SRT = 'Q';
const char INSRT_SRT = 'I';
const char EXIT_SRT = 'E';

const int SELECT_STRING = 10;
const int ARRAY_SIZE = 10000;          //Max size of array
const int MAX_ARRAY_NUM = 30000;        //Max value for static array input
const int BOTTOM_IDX = 0;
const string INVALID_NUM = "\n\tINVALID NUMBER!!!";
const int MAX_CHOICES = 2;
const int MIN_CHOICES = 1;