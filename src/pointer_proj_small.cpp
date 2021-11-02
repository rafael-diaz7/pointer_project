//============================================================================
// Name        : pointer_proj_small.cpp
// Author      : Rafael Diaz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
#include "../includes/constants.h"
#include "../includes/stringmanip.h"
#include "../includes/fileio.h"


int main(int argc, char *argv[]) {	
	//Get commandline arguments
	if (argc == 2 && argv[1][0] == HELP_CHAR){
		cout << HELP_STRING1 << HELP_STRING2 << endl;
		return SUCCESS;
	}
	if (argc != EXPECTED_NUMBER_ARGUMENTS){
		return FAIL_WRONG_NUMBER_ARGS;
	}

	string input = string(argv[1]);
	string output = string(argv[2]);
	string tag = string(argv[3]);
	string replacement = string(argv[4]);

	//can we read file? Fail if not -> completed in fileio.cpp
	string string1;
	readFile(input, string1); // adds item into string1
	// how many tags found in file? -> completed in stringmanip.cpp
	int tags = KP::findNumbOccurrences(string1.c_str(), tag.c_str());
	// how much memory to allocate -> completed in stringmanip.cpp
	int mem = KP::amountOfMemoryToAllocateForNewString(strlen(string1.c_str()), tags, strlen(tag.c_str()), strlen(replacement.c_str()));
	//allocate memory
	char *arr = new char[mem];
	//replace original tag with new tags
	KP::replace(string1.c_str(), arr, tag.c_str(), replacement.c_str());
	//deallocate any memory allocated
	writeFile(output, arr);
	if (arr){
		delete [] arr;
		arr = 0;
	}
}
