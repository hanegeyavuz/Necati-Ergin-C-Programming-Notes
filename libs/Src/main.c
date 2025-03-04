#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include "nutility.h"
#include <math.h>
#include <conio.h>
#include <time.h>
#include "date.h"
#include "person.h"
#include <limits.h>
#include <ctype.h>

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
int main(void)
{
    int x = 10;
    int* a = &x;
    printf("pointer variable value = %p",a);
}
#endif

#if 0
/*adress of pointer variable*/
int main(void)
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
int main(void)
{
    int x[] = {10,20,30};
	printf("before assign. a[0] = %d\n",x[0]);
    *x = 777;
    printf("after assign. a[0] = %d\n",x[0]);
}
#endif

#if 0
int main(void)
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
int main(void)
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
int main(void)
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
int main(void)
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

#if 0
/*Call by Reference and Call by Value at same example*/
#define pi 3.1415926

double get_circle_area_1(double radius){
	 double area = pi * (radius * radius);
	  return area;
}

void get_circle_area_2(double radius, double *p_area){
	 *p_area = pi * (radius * radius);
}

int main(void)
{
    double radius = 20;
	double area_1 = 0;
	double area_2 = 0;
	area_1 = get_circle_area_1(radius);
	get_circle_area_2(radius,&area_2);
	printf("area_1 = %d\n",area_1);
	printf("area_2 = %d\n",area_2);
}
#endif

#if 0
/*Cost of Call by Reference and Call by Value*/
typedef struct {
	int a[20][20];
	int row, col;

}Matrix;

Matrix get_random_matrix_1(void){};
void get_random_matrix_2(Matrix* m){};

int main(void)
{
	printf("sizeof(Matrix) = %zu\n",sizeof(Matrix)); //out: 1608 byte
	Matrix m1, m2;
	m1 = get_random_matrix_1(); // 1608 bytle'lık bir alan kopyalandı.
	get_random_matrix_2(&m2); // 4 bytle'lık alan kopyalandı.
}
#endif

#if 0
/*const keyword for input parameters*/
typedef struct {
	int a[20][20];
	int row, col;

}Matrix;
               //in param        in param         out param  
void add_matrix(const Matrix *x, const Matrix *y, Matrix *presult){
	// some codes here...
}
int main(void)
{
	Matrix m1;
	Matrix m2;
	Matrix result;
	add_matrix(&m1, &m2, &result);
}

#endif

#if 0
/*const pointer to int or Top-Level Const Pointer*/
int main(void){
	int x = 10;
	int y = 45;
	
	int* const ptr = &x; // const pointer to int
	printf("x = %d\n",x); // out:x = 10
	
	//ptr = &y; // SYNTAX ERROR!
	*ptr = 999; // LEGAL
	printf("x = %d\n",x); // out:x = 999
}
#endif

#if 0
/* pointer to const int or Low-Level Const Pointer*/
int main(void){
	int x = 10;
	int y = 45;
	const int* ptr = &x; // const pointer to int
	printf("*ptr = %d\n",*ptr); // out: *ptr = 10
	
	//*ptr = 999; // SYNTAX ERROR
	ptr = &y; // LEGAL
	printf("*ptr = %d\n",*ptr); // out: *ptr = 45
}
#endif

#if 0
/*const keyword in functions with const arrays*/
void printArray1(int* p, int size){
}

void printArray2(const int* p, int size){
	for(int i = 0; i < (size -1); ++i){
		//putchar(p[i]);
		printf("%d ",p[i]);
	}
}

int main(void){
	const int daytabs[] = {31,28,31,30};
	//printArray1(daytabs,asize(daytabs)); // HATA  note: expected 'int *' but argument is of type 'const int *'
	printArray2(daytabs,asize(daytabs)); // LEGAL
	

}
#endif
#if 0
int main(void){
	int a[10] = {0};
	int* p = a + 7; //Geçerli
	a + 5;//Geçerli
	3 + a;//Geçerli
	p - 5;//Geçerli
	//3 - a;//Geçersiz
	p + 1;//Geçerli
	//p + a;//Geçersiz
}

#endif

#if 0
/*Pointer Arithmetics*/
int main(void){
	int a[10] = {0}; //int
	for(int i = 0; i < 10; ++i){
		printf("%d. indisli elemanin adresi %p\n",i,a + i);
	}
}
#endif

#if 0
/*Pointer Arithmetics*/
int main(void){
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	printf("%d",*(a+3));
}
/* 
out: 3
*/
#endif

#if 0
int main(void)
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (int i = 0; i < asize(a); ++i)
	{
		printf("%d %d %d\n", a[i], *(a + i), *(i + a));
	}
}
/*
out:
0 0 0
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
8 8 8
9 9 9
*/
#endif

#if 0
int main(void)
{
	int a[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
	int* p = a;
	printf("%d\n",*p);
	printf("%p\n",p);
	++p; // p = p + 1 ----> p'nin değeri bir sonraki elemanın adresi olur.
	printf("%d\n",*p);
	printf("%p\n",p);
}
/*
out:
0
0061FEF4
10
0061FEF8
 */
#endif

#if 0
/* Subscript Operator */
int main(void)
{

	int x = 5;
	int *ptr = &x;
	printf("x = %d\n", x);

	ptr[0] = 888;
	printf("x = %d\n", x);
}

/*
out:
x = 5
x = 888
*/
#endif

#if 0

int main(void)
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *ptr = a + 5;

	printf("x = %d\n", a[0]);
	printf("x = %d\n", *ptr);
	printf("x = %d\n", ptr[0]); // *(ptr + 0)

	printf("x = %d\n", a[3]);	// third index
	printf("x = %d\n", ptr[3]); // *(ptr + 3)

	printf("x = %d\n", ptr[-4]); // *(ptr - 4)
	printf("x = %d\n", 2 [ptr]); // *(2 + ptr)
}
/*
out:
x = 0
x = 5
x = 5
x = 3
x = 8
x = 1
x = 7
*/
#endif

#if 0

void foo(int *ptr, int size)
{
	/* First Method for printing array */
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", ptr[i]);
	}
	printf("\n");
	/* Second Method for printing array */
	while (size--)
	{
		printf("%d ", *ptr);
		ptr++;
	}
	printf("\n");
}

int main(void)
{
	int ex = 592;
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	foo(a, asize(a));
}

/*
out:
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9

*/

#endif
#if 0

/*Mülakat sorusu: dizideki 2,3 ve 4. indexli elemanları yazdır.*/
void foo(const int *ptr, int size)
{
	/* First Method for printing array */
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", ptr[i]);
	}
	printf("\n");
	/* Second Method for printing array */
	while (size--)
	{
		printf("%d ", *ptr);
		ptr++;
	}
	printf("\n");
}

