#ifndef NUTILITY_H
#define NUTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

#define asize(x) (sizeof(x) / sizeof(x[0]))

void randomize(void);
void set_array_random(int *pArr, int size);
void print_array(const int *pArr, int size);
void sort_array(int *pa, int size);
void sgets(char *p);
void ispalindrom(char *pa, int len);
void swap(int *a, int *b);
int sum_arr(const int *p, int size);
double get_mean(const int *p, int size);
double get_std_dev(const int *p, int size);
void get_reverse_array(int *p, int size);
int get_max_array(const int *p, int size);
int get_min_array(const int *p, int size);
void get_max_min_array(const int *p, int size, int *max, int *min);
void copy_array(int *pdest, const int *psource, int size);
void bubble_sort(int *p, int size);
void swap_array(int *p1, int *p2, int size);
void reverse_copy(int* pdest, const int* psource,int size);
void printArray_alternative(const int* ps,const int* pe);

#endif // UTILITY_H