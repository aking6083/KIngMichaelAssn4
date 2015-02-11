#include <iomanip>
#include <iostream>      //cin and cout
#include <cstddef>       // used for assigning NULL
#include <cctype>	     //for cctype predefined functions
#include <ctime>			//for time seed in srand function
#include <cstdlib>			//for c standard library predefined functions

using namespace std;

enum sortType { BUBBLE, INSERT, MERGE, QUICK, EXIT };
const char BBL_SRT = 'B';
const char MRG_SRT = 'M';
const char QCK_SRT = 'Q';
const char INSRT_SRT = 'I';
const char EXIT_SRT = 'E';

const int SELECT_STRING = 10;
const int ARRAY_SIZE = 10;          //Max size of array
const int MAX_ARRAY_NUM = 30000;        //Max value for static array input
const int BOTTOM_IDX = 0;
const string INVALID_NUM = "\n\tINVALID NUMBER!!!";
const int MAX_CHOICES = 2;
const int MIN_CHOICES = 1;
