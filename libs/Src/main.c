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

#if 1
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