int main(void)
{
	int ex = 592;
	int a[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
	foo((a + 2), 3);
}

#endif

#if 0
/*Önceden yazılan fonksiyonları tekrar yazmak*/
#define SIZE 100

void set_array_random_1(int* p, int size){
	for(int i = 0; i < size; ++i){
		p[i] = rand() % 1000;
	}
/*	SECOND WAY
	while(--size){

		*p = rand() % 1000;
		++p;

	}*/
}
void print_array_random_1(const int *ptr, int size)
{
	/* First Method for printing array */
	for (int i = 0; i < size; ++i)
	{
		
		if( i && !(i % 20)){
			putchar('\n');
		}
		printf("%3d ", ptr[i]);
	}
	printf("\n-----------------------------------------\n");
}

int add_arr(const int* p, int size){
	int sum = 0;
	while(size--){
		sum += *p;
		++p;
	}
	// for(int i = 0; i < size ; ++i){
	// 	sum += p[i];

	// }
	return sum;
}


int main(void)
{	
	int sum = 0;
	int a[SIZE];
	randomize();
	set_array_random_1(a,asize(a));
	print_array_random_1(a,asize(a));
	sum = add_arr(a,asize(a));

	printf("\n sum = %d\n",sum);
}

#endif

#if 0
/*elemanları int olan bir dizinin elemanlarının ortalamasını hesaplayan fonksiyon*/
#define SIZE 100
double get_mean(const int* p,int size){
	return (double)(sum_arr(p,size) / size);

}

int main(void)
{	
	int sum = 0;
	double mean = 0;
	int a[SIZE];
	randomize();
	set_array_random(a,asize(a));
	print_array(a,asize(a));
	sum = sum_arr(a,asize(a));
	mean = get_mean(a,asize(a));

	printf("sum = %d\n",sum);
	printf("mean = %f\n",mean);
}

#endif

#if 0
#include <math.h>
/*elemanları int olan bir dizinin elemanlarının standart sapmasını hesaplayan fonksiyon*/
#define SIZE 100
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

int main(void)
{

	int a[SIZE];
	randomize();
	set_array_random(a, asize(a));
	print_array(a, asize(a));
	printf("stardart deviation = %f\n", get_std_dev(a, asize(a)));
}

#endif
#if 0
#include <math.h>
/*elemanları int olan bir diziyi reverse eden fonksiyon*/
#define SIZE 10
void get_reverse_array(int *p, int size)
{

	for (int i = 0; i < size / 2; ++i)
	{
		int temp = p[i];
		p[i] = p[size - 1 - i];
		p[size - 1 - i] = temp;
	}
}

int main(void)
{

	int a[SIZE];
	randomize();
	set_array_random(a, asize(a));
	print_array(a, asize(a));
	get_reverse_array(a, asize(a));
	print_array(a, asize(a));
}

#endif
#if 0
/*elemanları int olan bir dizinin max ve ming değerlerini bulan fonksiyonlar*/

#define SIZE 10
// int get_max_array(const int* p, int size){
//   int max = 0;
//   for(int i = 0; i < size; ++i){
//     max = p[i] > max ? p[i] : max;
//   }
//   return max;

// }

// int get_min_array(const int* p, int size){
//   int min = 0;
//   for(int i = 0; i < size; ++i){
//     min = p[i] < min ? p[i] : min;
//   }
//   return min;

// }
int main(void)
{

	int a[SIZE];
	randomize();
	set_array_random(a, asize(a));
	print_array(a, asize(a));
	printf("max = %d\n", get_max_array(a, asize(a)));
	printf("min = %d\n", get_min_array(a, asize(a)));
}
#endif
#if 0
/*elemanları int olan bir dizinin max ve min değerini tek fonksiyon ile bulmak*/

#define SIZE 10
/*
void get_max_min_array(const int* p, int size,int* max, int* min){
  *min = *p;
  *max = *p;
  for(int i = 0; i < size; ++i){
    *min = p[i] < *min ? p[i] : *min;
    *max = p[i] > *max ? p[i] : *max;
  }
}

*/
int main(void)
{
	int max, min = 0;
	int a[SIZE];
	randomize();
	set_array_random(a, asize(a));
	print_array(a, asize(a));
	printf("max = %d\n", get_max_array(a, asize(a)));
	printf("min = %d\n", get_min_array(a, asize(a)));
	get_max_min_array(a, asize(a), &max, &min);
	printf("max = %d\n min = %d\n", max, min);
}
#endif

#if 0
/*Array Copy*/
#define SIZE 10

// void copy_array(int* pdest, const int* psource,int size){
//   /*FIRST WAY*/
// 	// for(int i = 0; i < size; ++i){
//   //   pdest[i] = psource[i];
// 	// }
// /*SECOND WAY*/
//   // while(size--){
//   //   *pdest = *psource;
//   //   ++pdest;
//   //   ++psource;
//   // }
//   /*THIRD WAY */
//     while(size--){
//       *pdest++ = *psource++;
//   }
// }
int main(void)
{
	int a[SIZE] = {0};
	int b[SIZE] = {0};
	randomize();
	printf("Source Array: ");
	set_array_random(a, asize(a));
	print_array(a, asize(a));
	printf("Destination Array: ");
	print_array(b, asize(b));
	printf("Copy array source to destination ... \n");
	printf("Destination Array: ");
	copy_array(b,a,SIZE);
	print_array(b, asize(b));
}
#endif

#if 0
/*Copy Array with size*/
#define SIZE 100
int main(void)
{
	int a[SIZE] = {0};
	int b[SIZE] = {0};
	int idx_a = 0;
	int idx_b = 0;
	int n = 0;
	randomize();
	printf("Source Array: \n");
	set_array_random(a, asize(a));
	print_array(a, asize(a));
	printf("kaynak arrayin kacinci indexinden baslayarak: ");
	scanf("%d",&idx_a);
	printf("hedef arrayin kacinci indexinden baslayarak: ");
	scanf("%d",&idx_b);
	printf("kac eleman kopyalansin: ");
	scanf("%d",&n);
	copy_array((b+idx_b),(a+idx_a),n);
	print_array(b, asize(b));
}
#endif

#if 0
/*Bubble Sort Algorithm*/
#define SIZE 20

// void bubble_sort(int *p, int size)
// {
// 	for (int i = 0; i < size - 1; ++i)
// 	{
// 		for (int k = 0; k < size - 1 - i; ++k)
// 		{
// 			if (p[k] > p[k + 1])
// 			{
// 				swap((p + k), (p + k + 1));
// 			}
// 		}
// 	}
// }

int main(void)
{
	int a[SIZE] = {0};
	randomize();
	set_array_random(a, asize(a));
	print_array(a, asize(a));
	bubble_sort(a,SIZE);
	print_array(a, asize(a));

}
#endif

#if 0
/*Swap Array Algorithm*/
#define SIZE 20

// void swap_array(int *p1, int *p2, int size)
// {

// 	while (size--)
// 	{
// 		swap(p1++, p2++);
// 	}
// }

int main(void)
{
	int a[SIZE] = {0};
	int b[SIZE] = {0};
	randomize();
	set_array_random(a, asize(a));
	set_array_random(b, asize(b));
	print_array(a, asize(a));
	print_array(b, asize(b));
	swap_array(a, b, SIZE);
	print_array(a, asize(a));
	print_array(b, asize(b));
}
#endif

#if 0 

/*REVERSE COPY Array Algorithm*/
#define SIZE 20

void reverse_copy(int* pdest, const int* psource,int len){

	int start_idx = 0;
	int end_idx = 0;
	
	pdest += size;
	while(len--){
		*--pdest = *psource++;

	}
}

int main(void)
{
	int a[SIZE] = {0};
	int b[SIZE] = {0};
	randomize();
	set_array_random(a, asize(a));
	set_array_random(b, asize(b));
	print_array(a, asize(a));
	print_array(b, asize(b));
	reverse_copy(a, b, SIZE);
	print_array(a, asize(a));
	print_array(b, asize(b));
}
#endif

#if 0
/*Pointer equality*/
int main(void)
{
    
    int a[5] = {10,20,30,40,50};
    
    int* p = a;
    int* pend = a+5;
    
    while(p != pend){
        printf("%d\n",*p++);
    }
}
/*
out:
10
20
30
40
50
*/
#endif

#if 0
/*Alternative printArray function*/
void printArray(const int* ps,const int* pe){
	while(ps != pe){
		printf("%3d ",ps++);
	}
}
#endif

#if 0
/*Returning adress functions example */
#define SIZE 10

// int *get_Array_Max(const int *p, int size)
// {

// 	int *pmax = (int *)p;

// 	for (int i = 0; i < size; ++i)
// 	{

// 		if (*(p + i) > *pmax)
// 		{

// 			pmax = (int *)(p + i);
// 		}
// 	}
// 	return pmax;
// }

int main(void)
{

	int a[SIZE] = {0};
	randomize();
	set_array_random(a, SIZE);
	print_array(a, SIZE);

	int *p = get_Array_Max(a, SIZE);
	printf("max = %d ve dizinin %d indisli elemani.\n", *p, (p - a));
	*p = -23; // en büyük değer -23 oldu.

	print_array(a, SIZE);
}

#endif

#if 0
/*Quick Homework: Print values between max and min*/
#define SIZE 10
int main(void)
{

	int a[SIZE] = {0};
	randomize();
	set_array_random(a, SIZE);
	print_array(a, SIZE);
	
	int *pamax = get_Array_Max(a, SIZE);
	int *pamin = get_Array_Min(a, SIZE);
	printf("max = %d dizinin %d indisli elemani\nmin = %d dizinin %d indisli elemani\n", *pamax, pamax - a, *pamin, pamin - a);
	
	if(pamax > pamin)
		print_array(pamin, pamax - pamin);
	else
		print_array(pamax, pamin - pamax);

}

#endif

#if 0
#define SIZE 100

// /*Selection Sort Algorithm*/
// void selection_sort(int* p, int size){
// 	for(int i = 0; i < size - 1; ++i){
// 		swap(p+i,get_Array_Min(p+i,size-i));
// 	}
// }


int main(void){

	int a[SIZE] = {0};
	randomize();
	set_array_random(a, SIZE);
	print_array(a, SIZE);
	selection_sort(a,SIZE);
	print_array(a, SIZE);
}
#endif

#if 0
/*NULL Pointer*/
int main(void){

	FILE* f = fopen("abc.txt","r");

	if(f == NULL){

		printf("dosya acilamadi.");
		return 1;
	}
	printf("dosya acildi.");
}

#endif

#if 0
/*NULL Pointer*/
int main(void){

	FILE* f = fopen("README.md","r");

	if(f == NULL){

		printf("dosya acilamadi.");
		return 1;
	}
	printf("dosya acildi.");
}

#endif

#if 0
#define SIZE 100
#include "string.h"
/*NULL Pointer*/
int main(void){

	char str[SIZE];

	printf("bir yazi giriniz: ");

	scanf("%s",str);

	char* p = strchr(str,'a'); /*Bu fonksiyon ileriki zamanlarda ayrintili islenecektir.*/

	if(p){

		printf("bulundu idx = %d\n",p-str);
		puts(p); // sonraki kısmı yazdır
	}
	else{
		printf("bulunamadi");
	}
}
#endif
#if 0
#define SIZE 100
/*NULL Pointer - Search in Array Function*/

// int *search_in_array(const int *p, int size, int key)
// {
// 	while (size--)
// 	{
// 		if (*p == key)
// 		{
// 			return (int *)p;
// 		}
// 		++p;
// 	}
// 	return NULL;
// }
int main(void)
{

	int a[SIZE];
	int searched = 0;
	set_array_random(a, SIZE);
	print_array(a, SIZE);
	printf("aranan deger giriniz: ");
	scanf("%d", &searched);
	int *ptr = search_in_array(a, SIZE, searched);

	if (ptr)
	{
		printf("bulundu, %d indisli elemani\n", ptr - a);
	}
	else
	{
		printf("Bulunamadi");
	}
}
#endif

#if 0
void clear_array(int *p, size_t size)
{
	for (int i = 0; i < size; ++i)
	{
		*(p + i) = 0;
	}
}
int main(void)
{
	size_t SIZE = 10;

	int a[SIZE];
	set_array_random(a, SIZE);
	print_array(a, SIZE);
	clear_array(a, SIZE);
	print_array(a, SIZE);
}

#endif

#if 0
#define SIZE 100
void myputs(const char* p){
	/*First Way*/
	// for(int i = 0; *(p+i) != '\0';++i){
	// 	putchar(*(p+i));
	// }
	/*Second Way*/
	while(*p){
		putchar(*p++);
	}

	putchar('\n');
}

int main(void){
	char str[SIZE] = "yavuz hanege";
	myputs(str);
}

#endif

#if 0
/* string.h  test code*/
#include <string.h>

#define SIZE 100

int main(void){
	char str[SIZE];
	printf("bir yazi giriniz: ");
	sgets(str);
	printf("(%s)\n",str);
}

#endif

#if 0
/* string.h */
#include <string.h>
#include <stdint.h>

#define SIZE 100

int main(void){
	char str[SIZE];
	printf("bir yazi giriniz: ");
	sgets(str);
	printf("(%s)\n",str);
	size_t len = strlen(str);
	printf("uzunluk: %zu\n",len);
}

#endif

#if 0
/* strlen function implementation by yourself */
#include <string.h>
#include <stdint.h>

#define SIZE 100

size_t strlen_1(const char* p){

	size_t len = 0;
	for(int i = 0; *(p+i) != '\0'; ++i){
		len++;
	}
	return len;
}

size_t strlen_2(const char* p){

	size_t len = 0;
	for(; *(p+len) != '\0'; ++len){
		;
	}
	return len;
}
size_t strlen_3(const char* p){

	size_t len = 0;
	while(*(p+len)){
		len++;
	}
	return len;
}
size_t strlen_4(const char* p){

	const char* tempch = p;
	while(*p){
		++p;
	}
	return (size_t)(p-tempch); // dönüş türü ptrdiff_t olduğu için tür dönüşümü yapıldı
}

int main(void){
	char str[SIZE];
	printf("bir yazi giriniz: ");
	sgets(str);
	printf("(%s)\n",str);
	size_t len = strlen_4(str);
	printf("uzunluk: %zu\n",len);
}

#endif

#if 0
/*strchr function implementation*/
#include <string.h>
#include <stdint.h>

#define SIZE 100
char* strchr_1(const char* p,int ch){
	while(*p){
		if(*p == ch){
			return (char*)p;
		}
		p++;
	}
	if(ch == '\0'){
		return (char*)p;
	}
	return NULL;
}
	

int main(void){
	char str[SIZE];
	printf("bir yazi giriniz: ");
	sgets(str);
	printf("arancak karakteri giriniz: ");
	int c = getchar();
	char* p = strchr_1(str,c);
	if(p == NULL){
		printf("bulunamadi\n");
	}
	else{
		printf("bulundu idx: %d\n",p - str);
		*p = '*';
		puts(str);
	}

}
#endif

#if 0
/*strrchr function implementation*/
#include <string.h>
#include <stdint.h>

#define SIZE 100
char *strrchr_1(const char *p, int ch)
{
	char *pfound = NULL;
	while (*p)
	{
		if (*p == ch)
		{
			pfound = (char *)p;
		}
		++p;
	}
	if (ch == '\0')
	{
		return (char *)p;
	}
	return pfound;
}

int main(void)
{
	char str[SIZE];
	printf("bir yazi giriniz: ");
	sgets(str);
	printf("arancak karakteri giriniz: ");
	int c = getchar();
	char *p = strrchr_1(str, c);
	if (p == NULL)
	{
		printf("bulunamadi\n");
	}
	else
	{
		printf("bulundu idx: %d\n", p - str);
		*p = '*';
		puts(str);
	}
}
#endif

#if 0
/** HOMEWORK
 ** strstr function implementation*/
#include <string.h>
#include <stdint.h>

#define SIZE 100
char *strstr_1(const char *hay, const char *needle)
{
	size_t needle_size = strlen(needle);
	while (*hay)
	{
		if (*hay == *needle)
		{
			needle++;
			if (*needle == '\0')
			{
				return (char *)(hay - needle_size + 1);
			}
		}
		hay++;
	}
	return NULL;
}
/**/
#include <string.h>
#include <stdint.h>

#define SIZE 100
int main(void)
{
	char str[SIZE];
	char key[SIZE];
	printf("bir yazi giriniz: ");
	sgets(str);
	printf("arancak karakteri giriniz: ");
	sgets(key);
	char *pfound = strstr_1(str, key);
	if (pfound)
	{
		printf("bulundu idx = %d\n", pfound - str);
		puts(pfound);
	}
	else
	{
		printf("bulunamadi");
	}
}
#endif

#if 0
/*strpbrk() Function*/

#include <string.h>
#include <stdint.h>

#define SIZE 100
char *strpbrk_1(const char *ps, const char *pchars)
{
	for(int i = 0; ps[i] != '\0'; ++i){
		if(strchr(pchars,ps[i])){
			return (char*) (ps+i);
		}
	}
	return NULL;
}
/**/
#include <string.h>
#include <stdint.h>

#define SIZE 100
int main(void)
{
	char str[SIZE];
	char scars[SIZE] = "prtnl";
	printf("bir yazi giriniz: ");
	sgets(str);
	char *pfound = strpbrk_1(str, scars);
	if (pfound)
	{
		printf("bulundu idx = %d karakteri %c\n", pfound - str,*pfound);
	}
	else
	{
		printf("bulunamadi");
	}
}

#endif

#if 0
/*strcpy() Function*/

#include <string.h>
#include <stdint.h>

#define SIZE 100
char *strcpy_1(char *pdest, const char *psource)
{
	char *pret = pdest;
	while (*psource)
	{
		*pdest++ = *psource++;

	}
	*pdest = '\0';
	return pret;
}
int main(void)
{
	char source[SIZE];
	char dest[SIZE];
	printf("source string: ");
	sgets(source);
	puts(strcpy_1(dest,source));
}

#endif

#if 0
/*strcat() Function*/

#include <string.h>
#include <stdint.h>

#define SIZE 100
char *strcat_1(char *pdest, const char *psource)
{
	char *pret = pdest;
	while (*psource)
	{
		*pdest  ++ = *psource++;

	}
	*pdest = '\0';
	return pret;
}
int main(void)
{
	char source[SIZE];
	char dest[SIZE];
	printf("source string: ");
	sgets(source);
	puts(strcpy_1(dest,source));
}

#endif

#if 0
/*strcmp() Function*/

#include <string.h>
#include <stdint.h>

#define SIZE 100
int strcmp_1(const char *p1, const char *p2)
{
	while(*p1 == *p2){
		if(*p1 == '\0')
			return 0;
		++p1;
		++p2;
	}
	return *p1 - *p2;
}
int main(void)
{
	char p1[SIZE];
	char p2[SIZE];
	printf("p1 string: ");
	sgets(p1);
	printf("p2 string: ");
	sgets(p2);
	if(!strcmp_1(p1,p2)){
		printf("iki yazi birbirine esittir.");
	}
	else{
		printf("yazilar esit degildir.");
	}
}
#endif

#if 0
/*yazinin sonunda bir yazi olup olmadigini sinama*/
#include <string.h>
#include <stdint.h>

#define SIZE 100

// bool return value
int ends_with(const char *psource, const char *pkey)
{
	int len_key = strlen(pkey);
	int len_source = strlen(psource);
	if (len_source <= len_key)
	{
		return 0;
	}
	else
	{
		/*USE STD LIBRARY FUNCTIONS DO NOT WRITE HARD CODED STYLE*/
		// while (*(psource + len_source - len_key) == *pkey)
		// {
		// 	if (*(psource + len_source - len_key) == '\0')
		// 	{
		// 		return 1;
		// 	}

		// 	++pkey;
		// 	++psource;
		// }
		// return 0;
		return !strcmp((psource + len_source - len_key), pkey);
	}
}

int main(void)
{
	char p1[SIZE];
	char p2[SIZE];
	printf("p1 string: ");
	sgets(p1);
	printf("p2 string: ");
	sgets(p2);
	if (!ends_with(p1, p2))
	{
		printf("ilk yazinin icinde ikinci yazi yok.");
	}
	else
	{
		printf("ilk yazinin icinde ikinci yazi var.");
	}
}

#endif

#if 0
/*string literals*/
char* get_name(void){
	// static char str[100] = "yavuz";
	// return str;
	return "yavuz";
}
int main(void)
{
	//char* ptr = "yavuz";
	char* ptr = get_name();
	printf("%s",ptr);
}
#endif

#if 0
/*string literals*/

int main(void)
{
	for (int i = 0; i < 10; ++i)
	{
		char *ptr = "yavuz hanege";
		printf("%p\n", ptr + i);
	}
}
#endif

#if 0
/*string literals can not modified*/
int main(void){
	char* ptr = "yavuz";
	puts(ptr);
	ptr[0] = 'g'; /*UNDEFINED BEHAVIOUR*/
	puts(ptr);
}
#endif

#if 0
/*NO UB IN THIS EXAMPLE*/
int main(void){
	char ptr[100] = {0};
	puts(ptr);
	strcpy(ptr,"kerem"); 
	puts(ptr);
	strcat(ptr,"emre"); 
	puts(ptr);
}
#endif

#if 0
/*Yeni dosya adına eski dosya adını kopyalayınız.
Sonrasında dosya adında bir uzantı yoksa .txt uzantısı ekleyiniz.
Dosyanın uzantısı .jpg ise uzantısını .gif yapınız
Dosyanın uzantısı .xls ise uzantısı olmasın


*/
#define SIZE 100
int main(void)
{
	char old_file_name[SIZE] = {0};
	char new_file_name[SIZE] = {0};
	printf("bir dosya ismi giriniz: ");
	scanf("%s", old_file_name);
	strcpy(new_file_name, old_file_name);
	char *p = strstr(new_file_name, ".");
	if (p)
	{
		if (!strcmp(p, ".jpg"))
		{
			strcpy(p, ".gif");
		}
		else if (!strcmp(p, ".xls"))
		{
			//strcpy(p, "");
			*p = '\0';
		}
	}
	else
	{
		strcat(new_file_name, ".txt");
	}
	printf("old file name = (%s)\nnew file name = (%s)\n", old_file_name, new_file_name);
}

#endif

#if 0
/*String Literal with strlen function and sizeof operator */

  void foo(char* p)
  {
    printf("[8] -> %zu\n", sizeof(p));
  }

  int main(void)
  {
    char str[] = "hello";
    char* p = "world";

    printf("[1] -> %zu\n", sizeof(str));    // output -> [1] -> 6
    // "sizeof(str)" is a constant expression (compile time constant)

    printf("[2] -> %zu\n", strlen(str));    // output -> [2] -> 5
    // strlen function is executed at run-time

    printf("[3] -> %zu\n", sizeof(*str));   // output -> [3] -> 1
    // when sizeof operators operand is an expression
    // it will check the size of the type of the expression
    // "*str" is an expression and its data type is char

    printf("[4] -> %zu\n", sizeof(p));      // output -> [4] -> 8
    
    printf("[5] -> %zu\n", sizeof(p++));    // output -> [5] -> 8
    // no operation code will be generated for p++ expression

    printf("[6] -> %zu\n", strlen(p));      // output -> [6] -> 5

    printf("[7] -> %zu\n", sizeof(p[900])); // output -> [7] -> 1
    // "p[900]" is an expression and its data type is char
    // because of no operation code will be generated 
    // for p[900] expression, it won't be an UB

    foo("Istanbul Ankara Izmir");           // output -> [8] -> 8

    printf("[9] -> %zu\n", sizeof(""));     // output -> [9] -> 1

    printf("[10] -> %zu\n", strlen(""));    // output -> [10] -> 0
  }

#endif

#if 0
int main(void)
{
	printf("%d elma\n",2["elma"]-1["elma"]);
	printf("%d elma\n","elma"[2]-"elma"[1]);
	printf("%d elma\n",'m'-'l');
}
#endif

#if 0
/*escape char.*/
int main(void)
{
	printf("\"yavuz\"");
}
#endif

#if 0
/*Pointer Arrays*/
int x, y, z, t;
int main(void)
{

	int *ar[] = {&x, &y, &z, &t};
	//*ar[0] = 999; /* x = 999;*/
	**ar = 999; /* x = 999;*/
	printf("%d", **ar);
}
#endif

#if 0
/*Pointer Arrays*/
int x, y, z, t;
int a[] = {10,20,30,50};


int main(void)
{

	int *ar[] = {&x,a ,&y, &z, &t};
	//*ar[0] = 999; /* x = 999;*/
	**ar = 999; /* x = 999;*/
	printf("%d\n",*++ar[1]); 
	printf("%d\n",++*ar[1]);
}
#endif

#if 0
int x = 10;
int y = 20;
int z = 30;
int t = 40;
int main(void)
{
	int *p[] = {&x, &y, &z, &t};
	// code

	for (size_t i = 0; i < asize(p); ++i)
	{
		**(p + i) = 31;
	}
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
	printf("t = %d\n", t);
}

#endif
#if 0
int x = 10;
int y = 20;
int z = 30;
int t = 40;
int main(void)
{
	int* const p1[] = {&x, &y, &z, &t};
	const int* p2[] = {&x, &y, &z, &t};
	// code
	// p1[2] = error
	//*p1[2] = 90; legal
	//**(p1 + 2) = 90; // legal

	p2[2] = NULL; // legal
	//*p2[2] = 90; error
	//**(p2+2) = 90; // error
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
	printf("t = %d\n", t);
}

#endif

#if 0
char* x = "0";
int main(void)
{

	 char* pdays[] = {"pzt", "sali", "cars", "pers", "cuma", "cumartesi", "pazar"};

	//printf("%s\n",*pdays[2]);
	
	for (size_t i = 0; i < asize(pdays); ++i)
	{
		puts(*(pdays + i));
	}
}
#endif

#if 0
char *x = "0";
int main(void)
{

	char *pdays[] = {"pazartesi", "sali", "carsamba", "persembe", "cuma", "cumartesi", "pazar"};

	char buf[20];
	printf("bir gun ismi giriniz: ");
	scanf("%s", buf);
	for (size_t i = 0; i < asize(pdays); i++)
	{
		int p = strcmp(pdays[i], buf);
		if (!p)
		{
			printf("%d", i + 1);
			return 0;
		}
	}
	printf("gecersiz bir gun ismi girildi.");
}
#endif

#if 0
int main(void)
{

	const char* p[] = {"pazartesi", "sali", "carsamba", "persembe", "cuma", "cumartesi", "pazar"};

	for (size_t i = 0; i < asize(p); ++i)
	{

		putchar(p[i][strlen(p[i])- 1]);
		/*Way 1*/
		//printf("%c", *pdays[i]);
		/*Way 2*/
		
		/*Way 3*/
		//printf("%c", **(pdays + i));
	}
}
#endif
#if 0
int main(void)
{
	printf("bir karakter giriniz: ");
	int ch = getchar();
	const char *p[] = {"pazartesi", "sali", "carsamba", "persembe", "cuma", "cumartesi", "pazar"};

	for (size_t i = 0; i < asize(p); ++i)
	{
		char *ret = strchr(p[i], ch);
		if (ret)
		{
			//puts(p[i]);
			printf("%s\n",p[i]);
		} 
		else
		{
			continue;
		}
	}
}
#endif

#if 0
/*ODEV!
DIZIDEKI YAZILARDAN ICINDE HERHANGI BIR KARAKTERDEN BIRDEN FAZLA OLANLAR YAZDIRILACAK
*/

int has_repeated_char(const char *pa)
{
	for (int i = 'a'; i < 'z'; ++i)
	{
		char *pin = strchr(pa, i);
		if (pin)
		{
			// printf("%s yazisinda %c harfinden bir adet bulundu.",pa,i);
			if (strchr((pin + 1), i))
			{
				// printf("%s yazisinda %c harfinden iki adet bulundu.",pa,i);
				return 1;
			}
		}
	}
	return 0;
}

int main(void)
{
	const char *p[] = {"pazartesi", "sali", "carsamba", "persembe", "cuma", "cumartesi", "pazar"};
	for (size_t i = 0; i < asize(p); ++i)
	{
		if (has_repeated_char(p[i]))
		{
			printf("%s\n", p[i]);
		}
	}
}
#endif

#if 0
/*No Undefined Behaviour in this example, no change in string literals;
it changes elemnets of array
*/
int main(void)
{
	char *p[] = {"pazartesi", "sali", "carsamba", "persembe", "cuma", "cumartesi", "pazar"};
	for (size_t i = 0; i < 1000; ++i)
	{
		size_t idx1 = rand() % asize(p);
		size_t idx2 = rand() % asize(p);
		char* ptemp = p[idx1];
		p[idx1] = p[idx2];
		p[idx2] = ptemp;
	}
	for (size_t i = 0; i < asize(p); ++i)
	{	
		printf("%s\n",p[i]);
	}
	
}

#endif

#if 0
/*
 * Uzunluğa ve alfabetik Sıraya göre diziyi sıralayınız.
 */
int main(void)
{
	const char *p[] = {"pazartesi", "sali", "carsamba", "persembe", "cuma", "cumartesi", "pazar"};
	for (size_t i = 0; i < asize(p) - 1; ++i)
	{
		for (int k = 0; k < asize(p) - i - 1; ++k)
		{
			if ( strlen(p[k]) > strlen(p[k+1]) || ( strlen(p[k]) == strlen(p[k+1]) && strcmp(p[k],p[k+1]) > 0) ) 
			{
				const char* ptemp = p[k];
				p[k] = p[k + 1];
				p[k + 1] = ptemp;
			}
		}
	}
	for (size_t i = 0; i < asize(p); ++i)
	{
		printf("%s\n", p[i]);
	}
}
#endif

#if 0
/*Birlestirme*/
int main(void){

	static const char* p[] = {"emine","hande","kubilay","yavuz","hanege"};

	char buff[100] = {0};
	for (size_t i = 0; i < asize(p); ++i)
	{
		strcat(buff,p[i]);
		/* code */
	}
	
	puts(buff);
}
#endif

#if 0
/* Pointer to Pointer */
int main(void){

	int x = 10;
	int* p = &x;
	
	printf("&x = %p\n",&x);
	printf("p =  %p\n",p);
	printf("&p = %p\n",&p);
}

#endif

#if 0
/* Pointer to Pointer */
int main(void){

	int x = 10;
	int* p = &x; /* Pointer to int */
	int** ptr = &p; /* Pointer to pointer to int*/
	printf("x = %d\n",x);
	*p = 99;
	printf("x = %d\n",x);
	**ptr = 31;
	printf("x = %d\n",x);
	++**ptr;
	printf("x = %d\n",x);
}

#endif

#if 0
/* Pointer to Pointer */
int main(void){

	int x = 10;
	int* p = &x;
	
	printf("&x = %p\n",&x);
	printf("p =  %p\n",p);
	printf("&p = %p\n",&p);
}
#endif

#if 0

int main(void)
{
	double dval[] = {3.4, 5.6, 7.23, 30.0};
	printf("dval[2] = %f\n", dval[2]);
	double *dp = dval;
	double **ptr = &dp;
	(*ptr)[2]++;
	printf("dval[2] = %f\n", dval[2]);
}

#endif

#if 0
int g = 31;

void foo(int *ptr)
{
	*ptr = 777;
}
void bar(int **ptr)
{
	*ptr = &g;
}

int main(void)
{
	int x = 10;
	int *p = &x;

	printf("x = %d\n", x);
	printf("x = %d\n", *p);
	foo(p);
	printf("x = %d\n", x);
	printf("x = %d\n", *p);
	bar(&p);
	printf("x = %d\n", x);
	printf("x = %d\n", *p);
}

#endif

#if 0
/*Pointer to Pointer Exmaple Function*/
void pswap(int** const p1, int** const p2){
	int* ptemp = *p1;
	*p1 = *p2;
	*p2 = ptemp;

}

int main(void)
{
	int x = 10;
	int y = 45;
	int *p1 = &x;
	int *p2 = &y;
	printf("*p1 = %d\t*p2 = %d\n",*p1,*p2);
	pswap(&p1,&p2);
	printf("*p1 = %d\t*p2 = %d\n",*p1,*p2);
}

#endif

#if 0
/*max ve min değerlerin adreslerini döndüren fonksiyon*/
void p_getminmax(const int* arr, int size, int** ppmax,  int** ppmin){
	*ppmax = (int*)arr;
	*ppmin = (int*)arr;
	
	for(int i = 0; i < size;++i){

		*ppmax = arr[i] > **ppmax ? (int*)(arr + i) : *ppmax;
		*ppmin = arr[i] < **ppmin ? (int*)(arr + i) : *ppmin;
	}
}

int main(void){
	int a[10];
	randomize();
	set_array_random(a,10);
	print_array(a,10);
	int* pmin, *pmax;
	p_getminmax(a,asize(a),&pmax,&pmin);
	printf("min = %d dizisinin %d indexli elemani\n",*pmin,pmin-a);
	printf("max = %d dizisinin %d indexli elemani\n",*pmax,pmax-a);

}

#endif

#if 0
void print_pointees(int *const *pa, int size)
{
	/*WAY 1*/
	for (int i = 0; i < size; ++i)
	{
		printf("%d\t", **(pa + i));
	}
	/*WAY 2*/
	while (size--)
	{
		printf("%d\t", **(pa));
		pa++;
	}
	printf("\n");
}

int main(void)
{
	int x = 10;
	int y = 20;
	int z = 30;
	int t = 40;
	int *a[] = {&x, &y, &z, &t};
	print_pointees(a, asize(a));
}
#endif

#if 0
void cpswap(char**p1,char**p2){
	char* ptemp = *p1;
	*p1 = *p2;
	*p2 = ptemp;

}

void print_names(char **p, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%s ", p[i]);
	}
}

