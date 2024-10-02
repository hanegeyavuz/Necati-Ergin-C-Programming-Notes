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
#define URAND_MAX 20

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
#if 0

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

#if 0

int main(void){
	
	printf("%zu",sizeof(long long int)); // NOT %zu size_t türü içindir.
}
#endif

// DIZININ ELEMAN SAYISINI BULMAK:
#if 0

int main(void){

	int a[100];

	int array_element_num = sizeof(a) / sizeof(5); // 5 yerine herhangi bir elemanı gelebilir.
	printf("dizinin eleman sayisi: %zu", array_element_num);

}

#endif

#if 0

//#define aasize(x) (sizeof(x)) / (sizeof(x[0]))
int main(void){

	int a[100];

	int array_element_num = asize(a);
	printf("dizinin eleman sayisi: %zu", array_element_num);

}

#endif

/*MULAKAT SORUSU*/
#if 0
//#define asize(x) (sizeof(x) / sizeof(x[0])) zaten header file içerisinde tanımlı.
int main(void){
	int a[5] = {1,2,3,4,5};
	
	for(int i = -2; i < asize(a) - 2; ++i){
		printf("%d",a[i+2]);
	}
}
#endif

/*ODEV2*/

// dizinin elemaninin degeri kadar her seferinde yildiz bastır ekrana.
// Sonrasında ise bu olusan goruntunun horizonal halini bastıran kodu yaz.
#if 0
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

/*BUBBLE SORT ALGORITHM*/
#if 0
#define SIZE 100
int main(void)
{

	int a[SIZE];

	randomize();

	set_array_random(a, SIZE);

	print_array(a, SIZE);
	printf("\n");

	for (int i = 0; i < SIZE - 1; ++i)
	{
		for (int k = 0; k < SIZE - 1 - i; ++k)
		{
			if (a[k] < a[k + 1])
			{
				int temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
			}
		}
	}
	print_array(a, SIZE);
}
#endif

/*MERGE ALGORITHM*/
#if 0
#define SIZE 20
int main(void)
{
	int idx_a = 0;
	int idx_b = 0;
	int a[SIZE];
	int b[SIZE];
	int c[SIZE * 2];

	randomize();

	set_array_random(a, SIZE);
	set_array_random(b, SIZE);

	sort_array(a, SIZE);
	sort_array(b, SIZE);

	print_array(a, SIZE);
	print_array(b, SIZE);
	for (int i = 0; i < 2 * SIZE; ++i)
	{
		if (idx_a == SIZE)
		{
			c[i] = b[idx_b++];
		}
		else if (idx_b == SIZE)
		{
			c[i] = a[idx_a++];
		}
		else if (a[idx_a] < b[idx_b])
		{
			c[i] = a[idx_a++];
		}
		else
		{
			c[i] = b[idx_b++];
		}
	}
	print_array(c, SIZE * 2);
}
#endif

/*Binary Search*/
#if 0
#define SIZE 20
int main(void)
{
	int a[SIZE];
	randomize();
	set_array_random(a, SIZE);
	sort_array(a, SIZE);
	print_array(a, SIZE);

	int idx_first = 0;
	int idx_last = SIZE - 1;
	int idx_mid;
	int key;
	printf("Aranacak degeri giriniz: ");
	scanf("%d", &key);

	while (idx_first <= idx_last)
	{
		idx_mid = (idx_first + idx_last) / 2;
		if (a[idx_mid] < key)
		{
			idx_first = idx_mid + 1;
		}
		else if (a[idx_mid] > key)
		{
			idx_last = idx_mid - 1;
		}
		else
		{
			break;
		}
	}
	if(idx_first > idx_last)
	{
		printf("Bulunamadi");
	}
	else{
	printf("aranilan deger dizinin %d indexinde bulunmaktadir.", idx_mid);
	}
}
#endif

/*STRINGS*/
#if 0
int main(void)
{
	char s[100];
	s[0] = 'M';
	s[1] = 'U';
	s[2] = 'S';
	s[3] = 'A';
	s[4] = '\0';
	
	for(int i = 0; s[i] != '\0'; ++i){
		printf("%c",s[i]);
		
	}
}
#endif

/*puts() fonksiyonu*/
#if 0
int main(void)
{
	char s[100];
	s[0] = 'M';
	s[1] = 'U';
	s[2] = 'S';
	s[3] = 'A';
	s[4] = '\0';
	//puts(&s[0]);
	puts(s); // Fonksiyon dizinin adresini istiyor. Dizinin ismi yazıldığında ilk elemanın adresi verilmiş olur.
}
#endif

#if 0
int main(void)
{
	char s[100];
	s[0] = 'M';
	s[1] = 'U';
	s[2] = 'S';
	s[3] = 'A';
	s[4] = '\0';
	
	printf("isim = %s",s);
}
#endif

#if 0
int main(void)
{
	 char s[] = "yavuz"; // Sonuna \0 eklenir.
	 puts(s); // Tanımsız davranış değil. 
}
#endif

#if 0
/*Tanımsız Davranış*/
int main(void)
{
	 char s[4] = "mert"; // C++ da geçersiz fakat C de geçerli. SONUNDA NULL KARAKTER YOK.
	 puts(s); // Tanımsız davranış. 
}
#endif
/*Boşluk bulunduran bir yazıyı standart inputtan almak 1*/
#if 0
#define SIZE 100

  int main(void){
    char str[SIZE];

    printf("Enter a string: ");
    gets(str);
    printf("You entered: (%s)\n", str);

  }
