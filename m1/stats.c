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
 * @file <stats.c> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author VigneshRR
 * @date 13 Aug, 2023
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
							  114, 88,   45,  76, 123,  87,  25,  23,
							  200, 122, 150, 90,   92,  87, 177, 244,
							  201,   6,  12,  60,   8,   2,   5,  67,
								7,  87, 250, 230,  99,   3, 100,  90};

  	/* Other Variable Declarations Go Here */
  	int mean = 0, max = 0, min = 0, median = 0;

  	/* Statistics and Printing Functions Go Here */
	printf("Array - Unsorted:\n");
	(void)print_array(test, sizeof(test));
	
	(void)sort_array(test, sizeof(test));
	printf("\nArray - Sorted:\n");
	(void)print_array(test, sizeof(test));
	
	(void)print_statistics(test, sizeof(test));

	return(0);
}

/* Add other Implementation File Code Here */
int find_mean(unsigned char *parray, int array_size)
{
	/* Initialise values */
	float mean = 0.0;
	int result = 0, size = array_size;

	/* Assuming array size is n and not n-1 */
	while ((0 < size) && (NULL != parray)){
		mean += *parray;
		++parray;
		--size;
	}

	/* Calculate mean value */
	mean /= (float)array_size;
	result = (int)mean;

	/* Result */
	return (result);
}

int find_maximum(unsigned char *parray, int array_size)
{
	/* Initialise values */
	int result = 0, max = 0;	
	
	/* Initial dummy max value */
	max = *parray;

	/* Finding max value */
	while((0 < array_size) && (NULL != parray)){
		if (*parray >= max){
			max = *parray;
		} else {
			max = max;
		}
		++parray;
		--array_size;
	}
	
	/* Copy result */
	result = max;

	return (result);
}

int find_minimum(unsigned char *parray, int array_size)
{
	int result = 0, min = 0;

	/* Initialise dummy minimum value */
	min = *parray;

	/* Finding the min value */
	while((0 < array_size) && (NULL != parray)){
		if (*parray <= min){
			min = *parray;
		} else {
			min = min;
		}
		++parray;
		--array_size;
	}

	/* Copy the result */
	result = min;

	return (result);
}

int sort_array(unsigned char *parray, int array_size)
{
	int result = 0, size = array_size, max = 0;
	unsigned char *t_parray = parray;

	while ((0 < array_size) && (NULL != parray)){
		
		/* Initialize max value */
		max = *parray;
		t_parray = parray;
		size = array_size;
		
		/* Sorting from max to min value */
		while ((0 < size) && (NULL != t_parray)){
			if (*t_parray >= max){
				max = *t_parray;

				/* Swapping element in array */
				element_swap(parray, t_parray);
			} else {
				max = max;
			}
			++t_parray;
			--size;
		}
		++parray;
		--array_size;
	}
	result = 0;
	return (result);
}

int find_median(unsigned char *parray, int array_size)
{
	int result = 0, median_points = 0, even = array_size;
	float median = 0.0;

	/* Finding median point */
	if (0 == (even%2)){
		median_points = (array_size/2);
		--median_points;
		median = ((*(parray + median_points) + *(parray + median_points)) / 2.0);
	} else {
		median = *(parray + median_points);
	}

	/* Copy the result */
	result = (int)median;

	return (result);
}

int print_array(unsigned char *parray, int array_size)
{
	int result = -1;

	while((0 < array_size) && (NULL != parray)){
		if (0 != (1 - array_size)){
			printf("%d, ", *parray);
		} else {
			printf("%d", *parray);
		}
		++parray;
		--array_size;
	}
	printf("\n");

	result = 0;

	return (result);
}

void element_swap(unsigned char *p1, unsigned char *p2)
{
	int swap = 0;

	swap = *p1;
	*p1 = *p2;
	*p2 = swap;
}

int print_statistics(unsigned char *parray, int array_size)
{
	int result = -1;

	printf("\nArray Statistics (Rounded off to closest integer) \n");
	printf("Mean\t: %d\n",find_mean(parray, array_size));
	printf("Max\t: %d\n",find_maximum(parray, array_size));
	printf("Min\t: %d\n",find_minimum(parray, array_size));
	printf("Median\t: %d\n",find_median(parray, array_size));
	
	result = 0;

	return (result);
}