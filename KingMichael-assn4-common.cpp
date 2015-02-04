//*****************************************************************************
// FILE NAME: KingMichael-assn3common.h
// DESCRIPTION: This file contains the ADT structure definitions and constant
//              definitions
//
//****************************************************************************

#include <string>

using namespace std;

const int ARRAY_SIZE = 100000;          //Max size of array
const int MAX_ARRAY_NUM = 30000;        //Max value for static array input
const string PAUSE = "\n\tPress any key to continue . . . ";

// type definition of a pointer to a function with 2 int input parameters
// and an int return value
typedef int (*funcPtrType)(int list[], int length);