void bubble_sort_char(char **p, size_t size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int k = 0; k < size - i - 1; ++k)
		{
			if (strcmp(p[k], p[k + 1]) > 0)
			{
				cpswap(&p[k],&p[k+1]);
			}
		}
	}
}
int main(void)
{

	char *p[] = {"emine", "hande", "kubilay", "yavuz", "hanege"};

	print_names(p, asize(p));
	bubble_sort_char(p, asize(p));

	(void)getchar();
	system("cls");

	print_names(p, asize(p));
}

#endif

#if 0
/*const Corrections*/
int main(void)
{
	int x = 10;
	int y = 35;
	int *p1 = &x;
	int *p2 = &y;

	int **ptr = &p1;
	// int ** const ptr = &p1; // Durum 1
	// int *const* ptr = &p1; // Durum 2
	// const int ** ptr = &p1; // Durum 3

	ptr = &p2;	 // Durum 1 için ERROR
	*ptr = &x;	 // Durum 2 için ERROR
	**ptr = 999; // Durum 3 için ERROR
}

#endif

#if 0
/*Dizinin adresini tutan değişkenler*/
int main(void)
{
	int a[5] = {0, 10, 20, 30, 40};
	int(*p)[5] = &a;

	++**p;
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", (*p)[i]);
		/* code */
	}
}
#endif

#if 0
/* void pointer */
int main(void)
{
	int x = 5;
	double dval = 3.4;
	char str[] = "burhanettin";

	int *p;
	void *vp;
	p = &x;
	// p = &dval; /*Syntax Error*/
	vp = &dval; /*Legal*/
	vp = &x;	/*Legal*/
	vp = &str;	/*Legal*/
	vp = &vp;	/*Legal*/
	//vp = x; /*Syntax Error*/
}

#endif

#if 0
int main(void){

	int x = 10;
	void* vp = &x; /*int* ==> void* type cast */ /*C and C++ Legal*/
	int *iptr = vp; /* void* ==> int* type cast*/ /*C++ illegal*/

}
#endif

#if 0
/*Generic Programming with void pointer*/

void gswap(void *vp, void *vp2, size_t size)
{

}

int main(void)
{

	int x = 5, y = 475;

	gswap(&x, &y, sizeof(x));
}
#endif

#if 0
/*y = x*/
int main(void){
	double x = 34.7823;
	double y;

	//y = x;
	const char* px = (const char*)&x;
	char* py = (char*)&y;
	size_t size = sizeof(x);
	while(size--){
	
		*py++ = *px++;
	}
	printf("x = %f\n",x);
	printf("y = %f\n",y);

}
#endif

#if 0
void copy_object(void* vpdest,const void* vpsource,size_t n){
	const char* psource = (const char*)vpsource;
	char* pdest = (char*)vpdest;
	while(n--){
		*pdest++ = *psource++;
	}
}

int main(void){

	double d1 = 873.97664;
	double d2;

	int i1 = 6789;
	int i2;
	int a[] = {3,6,1,2,3,56,9};
	int b[7];

	copy_object(&d2,&d1,sizeof(double));
	copy_object(&i2,&i1,sizeof(int));
	copy_object(&b,&a,sizeof(b));

	printf("d1 = %f\n",d1);
	printf("d2 = %f\n",d2);
	printf("i1 = %d\n",i1);
	printf("i2 = %d\n",i2);
	print_array(a,asize(a));
	print_array(b,asize(b));
}
#endif

#if 0
/*Generic swap function*/

void gswap(void *vp, void *vp2, size_t size)
{
	char ctemp;
	char *cp1 = (char *)vp;
	char *cp2 = (char *)vp2;
	/*WAY 1*/
	// for(int i = 0; i < size;++i){
	// 	ctemp = cp1[i];
	// 	cp1[i] = cp2[i];
	// 	cp2[i] = ctemp;
	// }
	/*WAY 2*/
	while (size--)
	{
		ctemp = *cp1;
		*cp1++ = *cp2;
		*cp2++ = ctemp;
	}
}

int main(void)
{

	int x = 5, y = 475;
	double dx = 69.69;
	double dy = 31.31;

	printf("x = %d\t y = %d\n", x, y);
	gswap(&x, &y, sizeof(x));
	printf("x = %d\t y = %d\n", x, y);
	printf("x = %f\t y = %f\n", dx, dy);
	gswap(&dx, &dy, sizeof(dx));
	printf("x = %f\t y = %f\n", dx, dy);
}
#endif

#if 0
/*generic reverse array function*/
void gswap(void *vp, void *vp2, size_t size)
{
	char ctemp;
	char *cp1 = (char *)vp;
	char *cp2 = (char *)vp2;
	/*WAY 1*/
	// for(int i = 0; i < size;++i){
	// 	ctemp = cp1[i];
	// 	cp1[i] = cp2[i];
	// 	cp2[i] = ctemp;
	// }
	/*WAY 2*/
	while (size--)
	{
		ctemp = *cp1;
		*cp1++ = *cp2;
		*cp2++ = ctemp;
	}
}
// size -> sizeof 1 elements in array
void g_get_reverse_array(void *vp,size_t len, size_t size)
{
	char *p = (char *)vp;
	for (int i = 0; i < (len / 2); ++i)
	{
		gswap((p + i * size), (p + (len - 1 - i) * size), size);
	}
}

int main(void)
{
	int a[5] = {0, 2, 4, 5, 31};
	print_array(a, asize(a));
	g_get_reverse_array(a, asize(a), sizeof(int));
	print_array(a, asize(a));
}

#endif

#if 0
/*Alternative Generic reverse array implementation*/
void gswap(void *vp, void *vp2, size_t size)
{
	char ctemp;
	char *cp1 = (char *)vp;
	char *cp2 = (char *)vp2;
	/*WAY 1*/
	// for(int i = 0; i < size;++i){
	// 	ctemp = cp1[i];
	// 	cp1[i] = cp2[i];
	// 	cp2[i] = ctemp;
	// }
	/*WAY 2*/
	while (size--)
	{
		ctemp = *cp1;
		*cp1++ = *cp2;
		*cp2++ = ctemp;
	}
}

void g_get_reverse_array(void *vp,size_t len, size_t size)
{
	char *p = (char *)vp; // first element of array
	char *pe = (char*)vp + (len-1) * size; // end of array

	while(p < pe){
		gswap(p,pe,size);
		p += size;
		pe -= size;
	}
}
int main(void)
{
	int a[5] = {0, 2, 4, 5, 31};
	print_array(a, asize(a));
	g_get_reverse_array(a, asize(a), sizeof(int));
	print_array(a, asize(a));
}
#endif

#if 0
/*memset() function*/
int main(void)
{
	int x = 10;
	printf("x = %d\n",x);
	memset(&x,0,sizeof(x));
	printf("x = %d\n",x);
}

#endif
#if 0
/*memset() function*/
int main(void)
{
	int x = 10;
	printf("x = %d\n",x);
	int* p = (int*)memset(&x,0,sizeof(x));
	printf("x = %d\n",x);

	if(p == &x){
		printf("dogru");
	}
	else{
		printf("yanlis");
	}
}
/*
out:
x = 10
x = 0
dogru
*/
#endif

#if 0
#define SIZE 20
/*memset() function*/
int main(void)
{
	int a[SIZE];
	print_array(a,SIZE);
	memset(a,0,sizeof(a[0]));
	print_array(a,SIZE);
}

#endif

#if 0
#define SIZE 20
/*memset() function*/
int main(void)
{
	char str[100] = "Hande Kubilay";
	puts(str);
	memset(&str[6], '*', 7);
	puts(str);
}
#endif

#if 0
#define SIZE 20
/*arraydeki verilen indexten başlanarak kullanıcıdan alınan adet kadar elemanı 0 yapmak*/
int main(void)
{
	int a[SIZE];
	randomize();
	set_array_random(a,SIZE);
	print_array(a,SIZE);
	int idx,n;
	printf("index ve adet degeri giriniz: ");
	scanf("%d%d",&idx,&n);

	memset(a+idx,0,sizeof(int) * n);
	print_array(a,SIZE);
}

#endif

#if 0
#define SIZE 20
/*memcpy() function*/
int main(void)
{
	int x, y;
	printf("bir tam sayi giriniz: ");
	scanf("%d",&x);
	memcpy(&y,&x, sizeof x); // y = x;
	printf("y = %d\n",y);
}
#endif

#if 0
#define SIZE 20
/*copy array with memcpy() function*/
int main(void)
{
	int x[SIZE] = {31,31,31,31,31,3,13,1};
	int y[SIZE] =  {0};
	randomize();
	print_array(x,SIZE);
	print_array(y,SIZE);
	memcpy(&y,&x, sizeof x); 
	print_array(y,SIZE);
}
#endif

#if 0
#define SIZE 20
/*copy string with memcpy() function*/
int main(void)
{
	system("cls");
	puts("Evlendirme Dairesine Hosgeldiniz");
	char s1[] = "Yavuz Hanege";
	char s2[] = "Hande Kubilay";
	printf("Ilk kisi: %s\n",s1);
	printf("Ikinci kisi: %s\n",s2);
	puts("Islem gerceklesiyor.........\n");	
	printf("%s\n",s2);
	puts("Lutfen Enter Tusuna Basiniz.\n");
	(void)getchar();
	memcpy(s2+6,s1+6,sizeof s2);
	printf("%s\n",s2);
	printf("Islem Basarili!!!");

}
#endif

#if 0
/*memmove functions*/
int main(void)
{

	char str[100] = "gulsen";
	// strcpy(str+3,str);// UNDEFINED BEHAVIOUR
	// memcpy(str+3,str,strlen(str) + 1);// UNDEFINED BEHAVIOUR
	memmove(str + 3, str, strlen(str) + 1); // LEGAL

	puts(str);
}

#endif

#if 0
int main(void){

	unsigned char buf[] = {1,2,3,4,5,6,7,8,9,0};

	unsigned char* p = memchr(buf,0,sizeof(buf));
	printf("%d indexli elemani",p-buf);

}
#endif

#if 0
int main(void)
{

	char str[] = "ankara'da kara gozlu kara kasli bir arkadasim var";

	if (memchr(str, 'v', strlen(str)))
	{
		printf("bulundu.");
	}
	else
	{
		printf("bulunamadi.");
	}
}
#endif

#if 0
/*memchr function*/
void *my_memchr(const void *vp, int key, size_t size)
{
	const char *c = vp;

	while (size--)
	{
		if (*c == key)
		{
			return (char*)c;
		}
		c++;
	}
	return NULL;
}

int main(void)
{
	char str[] = "ankara'da kara gozlu kara kasli bir arkadasim var";

	if (my_memchr(str, 'v', sizeof(str)))
	{
		printf("bulundu.");
	}
}

#endif

#if 0
#define SIZE 10
/*memcmp function*/
int my_memcmp(const void *vp1, const void *vp2, size_t size)
{

	const unsigned char *p1 = (const unsigned char *)vp1;
	const unsigned char *p2 = (const unsigned char *)vp2;

	while (size--)
	{
		if (*p1 != *p2)
		{
			if (*p1 > *p2)
			{
				return 1;
			}
			else if (*p1 < *p2)
			{
				return -1;
			}
		}
		++p1;
		++p2;
	}
	return 0;
}

int main(void)
{

	char a[SIZE] = {1, 2, 3, 4, 5, 7, 8, 0};
	char b[SIZE];
	memcpy(b, a, sizeof(a));

	if (!my_memcmp(a, b, sizeof(b)))
	{
		printf("esittir\n");
	}
	else
	{
		printf("esit degildir\n");
	}

	a[3]++;

	if (!my_memcmp(a, b, sizeof(b)))
	{
		printf("esittir\n");
	}
	else
	{
		printf("esit degildir\n");
	}
}

#endif

#if 0
int main(void)
{

	int x = -856;
	int y = 1;

	if (y > x)
		printf("evet dogru\n");

	else
		printf("dogru degil\n");

	if (!memcmp(&y, &x, sizeof(x)))
		printf("esittir\n");

	else if (memcmp(&y, &x, sizeof(x)) > 0)
		printf("buyuktur\n");

	else
	{
		printf("kucuktur\n");
	}
}
#endif

#if 0
/*endianness*/
int main(void)
{
	int x = 1; /*00000000 00000000 00000000 00000001 */
	if (*(char*)&x)
	{
		printf("little endian");
	}
	else
	{
		printf("big-endian");
	}
}
#endif

#if 0
/*Generic strstr() function HOMEWORK*/
const void *g_strstr(const void *vp1, size_t sizevp1, const void *vp2, size_t sizevp2)
{
	const unsigned char *haystack = (const unsigned char *)vp1;
	const unsigned char *needle = (const unsigned char *)vp2;

	if (sizevp2 == 0) 
		return haystack;

	while (sizevp1 >= sizevp2)
	{
		if (memcmp(haystack, needle, sizevp2) == 0)
		{
			return haystack; 
		}
		haystack++;
		sizevp1--;
	}

	return NULL;
}

int main(void)
{

	char *str1 = "yavuzhanege";
	char *str2 = "hanege";
	if (g_strstr(str1, strlen(str1), str2, strlen(str2)))
	{
		printf("bulundu");
	}
	else
	{
		printf("bulunamadi.");
	}
}
#endif

#if 0
/*function pointers*/
int f1(int, int);
int f2(int, int);
void f3(int, int);

int main(void)
{
	int (*fptr)(int, int) = &f1;
	fptr = f2;			 /*function to pointer conversion*/
	fptr = f3; /*error*/ /*assignment from incompatible pointer type [-Wincompatible-pointer-types]gcc
						  */
}

#endif
#if 0
/*function pointers*/
int f1(int, int);
int f2(int, int);
void f3(int, int);

int main(void)
{
	int (*fptr)(int, int) = &f1;
	fptr = f2;			 /*function to pointer conversion*/
	fptr = f3; /*error*/ /*assignment from incompatible pointer type [-Wincompatible-pointer-types]gcc
						  */
}
#endif

#if 0

typedef int(*FPTR)(int,int);

int main(void)
{
	FPTR fp1; /*int(*fp1)(int,int)*/
	FPTR fp2,fp3,fp4; 
}
#endif

#if 0

typedef int (*FPTR_t)(const char*, const char*);

FPTR_t gf = &strcmp;

void func(FPTR_t x)
{
	FPTR_t fp1 = &strcmp;
	static FPTR_t fp2 = &strcmp;
}
int main(void)
{

	
}

#endif

#if 0

int foo(int,int);
int main(void)
{
	int (*fp)(int,int) = &foo;

}

#endif

#if 0

int foo(int, int);
int main(void)
{
	int (*fp)(int, int) = &foo;
	int (**fptr)(int, int) = &fp; /*pointer to function pointer */
}

#endif
#if 0

int foo(int, int);
typedef int (*FPTR)(int, int);
int main(void)
{
	// int (*fp)(int, int) = &foo;
	FPTR fp = &foo;
	// int (**fptr)(int, int) = &fp; /*pointer to function pointer */
	FPTR *fptr = &fp;
}

#endif
#if 0

int foo(int a, int b){return 1;}
int bar(int a, int b){return 1;}
int baz(int a, int b){return 1;}
int bom(int a, int b){return 1;}
typedef int (*FPTR)(int, int);
int main(void)
{

	int (*fa1[4])(int,int) = {&foo,&bar,&baz,&bom};
	int (*fa2[4])(int,int) = {foo,bar,baz,bom};
	FPTR fa3[] = {foo,bar,baz,bom};
}

#endif

#if 0
/*Function call*/
void foo(void){
	printf("void func call\n");
}

int main(void)
{
/*SAME CALL TYPES*/
	foo();
	(&foo)(); 
}

#endif

