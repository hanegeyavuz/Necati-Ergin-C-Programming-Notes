#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nutility.h"

/*ODEV2*/
//BOLUM1
// dizinin elemaninin degeri kadar yildizi ekrana bastır.

//BOLUM2

//Bolum 1 de ekrana bastirilan örüntünün 90 derece saat yönünün tersine döndürülmüş halini ekrana bastır.

#if 1
#define SIZE 10
int main(void)
{

	int a[SIZE];
	randomize;
	for (int i = 0; i < SIZE; ++i)
	{
		a[i] = rand() % 20 + 1;
		printf("%d ", a[i]);
	}
	printf("\n");

	for (int i = 0; i < SIZE; ++i)
	{

		for (int j = 0; j < a[i]; ++j)
		{

			putchar('*');
		}
		putchar('\n');
	}
}

#endif

