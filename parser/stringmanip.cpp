/*
 * stringmanip.h
 *
 *  Created on: 11/1, 2021
 *      Author: rafaeldiaz
 */

#include <iostream>
#include <string.h>
#include "../includes/constants.h"

namespace KP{
	/**
	 * Calculate the exact amount of memory needed to allocate a that consists of the old string with all tags replaced by tag_replacements.
	 * Don't forget the terminating null!
	 * 
	 * ex. src="a large ship"
	 *     tag="large"
	 *     tag_replacement="really large"
	 *     
	 *     then
	 *     len_src = 14
	 *     numbTagsToReplace=1
	 *     len_tag=5
	 *     len_tag_replacement=12
	 *     
	 *     the function should return 22
	 * 
	 * \param len_src - length of original string
	 * \param numbTagsToReplace - number of tags to replace in the original string
	 * \param len_tag - length of the tag
	 * \param len_tag_replacement - length of the tag replacement
	 * \return
	 */
	int amountOfMemoryToAllocateForNewString(int len_src, int numbTagsToReplace, int len_tag, int len_tag_replacement){
		int diff = len_tag_replacement - len_tag;
		return len_src + (diff * numbTagsToReplace) + 1;
	}
	
	/**
	 * If src,new_src, tag or tag_replacment are null then returns INVALID_NULL_PTR_DETECTED
	 * 
	 * Copies src char string to new_src char string, replaces all tag occurrences with tag_replacement.
	 * Please ensure that new_src is allocated and of proper size before calling this function
	 * 
	 * ex.
	 * 	src ="a large bucket on a large ship" 
		tag="large" 
		tag_replacement="really large"
		then when the function returns 
		new_src="a really large bucket on a really large ship"
	 * 
	 * \param src  initial char string, may be deleted and reallocated by this function
	 * \param new_src char string with enough space to hold src string with all tag occurrences replaced by tag_replacement
	 * \param tag  the tag to search for 
	 * \param tag_replacement  replaces all occurrences of tag
	 * \return INVALID_NULL_PTR_DETECTED one or more of src, tag or tag_replacement is NULL 
	 * 		   SUCCESS everything went well, src contains the 
	 */
	int replace(const char *src, char *new_src, const char *tag, const char *tag_replacement){
		if (src == 0 || new_src == 0 || tag == 0 || tag_replacement == 0){
			return INVALID_NULL_PTR_DETECTED;
		}
		const char *src_ptr = &src[0];
		char *new_ptr = &new_src[0];

		int src_start = 0;
		int new_start = 0;
		while (src_start <= strlen(src)){
			if (*(src_ptr + src_start) == tag[0]){ // move pointer across, compare to first char of tag
				if (strncmp((src_ptr+src_start), tag, strlen(tag)) == 0){
					strncpy((new_ptr+new_start), tag_replacement, strlen(tag_replacement));
//					src_ptr += strlen(tag); // move pointer ahead past the tag
//					new_ptr += strlen(tag_replacement); // move other pointer ahead by the replacement
					new_start += strlen(tag_replacement);
					src_start += strlen(tag);
				}
			}
			strncpy(new_ptr+new_start,src_ptr+src_start, 1);
//			strncpy(new_ptr, src_ptr, 1);
//			new_src[new_start] = src[src_start];
			new_start++;
			src_start++;
		}

		return SUCCESS;
	}
	
	/**
	 * how often does the string in tag occur in src? 
	 * 
	 * \param src  initial char string
	 * \param tag  the tag to search for
	 * \return INVALID_NULL_PTR_DETECTED one or more of src, or tag is NULL
	 *         otherwise the number of times tag occurs in src
	 */
	int findNumbOccurrences(const char *src,  const char *tag){
		if (src == 0 || tag == 0){
			return INVALID_NULL_PTR_DETECTED;
		}
		int srcSize = strlen(src);
		int tagSize = strlen(tag);
		int count = 0;
		const char *pointer = &src[0]; // pointer for src
		for (int i = 0; i < srcSize; i++){
			const char *curr = pointer+i;
			if (*(curr) == tag[0]){ // move pointer across, compare to first char of tag
				if (strncmp(curr, tag, tagSize) == 0){
					count++;
				}
			}
		}
		return count;
	}
}
