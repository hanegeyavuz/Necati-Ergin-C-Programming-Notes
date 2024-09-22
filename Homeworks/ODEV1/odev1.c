#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nutility.h"

// ODEV 1 
// Dizi içerisindeki unique elemanları bulunuz.
#if 1

#define SIZE 20

int main(void){

	int a[SIZE];
	int cnt = 0;
	for(int i = 0; i < SIZE; ++i){

		a[i] = rand() % 20; 
		printf("%d ",a[i]); 
	}
	printf("\n");
	for(int i = 0; i < SIZE; ++i){
	    cnt = 0;
		for(int j = 0; j < SIZE; ++j){
			if(a[i] == a[j]){
				//printf("%d ile %d esittir\n",i,j);
				cnt++;
			}
			
		}
		if(cnt == 1){
		printf("unique = %d \n", a[i]);

		}		
	}
	printf("cnt = %d\n",cnt);

}

#endif