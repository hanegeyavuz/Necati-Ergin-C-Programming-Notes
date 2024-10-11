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
    if (i && i % 20 == 0)
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

void ispalindrom(char *pa, int len)
{
  int idx_start = 0;
  int idx_end = len - 1;

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
    if (idx_start > idx_end || tolower(pa[idx_start]) != tolower(pa[idx_end]))
    {
      break;
    }
    idx_start++;
    idx_end--;
  }
  if (idx_start > idx_end)
  {
    printf("Bu bir palindromdur.\n");
  }
  else
  {
    printf("Bu bir palindrom degildir.\n");
  }
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int sum_arr(const int *p, int size)
{
  int sum = 0;
  while (size--)
  {
    sum += *p;
    ++p;
  }
  // for(int i = 0; i < size ; ++i){
  // 	sum += p[i];

  // }
  return sum;
}

double get_mean(const int *p, int size)
{
  return (double)(sum_arr(p, size) / size);
}

double get_std_dev(const int *p, int size)
{
  double mean = get_mean(p, size);
  double sum_square;
  for (int i = 0; i < size; ++i)
  {
    sum_square += (p[i] - mean) * (p[i] - mean);
  }
  return sqrt(sum_square / (size - 1));
}

void get_reverse_array(int *p, int size)
{

  for (int i = 0; i < size / 2; ++i)
  {
    swap(p + i, p + size - 1 - i);
    // swap(&p[i], &p[size - 1 - i]); ALTERNATIF OLARAK BU KOD DA YAZILABILIR
  }
}

int get_max_array(const int *p, int size)
{
  int max = *p;
  for (int i = 0; i < size; ++i)
  {
    max = p[i] > max ? p[i] : max;
  }
  return max;
}
int get_min_array(const int *p, int size)
{
  int min = *p;
  for (int i = 0; i < size; ++i)
  {
    min = p[i] < min ? p[i] : min;
  }
  return min;
}

void get_max_min_array(const int *p, int size, int *max, int *min)
{
  *min = *p;
  *max = *p;
  for (int i = 0; i < size; ++i)
  {
    *min = p[i] < *min ? p[i] : *min;
    *max = p[i] > *max ? p[i] : *max;
  }
}
void copy_array(int *pdest, const int *psource, int size)
{
  /*FIRST WAY*/
  // for(int i = 0; i < size; ++i){
  //   pdest[i] = psource[i];
  // }
  /*SECOND WAY*/
  // while(size--){
  //   *pdest = *psource;
  //   ++pdest;
  //   ++psource;
  // }
  /*THIRD WAY */
  while (size--)
  {
    *pdest++ = *psource++;
  }
}

void bubble_sort(int *p, int size)
{
  for (int i = 0; i < size - 1; ++i)
  {
    for (int k = 0; k < size - 1 - i; ++k)
    {
      if (p[k] > p[k + 1])
      {
        swap((p + k), (p + k + 1));
      }
    }
  }
}

void swap_array(int *p1, int *p2, int size)
{

  while (size--)
  {
    swap(p1++, p2++);
  }
}


void reverse_copy(int* pdest, const int* psource,int size){

	int start_idx = 0;
	int end_idx = 0;
	
	pdest += size;
	while(size--){
		*--pdest = *psource++;

	}
}

void printArray_alternative(const int* ps,const int* pe){
	while(ps != pe){
		printf("%3d ",ps++);
	}
}