#if 0
/*Function call*/
void foo(void){
	printf("void func call\n");
}

int main(void)
{

	void (*fp)(void) = &foo;
	fp(); /*FUNCTION CALL*/
}

#endif

#if 0
/*Function call*/
void foo(void){printf("void foo func call\n");}
void bar(void){printf("void bar func call\n");}
void baz(void){printf("void baz func call\n");}

int main(void)
{

	void (*fptr)(void);

	fptr = &foo;
	fptr();
	fptr = &bar;
	fptr();
	fptr = &baz;
	fptr();
}

#endif

#if 0
/*Function Calls*/
void foo(void) { printf("void foo func call\n"); }
void bar(void) { printf("void bar func call\n"); }
void baz(void) { printf("void baz func call\n"); }

int main(void)
{
	void (*fp)(void) = &foo;

	foo();
	(&foo)();
	(*foo)();
	fp();
	(*fp)();
}

#endif

#if 0
void foo(void) { printf("void foo func call\n"); }
void bar(void) { printf("void bar func call\n"); }
void baz(void) { printf("void baz func call\n"); }


void func(void(*fp)(void)){
	fp();

}

int main(void){

	func(foo); // foo function call
	func(&foo); // foo function call
	func(&bar); // bar function call

	

}
#endif

#if 0
/*Function callback Mechanism*/
void print_chars(int (*fp)(int))
{
	for (int i = 0; i < 128; ++i)
	{
		if (fp(i))
		{
			putchar(i);
		}
	}
	putchar('\n');
}
int main(void)
{

	print_chars(isupper);
	print_chars(&islower);
	print_chars(&isalpha);
	print_chars(isalnum);
	print_chars(isxdigit);
}

#endif

#if 0
void print_object(const void* vp,void(*fpr)(const void*)){
	fpr(vp);
}
void my_iprint(const void* vp){

	int val = *(const int*)vp;
	printf("(%d)\n",val);

}
void my_dprint(const void* vp){

	double dval = *(const double*)vp;
	printf("(%f)\n",dval);

}
void my_cprint(const void* vp){

	char cval = *(const char*)vp;
	printf("(%c)\n",cval);

}
int main(void)
{

	int i = 5;
	double d = 3.4;
	char c = 'A';
	print_object(&i,my_iprint);
	print_object(&d,my_dprint);
	print_object(&c,my_cprint);
}

#endif

#if 0
/*story of qsort()*/
#define SIZE 20
int mycmp(const void* vp1,const void* vp2){
	const int* p1 = (const int*)vp1; 
	const int* p2 = (const int*)vp2;
	if(*p1 == *p2)
		return 0;
	else if(*p1 > *p2){
		return 1;
	}
	else{
		return -1;
	}

}

int main(void)
{
	int a[SIZE];
	randomize();
	set_array_random(a,SIZE);
	print_array(a,SIZE);
	qsort(a,SIZE,sizeof(int),&mycmp);
	print_array(a,SIZE);
	
}

#endif

#if 0
#define SIZE 20
/*bubble sort generic algortihm like qsort*/
void gbsort(void *vpa,size_t size,size_t sz,int (*fcmp)(const void*,const void*)){
	
	char* p = (char*)vpa;

	
	for(int i = 0; i < size-1;++i){
		for(int k = 0; k < size - i -1;++k){
			if(fcmp((p+k*sz),(p+(k+1)*sz))){
				gswap((p+k*sz),(p+(k+1)*sz),sz);
			}
		}
	}

}

int myicmp(const void* vp1,const void* vp2){
	const int* p1 = (const int*)vp1; 
	const int* p2 = (const int*)vp2;
	if(*p1 == *p2)
		return 0;
	else if(*p1 > *p2){
		return 1;
	}
	else{
		return -1;
	}

}

int main(void){
	int a[SIZE];
	randomize();
	set_array_random(a,SIZE);
	print_array(a,SIZE);
	qsort(a,SIZE,sizeof(int),&myicmp);
	print_array(a,SIZE);


}
#endif

#if 0
/*generic search function implementation*/
#define SIZE 20
void *gsearch(const void *vp, size_t size, size_t sz, const void *vpkey)
{
	const char *p = (const char *)vp;
	while (size--)
	{
		if (!memcmp(p, vpkey, sz))
			return (char *)p;

		p += sz;
	}
	return NULL;
}

int main(void)
{
	int a[SIZE];
	randomize();
	set_array_random(a, SIZE);
	print_array(a, SIZE);
	int key;

	printf("arancak degeri giriniz: ");
	scanf("%d", &key);
	int *p = gsearch(a, SIZE, sizeof(a[0]), &key);

	if (p)
	{
		printf("bulundu %d indexli elemani", p - a);
	}
	else
	{
		printf("bulunamadi.");
	}
}

#endif

#if 0
#define SIZE 20

int icmp(const void *vp1, const void *vp2)
{
	const int *p1 = (const int *)vp1;
	const int *p2 = (const int *)vp2;
	if (*(p1) > *(p2))
	{
		return 1;
	}
	else if (*(p1) < *(p2))
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{

	int a[SIZE];
	randomize();
	set_array_random(a, SIZE);
	print_array(a, SIZE);
	qsort(a, SIZE, sizeof(a[0]), icmp);
	print_array(a, SIZE);
	int key;
	printf("arancak degeri giriniz: ");
	scanf("%d", &key);
	int *p = bsearch(&key, a, SIZE, sizeof(a[0]), icmp);
	if (p)
	{
		printf("bulundu, dizinin %d indexli adresi\n", p - a);
	}
	else
	{
		printf("bulunamadi.\n");
	}
}

#endif

#if 0
/*HOMEWORK:Bir char pointer dizisindeki tüm elemanlari qsort fonksiyonu ile sıralayınız. */

int g_c_cmp(const void *vp1, const void *vp2)
{
	const char *const*p1 = (const char *const*)vp1;
	const char *const*p2 = (const char *const*)vp2;

	return strcmp(*p1, *p2);
}
int main(void)
{
	const char *charPointerArray[] = {
		"G", "B", "K", "D", "Y", "W", "L", "Q", "E", "A", "Z", "U", "T",
		"R", "H", "P", "C", "S", "F", "X", "I", "V", "M", "N", "J", "O"};

	for (size_t i = 0; i < asize(charPointerArray); ++i)
	{
		printf("%s ", charPointerArray[i]);
	}
	putchar('\n');
	printf("-----------------------------------------");
	putchar('\n');

	qsort(charPointerArray, asize(charPointerArray), sizeof(charPointerArray[0]), g_c_cmp);

	for (size_t i = 0; i < asize(charPointerArray); ++i)
	{
		printf("%s ", charPointerArray[i]);
	}
	putchar('\n');
	printf("-----------------------------------------");
	putchar('\n');
}

#endif

#if 0
/*function pointer return type functions */
int foo(const char* c1,const char* c2){
	printf("function foo call");
	return 1;
}

int(*bar(void))(const char*,const char*){
	return &foo;
}
int main(void){
	const char ch1,ch2;
	int(*fp)(const char*,const char*) = bar();
	fp(&ch1,&ch2);

}
#endif

#if 0
typedef int (*FPTYPE)(const char*,const char*);

/*function pointer return type functions */
int foo(const char* c1,const char* c2){
	printf("function foo call");
	return 1;
}

// int(*bar(void))(const char*,const char*){
// 	return &foo;
// }

FPTYPE bar(void){
	return &foo;
}

int main(void){
	const char ch1,ch2;
	//int(*fp)(const char*,const char*) = bar();
	FPTYPE fp = bar();
	fp(&ch1,&ch2);

}
#endif

#if 0
/*Function pointer arrays*/
int f1(int x, int y)
{
	printf("function f1 call\n");
	return 1;
}
int f2(int x, int y)
{
	printf("function f2 call\n");
	return 2;
}
int f3(int x, int y)
{
	printf("function f3 call\n");
	return 3;
}
int f4(int x, int y)
{
	printf("function f4 call\n");
	return 4;
}

int main(void)
{
	int a = 0, b = 0;
	int (*fp[])(int, int) = {&f1, &f2, &f3, &f4};
	for (int i = 0; i < 4; i++)
	{
		(fp[i])(a, b);
	}
}

#endif

#if 0
/*Function pointer arrays*/
int f1(int x, int y)
{
	printf("x = %d\ty = %d function f1 call\n",x,y);
	return 1;
}
int f2(int x, int y)
{
	printf("x = %d\ty = %d function f2 call\n",x,y);
	return 2;
}
int f3(int x, int y)
{
	printf("x = %d\ty = %d function f3 call\n",x,y);
	return 3;
}
int f4(int x, int y)
{
	printf("x = %d\ty = %d function f4 call\n",x,y);
	return 4;
}

int main(void)
{
	int (*fp[])(int, int) = {&f1, &f2, &f3, &f4};
	for (int i = 0; i < 4; i++)
	{
		(fp[i])(i, i);
	}
}

#endif

#if 0
/*Function Pointer Array Example*/
void print_menu(void)
{
	printf(
		"[1] isupper\n"
		"[2] islower\n"
		"[3] isalpha\n"
		"[4] isdigit\n"
		"[5] isalnum\n"
		"[6] isxdigit\n"
		"[7] ispunct\n");
}

int get_option(void)
{
	print_menu();
	int option;
	printf("seciminizi giriniz: ");
	scanf("%d", &option);
	return option;
}

int (*fa[])(int) = {isupper,
					islower,
					isalpha,
					isdigit,
					isalnum,
					isxdigit,
					ispunct};

int main(void)
{
	printf("bir karakter girin: ");
	int ch = getchar();
	int op = get_option();
	if (fa[op](ch))
	{
		printf("girilen karakter secilen fonksiyona uygun degildir.");
	}
	else
	{
		printf("girilen karakter secilen fonksiyona uygundur.");
	}
}

#endif

#if 0
/*Function Pointer Array Interview Question*/
void print_menu(void)
{
	printf(
		"[1] isupper\n"
		"[2] islower\n"
		"[3] isalpha\n"
		"[4] isdigit\n"
		"[5] isalnum\n"
		"[6] isxdigit\n"
		"[7] ispunct\n");
}

char *get_option(void)
{
	print_menu();
	static char str_option[45];
	printf("seciminizi giriniz: ");
	scanf("%s", str_option);
	return str_option;
}

int (*const fa[])(int) = {isupper,
					islower,
					isalpha,
					isdigit,
					isalnum,
					isxdigit,
					ispunct};

const char* const func_names[] = {
	"isupper",
	"islower",
	"isalpha",
	"isdigit",
	"isalnum",
	"isxdigit",
	"ispunct"};

int main(void)
{
	printf("bir karakter girin: ");
	int ch = getchar();
	char *op = get_option();
	for (size_t i = 0; i < asize(func_names); ++i)
	{
		if (!strcmp(op, func_names[i]))
		{
			if (fa[i](ch))
			{
				printf("OK\n");
			}
			else
			{
				printf("NOK\n");
			}
		}
	}
}

#endif

#if 0
/*function behaviour set in library function*/
#include "fpointers.h"

void yavuz(void) { printf("yavuz cagirildi\n"); }

int main(void)
{
	foo();
	ftype fpp = set_foo(yavuz);
	foo();
	set_foo(fpp);
	foo();
}

#endif

#if 0
/*function register with function pointer arrays example*/
#include "fpointers.h"
void f1(void) { printf("f1 cagrildi\n"); }
void f2(void) { printf("f2 cagrildi\n"); }
void f3(void) { printf("f3 cagrildi\n"); }
void f4(void) { printf("f4 cagrildi\n"); }
void f5(void) { printf("f5 cagrildi\n"); }

int main(void)
{
	reg_func(f1);
	// reg_func(f2);
	reg_func(f3);
	// reg_func(f4);
	reg_func(f5);

	reg_foo();
}

#endif

#if 0
void f1(void) { printf("f1 cagrildi\n"); }
void f2(void) { printf("f2 cagrildi\n"); }
void f3(void) { printf("f3 cagrildi\n"); }
void f4(void) { printf("f4 cagrildi\n"); }
void f5(void) { printf("f5 cagrildi\n"); }

int main(void)
{
	atexit(f1);
	atexit(f2);
	atexit(f3);
	atexit(f4);
	atexit(f5);
	printf("main basladi.\n");
	exit(1);
	printf("main devam ediyor\n");
}

#endif

#if 0
/*Multi-Dimensional Arrays*/
int main(void)
{
	int a[10][20];
	printf("a size = %zu", asize(a));
}

#endif

#if 0
/*Multi-Dimensional Arrays Init*/
int main(void)
{
	int a[4][3] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}};
}

#endif

#if 0
/*Multi-Dimensional Arrays */
int main(void)
{
	int a[4][3] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}};
	for (int i = 0; i < 4; ++i)
	{
		for (int k = 0; k < asize(a[1]); ++k)
		{
			printf("%d", a[i][k]);
		}
		putchar('\n');
	}
}

#endif

#if 0

int main(void)
{

	int a[4][3] = {
		{1, 1, 1},
		{2, 2, 2},
		{3, 3, 3},
		{4, 4, 4}};

	for (int i = 0; i < 4; ++i)
	{
		/* ARRAY DECAY */
		print_array(a[i], 3);
		// print_array(&a[i][0],3);
		/* NO DIFFERENCE */
	}
}

#endif

#if 0
int main(void)
{

	int a[4][3] = {
		{1, 1, 1},
		{2, 2, 2},
		{3, 3, 3},
		{4, 4, 4}};

	int (*p)[3] = a;

	size_t size = asize(a);
	while(size--){
		print_array(*p++,asize(a[1]));
	}
}

#endif
#if 0
int main(void)
{

	int a[4][3] = {
		{1, 1, 1},
		{2, 2, 2},
		{3, 3, 3},
		{4, 4, 4}};

	int (*p)[3] = a;

	for(int i = 0; i < 4; ++i){
		for(int k = 0; k < 3; ++k){
			printf("%d, ",(*p)[k]);
		}
		putchar('\n');
		++p;
	}
}

#endif
#if 0
/*Mult-Dim arrays with functions*/
void set_matrix20(int(*p)[20],int size){
	for(int i = 0; i < size;++i){
		for(int k = 0; k < 20;++k){
			p[i][k] = rand() % 31;
		}
	}
}

int main(void)
{

	int a[4][20];
	set_matrix20(a,4);
	int (*p)[20] = a;

	for(int i = 0; i < 4; ++i){
		for(int k = 0; k < 20; ++k){
			printf("%d ",(*p)[k]);
		}
		putchar('\n');
		++p;
	}
}

#endif
#if 0
/*Mult-Dim arrays with function makros*/

#define set_mtrx(s)                          \
	void set_matrix##s(int(*p)[s], int size) \
	{                                        \
		for (int i = 0; i < size; ++i)       \
		{                                    \
			for (int k = 0; k < s; ++k)      \
			{                                \
				p[i][k] = rand() % 31;       \
			}                                \
		}                                    \
	}

#define print_mtrx(s)                                            \
	void print_matrix##s(int(*p)[s], int size)                   \
	{                                                            \
		for (int i = 0; i < 4; ++i)                              \
		{                                                        \
			for (int k = 0; k < s; ++k)                          \
			{                                                    \
				printf("%d ", p[i][k]);                          \
			}                                                    \
			putchar('\n');                                       \
		}                                                        \
		printf("-------------------------------------------\n"); \
	}

/*
void set_matrix20(int(*p)[20],int size){
	for(int i = 0; i < size;++i){
		for(int k = 0; k < 20;++k){
			p[i][k] = rand() % 31;
		}
	}
}
*/

/*void print_matrix20(int(*p)[20],int size){
	for (int i = 0; i < 4; ++i)
	{
		for (int k = 0; k < 20; ++k)
		{
			printf("%d ",p[i][k]);
		}
		putchar('\n');
	}
	printf("-------------------------------------------\n");
}*/

set_mtrx(20);
set_mtrx(5);
print_mtrx(20);
print_mtrx(5);
int main(void)
{
	int b[12][5];
	int a[4][20];
	set_matrix20(a, 4);
	set_matrix5(b, 12);
	print_matrix20(a, 4);
	print_matrix5(b, 12);
}

#endif

#if 0
/*strncat() function*/
#define SIZE 100
int main(void)
{
	char dest[SIZE];
	char source[SIZE] = "yavuz hanege";
	strncpy(dest, source, 5);
	puts(dest);
}

#endif

#if 0
#define SIZE 100
int main(void)
{
	char dest[SIZE] = "hande kubilay";
	char source[SIZE] = "yavuz hanege";
	// strcpy(dest)
	strncpy(dest + 6, source + 6, 6);
	dest[strlen(dest) - 1] = 0;
	puts(dest);
}
#endif

#if 0
/*strncmp() function*/
#define SIZE 100
int main(void)
{
	int n = 6;
	char p1[SIZE] = "hande hanege";
	char p2[SIZE] = "yavuz hanege";
	// strcpy(dest)
	if(!strncmp(p1+6,p2+6,n)){
		printf("yazilarin son %d karakteri (%s) esitir",n,p1+6);
	}
	else{
		printf("yazilarin son %d karakteri esit degildir",n);
	}
}
#endif

#if 0
/*strspn() function*/
int main(void){

	char str1[] = "yavuz";
	char str2[] = "vuay";
	int indx_span = strspn(str1,str2);
	printf("span = %d\n",indx_span);
}
#endif

#if 0
/*strcspn() function*/
int main(void){

	char str1[] = "yavuz";
	char str2[] = "vu";
	int c_indx_span = strcspn(str1,str2);
	printf("c_span = %d\n",c_indx_span);
}
#endif

#if 0
/*strtok() function*/
int main(void)
{
	char str1[100];
	printf("bir yazi giriniz: ");
	sgets(str1);
	const char *p = strtok(str1, " \t.!");
	while (p)
	{
		puts(p);
		p = strtok(NULL, " \t.!");
	}
}
#endif
#if 0
/*atoi() function*/
int main(void)
{
	char str1[100];
	printf("bir yazi giriniz: ");
	sgets(str1);
	int val = atoi(str1);
	printf("val = %d\n",val);
}
#endif

#if 0
int main(void)
{
	char str1[100];
	printf("bir yazi giriniz: ");
	sgets(str1);
	int day,mon,year;
	const char *p = strtok(str1, "-/"); /*bosluk, tab, nokta ve unlem karakterleri seperator*/
	int i = 0;
	while (p)
	{
		puts(p);
		switch (i)
		{
		case 0:
			day = atoi(p);
			break;
		case 1:
			mon = atoi(p);

		case 2:
			year = atoi(p);

		default:
			break;
		}
		p = strtok(NULL, "-/");
		i++;
	}
	printf("day = %d\nmon = %d\nyear = %d\n",day,mon,year);
}
#endif

