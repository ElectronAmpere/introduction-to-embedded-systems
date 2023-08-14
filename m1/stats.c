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
	(void)print_statistics(test, SIZE);
	printf("Sorted Array \t\t: [ ");
  	(void)sort_array(test, SIZE);
  	(void)print_array(test, SIZE);
	printf("]\n");
  
  return(0);
}

/* Add other Implementation File Code Here */
int find_mean(unsigned char *parray, int array_size)
{
	int sum  = 0,
		mean = 0,
		size = 0;
	if ((parray != NULL) && (array_size > 0)){
		size = array_size;
		while(size > 0){
			sum += *parray;
			parray++;
			size--;
		}
		mean = sum/array_size;
	} else {
		mean = 0;
	}
	return (mean);
}

int find_maximum(unsigned char *parray, int array_size)
{
	int max = 0;
	if ((parray != NULL) && (array_size > 0)){
		max = *parray;
		while (array_size > 0){
			parray++;
			if (max >= *parray){
				max = max;
			} else {
				max = *parray;
			}
			array_size--;
		}
	} else {
		max = 0;
	}
	return (max);
}

int find_minimum(unsigned char *parray, int array_size)
{
	int min = 0;
	if ((parray != NULL) && (array_size > 0)){
		min = *parray;
		while (array_size > 0){
			parray++;
			if (min <= *parray){
				min = min;
			} else {
				min = *parray;
			}
			array_size--;
		}
	} else {
		min = 0;
	}
	return (min);
}

int sort_array(unsigned char *parray, int array_size)
{
	int ret = SORTED, min_idx = 0;
	if ((parray != NULL) && (array_size > 0)){
		for (int i = 0; i < (array_size - 1); i++){
			min_idx = i;
			for (int j = i+1; j < array_size; j++){
				if (*(parray + j) < *(parray + min_idx)){
					min_idx = j;
				}
				if (min_idx != i){
					element_swap((parray + min_idx), (parray + i));
				}
			}
		}
		ret = SORTED;
	} else {
		ret = UNSORTED;
	}
	return (ret);
}

int find_median(unsigned char *parray, int array_size)
{
	int median = 0, ret = 0, median_l = 0, median_r = 0;

	if ((parray != NULL) && (array_size > 0)){
		ret = sort_array(parray, array_size);

		if (ret == SORTED){
			if ((array_size % 2) == 0)
			{
				median_l = (array_size / 2) - 1;
				median_r = (median_l + 1);
				median   = (*(parray + median_l) + *(parray + median_r));
				median   /= 2;
			} else {
				median = (*(parray + (array_size % 2)));
			}
		}
	}
	return (median);
}

int print_array(unsigned char *parray, int array_size)
{
	int ret = PRINTED;
	if ((parray != NULL) && (array_size > 0)){
		while(array_size > 0){
			printf("%d", *parray);
			parray++;
			array_size--;
			if (array_size > 0){
				printf(", ");
			} else {
				printf(" ");
			}
		}
		ret = PRINTED;
	} else {
		ret = NOTPRINTED;
	}
	return (ret);
}

void element_swap(unsigned char *p1, unsigned char *p2)
{
	unsigned char temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int print_statistics(unsigned char *parray, int array_size)
{
	int ret = PRINTED;
  	
	printf("Mean 	\t\t: %d\n", find_mean(parray, SIZE));
  	printf("Max 	\t\t: %d\n", find_maximum(parray, SIZE));
  	printf("Min 	\t\t: %d\n", find_minimum(parray, SIZE));
	printf("Median  \t\t: %d\n", find_median(parray, SIZE));
	return (ret);
}