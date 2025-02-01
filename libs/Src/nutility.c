#include "nutility.h"


const int primes[10] = {2,3,5,7,11,13,17,19,23,29};

/**
 * @brief Seeds the random number generator using the current time.
 */
void randomize(void)
{
    srand((unsigned)time(NULL));
}

/**
 * @brief Fills an array with random integers between 0 and 999.
 * 
 * @param pArr Pointer to the array.
 * @param size Size of the array.
 */
void set_array_random(int *pArr, size_t size)
{
    while (size--)
        *pArr++ = rand() % 1000;
}

/**
 * @brief Prints the elements of an integer array.
 * 
 * @param pArr Pointer to the array.
 * @param size Size of the array.
 */
void print_array(const int *pArr, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        if (i && i % 20 == 0)
            putchar('\n');
        printf("%3d ", pArr[i]);
    }
    printf("\n---------------------------------------\n");
}

/**
 * @brief Sorts an array of integers in ascending order using bubble sort.
 * 
 * @param pa Pointer to the array.
 * @param size Size of the array.
 */
void sort_array(int *pa, size_t size)
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

/**
 * @brief Reads a string from standard input.
 * 
 * @param p Pointer to the character array to store the string.
 */
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

/**
 * @brief Checks if a string is a palindrome.
 * 
 * @param pa Pointer to the string.
 * @param len Length of the string.
 * @return non-zero if input is palindrom, otherwise zero
 */
int ispalindrom(char *pa, size_t size)
{
    int idx_start = 0;
    int idx_end = size - 1;

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
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief Swaps the values of two integers.
 * 
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Calculates the sum of elements in an integer array.
 * 
 * @param p Pointer to the array.
 * @param size Size of the array.
 * @return The sum of the array elements.
 */
int sum_arr(const int *p, size_t size)
{
    int sum = 0;
    while (size--)
    {
        sum += *p;
        ++p;
    }
    return sum;
}

/**
 * @brief Calculates the mean of an array of integers.
 * 
 * @param p Pointer to the array.
 * @param size Size of the array.
 * @return The mean value of the array.
 */
double get_mean(const int *p, size_t size)
{
    return (double)(sum_arr(p, size) / size);
}

/**
 * @brief Calculates the standard deviation of an array of integers.
 * 
 * @param p Pointer to the array.
 * @param size Size of the array.
 * @return The standard deviation of the array.
 */
double get_std_dev(const int *p, size_t size)
{
    double mean = get_mean(p, size);
    double sum_square = 0;
    for (int i = 0; i < size; ++i)
    {
        sum_square += (p[i] - mean) * (p[i] - mean);
    }
    return sqrt(sum_square / (size - 1));
}

/**
 * @brief Reverses the elements of an integer array in place.
 * 
 * @param p Pointer to the array.
 * @param size Size of the array.
 */
void get_reverse_array(int *p, size_t size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        swap(p + i, p + size - 1 - i);
    }
}

/**
 * @brief Finds the maximum value in an array of integers.
 * 
 * @param p Pointer to the array.
 * @param size Size of the array.
 * @return The maximum value in the array.
 */
int get_max_array(const int *p, size_t size)
{
    int max = *p;
    for (int i = 0; i < size; ++i)
    {
        max = p[i] > max ? p[i] : max;
    }
    return max;
}

/**
 * @brief Finds the minimum value in an array of integers.
 * 
 * @param p Pointer to the array.
 * @param size Size of the array.
 * @return The minimum value in the array.
 */
int get_min_array(const int *p, size_t size)
{
    int min = *p;
    for (int i = 0; i < size; ++i)
    {
        min = p[i] < min ? p[i] : min;
    }
    return min;
}

/**
 * @brief Finds both the maximum and minimum values in an array.
 * 
 * @param p Pointer to the array.
 * @param size Size of the array.
 * @param max Pointer to store the maximum value.
 * @param min Pointer to store the minimum value.
 */
void get_max_min_array(const int *p, size_t size, int *max, int *min)
{
    *min = *p;
    *max = *p;
    for (int i = 0; i < size; ++i)
    {
        *min = p[i] < *min ? p[i] : *min;
        *max = p[i] > *max ? p[i] : *max;
    }
}

/**
 * @brief Copies elements from one array to another.
 * 
 * @param pdest Pointer to the destination array.
 * @param psource Pointer to the source array.
 * @param size Size of the arrays.
 */