#if 0
/*strto functions*/
int main(void)
{
	char str[] = "87542hande";
	char *p = 0;
	long x = strtol(str, &p, 10);
	printf("(%s) yazisinin sayi kismi %ld ve bittigi yerdeki karakter (%c) ve adresi %p", str, x, *p, p);
}

#endif

#if 0
int main(void)
{
    int id = 36;
    float fd = 121.45;
    char cdizi[] = "C Programlama Dili";
    char buffer[100];

    sprintf(buffer, "%d %.2f %s", id, fd, cdizi);
    printf("Olusturulan karakter dizisi: %s\n", buffer);

    /* Sadece ilk 7 karakteri okur. */
    sprintf(buffer, "%.*s\n", 7, cdizi);
    printf("Olusturulan karakter dizisi: %s\n", buffer);
	exit(31); /*exit function*/
}
#endif

#if 0
/* atexit() Function */

void fooo(void)
{
	printf("program sonlandirilmadan once fooo() calistirildi\n");
}
void bar(void)
{
	printf("program sonlandirilmadan once bar() calistirildi\n");
}

int main(void)
{

	atexit(&fooo);
	atexit(&bar);
	printf("main() basladi.\n");
	exit(EXIT_SUCCESS);
}

#endif
#if 0
	/* abort() Function */

	void fooo(void)
	{
		printf("program sonlandirilmadan once fooo() calistirildi\n");
		abort();
		
	}
	void bar(void)
	{
		printf("program sonlandirilmadan once bar() calistirildi\n");
	}

	int main(void)
	{
		printf("main() basladi.\n");
		fooo();
		exit(EXIT_FAILURE);
	}

#endif

#if 0
/*malloc() functions*/
int main(void)
{
	size_t n;
	printf("kac tam sayi: ");
	scanf("%d", &n);
	int *ptr = (int *)malloc(n * sizeof(int));
	if(!ptr){
		fprintf(stderr,"malloc basarisiz oldu\n");
		exit(EXIT_FAILURE);
	}
	randomize();
	set_array_random(ptr,n);
	print_array(ptr,n);
	free(ptr); /*for memory leak*/
}

#endif

#if 0
/*malloc() augmentation wrapper*/

void *checked_malloc(size_t n)
{
	void *vp = malloc(n);
	if (!vp)
	{
		fprintf(stderr, "malloc basarisiz oldu\n");
		exit(EXIT_FAILURE);
	}
	return vp;
}

int main(void)
{
	size_t n;
	printf("kac tam sayi: ");
	scanf("%d", &n);
	int *ptr = (int *)checked_malloc(n * sizeof(int));
	randomize();
	set_array_random(ptr, n);
	print_array(ptr, n);
	free(ptr); /*for memory leak*/
}
#endif

#if 0
/*DANGLING POINTER (UNDEFINED BEHAVIOUR)*/
void *checked_malloc(size_t n)
{
	void *vp = malloc(n);
	if (!vp)
	{
		fprintf(stderr, "malloc basarisiz oldu\n");
		exit(EXIT_FAILURE);
	}
	return vp;
}

int main(void)
{
	size_t n;
	printf("kac tam sayi: ");
	scanf("%d", &n);
	int *ptr = (int *)checked_malloc(n * sizeof(int));
	randomize();
	set_array_random(ptr, n);
	print_array(ptr, n);
	int* p2 = ptr;
	free(ptr); /*for memory leak*/
	print_array(p2,n); /*DANGLING POINTER*/
}
#endif

#if 0
int main(void)
{
	size_t n;
	printf("kac tam sayi: ");
	scanf("%d", &n);
	int *ptr = (int *)calloc(n, sizeof(int));
	print_array(ptr, n);
	randomize();
	set_array_random(ptr, n);
	print_array(ptr, n);
	free(ptr); /*for memory leak*/
}
#endif

#if 0
#define SIZE 20
char *my_strdup(const char *str)
{
	char *p = malloc(strlen(str) + 1);
	if (!p)
	{
		return NULL;
	}
	return strcpy(p, str);
}

int main(void)
{
	char str[SIZE];
	printf("bir yazi giriniz:");
	sgets(str);
	char *pd = my_strdup(str);
	printf("%s\n", str);
	printf("%s\n", pd);
	free(pd);
}

#endif

#if 0
char *strconcat(const char *c1, const char *c2)
{
	char *p1 = my_strdup(c1);
	char *p2 = my_strdup(c2);
	char *ret = malloc(strlen(p1) + strlen(p2) + 1);
	if(ret == NULL){
		return NULL;
	}
	ret = p1;
	strcat(ret, p2);
	return ret;
}
int main(void)
{
	char *yvz = "yavuz";
	char *hng = "hanege";
	char *pd = strconcat(yvz, hng);
	printf("(%s) + (%s) = (%s)",yvz,hng, pd);
	free(pd);
}

#endif

#if 0

#include <stddef.h> // size_t

int fn_compare_int(const void *vp1, const void *vp2)
{
	return *(const int *)vp1 - *(const int *)vp2;
}

int *create_random_array(size_t size)
{
	int *pd_arr = (int *)malloc(size * sizeof(int));

	if (!pd_arr)
		return NULL;

	return set_array_random_2(pd_arr, size);
}

int main(void)
{
	size_t N = 20;

	int *p_arr = create_random_array(N);
	print_array(p_arr, N);
	// output ->
	//   41 467 334 500 169 724 478 358 962 464
	//  705 145 281 827 961 491 995 942 827 436

	qsort(p_arr, N, sizeof(*p_arr), &fn_compare_int);

	print_array(p_arr, N);
	// output ->
	//   41 145 169 281 334 358 436 464 467 478
	//  491 500 705 724 827 827 942 961 962 995

	free(p_arr);
	p_arr = NULL;
}

#endif

#if 0

#define SIZE 100
#define MIN_LEN 8
#define MAX_LEN 16

char *get_rand_psw(char *p)
{
	char* ptemp = p;
	size_t len = rand() % (MAX_LEN - MIN_LEN + 1) + MIN_LEN;
	while (len--)
	{
		*p++ = rand() % 26 + 'a';
	}
	*p = '\0';
	return ptemp;
}

int main(void)
{
	char psw[SIZE];
	randomize();
	get_rand_psw(psw);
	puts(psw);
}

#endif

#if 0
#define SIZE 100
#define MIN_LEN 8
#define MAX_LEN 16

char *get_rand_psw(void)
{
	static char psw[SIZE];
	size_t len = rand() % (MAX_LEN - MIN_LEN + 1) + MIN_LEN;
	for(int i = 0; i < len; ++i){
		psw[i] = rand() % 26 + 'a';

	}
	return psw;
}

int main(void)
{
	randomize();
	char* psw = get_rand_psw();
	puts(psw);
}

#endif

#if 0
#define SIZE 100
#define MIN_LEN 8
#define MAX_LEN 16

char *get_rand_psw(void)
{
	static char psw[SIZE];
	size_t len = rand() % (MAX_LEN - MIN_LEN + 1) + MIN_LEN;
	for (int i = 0; i < len; ++i)
	{
		psw[i] = rand() % 26 + 'a';
	}
	psw[len] = '\0';
	return my_strdup(psw);
}

int main(void)
{
	// randomize();
	char *psw = get_rand_psw();
	puts(psw);
	free(psw);
}

#endif

#if 0
int main(void)
{
	randomize();
	size_t row = 0, col = 0;
	printf("row degeri giriniz: ");
	scanf("%d", &row);
	printf("col degeri giriniz: ");
	scanf("%d", &col);
	int **pd = (int **)malloc(row * sizeof(int *));
	if (!pd)
	{
		exit(1);
	}
	for (size_t i = 0; i < row; ++i)
	{
		pd[i] = (int *)malloc(col * sizeof(int));
		if (!pd[i])
		{
			exit(1);
		}
	}

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			pd[i][j] = rand() % 10;
			printf("%d ", pd[i][j]);
		}
		putchar('\n');
	}

	for (size_t i = 0; i < row; i++)
	{
		free(pd[i]);
	}
	free(pd);
}

#endif
#if 0
int main(void)
{
	randomize();
	size_t row = 0, col = 0;
	printf("row degeri giriniz: ");
	scanf("%d", &row);
	printf("col degeri giriniz: ");
	scanf("%d", &col);
	int *pd = (int *)malloc(row * col * sizeof(int));
	if (!pd)
	{
		exit(1);
	}
	for (size_t i = 0; i < row * col ; ++i)
	{
		pd[i] = rand() % 10;
		printf("%d ",pd[i]);
		if (i % row == 2){
			putchar('\n');
		}
	}
	free(pd);
}

#endif

#if 0
int main(void)
{
	randomize();
	size_t row = 0, col = 0;
	printf("row degeri giriniz: ");
	scanf("%d", &row);
	printf("col degeri giriniz: ");
	scanf("%d", &col);
	int *pd = (int *)malloc(row * col * sizeof(int));

	int **p = (int **)malloc(row * sizeof(int *));
	if (!pd || !p)
	{
		exit(1);
	}

	for (size_t i = 0; i < row; ++i)
	{

		p[i] = pd + i * col;
	}

	for (size_t i = 0; i < row; ++i)
	{
		for (size_t j = 0; j < col; ++j)
		{

			p[i][j] = rand() % 10;
		}
	}
	for (size_t i = 0; i < row; ++i)
	{
		for (size_t j = 0; j < col; ++j)
		{

			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	free(pd);
	free(p);
}
#endif

#if 0
/*realloc() function*/
int main()
{
	size_t n;
	printf("kac tam sayi ");
	// scanf'in dönüş değerini kontrol ediyoruz
	if (scanf("%d", &n) != 1)
	{
		printf("Invalid input!\n");
		// Eğer giriş geçersizse, giriş tamponunu temizlemek faydalı olur
		while (getchar() != '\n')
			; // Giriş tamponunu temizler
	}
	else
	{
		printf("Input Number: %d\n", n);
	}
	int *pd = malloc(n * sizeof(int));
	if (!pd)
	{
		abort();
	}
	randomize();
	set_array_random(pd, n);
	print_array(pd, n);
	size_t n_add;
	printf("kac tam sayi daha eklensin ");

	if (!scanf("%d", &n_add))
	{
		while (getchar() != '\n')
			; // Giriş tamponunu temizler
	}

	pd = realloc(pd, (n + n_add) * sizeof(int));
	if (!pd)
	{
		abort();
	}
	set_array_random(pd + n, n_add);
	print_array(pd, n + n_add);
	free(pd);
}

#endif

#if 0
/*reallocation with NULL pointer parameter example*/
int main()
{
	int ch;
	int val;
	size_t size = 0;
	int *pd = NULL;
	for (;;)
	{
		printf("bir tam sayi girecek misiniz (e) (h)");
		while ((ch = _getch()) != 'e' && ch != 'h')
			; // null statement
		printf("\nch = %c\n", ch);
		if (ch == 'h')
		{
			break;
		}
		pd = (int *)realloc(pd, (size + 1) * sizeof(int));
		if (!pd)
		{
			abort();
		}
		printf("tam sayi girin: ");
		val = rand() % 1000;
		printf("%d\n", val);
		pd[size++] = val;
	}
	printf("size = %zu\n", size);
	print_array(pd, size);
	free(pd);
	if (!size)
	{
		printf("hic giris yapmadiniz!\n");
	}
}

#endif
#if 0
/*ODEV dynamic array structures*/
int isDuplicated(const char **str1, size_t size, const char *str2)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (strcmp(str1[i], str2) == 0)
		{
			return 1;
		}
	}
	return 0;
}

void printCharArray(char **arr, size_t size)
{
	if (!arr || size == 0)
	{
		printf("Hic isim girilmedi!\n");
		return;
	}
	printf("Girilen isimler:\n");
	for (size_t i = 0; i < size; i++)
	{
		printf("%s\n", arr[i]);
	}
}
int ccmp(const void *c1, const void *c2)
{
	const char *str1 = *(const char **)c1;
	const char *str2 = *(const char **)c2;
	return strcmp(str1, str2);
}

int main()
{
	int ch;
	char *isim = NULL;
	size_t size = 0;
	size_t isim_len = 0;
	char **pd = NULL;
	for (;;)
	{
		printf("bir isim girecek misiniz (e) (h)");
		while ((ch = _getch()) != 'e' && ch != 'h')
			; // null statement
		printf("\nch = %c\n", ch);
		if (ch == 'h')
		{
			break;
		}
		if (!isim)
		{
			isim = malloc(isim_len * sizeof(char));
		}
		else if (strlen(isim) + 1 >= isim_len)
		{
			isim_len *= 2;
			isim = realloc(isim, isim_len * sizeof(char));
		}
		pd = (char **)realloc(pd, (size + 1) * sizeof(char *));
		if (!pd || !isim)
		{
			printf("allocation failed\n");
			abort();
		}

		printf("tam isim girin: ");
		scanf("%s", isim);
		printf("isim = %s\n", isim);
		if (isDuplicated((const char **)pd, size, isim))
		{
			printf("bu isim daha onceden girildi\n");
			free(isim);
			continue;
		}
		pd[size++] = my_strdup(isim);
	}
	printf("donguden cikti\n");
	printf("size = %zu\n", size);
	qsort(pd, size, sizeof(char *), ccmp);
	printCharArray(pd, size);
	for (size_t i = 0; i < size; ++i)
	{
		free(pd[i]);
	}
	free(pd);
	if (!size)
	{
		printf("hic giris yapmadiniz!\n");
	}
}
#endif

#if 0
#define INDEX 8
/*extern keyword*/
int main(void){
	printf("index %d of primes array is = %d\n", INDEX, primes[INDEX]);
}
#endif

#if 0
int main(void)
{
	int x = 2;
	int prime_count = 0;
	while (prime_count < 100)
	{
		if (isprime(x))
		{
			if (!prime_count || prime_count % 20 == 0)
			{
				putchar('\n');
			}
			printf("%3d,", x);
			prime_count++;
		}
		++x;
	}
}
#endif

#if 0
/*USER-DEFINED TYPES*/
/* dot operator */
struct data {
	int x,y;
	double d;
	char str[12];
};
int main(void){
	struct data mydata;
	mydata.x = 31; /*mydata nesnesinin x üyesine 31 değeri atandı.*/
	printf("member x of mydata struct = %d\n",mydata.x);
	++mydata.x; /*mydata nesnesinin x üyesinin değeri 1 arttırıldı*/
	printf("member x of mydata struct = %d\n",mydata.x);

}
#endif

#if 0
/*arrow operator*/
struct data
{
	int x, y;
	double d;
	char str[12];
};
int main(void)
{
	struct data mydata;

	struct data *p = &mydata;
	p->x = 31; /*mydata nesnesinin x üyesine 31 değeri atandı.*/
	printf("member x of mydata struct = %d\n", p->x);
	++p->x; /*mydata nesnesinin x üyesinin değeri 1 arttırıldı*/
	printf("member x of mydata struct = %d\n", p->x);
}
#endif

#if 0
/* Structure Initialization */
struct Employee{
	int id;
	char name[20];
	char surname[20];
	double wage;
};

int main(void){
	struct Employee e = {.name = "hande", .surname = "kubilay",.wage = 3131.31};
	
	printf("id = %d\n",e.id);
	printf("name = %s\n",e.name);
	printf("surname = %s\n",e.surname);
	printf("wage = %f\n",e.wage);
}
#endif

#if 0
/* Arrow Operator */
struct point
{
	int x, y, z;
};
int main(void)
{
	struct point p = {
		.x = 31,
		.y = 69,
		.z = 23};
	struct point *ptr = &p;

	printf("dot operator: point x = %d\n", p.x);
	printf("pointer dereferencing operator: point x = %d\n", (*ptr).x);
	printf("arrow operator: point x = %d\n", ptr->x);
}
#endif

#if 0
/*structures typedef declarations*/
typedef struct data{
	int x,y,z;

}data_t,*dataptr_t;

int main(void){
	data_t data = {1,2,3};
	printf("data.x = %d\n",data.x);
	dataptr_t ptr_data = &data;
	printf("ptr_data->x = %d\n",ptr_data->x);

}
#endif

#if 0
/* Structures and Functions */
typedef struct
{
	int id;
	char name[20];
	char surname[20];
	double wage;
} employee_t;

void print_employee(employee_t e)
{
	printf("id = %d\n", e.id);
	printf("name = %s\n", e.name);
	printf("surname = %s\n", e.surname);
	printf("wage = %f\n", e.wage);
}

int main(void)
{
	employee_t employee_hande = {
		.id = 31,
		.name = "Hande",
		.surname = "Kubilay",
		.wage = 3131.3131,
	};
	print_employee(employee_hande);
}
#endif

#if 0
/* Structures and Functions with call by reference  */
typedef struct
{
	int id;
	char name[20];
	char surname[20];
	double wage;
} employee_t;

void print_employee(const employee_t* e)
{
	printf("id = %d\n", e->id);
	printf("name = %s\n", e->name);
	printf("surname = %s\n", e->surname);
	printf("wage = %f\n", e->wage);
}

int main(void)
{
	printf("sizeof(employee_t) = %zu\n",sizeof(employee_t));
	printf("sizeof(employee_t*) = %zu\n",sizeof(employee_t*));

	employee_t employee_hande = {
		.id = 31,
		.name = "Hande",
		.surname = "Kubilay",
		.wage = 3131.3131,
	};
	print_employee(&employee_hande);
}
/*
out:
sizeof(employee_t) = 56
sizeof(employee_t*) = 4
id = 31
name = Hande
surname = Kubilay
wage = 3131.313100
*/

#endif

#if 0
// #include <time.h>
/* time.h library */
int main(void)
{
	for (;;)
	{
		time_t sec;
		time(&sec);
		printf("%lld\r", sec);
		
	}
}
#endif

#if 0
/* localtime() function */
int main(void){
	time_t sec;
	time(&sec);
	struct tm* tm_test = localtime(&sec);
	printf("date = %d/%d/%d\n",tm_test->tm_year + 1900,tm_test->tm_mon + 1,tm_test->tm_mday);
}
#endif

#if 0
/* gmtime() function */
int main(void){
	const char* const pmons[] = {"Jan","Feb","Mar","April","May","June","July","Agust","September","October","November","December"};
	time_t sec1,sec2;
	time(&sec1);
	time(&sec2);
	struct tm* ptr_lcl_tm = localtime(&sec1);
	struct tm* ptr_gm_tm = gmtime(&sec2);
	printf("%d %s %d\t%02d:%02d:%02d\n",ptr_lcl_tm->tm_mday,pmons[ptr_lcl_tm->tm_mon],ptr_lcl_tm->tm_year + 1900,ptr_lcl_tm->tm_hour,ptr_lcl_tm->tm_min, ptr_lcl_tm->tm_sec);
	printf("%d %s %d\t%02d:%02d:%02d\n",ptr_gm_tm->tm_mday,pmons[ptr_gm_tm->tm_mon],ptr_gm_tm->tm_year + 1900,ptr_gm_tm->tm_hour,ptr_gm_tm->tm_min, ptr_gm_tm->tm_sec);
}
#endif

