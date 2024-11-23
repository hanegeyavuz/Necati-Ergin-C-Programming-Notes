#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include "nutility.h"
#include <math.h>

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

#if 1
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
	exit(31);
}
#endif