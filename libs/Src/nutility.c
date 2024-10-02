#include "nutility.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void randomize(void)
{
  srand((unsigned)time(NULL));
}

void set_array_random(int *pArr, int size)
{
  while (size--)
    *pArr++ = rand() % 1000;
}

void print_array(const int *pArr, int size)
{
  for (int i = 0; i < size; ++i)
  {
    if (i && i % 10 == 0)
      putchar('\n');
    printf("%3d ", pArr[i]);
  }
  printf("\n---------------------------------------\n");
}

void sort_array(int *pa, int size)
{

  for (int i = 0; i < size - 1; ++i)
  {
    for (int k = 0; k < size - 1 - i; ++k)
    {
      if (pa[k] > pa[k + 1])
      {
        int temp;
        temp = pa[k];
        pa[k] = pa[k + 1];
        pa[k + 1] = temp;
      }
    }
  }
}

void sgets(char *p)
{

  int len = 0;
  int ch;
  while ((ch = getchar()) != '\n')
  {
    p[len++] = (char)ch;
  }
  p[len] = '\0';
}


void ispalindrom(char *pa,int len)
{
    int idx_start = 0;
    int idx_end =len - 1;

    while (1)
    {

        while (idx_start <= idx_end && !(isalpha(pa[idx_start])))
        {
            idx_start++;
        }

        while (idx_start <= idx_end && !(isalpha(pa[idx_end])))
        {
            idx_end--;
        }
        if(idx_start > idx_end || tolower(pa[idx_start]) != tolower(pa[idx_end])){
          break;
        }
        idx_start++;
        idx_end--;
    }
    if(idx_start > idx_end){
        printf("Bu bir palindromdur.\n");
    }
    else{
      printf("Bu bir palindrom degildir.\n");

    }
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}