#endif
/*Boşluk bulunduran bir yazıyı standart inputtan almak 2*/
#if 0
#define SIZE 100

  int main(void){
    char str[SIZE];

    printf("Enter a string: ");
	int len = 0;
	int ch;
	while((ch = getchar()) != '\n'){
		str[len++] = (char)ch;
	}
	str[len] = '\0';
	printf("yazi (%s) uzunluk (%d)\n",str,len);
  }
#endif
/*sgets Funciton Test*/
#if 0

#define SIZE 100

  int main(void){
    char str[SIZE];

    printf("Enter a string: ");
	sgets(str);
  }

#endif

/*Array Lenght Algorithm (strlen function implemetation) */
#if 0
#define SIZE 100

int main(void)
{
	char str[SIZE];
	int len = 0;

	printf("Enter a string: ");
	sgets(str);
	for (int i = 0; str[i] != '\0'; ++i)
	{
		len++;
	}
	printf("yazinin uzunlugu %d 'dir.", len);
}

#endif

/*Yaziyi Tersten Yazdirma*/
#if 0
#define SIZE 100

int main(void)
{
	char str[SIZE];

	printf("Bir yazi giriniz: ");
	sgets(str);
	int i = 0;
	while(str[i]){
		++i;
	}
	while(i >= 0){
		putchar(str[i--]);
	}
	putchar('\n');
}

#endif

/*Palindrom Odevi */
#if 0
int main(void)
{
	char test_str1[255] = "en iyi mese bese mi yine?";
	char test_str2[255] = "Ana, Naci Dede ne dedi Canan'a?";
	char test_str3[255] = "Tras neden sart?";
	char test_str4[255] = "Para hazir. Ama Riza harap!";
	char test_str5[255] = "at sahibi gibi hasta";
	char test_str6[255] = "A man, a plan, a canal, Panama";
	char test_str7[255] = "A man, a plan, a canal, Panama?s^''";
	int len1 = asize(test_str1);
	int len2 = asize(test_str2);
	int len3 = asize(test_str3);
	int len4 = asize(test_str4);
	int len5 = asize(test_str5);
	int len6 = asize(test_str6);
	int len7 = asize(test_str7);
	printf(test_str1);printf("	");ispalindrom(test_str1, len1);
	printf(test_str2);printf("	");ispalindrom(test_str2, len2);
	printf(test_str3);printf("	");ispalindrom(test_str3, len3);
	printf(test_str4);printf("	");ispalindrom(test_str4, len4);
	printf(test_str5);printf("	");ispalindrom(test_str5, len5);
	printf(test_str6);printf("	");ispalindrom(test_str6, len6);
	printf(test_str7);printf("	");ispalindrom(test_str7, len7);
}
#endif

#if 0
/*Pointer Variable formatting*/
int main()
{
    int x = 10;
    int* a = &x;
    printf("pointer variable value = %p",a);
}
#endif

#if 0
/*adress of pointer variable*/
int main()
{
    int x = 10;
	int* ptr = &x;

	printf("&x  = %p\n",&x);
	printf("ptr  = %p\n",ptr);
	printf("&ptr  = %p\n",&ptr);
}

/*out:
&x  = 0x7ffd170b64dc
ptr  = 0x7ffd170b64dc
&ptr  = 0x7ffd170b64e0
*/
#endif

#if 0
/*Dereferencing Operator*/
int main()
{
    int x[] = {10,20,30};
	printf("before assign. a[0] = %d\n",x[0]);
    *x = 777;
    printf("after assign. a[0] = %d\n",x[0]);
}
#endif

#if 0
int main()
{
	int x = 35;
	printf("x = %d\n", x);

	int *ptr = &x;

	*ptr = 999;

	printf("x = %d\n", x);
	++*ptr;
	printf("x = %d\n", x);
}

/*
out:
x = 35
x = 999
x = 1000
*/
#endif

#if 0
int main()
{
	int x = 35;
	int y = 45;
	int z = 55;
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
	printf("\n", x);

	int *ptr = &x;
		*ptr = 999;
	ptr = &y;
		*ptr = 999;
	ptr = &z;
		*ptr = 999;

	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
}
/*
out:
x = 35
y = 45
z = 55

x = 999
y = 999
z = 999
*/
#endif

#if 0
/*pointerların adresini takas etmek*/
int main()
{
	int x = 10;
	int y = 20;
	int* p1 = &x;
	int* p2 = &y;

	printf("x = %d\n", x);
	printf("y = %d\n", y);

	int* ptemp = p1;
	p1 = p2;
	p2 = ptemp;

	++*p1;
	--*p2;
	printf("x = %d\n", x);
	printf("y = %d\n", y);
}
#endif

#if 0
/*Test of swap fucntion with call by reference*/
int main()
{
	int x = 31;
	int y = 69;

	int *p1 = &x;
	int *p2 = &y;

	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("\n");

	swap(&x, &y);

	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("\n");

	swap(p1, p2);

	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("\n");
}

/*
out:
x = 31
y = 69

x = 69
y = 31

x = 31
y = 69
*/
#endif