#if 0
/* ctime() and asctime() */
int main(void){
	time_t sec;
	time(&sec);
	char* p1 = ctime(&sec);
	const struct tm* tm_ptr = localtime(&sec);
	char* p2 = asctime(tm_ptr);
	printf("date with ctime = %s",p1);
	printf("date with asctime = %s",p2);
}
#endif

#if 0
/*locale*/
#include <locale.h>
int main(void)
{
	double dval = 3131.6969;
	printf("dval before the change locale to turkish = %f\n", dval);

	char *p = setlocale(LC_ALL, "turkish");
	if (!p)
	{
		printf("locale degistirilemedi\n");
		exit(0);
	}
	else
	{
		printf("locale degistirildi\n");
	}

	printf("dval after the change locale to turkish = %f\n", dval);
}
#endif

#if 0
/* strftime() function */
int main(void){
	time_t sec;
	time(&sec);
	char buf[100];
	size_t n = strftime(buf,asize(buf),"%d %B / %A / %Y",localtime(&sec));
	printf("n = %zu\n",n);
	printf("%s",buf);
}
#endif

#if 0
#include <locale.h>
int main(void) {
    time_t sec;
    time(&sec);
    char buf1[100]; 
    char buf2[100]; 
    size_t n1 = strftime(buf1, sizeof(buf1), "%d %B / %A / %Y / %H:%M:%S", localtime(&sec));

    printf("n = %zu\n", n1);  
    printf("Tarih: %s\n", buf1);
	/* change locale to turkish */
	setlocale(LC_ALL,"turkish");

	size_t n2 = strftime(buf2, sizeof(buf2), "%d %B / %A / %Y / %H:%M:%S", localtime(&sec));
    printf("n = %zu\n", n2);  
    printf("Tarih: %s\n", buf2);
}
#endif

#if 0
/*clock() function*/
int icmp(const void* p1,const void* p2){
	return *(int*)p1 - *(int*)p2;
}

int main(void){
	int n;
	printf("kac tam sayi:");
	scanf("%d",&n);

	int* p = malloc(n*sizeof(int));
	if(!p){
		printf("bellek yetersiz\n");
	}
	set_array_random(p,n);

	//print_array(p,n);
	clock_t clk_start = clock();
	qsort(p,n,sizeof(int),icmp);
	clock_t clk_end = clock();
	printf("clock of qsort = %f\n",(double)(clk_end-clk_start)/CLOCKS_PER_SEC);
	system("pause");
	print_array(p,n);
	free(p);
}

#endif

#if 0
int main(void){
	FILE* f = fopen("ali.txt","w");
	fprintf(f,"....");
	fclose(f);
}
#endif

#if 0
/* oop type library test code-1 */
#include "date.h"
int main(void){
	Date dt;
	int d = 27;
	int m = 1;
	int y = 2001;

	if(!set_date_by_str(&dt,"10-10-2021")){
		printf("gecersiz tarih");
		return 1;
	}
	print_date(&dt);

	if(!set_date(&dt,d,m,y)){
		printf("gecersiz tarih");
		return 1;
	}
	print_date(&dt);

	if(!set_date(&dt,5,11,2031)){
		printf("gecersiz tarih");
		return 1;
	}
	print_date(&dt);
	
}
#endif

#if 0
#include "date.h"

/* oop type library test code-2 */
void set_date_array(Date* p, size_t size){
	while(size--){
		set_random_date(p++);
	}
}
void print_date_array(Date* p, size_t size){
	while(size--){
		print_date(p++);
	}
}
#define SIZE 100
int main(void){
	Date ar[SIZE];
	randomize();
	set_date_array(ar,SIZE);
}
#endif

#if 0
#include "date.h"

/* oop type library test code-3 */
int maim(void){
	Date dt;
	printf("bir tarih giriniz:");
	scan_date(&dt);
	print_date(&dt);

	printf("%d yiinin %d ayinin %d gunu\n",get_year(&dt),get_month(&dt),get_month_day(&dt));
}
#endif

#if 0
/* memory allocation remind */

int main(void) {
    int start_size = 31;        
    int current_size = start_size;
    char* std_date = malloc(current_size * sizeof(char)); 
    if (std_date == NULL) {
        printf("Bellek ayrilamadi");
        return 1;
    }

    printf("Lutfen gecerli bir tarih giriniz: ");

    int c, index = 0;
    while ((c = getchar()) != '\n' && c != EOF) { 
        if (index >= current_size - 1) { 
            current_size *= 2; 
            char* new_date = realloc(std_date, current_size * sizeof(char));
            if (new_date == NULL) {
                printf("Bellek yeniden ayrilamadi");
                free(std_date);
                return 1;
            }
            std_date = new_date;
        }
        std_date[index++] = c; 
    }
    std_date[index] = '\0'; 

    printf("Tarih = %s\n", std_date);

    free(std_date); 
    return 0;
}

#endif

#if 0
/* oop type library test code-4 */

#include "date.h"
void set_date_array(Date* p, size_t size){
	while(size--){
		set_random_date(p++);
	}
}
void print_date_array(Date* p, size_t size){
	while(size--){
		print_date(p++);
	}
}

int callback_date_cmp(const void* p1,const void* p2){
	return cmp_date((const Date*)p1,(const Date*)p2);
}


int main(void){
	size_t n;
	printf("kac tarih: ");
	scanf("%d",&n);
	Date* dt  = (Date*)malloc(n * sizeof(Date));
	if(!dt){
		printf("bellek yetersiz");
		free(dt);
		return 1;
	}
	set_date_array(dt,n);
	printf("siralama basladi\n");
	clock_t clk_start = clock();
	qsort(dt,n,sizeof(*dt),callback_date_cmp);
	clock_t clk_end = clock();
	printf("siralama bitti\n");
	printf("siralama suresi = %f",(double)(clk_end-clk_start) / CLOCKS_PER_SEC);
	free(dt);
}
#endif

#if 0
#include "date.h"
/* oop type library test code-5 */
int main(void){
	Date birth_date;
	printf("dagum tarihinizi giriniz: ");
	scan_date(&birth_date);
	printf("dogum tarihiniz: ");
	print_date(&birth_date);
	Date today;
	set_date_today(&today);
	printf("bugunun tarihi: ");
	print_date(&today);
	printf("date diff = %d\n",date_diff(&birth_date,&today));
}

#endif

#if 0
#include "date.h"
/* oop type library test code-6 */
int main(void){
	Date today;
	set_date_today(&today);
	printf("bugunun tarihi: ");
	print_date(&today);
	int n;

	printf("kac gun sonrasi: ");
	Date future_date;
	scan_date(&future_date);
	n_days_after(&future_date,&today);
	print_date(&future_date);
}

#endif

#if 0
#include "date.h"
int main(void){
	Date dt;
	/*set_date(&dt,27,01,2001);
	printf("week day = %d\n",get_week_day(&dt));
	print_date(&dt);*/
	printf("lutfen dogum gununuzu giriniz: ");
	scan_date(&dt);
	printf("dogum gununuz: ");
	print_date(&dt);
}
#endif

#if 0
#include "date.h"

int main(void){
	Date dt1;
	Date dt2;
	set_date(&dt1,22,02,2000);
	set_date(&dt2,27,01,2001);
	printf("hande ile yavuz arasindaki gun farki: %d\n",date_diff(&dt1,&dt2));

}
#endif

#if 0
/* test code for n_days_after and before */
#include "date.h"
int main(void){
	Date today;
	printf("bugun: ");
	set_date_today(&today);
	print_date(&today);
	int n;

	printf("\nkac gun sonrasi ve oncesi: ");
	scanf("%d",&n);
	Date future_date;
	n_days_after(&future_date,&today,n);
	printf("\nn gun sonrasi: ");
	print_date(&future_date);

	Date before_date;
	n_days_before(&before_date,&today,n);
	printf("\nn gun oncesi: ");
	print_date(&before_date);
}
#endif

#if 0
/* Composition */
struct Nec
{
	int a,b,c;
};

struct Erg{
	double d1,d2;
	struct Nec nec;
};

int main(int argc, char const *argv[])
{
	printf("sizeof double = %zu\n",sizeof(double));
	printf("sizeof(struct Nec) = %zu\n",sizeof(struct Nec));
	printf("sizeof(struct Erg) = %zu\n",sizeof(struct Erg));

}
#endif

#if 0
/* Composition */
struct Nec
{
	int a,b,c;
};

struct Erg{
	double d1,d2;
	struct Nec nec;
};

int main(int argc, char const *argv[])
{
	//struct Erg erg = {1.2,2.3,{31,69,32}};

	struct Erg erg = { .nec.a = 66};
	printf("%d\n",erg.nec.a);
}

#endif
#if 0
/* Composition */
struct Nec
{
	int a,b,c;
};

struct Erg{
	double d1,d2;
	struct Nec* necptr;
};

int main(int argc, char const *argv[])
{
	struct Erg erg = {};
	struct Erg* erg_ptr = &erg;

	//
	struct Nec nec_str = {1,2,3};
	erg.necptr = &nec_str;
	printf("(erg.necptr->a) = %d\n",erg.necptr->a);
	printf("(erg_ptr->necptr->b) = %d\n",erg_ptr->necptr->b);
}

#endif

#if 0
#include "date.h"
struct Employee{
	int id;
	char name[20];
	char adress[40];
	Date birth_date;	
};

int main(void){
	struct Employee hande;
	Date* hande_ptr = set_date(&(hande.birth_date),22,02,2000);
	print_date(hande_ptr);
}

#endif

#if 0
/*test code for person.h functions*/
int main(void){
	randomize();
	Person rand_person_1;
	Person rand_person_2;
	Person* ptr_1 = set_random_person(&rand_person_1);
	Person* ptr_2 = set_random_person(&rand_person_2);
	print_person(&rand_person_1);
	print_person(&rand_person_2);
	int cmp_result = cmp_person(ptr_1,ptr_2);
	if(cmp_result > 0){
		printf("person 1 is greather than person 2\n");
	}
	else if(cmp_result < 0){
		printf("person 2 is greather than person 1\n");

	}
	else{
		printf("persons are equal\n");
	}
}
#endif

#if 0
/* dynamic test code for person.h*/
void print_person_array(Person *p_arr, size_t size)
{
	while (size--)
	{
		print_person(p_arr++);
	}
}
void set_person_array(Person *p_arr, size_t size)
{
	while (size--)
	{
		set_random_person(p_arr++);
	}
}
int cmp_person_callback(const void *vp1, const void *vp2)
{
	const Person *person_1 = (const Person *)vp1;
	const Person *person_2 = (const Person *)vp2;

	return cmp_person(person_1, person_2);
}

int main(void)
{
	size_t n;
	clock_t clk_start;
	clock_t clk_end;
	printf("kac kisi ");
	scanf("%d", &n);

	Person *p_arr = (Person *)malloc(n * sizeof(Person));
	if (!p_arr)
	{
		printf("bellek yetersiz\n");
	}
	set_person_array(p_arr, n);
	// print_person_array(p_arr,n);
	printf("\nsorting starts now\n");
	clk_start = clock();
	qsort(p_arr, n, sizeof(Person), cmp_person_callback);
	clk_end = clock();
	printf("\nsorting ended.sorting time = %f\n", (double)(clk_end - clk_start) / CLOCKS_PER_SEC);
	printf("sorted array:\n");

	print_person_array(p_arr, n);

	free(p_arr);
}

#endif

#if 0
/* 1-test code for personlist.h  */
#include "personlist.h"
int main(void){
	Person p;
	randomize();
	for(int i = 0; i < 10; ++i){
		set_random_person(&p);
		print_person(&p);
		push_front(&p);
	}

	printf("listede %d kisi var\n",get_size());
	print_list();
	make_empty();
	//...
}
#endif
#if 0
/* 2-test code for personlist.h  */
#include "personlist.h"
int main(void){
	Person p;
	randomize();
	for(int i = 0; i < 500000; ++i){
		set_random_person(&p);
		push_front(&p);
	}

	printf("listede %d kisi var\n",get_size());
	(void)getchar();
	print_list();
	make_empty();
	//...
}
#endif
#if 0
/* 3-test code for personlist.h  */
#include "personlist.h"
int main(void){
	Person p;
	randomize();
	for(int i = 0; i < 10; ++i){
		set_random_person(&p);
		push_front(&p);
	}
	while(!is_empty()){
		printf("listede %d kisi var\n",get_size());
		print_list();
		pop_front(&p);
	}

}
#endif

#if 0
#include "personlist.h"
/*test code for handle system*/
int main(void){
	randomize();
	Person p;

	ListHandle h1 = create_list();
	for(int i = 0; i < 10; ++i){
		set_random_person(&p);
		push_front(h1,&p);
	}
	ListHandle h2 = create_list();
	for(int i = 0; i < 20; ++i){
		set_random_person(&p);
		push_front(h2,&p);
	}
	ListHandle h3 = create_list();
	for(int i = 0; i < 8; ++i){
		set_random_person(&p);
		push_front(h3,&p);
	}
	print_list(h1);
	print_list(h2);
	print_list(h3);
}
#endif

#if 0
/* alignment */
int main(void){
	int x = 5;
	int y = 10;
	double d1 = 3.4;

	double d2 = 2.2;

	printf("%d\n",(unsigned)&x % 4 == 0);
	printf("%d\n",(unsigned)&y % 4 == 0);
	printf("%d\n",(unsigned)&d1 % 8 == 0);
	printf("%d\n",(unsigned)&d2 % 8 == 0);
}

#endif
#if 0
/* alignment requirement pack(1) pragma*/
#include "stdalign.h"
#pragma pack(1)
typedef struct {
	char c1;
	int i;
	char c2;
	long long lval;
	char c3;
}data;

int main(void){
	printf("sizeof(data) = %zu\n",sizeof(data));
}

#endif
#if 0
/* alignment requirement */
#include "stdalign.h"
typedef struct {
	char c1;
	int i1;
	char c2;
}data;

int main(void){
	printf("sizeof(data) = %zu\n",sizeof(data));
}

#endif

#if 0
/*offsetof macro usage*/
#include <stddef.h>
#include <stdalign.h>

typedef struct {
	char c1; // offset = 0
	int i;	 // offset = 4
	char c2; // offset = 8
}data;

int main(void){
	data mydata = {
		.c1 = 55,
		.i = 32425,
		.c2 = 78
	};
	printf("offset for c1 = %zu\n",offsetof(data,c1));
	printf("offset for c2 = %zu\n",offsetof(data,c2));
	printf("offset for i = %zu\n",offsetof(data,i));


}
#endif

#if 0
/*offsetof macro implementation*/

#define Offsetof(s, m) ((size_t)&(((s *)0)->m))

#include <stddef.h>
#include <stdalign.h>

typedef struct {
	char c1; // offset = 0
	int i;	 // offset = 4
	char c2; // offset = 8
}data;

int main(void){
	data mydata = {
		.c1 = 55,
		.i = 32425,
		.c2 = 78
	};
	printf("offset for c1 = %zu\n",Offsetof(data,c1));
	printf("offset for c2 = %zu\n",Offsetof(data,c2));
	printf("offset for i = %zu\n",Offsetof(data,i));

}
#endif

#if 0
#include <stddef.h>
#include <stdalign.h>

typedef struct {
	char c1; // offset = 0
	int i;	 // offset = 4
	char c2; // offset = 8
}data;

int main(void){
	data mydata = {
		.c1 = 55,
		.i = 32425,
		.c2 = 78
	};
	char* pchar = &mydata.c1;
	int* iptr = (int*)(pchar + offsetof(data,i));
	printf("mydata.i = %d\n",*iptr);

}

#endif

#if 0
/* UNIONS */
typedef struct
{
	uint16_t high_bytes;
	uint16_t low_bytes;

}Word;

typedef union
{
	uint32_t uval;
	Word w;
	uint8_t per_bytes[4];
}Myint;


int main(void)
{
	Myint m;
	printf("sizeof(Myint) = %zu\n",sizeof(Myint));
	printf("sizeof(Word) = %zu\n",sizeof(Word));
	printf("sizeof(m.per_bytes) = %zu\n",sizeof(m.per_bytes));
}

#endif

#if 0
/* tagged union*/
#define NAME 0
#define DOUBLE 1
#define DATE 2
#define NUMBER 3

#include "date.h"
typedef struct
{
	union
	{
		char name[20];
		double dval;
		Date dt;
		int ival;
	};
	int type;
} NecType;

void set_nec(NecType *p)
{
	switch (rand() % 4)
	{
	case NAME:
		p->type = NAME;
		strcpy(p->name, get_random_name());
		break;
	case DOUBLE:
		p->type = DOUBLE;
		p->dval = rand() % 31;
		break;
	case DATE:
		p->type = DATE;
		set_random_date(&p->dt);
		break;
	case NUMBER:
		p->type = NUMBER;
		p->ival = rand() % 31;
		break;
	default:
		break;
	}
}

void print_necc(const NecType *p)
{
	switch (p->type)
	{
	case NAME:
		printf("%s\n", p->name);
		break;
	case DOUBLE:
		printf("%f\n", p->dval);
		break;
	case DATE:
		print_date(&p->dt);
		break;
	case NUMBER:
		printf("%d\n", p->ival);
		break;
	default:
		break;
	}
}

int main(void)
{
	NecType n;
	for (int i = 0; i < 31; ++i)
	{
		set_nec(&n);
		print_necc(&n);
		putchar('\n');
	}
}

#endif

#if 0
typedef enum { /* color -> enum tag -> zorunlu degil */
	WHITE, /* enum constants */
	YELLOW,
	GRAY,
	GREEN,
	BLACK
}color;

int main(void){
	color c = YELLOW;
	printf("yellow enum constant value is %d\n",c);
	printf("yellow enum constant value is %d\n",YELLOW);
}
#endif

#if 0
/*bprint function test (implementation detail is later)*/
int main(void)
{
	uint16_t reg = 31;

	bprint(reg);
}

#endif

#if 0

int main(void){
	int x = 23;
	bprint(x);
	bprint(~x);
	printf("printf(x) = %d\n",x);
	printf("printf(~x) = %d\n",~x);

}

#endif

#if 0
/*bitwise left shift*/
int main(void){
	unsigned int x = 23;
	while(x){
		bprint(x);
		x <<=1;
	}
	printf("%u\n",x);
}

#endif
#if 0
/*bitwise left shift*/
int main(void){
	unsigned int x = 23;
	while(x){
		bprint(x);
		x <<=1;
	}
	printf("%u\n",x);
}

