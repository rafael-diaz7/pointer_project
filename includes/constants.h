/*
 * constants.h
 *
 *  Created on: Feb 28, 2021
 *      Author: keith
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include <string>

const char HELP_CHAR = 'h';
const int HELP_NUMBER_ARGUMENTS =2;
const std::string HELP_STRING1 = "This program expects 4 arguments; an inputfile, an ouput file, a tag to search for, a replacement tag";
const std::string HELP_STRING2 = "This program opens and reads inputfile, replaces all occurrences of tag with tag_replacement,\nthen writes the result to output file";

const int EXPECTED_NUMBER_ARGUMENTS =5;
const std::string CANNOT_OPEN_FILE = "Cannot open input file";

const int SUCCESS = 0;
const int FAIL_WRONG_NUMBER_ARGS = -1;
const int INVALID_NULL_PTR_DETECTED = -2;
const int FAIL_CANNOT_OPEN_FILE = -4;

#endif /* CONSTANTS_H_ */
