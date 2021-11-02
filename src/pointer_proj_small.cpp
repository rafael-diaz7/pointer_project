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
	
	// how many tags found in file? -> completed in stringmanip.cpp
	
	// how much memory to allocate -> completed in stringmanip.cpp
	
	//TODO allocate memory
	
	//TODO replace original tag with new tags
	
	//TODO deallocate any memory allocated
}