#endif
#if 0
/*bitwise left shift*/
int main(void){
	int x = -1;
	bprint(x >> 5);
}

#endif
#if 0
/* bitwise and */
int main(void){
	int x,y;
	printf("birinci sayiyi giriniz: ");
	scanf("%d",&x);
	printf("ikinci sayiyi giriniz: ");
	scanf("%d",&y);
	bprint(x);
	bprint(y);
	bprint(x & y);
}

#endif

#if 0
/* 2'nin kuvveti oldugunu bulmak */
int main(void)
{
	int x;

	printf("bir tam sayi giriniz: ");
	scanf("%d", &x);

	if (x && !(x & (x - 1)))
	{
		printf("girdiginiz sayi 2'nin kuvvetidir.");
	}
	else
	{
		printf("girdiginiz sayi 2'nin kuvveti degildir.");
	}
}

#endif

#if 0
/*Kernigham Algorithm*/

int set_bit_count(int x)
{
	int count = 0;
	while (x)
	{
		x &= x - 1;
		++count;
	}
	return count;
}

int main(void)
{
	int x;

	printf("bir tam sayi giriniz: ");
	scanf("%d", &x);

	printf("%d sayisinin %d adet set biti vardir\n", x, set_bit_count(x));
}
#endif

#if 0
/*bitwise or*/
int main(void){
	int x,y;
	printf("iki tam sayi giriniz");
	scanf("%d%d",&x,&y);
	bprint(x);
	bprint(y);
	bprint(x | y);
}
#endif

#if 0
/*bitwise xor*/
int main(void){
	int x,y;
	printf("iki tam sayi giriniz");
	scanf("%d%d",&x,&y);
	bprint(x);
	bprint(y);
	bprint(x ^ y);
}
#endif

#if 0
/*xor swap*/
#define xor_swap(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y)) /*macro definition*/

int main(void){
	int x,y;
	printf("iki tam sayi giriniz");
	scanf("%d%d",&x,&y);
	printf("x = %d y = %d\n",x,y);/* x = 0000 1011 y = 0010 0001 */ 
	// x ^= y; /* x = 0010 1010*/
	// y ^= x; /* y = 0000 1011*/
	// x ^= y; /*x = 0010 0001*/
	xor_swap(x,y);
	printf("x = %d y = %d\n",x,y);
}
#endif

#if 0
/*set nth bit*/
#define SET_NTH_BIT(x, n) ((x) |= (1 << n))

void to_set_nth_bit(int *x, int n)
{
	*x |= (1 << n);
}

int main(void)
{
	int x, n;
	printf("bir tam sayi giriniz");
	scanf("%d", &x);
	printf("x = %d\n", x);
	bprint(x);
	printf("kacinci biti 1 olsun: ");
	scanf("%d", &n);
	//to_set_nth_bit(&x, n);
	SET_NTH_BIT(x, n);
	printf("new x = %d\n", x);
	bprint(x);
}

#endif

#if 0
/*reset nth bit*/
#define RESET_NTH_BIT(x, n) ((x) &= ~(1 << n))

void to_reset_nth_bit(int *x, int n)

{

	*x &= ~(1 << n);
}

int main(void)

{

	int x, n;

	printf("bir tam sayi giriniz");

	scanf("%d", &x);

	printf("x = %d\n", x);

	bprint(x);

	printf("kacinci biti 0 olsun: ");

	scanf("%d", &n);

	// to_reset_nth_bit(&x, n);

	RESET_NTH_BIT(x, n);

	printf("new x = %d\n", x);

	bprint(x);
}
#endif

#if 0
/*toggle nth bit*/
#define TOGGLE_NTH_BIT(x, n) ((x) ^= (1 << n))

void to_toggle_nth_bit(int *x, int n)

{

	*x ^= (1 << n);
}

int main(void)

{

	int x, n;

	printf("bir tam sayi giriniz: ");

	scanf("%d", &x);

	printf("x = %d\n", x);

	bprint(x);

	printf("kacinci biti degistirilsin olsun: ");

	scanf("%d", &n);

	// to_toggle_nth_bit(&x, n);

	TOGGLE_NTH_BIT(x, n);

	printf("new x = %d\n", x);

	bprint(x);
}
#endif

#if 0
/*get nth bit*/
#define GET_NTH_BIT(x, n) (!((x) & (1 << (n))) ? 0 : 1)
int to_get_nth_bit(const int *x, int n)

{
	return !(*x & (1 << n)) ? 0 : 1;
}

int main(void)

{
	int x, n;

	printf("bir tam sayi giriniz: ");

	scanf("%d", &x);

	printf("x = %d\n", x);

	bprint(x);

	printf("kacinci biti alinsin: ");

	scanf("%d", &n);

	//printf("%dth bit value = %d\n", n, to_get_nth_bit(&x, n));
	printf("%dth bit value = %d\n", n, GET_NTH_BIT(x, n));
}
#endif

#if 0
/*alternative bprint function implementation*/
void bprint_alt(uint32_t val){
	for(int i = sizeof(uint32_t) * CHAR_BIT - 1; i >= 0; --i){
		putchar((val >> i) & 1 ? '1' : '0');
	}
}

int main(void){
	int x;
	printf("bir sayi giriniz: ");

	scanf("%d",&x);

	bprint_alt(x);

}

#endif

#if 0
/*results for nec_type library's look-up tablelookup table*/
#include "nec_type.h"
int main(void){
	for(int i = 0; i < 128; ++i){
		if(i && i % 8 == 0){putchar('\n');}
		int flag = 0;	
		if(isupper(i)){flag |= UPPER;}
		if(islower(i)){flag |= LOWER;}
		if(isdigit(i)){flag |= DIGIT;}
		if(isxdigit(i)){flag|= HEX;}
		if(ispunct(i)){flag |= PUNCT;}
		if(isspace(i)){flag |= SPACE;}
		if(isprint(i)){flag |= PRINT;}
		if(iscntrl(i)){flag |= CNTRL;}
		printf("%3d,",flag);	
	}
}
#endif

#if 0
/*test code for implemented ctype lib*/
#include "nec_type.h"

int main(void){

	printf("bir karakter giriniz: ");
	int ch = getchar();

	if(ISUPPER(ch)){
		printf("girdiginiz karakter buyuk harf\n");
	}
	else{
		printf("buyuk harf degil\n");
	}


}
#endif

#if 0
/*bit-fields*/

typedef struct{
	unsigned int mday: 5;
	unsigned int mon: 4;
	unsigned int year: 7;
	unsigned int hour: 5;
	unsigned int min: 6;
	unsigned int sec: 5;
}DateTime;

void print_date_(const DateTime dt){
	printf("mday = %u mon = %u year = %u hour = %u min = %u sec = %u\n",dt.mday,dt.mon,dt.year+1980,dt.hour,dt.min,dt.sec*2);
}

int main(void){
	DateTime dt = {2,2,2025-1980,23,8,20};
	print_date_(dt);
}
#endif

#if 0
typedef union {
    struct {
      unsigned int mb_bit0   : 1;
      unsigned int mb_bit1   : 1;
      unsigned int mb_bit2   : 1;
      unsigned int mb_bit3   : 1;
      unsigned int mb_bit4   : 1;
      unsigned int mb_bit5   : 1;
      unsigned int mb_bit6   : 1;
      unsigned int mb_bit7   : 1;
      unsigned int mb_bit8   : 1;
      unsigned int mb_bit9   : 1;
      unsigned int mb_bit10  : 1;
      unsigned int mb_bit11  : 1;
      unsigned int mb_bit12  : 1;
      unsigned int mb_bit13  : 1;
      unsigned int mb_bit14  : 1;
      unsigned int mb_bit15  : 1;
      unsigned int mb_bit16  : 1;
      unsigned int mb_bit17  : 1;
      unsigned int mb_bit18  : 1;
      unsigned int mb_bit19  : 1;
      unsigned int mb_bit20  : 1;
      unsigned int mb_bit21  : 1;
      unsigned int mb_bit22  : 1;
      unsigned int mb_bit23  : 1;
      unsigned int mb_bit24  : 1;
      unsigned int mb_bit25  : 1;
      unsigned int mb_bit26  : 1;
      unsigned int mb_bit27  : 1;
      unsigned int mb_bit28  : 1;
      unsigned int mb_bit29  : 1;
      unsigned int mb_bit30  : 1;
      unsigned int mb_bit31  : 1;
    };
    uint32_t m_value;
  } Bits_t;

  int main(void)
  {
    Bits_t b1 = { .m_value = 0 };

    // ------------------------------------------------------

    b1.mb_bit4 = 1;
    printf("%u\n", b1.m_value); // output -> 16

    // ------------------------------------------------------

    b1.m_value = 15;
    printf("%u\n", b1.mb_bit0); // output -> 1
    printf("%u\n", b1.mb_bit1); // output -> 1
    printf("%u\n", b1.mb_bit2); // output -> 1
    printf("%u\n", b1.mb_bit3); // output -> 1
    printf("%u\n", b1.mb_bit4); // output -> 0

    // ------------------------------------------------------
  }
#endif

#if 0
/*command line arguments*/
int main(int argc, char const *argv[])
{
	printf("agrc = %d\n",argc);
	for (size_t i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s\n",i,argv[i]);
	}
	
}
#endif

#if 0
/*filecopy with command line arg*/

int main(int argc, char const *argv[])
{
	if (argc != 3){
		printf("usage: <filecopy> <source_file_name> <dest file name>\n");
		exit(EXIT_FAILURE);
	}

	printf("file %s copied as file %s\n",argv[1],argv[2]);
}

/*
out:
C:\Users\yhane\Necati-Ergin-C-Programming-Notes\libs\Src>main ali.txt veli.txt
file ali.txt copied as file veli.txt
*/
#endif

#if 0
/*command line arg. calculator example*/
int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		printf("kullanim: <hes> <sol operand> <isaret> <sag operand>\n");
		exit(EXIT_FAILURE);
	}
	int left_operand = atoi(argv[1]);
	int right_operand = atoi(argv[3]);
	switch (*(argv[2]))
	{
	case '+':
		printf("%d + %d = %d", left_operand, right_operand, left_operand + right_operand);
		break;
	case '-':
		printf("%d - %d = %d", left_operand, right_operand, left_operand - right_operand);
		break;
	case '/':
		if (!right_operand)
		{
			printf("paydada sifir olamaz.\n");
			exit(EXIT_FAILURE);
		}
		printf("%d / %d = %f", left_operand, right_operand, (double)left_operand / right_operand);
		break;
	case '*':
		printf("%d * %d = %d", left_operand, right_operand, left_operand * right_operand);
		break;
	default:
		printf("lutfen dogru sekilde kullaniniz");
		exit(EXIT_FAILURE);
		break;
	}
}

#endif

