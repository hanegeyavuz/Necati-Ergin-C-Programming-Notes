#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nutility.h"

#if 0

#define NGAMES 10000000


int roll_dice(void){

	int dice1 = rand() % 6 + 1; // kotu teknik

	
	int dice2 = rand() % 6 + 1; // kotu teknik
	return dice1 + dice2;

}

int game_(int dice){
	int new_dice;
	while(1){
		new_dice = roll_dice();
		if(new_dice == dice){return 1;}
		else if(new_dice == 7) {return 0;}
	}
	return 0;
}

// returns 1 for win, 0 for loss
int game(void){
	int dice = roll_dice();
	switch(dice){
	case 7:
	case 11: return 1;
	case 2:
	case 3:
	case 12: return 0;
	default: return game_(dice);
	}



}

int main(void){
int win_count = 0;
	for(int i = 0; i < NGAMES; ++i){
		win_count += game();
	
	
	}

	printf("kazanma olasiligi: %f\n",((double)win_count * 100) / NGAMES);

}

#endif

#if 0 

int main(void){
	
	int x = 10;
	int y = 3;
	
	double d1 =  x / y;
	double d2  = (double)x / y;
	double d3  = x / (double)y;
	
	printf("d1 = %f\n",d1);
	printf("d2 = %f\n",d2);
	printf("d3 = %f\n",d3);

}

#endif


#if 0

int main(void){

	unsigned char c = 178;
	if(c == 178) {
		printf("dogru\n");
	}
	else{
		printf("yanlis\n");
	}
	printf("c = %d\n",c);
}

#endif

#if 0

#define SIZE 20

int main(void){
	
	int a[SIZE];
	
	randomize();
	set_array_random(a,SIZE);
	print_array(a,SIZE);

	int sum = 0;
	for(int i = 0; i < SIZE; ++i){
		sum += a[i];
		
	}
	printf("sum = %d\n",sum); // toplamını bulma formülü
	
	printf("mean = %d\n",(double)sum / SIZE); // ortalamasını bulma formülü

	int max = a[0];
	int min = a[0];

	for(int i = 1; i < SIZE; ++i){

		max = a[i] > max ? a[i] : max ; // max 
		min = a[i] < min ? a[i] : min ; // min
	}
	printf("maximum = %d\n",max);
	printf("minimum = %d\n",min);


}

#endif

// ODEV 1
// Dizi içerisindeki unique elemanları bulunuz.
#if 0

#define SIZE 20

int main(void)
{
	int a[SIZE];
	int flag = 0;
	for (int i = 0; i < SIZE; ++i)
	{

		a[i] = rand() % 20;
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i < SIZE; ++i)
	{
		flag = 0;
		for (int j = 0; j < SIZE; ++j)
		{
			if (a[i] == a[j])
			{
				// printf("%d ile %d esittir\n",i,j);
				flag++;
			}
		}
		if (flag == 1)
		{
			printf("unique = %d", a[i]);
		}
	}
}

#endif


// LINEAR SEARCH ALGORITHM
#if 0

#define SIZE 20

int main(void){
	int a[SIZE];
	randomize();
	set_array_random(a,SIZE);
	print_array(a,SIZE);
	int key;
	int i;

	printf("Aranacak degeri giriniz: ");
	scanf("%d",&key);
	for(i = 0; i < SIZE && a[i] != key; ++i){
		; // null statement
	}

	if(i < SIZE){
		printf("bulundu idx = %d\n",i);
	}
	else{
		printf("bulunamadi\n");


	}

}

#endif

#if 0
// Fonksiyon her çağırıldığında 0-urand_max arasında rastgele sayı üretmeli.
// bu durumda fonksiyon en fazla URAND_MAX kadar sayi üretebilir.
// Daha fazla çağırılırsa unique random sayi kalmamışsa hata olarka -1 döndürmeli.
#define URAND_MAX      20

int urand(void){

	static int flags[URAND_MAX] = { 0 };
	static int cnt = 0;

	if(cnt == URAND_MAX)
		return -1;


	int val;
	for(; ;){ // while(1) ile aynı şey
	val = rand() % URAND_MAX;
		if(flags[val]  == 0){
			break;
		}

	}

	flags[val] = 1;
	++cnt;

	return val;
}

int main(void){
	randomize();
	for(int i = 0; i < URAND_MAX; ++i){

		printf("%d ",urand());
	}
	printf("\n\n%d\n ",urand());


}

#endif


// Diziyi ters çevirme algoritması
#if  0

#define SIZE 20

int main(void){
	int a[SIZE];
	randomize();
	set_array_random(a,SIZE);
	print_array(a,SIZE);
	for(int i = 0; i < SIZE/2 ; ++i){
		int temp = a[i];
		a[i] = a[SIZE-i-1];
		a[SIZE-i-1] = temp;	}
	print_array(a,SIZE);
}
#endif

