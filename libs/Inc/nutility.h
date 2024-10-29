#ifndef NUTILITY_H
#define NUTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

#define asize(x) (sizeof(x) / sizeof(x[0]))

void randomize(void);
void set_array_random(int *pArr, size_t size);
void print_array(const int *pArr, size_t size);
void sort_array(int *pa, size_t size);
void sgets(char *p);
int ispalindrom(char *pa, size_t size);
void swap(int *a, int *b);
int sum_arr(const int *p, size_t size);
double get_mean(const int *p, size_t size);
double get_std_dev(const int *p, size_t size);
void get_reverse_array(int *p, size_t size);
int get_max_array(const int *p, size_t size);
int get_min_array(const int *p, size_t size);
void get_max_min_array(const int *p, size_t size, int *max, int *min);
void copy_array(int *pdest, const int *psource, size_t size);
void bubble_sort(int *p, size_t size);
void swap_array(int *p1, int *p2, size_t size);
void reverse_copy(int* pdest, const int* psource,size_t size);
void printArray_alternative(const int* ps,const int* pe);
int *get_Array_Max(const int *p, size_t size);
int *get_Array_Min(const int *p, size_t size);
void selection_sort(int* p, size_t size);
int *search_in_array(const int *p, size_t size, int key);

#endif // NUTILITY_H