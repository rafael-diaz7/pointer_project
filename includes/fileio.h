/*
 * fileio.h
 *
 *  Created on: Mar 1, 2021
 *      Author: keith
 */

#ifndef FILEIO_H_
#define FILEIO_H_
#include <string>

/**
 * write data in contents to filename 
 * 
 * \param filename: where data will go, overwrite if already there
 * \param contents: data to write to filename
 *        hint:  you can get a const char * by calling the method .c_str() on a std::string 
 * \return
 *        INVALID_NULL_PTR_DETECTED if contents ==NULL 
 *        SUCCESS otherwise 
 */
int writeFile(std::string &filename,char *contents);

/**
 * Reads info from filename into contents
 * 
 * \param filename where data is 
 * \param contents data to write to file
 * \return
 *        FAIL_CANNOT_OPEN_FILE  if filename cannot be opened
 *        SUCCESS
 */
int readFile(std::string &filename,std::string &contents);

#endif /* FILEIO_H_ */
