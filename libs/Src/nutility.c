#include "nutility.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void randomize(void){
  srand((unsigned)time(NULL));
}

void set_array_random(int* pArr, int size){
  while (size--)
    *pArr++ = rand() % 1000;
}

void print_array(const int* pArr, int size){
  for (int i = 0; i < size; ++i){
    if (i && i % 10 == 0)
      putchar('\n');
    printf("%3d ", pArr[i]);
  }
  printf("\n---------------------------------------\n");
}

void sort_array(int* pa, int size){

  for(int i = 0; i < size - 1; ++i){
    for(int k = 0; k < size - 1 - i; ++k){
      if(pa[k] > pa[k+1]){
        int temp;
        temp = pa[k];
        pa[k] = pa[k + 1];
        pa[k + 1] = temp;
      }

    }

  }

}