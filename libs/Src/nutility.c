#include "nutility.h"


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
void set_array_random(int *pArr, int size)
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

/**
 * @brief Sorts an array of integers in ascending order using bubble sort.
 * 
 * @param pa Pointer to the array.
 * @param size Size of the array.
 */
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
 */
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
int sum_arr(const int *p, int size)
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
double get_mean(const int *p, int size)
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
double get_std_dev(const int *p, int size)
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
void get_reverse_array(int *p, int size)
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
int get_max_array(const int *p, int size)
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
int get_min_array(const int *p, int size)
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

/**
 * @brief Copies elements from one array to another.
 * 
 * @param pdest Pointer to the destination array.
 * @param psource Pointer to the source array.
 * @param size Size of the arrays.
 */
void copy_array(int *pdest, const int *psource, int size)
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

/**
 * @brief Swaps the contents of two arrays.
 * 
 * @param p1 Pointer to the first array.
 * @param p2 Pointer to the second array.
 * @param size Size of the arrays.
 */
void swap_array(int *p1, int *p2, int size)
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
void reverse_copy(int *pdest, const int *psource, int size)
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
int *get_Array_Max(const int *p, int size)
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
int *get_Array_Min(const int *p, int size)
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
void selection_sort(int* p, int size){
	for(int i = 0; i < size - 1; ++i){
		swap(p+i, get_Array_Min(p+i, size-i));
	}
}

