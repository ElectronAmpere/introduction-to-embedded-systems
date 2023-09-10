/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author Vignesh RR
 * @date 13 Aug, 2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * This function prints the statistics of an array of unsigned char.
 * Statistics:
 * 1. Mean = Average of the elements in the array
 * 2. Maximum = Maximum value of the element present in the array
 * 3. Minimum = Minimum value of the element present in the array
 * 4. Median = The middle value of the elements presented in the array
 *      even elements = (median left + median right)/2
 *      odd elements = centre value
 * 
 *
 * @param parray The address of the unsigned char array 
 * @param array_size The size of the unsigned char array
 *
 * @return void
 */
void print_statistics(unsigned char *parray, int array_size);

/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * This function prints the array elements given to it, array should not be NULL
 *
 * @param parray The address of the unsigned char array 
 * @param array_size The size of the unsigned char array
 *
 * @return void
 */
void print_array(unsigned char *parray, int array_size);

/**
 * @brief Sorts the array from largest to smallest.
 *
 * Given an array of data and a length, sorts the array from largest to smallest
 *
 * @param parray The address of the unsigned char array 
 * @param array_size The size of the unsigned char array
 *
 * @return void
 */
void sort_array(unsigned char *parray, int array_size);

/**
 * @brief Finds the median of the array provided
 *
 * Given an array of data and a length, returns the median value
 *
 * @param parray The address of the unsigned char array
 * @param array_size The size of the unsigned char array
 *
 * @return median value from the array
 */
unsigned char find_median(unsigned char *parray, int array_size);

/**
 * @brief Finds the mean of the array provided
 *
 * Given an array of data and a length, returns the mean
 *
 * @param parray The address of the unsigned char array 
 * @param array_size The size of the unsigned char array as n
 *
 * @return mean value from the array
 */
unsigned char find_mean(unsigned char *parray, int array_size);

/**
 * @brief Finds the maximum value in the array provided
 *
 * Given an array of data and a length, returns the maximum
 *
 * @param parray The address of the unsigned char array 
 * @param array_size The size of the unsigned char array
 *
 * @return maximum value from the array
 */
unsigned char find_maximum(unsigned char *parray, int array_size);

/**
 * @brief Finds the minimum value in the array provided
 *
 * Given an array of data and a length, returns the minimum
 *
 * @param parray The address of the unsigned char array 
 * @param array_size The size of the unsigned char array
 *
 * @return minimum value from the array
 */
unsigned char find_minimum(unsigned char *parray, int array_size);

/**
 * @brief Swaps the elements given
 *
 * Swaps the elements given as in unsigned char
 *
 * @param parray The address of the unsigned char array 
 * @param array_size The size of the unsigned char array
 *
 * @return void
 */
void element_swap(unsigned char *p1, unsigned char *p2);

#endif /* __STATS_H__ */