void copy_array(int *pdest, const int *psource, size_t size)
{
    while (size--)
    {
        *pdest++ = *psource++;
    }
}

/**
 * @brief Sorts an array using the bubble sort algorithm.
 * 
 * @param p Pointer to the array.
 * @param size Size of the array.
 */
void bubble_sort(int *p, size_t size)
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

/**
 * @brief Swaps the contents of two arrays.
 * 
 * @param p1 Pointer to the first array.
 * @param p2 Pointer to the second array.
 * @param size Size of the arrays.
 */
void swap_array(int *p1, int *p2, size_t size)
{
    while (size--)
    {
        swap(p1++, p2++);
    }
}

/**
 * @brief Copies the elements of an array in reverse order.
 * 
 * @param pdest Pointer to the destination array.
 * @param psource Pointer to the source array.
 * @param size Size of the arrays.
 */
void reverse_copy(int *pdest, const int *psource, size_t size)
{
    pdest += size;
    while (size--)
    {
        *--pdest = *psource++;
    }
}

/**
 * @brief Prints the elements of an array using a pointer range.
 * 
 * @param ps Pointer to the start of the array.
 * @param pe Pointer to the end of the array.
 */
void printArray_alternative(const int *ps, const int *pe)
{
    while (ps != pe)
    {
        printf("%3d ", *ps++);
    }
}

/**
 * @brief Finds the pointer to the maximum element in an array.
 * 
 * @param p Pointer to the array.
 * @param size Size of the array.
 * @return Pointer to the maximum element.
 */
int *get_Array_Max(const int *p, size_t size)
{
    int *pmax = (int *)p;

    for (int i = 0; i < size; ++i)
    {
        if (*(p + i) > *pmax)
        {
            pmax = (int *)(p + i);
        }
    }
    return pmax;
}

/**
 * @brief Finds the pointer to the minimum element in an array.
 * 
 * @param p Pointer to the array.
 * @param size Size of the array.
 * @return Pointer to the minimum element.
 */
int *get_Array_Min(const int *p, size_t size)
{
    int *pmin = (int *)p;

    for (int i = 0; i < size; ++i)
    {
        if (*(p + i) < *pmin)
        {
            pmin = (int *)(p + i);
        }
    }
    return pmin;
}


/**
 * @brief Sorts an array in ascending order using the selection sort algorithm.
 *
 * @param p Pointer to the first element of the array to be sorted.
 * @param size The number of elements in the array.
 * 
 * @note The function assumes that the `swap` and `get_Array_Min` functions are
 * defined elsewhere and work as expected.
 */
void selection_sort(int* p, size_t size){
	for(int i = 0; i < size - 1; ++i){
		swap(p+i, get_Array_Min(p+i, size-i));
	}
}

/**
 * @brief Search spesific key in array function
 *
 * @param p Pointer to the first element of the array to be searched.
 * @param size The number of elements in the array.
 * @param key The key which is search in array
 * 
 * @return Adress of key in array if detect the key, otherwise NULL Pointer.
 */

int *search_in_array(const int *p, size_t size, int key)
{
	while (size--)
	{
		if (*p == key)
		{
			return (int *)p;
		}
		++p;
	}
	return NULL;
}


void gswap(void* vp1, void* vp2, size_t size)
{
  char* p1 = vp1;
  char* p2 = vp2;

  while (size--)
  {
    char temp = *p1;
    *p1++ = *p2;
    *p2++ = temp;
  }
}


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


char *my_strdup(const char *str)
{
	char *p = malloc(strlen(str) + 1);
	if (!p)
	{
		return 0;
	}
	return strcpy(p, str);
}

int isprime(int n){
    if(n < 2){
        return 0;
    }
    if(n % 2 == 0){
        return n == 2;
    }
    if(n % 3 == 0){
        return n == 3;
    }
    if(n % 5 == 0){
        return n == 5;
    }
    for(int i = 7; i*i <= (n); i += 2){
        if(!(n % i)){
           return 0; 
        }
    }
    return 1;

}

