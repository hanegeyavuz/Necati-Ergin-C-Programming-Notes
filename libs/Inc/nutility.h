#ifndef   NUTILITY_H
#define   NUTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define   asize(x)      (sizeof(x) / sizeof(x[0]))

void randomize(void);
void set_array_random(int* pArr, int size);
void print_array(const int* pArr, int size);
void sort_array(int* pa, int size);
void sgets(char* p);
void ispalindrom(char *pa,int len);


#endif // UTILITY_H