#if 0
  // weekday program 
  int main(int argc, char** argv)
  {
    if (argc != 4)
    {
      printf("Usage: %s <day> <month> <year>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    int day = atoi(argv[1]);
    int month = atoi(argv[2]);
    int year = atoi(argv[3]);

    Date d1;
    set_date(&d1, day, month, year);
    print_date(&d1);
  }

  // command line -> prog.exe 1 1 2001 12
  // output -> Usage: prog.exe <day> <month> <year>

  // command line -> prog.exe 1 1 2001
  // output -> 01 Ocak 2001 Pazartesi

  // command line -> prog.exe 30 11 2024
  // output -> 30 Kasım 2024 Cumartesi

#endif

#if 0
#define FILE_NAME_SIZE 100

  int main(int argc, char** argv) 
  {
    char source_file_name[FILE_NAME_SIZE];
    char destination_file_name[FILE_NAME_SIZE];

    if (argc != 3) {
      printf("Usage: %s <source> <destination>\n", argv[0]);
      printf("Enter source file name: ");
      scanf("%s", source_file_name);

      printf("Enter destination file name: ");
      scanf("%s", destination_file_name);
    }
    else {
      strcpy(source_file_name, argv[1]);
      strcpy(destination_file_name, argv[2]);
    }

    printf("file %s copied to %s\n",  source_file_name, 
                                      destination_file_name);
  }

  // command line -> prog.exe a.txt
  // output -> Usage: prog.exe <source> <destination>
  // input  -> Enter source file name: a.txt
  // input  -> Enter destination file name: b.txt
  // output -> file a.txt copied to b.txt

  // command line -> prog.exe a.txt b.txt
  // output -> file a.txt copied to b.txt

#endif

#if 0
/* FILE OPERATIONS */
int main(int argc, char const *argv[])
{
	
	FILE* f = fopen("yavuz.txt","w");
	if(!f){
		printf("dosya olusturulamadi\n");
		abort();
	}
	printf("dosya olusturuldu.");
	fclose(f);
}

#endif

#if 0
/* FILE OPERATIONS */
int main(int argc, char const *argv[])
{
	
	FILE* f = fopen("yavuz.txt","r");
	if(!f){
		printf("dosya acilamadi\n");
		abort();
	}
	printf("dosya acildi.");
	fclose(f);
}

#endif
#if 0
/* FILE OPERATIONS */
int main(int argc, char const *argv[])
{
	
	FILE* f = fopen("C:\\Users\\yhane\\Necati-Ergin-C-Programming-Notes\\libs\\Src\\yavuz.txt","w");
	if(!f){
		printf("dosya olusturulamadi\n");
		abort();
	}
	printf("dosya olusturuldu.");
	fclose(f);
}
#endif

#if 0
/*fgetc function */
int main(int argc, char const *argv[])
{
	FILE* f = fopen("C:\\Users\\yhane\\Necati-Ergin-C-Programming-Notes\\libs\\Inc\\date.h","r");
	if(!f){
		printf("dosya acilamadi\n");
		exit(EXIT_FAILURE);
	}
	int ch;
	while((ch = fgetc(f)) != EOF){
		putchar(ch);
	}
	fclose(f);
}

#endif
#if 0
/*fgetc function */
/*komut satirindan calistirilan dosyaz isimli programi yazdiriniz*/
int main(int argc, char const *argv[])
{
	if(argc != 2){
		printf("kullanim: <dosyaz> <dosya ismi>\n");
		exit(EXIT_FAILURE);
	}

	FILE* f = fopen(argv[1],"r");
	if(!f){
		printf("dosya acilamadi\n");
		exit(EXIT_FAILURE);
	}
	int ch;
	while((ch = fgetc(f)) != EOF){
		putchar(ch);
	}
	fclose(f);
}

#endif

#if 0
/*interview question*/
typedef struct
{
	int ch;
	int cnt;
} data_t;

int cmpdata(const void *p1, const void *p2)
{

	return ((const data_t *)p2)->cnt - ((const data_t *)p1)->cnt;
}

/*dosyadaki her karakterden kac tane oldugunu bulma kodu*/
int main(int argc, char const *argv[])
{
	if (argc != 3)
	{
		printf("karsay kullanim: <%c> <karsay> <dosya ismi>\n");
		exit(EXIT_FAILURE);
	}

	FILE *f = fopen(argv[2], "r");
	if (!f)
	{
		printf("dosya acilamadi\n");
		exit(EXIT_FAILURE);
	}

	int ch;
	data_t chr_cnt[26] = {
		{'A', 0}, {'B', 0}, {'C', 0}, {'D', 0}, {'E', 0}, {'F', 0}, {'G', 0}, {'H', 0}, {'I', 0}, {'J', 0}, {'K', 0}, {'L', 0}, {'M', 0}, {'N', 0}, {'O', 0}, {'P', 0}, {'Q', 0}, {'R', 0}, {'S', 0}, {'T', 0}, {'U', 0}, {'V', 0}, {'W', 0}, {'X', 0}, {'Y', 0}, {'Z', 0}};

	while ((ch = fgetc(f)) != EOF)
	{
		if (isalpha(ch))
		{
			++(chr_cnt[toupper(ch) - 'A'].cnt);
		}
	}
	fclose(f);
	qsort(chr_cnt, 26, sizeof(data_t), cmpdata);
	for (size_t i = 0; i < 26; ++i)
	{
		if (chr_cnt[i].cnt)
		{
			printf("%c %d\n", chr_cnt[i].ch, chr_cnt[i].cnt);
		}
	}
}

#endif

#if 0
/*fputc() function*/
int main(int argc, char const *argv[])
{
	FILE* f = fopen("yavuz.txt","w");
	if(!f){
		printf("dosya olusturulamadi\n");
		exit(EXIT_FAILURE);
	}

	for (size_t i = 'A'; i < 'Z'; i++)
	{
		fputc(i,f);
	}
	fputc('\n',f);
	for (size_t i = 'a'; i < 'z'; i++)
	{
		fputc(i,f);
	}
	fclose(f);
}

#endif

#if 0
/*grfile*/
/*main grfile yavuz.txt 10000 40 70 */

int get_rand_char(void){
	int ch;
	while(!isalnum(ch = rand() % 128))
		; //null statement

	return ch;
}

int main(int argc, char const *argv[])
{
	if(argc != 6 ){
		printf("grfile kullanim: <.exe name> <file name> <total char count> <min char count in line> <max char count in line>");
	}
	randomize();
	FILE* f = fopen(argv[2],"w");

	for (size_t i = 0; i < atoi(argv[3]); i++)
	{
		int linelen = rand() % (atoi(argv[5])-atoi(argv[4]) + 1) + atoi(argv[4]);
		while (linelen--)
		{
			fputc(get_rand_char(),f);
		}	
		fputc('\n',f);
	}
	fclose(f);
	
}

#endif

#if 0
/*file copy with command line arguments*/
/*usage: <.exe name> <filecopy> <source_file_name> <dest file name>*/
int main(int argc, char const *argv[])
{
	if (argc != 4){
		printf("usage: <%s> <filecopy> <source_file_name> <dest file name>\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE* fsource = fopen(argv[2],"r");
	FILE* fdest = fopen(argv[3],"w");
	if(!fdest || !fsource){
		printf("fopen() fail!\n");
		exit(EXIT_FAILURE);
	}

	int ch;
	while ((ch = fgetc(fsource)) != EOF )
	{
		fputc(ch,fdest);
	}

	fclose(fdest);
	fclose(fsource);
	printf("source file %s copied as dest file %s\n",argv[2],argv[3]);
}
#endif

#if 0
/*Dosbol*/
/*<dosbol> <ali.exe> 1000*/
// ali.exe 11760
// parca001.par 	1000
// parca002.par 	1000
// parca0011.par 	1000
// parca0012.par 	760

#define MAX_FILENAME_LEN 79

int main(int argc, char const *argv[])
{
	printf("program calistiirliyor...\n");
	if (argc != 3){
		printf("usage: <dosbol> <dosya ismi> <parca boyutu(byte)>\n");
		exit(EXIT_FAILURE);
	}	
	FILE* fs = fopen(argv[1],"rb");
	if(!fs){
		perror("fopen fail!");
		exit(EXIT_FAILURE);
	}
	int chunk_size = atoi(argv[2]);
	int file_count = 0;
	char dest_file_name[MAX_FILENAME_LEN + 1];
	int ch;
	int byte_count = 0;
	FILE* fd = NULL; /*flag */


	while((ch = fgetc(fs)) != EOF){
		if(!fd){
			sprintf(dest_file_name,"parca%03d.par",file_count+1);
			fd = fopen(dest_file_name,"wb");
			if(!fd){
				printf("can not create file\n");
				fclose(fs);
				exit(EXIT_FAILURE);
			}
			++file_count;
		}
		fputc(ch,fd);
		++byte_count;
		if(byte_count % chunk_size == 0){
			fclose(fd);
			fd = NULL;
		}
	}
	fclose(fs);
	if(fd){
		fclose(fd);
	}
	printf("%d byte'lik %s dosyasi %d byte'lik %d parcaya bolundu\n",byte_count,argv[2],chunk_size,file_count);

}
#endif

#if 0
/*dosbir ali.exe*/
// remove function
// rename function
int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("usage: <dosbir> <dosya ismi>\n");
		exit(EXIT_FAILURE);
	}
	FILE *fd = fopen(argv[1], "wb");
	if (!fd)
	{
		perror("fopen fail!");
		exit(EXIT_FAILURE);
	}
	char filename[100];
	int file_count = 0;
	int byte_count = 0;

	while (1)
	{
		sprintf(filename, "parca%03d.par", file_count + 1);
		FILE *fs = fopen(filename, "rb");
		if (!fs)
		{
			break;
		}
		++file_count;
		int ch;
		while ((ch = fgetc(fs)) != EOF)
		{
			fputc(ch, fd);
			++byte_count;
		}
		fclose(fs);
	}
	fclose(fd);
	printf("%d dosya %d byte'lik %s dosyasi olarak birlestirildi\n", file_count, byte_count, argv[1]);

	for (size_t i = 1; i <= file_count; i++)
	{
		sprintf(filename, "parca%03d.par", i);
		if (remove(filename))
		{
			printf("%s dosyasi silinemedi\n", filename);
			exit(EXIT_FAILURE);
		}
	}
}
#endif

#if 0
int main(int argc, char** argv)
  {
    if (argc != 3){
      printf("usage: %s <source_file> <seed>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    FILE* f_src = fopen(argv[1], "rb");
    if (f_src == NULL){
      printf("%s could not be opened.\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    char dest_filename[L_tmpnam];
    tmpnam(dest_filename);

    FILE* f_dst = fopen(dest_filename, "wb");  
    if (f_dst == NULL){
      printf("%s temp file could not be created.\n", dest_filename);
      fclose(f_src);
      exit(EXIT_FAILURE);
    }

    long long seed = atoll(argv[2]);
    srand((unsigned)seed);

    int ch;
    while ((ch = fgetc(f_src)) != EOF)
      fputc(ch ^ rand(), f_dst);

    fclose(f_src);
    fclose(f_dst);

    if (remove(argv[1])){
      printf("%s could not be deleted.\n", argv[1]);
      exit(EXIT_FAILURE);
    }

    if (rename(dest_filename, argv[1])){
      printf("%s file could not be renamed\n", dest_filename);
      exit(EXIT_FAILURE);
    }
  }

#endif

#if 0
/*fscanf and fprintf functions*/
int main(int argc, char const *argv[])
{
	FILE* f = fopen("out.txt","w");
	if(!f){
		printf("dosya olusturulamadi\n");
	}

	for (size_t i = 0; i < 10; i++)
	{
		fprintf(f,"%d\n",i);
	}
	fclose(f);
}

#endif
#if 0
/*fscanf and fprintf functions*/
int main(int argc, char const *argv[])
{
	FILE* f = fopen("kayitlar.txt","w");
	if(!f){
		printf("dosya olusturulamadi\n");
	}

	for (size_t i = 0; i < 1000; i++)
	{
		fprintf(f,"%-5d  %-16s %d\n",rand(),get_random_name(), rand() % 101);
	}
	fclose(f);
}

#endif

#if 0
/*fscanf and fprintf functions*/
int main(int argc, char const *argv[])
{
	FILE* f = fopen("asal1.txt","w");
	if(!f){
		printf("dosya olusturulamadi\n");
	}
	int prime_count = 0;
	for (size_t i = 2; i < 10000; i++)
	{
		if(isprime(i)){
			if(i && i % 10 == 0){
				
				fprintf(f,"\n");
			}
			fprintf(f,"%12d ",i);
			++prime_count;
		}

	}
	fclose(f);
}

#endif

#if 0
/*fscanf*/
int main(int argc, char const *argv[])
{
	FILE* f = fopen("yavuz.txt","r");
	if(!f){
		printf("dosya acilamadi\n");
		exit(EXIT_FAILURE);
	}
	char str[900];
	while ((fscanf(f,"%s",str)) != EOF)
	{
		printf("%s",str);
		(void)getchar();
	}
	
	fclose(f);
}

#endif
#if 0
/*fscanf*/
int main(int argc, char const *argv[])
{
	FILE* f = fopen("kayitlar.txt","r");
	if(!f){
		printf("dosya acilamadi\n");
		exit(EXIT_FAILURE);
	}
	int num;
	char name[40];
	int grade;
	while ((fscanf(f,"%d %s %d",&num,name,&grade)) != EOF)
	{
		printf("%d %s %d\n",num,name,grade);
	}
	fclose(f);
}
#endif
#if 0
/*fscanf*/
/*interview question*/
int main(int argc, char const *argv[])
{
	char file_name[40];
	int num;
	char name[40];
	int grade = 0;

	FILE* fa[101];
	for (size_t i = 0; i <= 100; i++)
	{	
		sprintf(file_name,"grade%d.txt",i);

		fa[i] = fopen(file_name,"w");
		if(!fa[i]){
			printf("dosya acilamadi\n");
			exit(EXIT_FAILURE);
		}
	}
	FILE* fs = fopen("kayitlar.txt","r");
	if(!fs){
		printf("dosya acilamadi\n");
		exit(EXIT_FAILURE);
	}

	while ((fscanf(fs,"%d%s%d",&num,name,&grade)) != EOF)
	{
		fprintf(fa[grade],"%-5d %-12s %d\n",num,name,grade);
		printf("%-5d %-12s %d\n",num,name,grade);
		fflush(fa[grade]);

	}
	fclose(fs);
	for (size_t i = 0; i <= 100; i++)
	{
		fclose(fa[i]);
	}


}
#endif

#if 0
/*fgets function*/
int main(int argc, char const *argv[])
{
	char buf[100];
	FILE* f = fopen("kayitlar.txt","r");
	if(!f){
		printf("dosya acilamadi\n");
		exit(EXIT_FAILURE);
	}
	while(fgets(buf,asize(buf),f)){
		printf("%s",buf); /*no newline, the file is already exists*/
	}
}

#endif

#if 0
/*fputs function*/
int main(int argc, char const *argv[])
{
	FILE* f = fopen("kayitlar.txt","w");
	if(!f){
		printf("dosya olusturulamadi\n");
		exit(EXIT_FAILURE);
	}
	char str[100];
	for(int i = 0; i < 5; ++i){
		printf("giris yapiniz: ");
		sgets(str);
		fputs(str,f);
		fputs("\n",f);
	}
	fclose(f);
}
#endif

#if 0
int main(int argc, char const *argv[])
{
	FILE* f = fopen("sayilar.dat","wb");
	if(!f){
		printf("dosya olusturulamadi\n");
		exit(EXIT_FAILURE);
	}

	int x = 12321;
	fwrite(&x,sizeof(x),1,f);

}

#endif

#if 0
#define SIZE 100
int main(int argc, char const *argv[])
{
	int n;
	printf("ilk kac asal sayi: ");
	scanf("%d",&n);
	char filename[SIZE];
	sprintf(filename,"f_asal%d.txt",n);
	FILE* f = fopen(filename,"wb");
	if(!f){
		exit(EXIT_FAILURE);
	}
	int x = 2;
	int prime_count = 0;

	while(prime_count <= n){
		if(isprime(x)){
			fwrite(&x,sizeof(x),1,f);
			++prime_count;
		}
		++x;
	}

	fclose(f);
}

#endif

#if 0
/*fread() function*/
#define SIZE 15
int main(int argc, char const *argv[])
{
	FILE* f = fopen("f_asal100.txt","rb");
	if(!f){
		printf("dosya acilamadi\n");
		exit(EXIT_FAILURE);
	}
	int n;
	int ar[SIZE];
	while((n = fread(&ar,sizeof(int),SIZE,f)) != 0){
		print_array(ar,n);
	}
	fclose(f);

}
#endif

#if 0
#define BUF_SIZE 10
int main(int argc, char const *argv[])
{
	if (argc != 4){
		printf("usage: <%s> <filecopy> <source_file_name> <dest file name>\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE* fsource = fopen(argv[2],"rb");
	FILE* fdest = fopen(argv[3],"wb");
	if(!fdest || !fsource){
		printf("fopen() fail!\n");
		exit(EXIT_FAILURE);
	}

	int n;
	char buf[BUF_SIZE];
	while ((n = fread(buf,1,BUF_SIZE,fsource)) != 0 )
	{
		fwrite(buf,sizeof(char),n,fdest);
	}

	fclose(fdest);
	fclose(fsource);
	printf("source file %s copied as dest file %s\n",argv[2],argv[3]);
}
#endif

#if 0
int main(int argc, char const *argv[])
{
	FILE* f = fopen("f_asal100.txt","rb");
	int n = 0;
	int x;
	if(!f){
		printf("dosya acilamadi\n");
		exit(EXIT_FAILURE);
	}
	printf("kacinci asal sayi: ");
	scanf("%d",&n);
	fseek(f,(n-1)*sizeof(int),SEEK_SET);
	fread(&x,(long)sizeof(x),1,f);
	printf("%d. asal sayi = %d\n",n,x);
	
	fclose(f);
}

#endif

#if 0
/*fsetpos function*/
int main(int argc, char const *argv[])
{
	FILE* f = fopen("f_asal100.txt","rb");
	int n = 0;
	int x;
	if(!f){
		printf("dosya acilamadi\n");
		exit(EXIT_FAILURE);
	}
	printf("kacinci asal sayi: ");
	scanf("%d",&n);
	const fpos_t pos = (fpos_t)(n * sizeof(int));
	fsetpos(f,&pos);
	fread(&x,(long)sizeof(x),1,f);
	printf("%d. asal sayi = %d\n",n,x);
	
	fclose(f);
}
#endif

#if 0
/*feof function*/
const char* name = "yavuz";
int main (void)
{
    FILE *fp;
//    int id;
    /* Dosyayı oluşturarak okuma ve azma için açma */
    if ((fp = fopen ("dosya.txt", "w+")) == NULL) {
         printf("Dosya açma hatası!");
         exit(1);
    }

    //for (id=0; id<10; id++) fputc('E', fp);

	fprintf(fp,name);
    rewind(fp);

    printf("Dosya icerigi: ");
    while (!feof(fp)) {
       printf("%c", fgetc(fp));
    }

    fclose(fp);

    return 0;
}
#endif

#if 0
int main (void)
{
    FILE *fp;
    if ((fp = fopen ("dosya.txt", "w+")) == NULL) {
         printf("Dosya açma hatası!");
         exit(1);
    }

	printf("eof flag is %s\n",(feof(fp) ? "set":"unset"));
	fseek(fp,0L,SEEK_END);
	printf("eof flag is %s\n",(feof(fp) ? "set":"unset"));
	int c = fgetc(fp);
	printf("eof flag is %s\n",(feof(fp) ? "set":"unset"));
    fclose(fp);
}
#endif

#if 0
int main (void)
{
    FILE *fp;

    if ((fp = fopen ("dosya.txt", "r")) == NULL) {
         printf("Dosya açma hatasi!");
         exit(1);
    }

    fputc('A', fp);

    if(ferror(fp)) {
       printf("Dosyaya yazma hatasi!\n");
    }

    fclose(fp);

    return 0;
}
#endif

#if 0
/*fflush function*/
int main(void)
{
    FILE *fp;
    char cdizi[20];
    int id;

    if ((fp = fopen ("dosya.txt", "w+")) == NULL) {
         printf("Dosya açma hatası!");
         exit(1);
    }

    fputs("B2ilg3isa5yar", fp);

    rewind(fp);
    if (fgets(cdizi, 20, fp)) printf("%s\n", cdizi);

    rewind(fp);
    while ((id=getc(fp))!= EOF) {      /* Dosya sonuna kadar (EOF) karakter karakter okuma işlemi */
       if (isdigit(id)) {              /* Eğer bir sayı ise */
           fseek(fp, -1, SEEK_CUR);    /* Sayı değerinin olduğu yere dönüş */
           fputc('A', fp);             /* A karakteri ile değiştirme */
           fflush(fp);                 /* Akış belleğini temizleme */
       }
    }

    rewind(fp);
    if (fgets(cdizi, 20, fp)) printf("%s", cdizi);

    fclose(fp);

    return 0;
}
#endif

#if 0
int main(int argc, char const *argv[])
{
	fprintf(stdout,"yavuzhanege\n");
}

#endif

#if 0
/*Static Assertion*/
_Static_assert(sizeof(int) > 4,"int turunun sizeof degeri kucuk");
int main(int argc, char const *argv[])
{
	
}
#endif

#if 0
/* Dynamic Assertion */
#include "assert.h"
int foo_assert(void){
	return 0;
}
int main(int argc, char const *argv[])
{
	int x = 12;
	int y = foo_assert();
	///
	assert(y != 0);
	int a = x / y;

}

#endif

#if 0
/*error handling*/
#include "errno.h"
int main(int argc, char const *argv[])
{
	FILE* f = fopen("yavuzzzz.dat","rb");
	printf("errno = %d\n",errno);
}

#endif
#if 0
/*perror*/
#include "errno.h"
int main(int argc, char const *argv[])
{
	FILE* f = fopen("yavuzzzz.dat","rb");
	printf("errno = %d\n",errno);
	if(!f){
		perror("file not opened");
	}
}

#endif
#if 0
/*strerror*/
#include "errno.h"
int main(int argc, char const *argv[])
{
	for (size_t i = 0; i < 20; i++)
	{

		printf("errno value %d is: %s\n", i, strerror(i));
	}
}

#endif

#if 0
/*variadic functions*/
#include "stdarg.h"

int sum(int n, ...)
{
	va_list args;
	va_start(args, n);
	int sum = 0;

	for (size_t i = 0; i < n; i++)
	{
		sum += va_arg(args, int);
	}
	va_end(args);
	return sum;
}

int main(int argc, char const *argv[])
{
	int x = 10;
	int y = 11;
	int z = 12;
	int t = 13;
	int k = 14;

	printf("sum = %d\n", sum(3, x, y, z));
	printf("sum = %d\n", sum(5, x, y, z, t, k));
}
#endif

#if 0
/*variadic functions*/
#include "stdarg.h"

int myprint(const char* p, ...){
	va_list args;
	int char_count;
	va_start(args,p);

	while(*p){
		int ch = toupper(*p);
		if(ch == 'I'){
			char_count += printf("%d ",va_arg(args,int));
		}
		else if(ch == 'F' || ch == 'D'){
			char_count += printf("%f ",va_arg(args,double));
		}
		else if(ch == 'L'){
			char_count += printf("%ld ",va_arg(args,long));
		}
		else if(ch == 'C'){
			char_count += printf("%c ",va_arg(args,int));
		}
		else if(ch == 'S'){
			char_count += printf("%s ",va_arg(args,const char*));
		}
		else if(ch == 'U'){
			char_count += printf("%u ",va_arg(args,unsigned));
		}
		++p;
	}
	return char_count;
}

int main(int argc, char const *argv[])
{
	int x = 45;
	double dval = 2.732;
	char* name = "yavuz hanege";

	int n = myprint("IDS",x,dval,name);

}

#endif

#if 0
/*volatile keyword*/
#include <time.h>
#include <stdio.h>

int main(void)
{
  clock_t c1 = clock();
  volatile double d = 0.0;

  // --------------------------------------------------

  for (int i = 0; i < 10000; ++i)
	for (int k = 0; k < 10000; ++k)
	  d += d * i * k;   
  // reads from and writes to non-volatile variable

  printf( "modified non-volatile variable 100millon times\n"
		  "time elapsed: %.2f seconds\n",
		  (double)(clock() - c1) / CLOCKS_PER_SEC);
	
}
#endif

#if 0
/*restrict keyword*/
int main(int argc, char const *argv[])
{
	int a = 31;
	 int* restrict x = &a;
}

#endif

#if 0
/* C99 Changes */
/* Variable Length Array */
void func_vla(int n){
	int a[n];
	printf("sizeof(a) = %zu\n",sizeof(a));
	printf("size a = %zu\n",sizeof(a) / sizeof(a[0]));
}
int main(int argc, char const *argv[])
{
	func_vla(5);
}

#endif

#if 0
/* C99 Changes */
/* Variable Length Array */

int dcmp(const void* p1, const void* p2){
	return (*(double*)p1 - *(double*)p2);
}

double get_median(const double* pa, size_t size){
	double ar[size];
	memcpy(ar,pa,size*sizeof(double));
	qsort(ar,size,sizeof(*ar),dcmp);
	return !(size % 2) ? ((ar[(size-1)/2] + ar[((size-1)/2) + 1])/2):ar[(size-1)/2];
}
int main(void)
{
	const double arr_odd[3] = {1.2,3.6,7.3};
	const double arr_even[6] = {1.2,3.6,7.3,5.2,8.5,9.4};
	printf("median  = %f\n",get_median(arr_odd,asize(arr_odd)));
	printf("median  = %f\n",get_median(arr_even,asize(arr_even)));
}
#endif

#if 0
/* C99 Changes */
/* Compound literals */
void func_compound(int *p) { printf("%d", *p); };
int main(int argc, char const *argv[])
{
	func_compound(&(int){12});
}
#endif
#if 0
/* C99 Changes */
/* Compound literals */
int main(int argc, char const *argv[])
{
	print_array((int[5]){3,6,8,1,4},5);
}
#endif

#if 0
/* Flexible Array Member*/
typedef struct vectord
{
	int len;	  // there must be at least one other data member
	double arr[]; // the flexible array member must be last
	// The compiler may reserve extra padding space here, like it can between struct members
} vectord;

int main(void)
{
	int num_vec = 12;
	vectord *vector = malloc(sizeof(vectord) + (num_vec * sizeof(int)));
	vector->len = num_vec;
	for (int i = 0; i < num_vec; i++)
	{
		vector->arr[i] = (double)i; // transparently uses the right type (double)
	}
	free(vector);
}
#endif