const char* get_random_name(void){
    static const char* const p_names[] = {
"ata", "emrecan", "adem", "burhan", "korhan", "demir", "bilal", 
"emrecan", "celik", "zahide", "dost", "lale", "baran", "saniye", 
"poyraz", "saadet", "aynur", "yeliz", "berivan", "mukerrem", "melih", 
"necati", "cezmi", "muslum", "azize", "atif", "rupen", "alev", "haldun", 
"hulusi", "yelda", "billur", "yasemin", "tarcan", "yasar", "tarkan", 
"refik", "berk", "kenan", "izzet", "adnan", "sefa", "kazim", "gursel", 
"huseyin", "suheyla", "binnaz", "nusret", "aykut", "efecan", "esra", 
"tonguc", "kunter", "yurdanur", "abdi", "fugen", "ayse", "aydan", "edip", 
"nazli", "nucahit", "onat", "cumhur", "yalcin", "ziya", "ali", "ismail", 
"recep", "sarp", "yilmaz", "hilal", "atakan", "cemre", "emirhan", 
"ceylan", "sabriye", "necmettin", "nagehan", "muhsin", "perihan", 
"suleyman", "zeliha", "cahide", "beril", "askin", "zahit", "sevim", 
"ege", "utku", "ercument", "seyhan", "sadegul", "enes", "sadi", "candan",
"cemile", "tansel", "turgut", "sumeyye", "aylin", "hakan", "ferhunde", 
"cebrail", "nihat", "alparslan", "osman", "efe", "ece", "soner", "necmi",
"polat", "naci", "pelinsu", "kerim", "eylul", "beste", "mert", "akin", 
"kamile", "kerem", "bekir", "nalan", "bulent", "tijen", "durmus", "cansu", 
"sadri", "atil", "yesim", "sevilay", "furkan", "ediz", "helin", "sadettin",
"gulden", "samet", "binnur", "celal", "murat", "sezer",
"bilge", "yunus", "cem", "temel", "sefer", "petek", "haluk", "teoman", 
"aslican", "aycan", "azmi", "nazife", "nurullah", "yasin", "nedim", 
"abdulmuttalip", "gulsen", "devlet", "mahir", "tarik", "yurdagul", 
"nisan", "derya", "emre", "sade", "leyla", "fadime", "tamer", "julide", 
"busra", "feramuz", "dilek", "dilber", "tansu", "abdullah", "mehmet", 
"nuri", "gizem", "nefes", "yavuz", "demet", "zekai", "zerrin", "umit", 
"gul", "emine", "sezen", "ugur", "turhan", "aziz", "tuncer", "handan", 
"okan", "irmak", "lamia", "can", "kelami", "ceyhan", "cahit", "gazi",
"bilgin", "su", "tayyar", "ferhat", "nuriye", "cemal", "engin", "pelin", 
"yusuf", "garo", "iffet", "galip", "deniz", "belgin", "muzaffer", 
"niyazi", "kayahan", "hulki", "kaya", "necmiye", "kasim", "hulya", 
"sidre", "esin", "suphi", "cengiz", "olcay", "rumeysa", "tugay", "asim", 
"yurdakul", "feraye", "derin", "cuneyt", "keriman", "naciye", "esen", 
"tevfik", "naz", "gurbuz", "cetin", "bora", "taci", "sadullah", "gulsah", 
"menekse", "semsit", "burak", "fikret", "cihan", "ceyda", "selenay", 
"alican", "figen", "nasrullah", "cesim", "zubeyde", "sezai", "melike", 
"nurdan", "arda", "nazif", "fuat", "gunay", "tufan", "fahri", "handesu", 
"kezban", "halime", "beyhan", "ciler", "tayyip", "afacan", "mustafa", 
"kurthan", "tugra", "ahmet", "hasan", "hakki", "metin", "aytac", "pinat",
"selin", "kaan", "melisa", "sevda", "nihal", "nevsin", "pakize", 
"teslime", "tunc", "nahit", "ceyhun", "hikmet", "eda", "malik", "anil", 
"canan", "egemen", "hande", "hilmi", "muruvvet", "cemil", "diana", 
"tayfun", "zarife", "tekin", "murathan", "caner", "devrim", "agah", 
"kamil", "ayla", "papatya", "kayhan", "durriye", "melek", "tanju", 
"sinem", "jade", "sadiye", "refika", "birhan", "sami", "orkun", "erdem", 
"ufuk", "dogan", "atalay", "fazilet", "taner", "polathan", "bennur", 
"aslihan", "cihat", };
    return r_elem(p_names);
}

void bprint(unsigned int x){
    unsigned int mask = ~(~0u >> 1);

    while(mask){
        putchar(mask & x ? '1':'0');
        mask >>= 1;
    }
    putchar('\n');
}
