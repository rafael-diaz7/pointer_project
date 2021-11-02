/*
 * fileio.h
 *
 *  Created on: 11/1
 *      Author: rafaeldiaz
 */

#include <fstream>
#include <string>
#include "../includes/fileio.h"
#include "../includes/constants.h"

using namespace std;

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
int writeFile(std::string &filename,char *contents){
    ofstream writer;
    writer.open(filename.c_str());
    if (!writer.is_open()){
        return FAIL_CANNOT_OPEN_FILE;
    }
    // writer should be open
    writer << contents;
    writer.close();
    return SUCCESS;
}

/**
 * Reads info from filename into contents
 * 
 * \param filename where data is 
 * \param contents data to write to file
 * \return
 *        FAIL_CANNOT_OPEN_FILE  if filename cannot be opened
 *        SUCCESS
 */
int readFile(std::string &filename,std::string &contents){
    ifstream file;
    file.open(filename.c_str()); 
    if (!file.is_open()){
        return FAIL_CANNOT_OPEN_FILE;
    }
    // file will be open
    string info = "";
    while (!file.eof()){
        getline(file, info); // put file stream line into info
        contents += info;
    }
    file.close();

    return SUCCESS;
}
