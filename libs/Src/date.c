#include "date.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"
#include <time.h>
/*------------------------------------------------------*/
/* MACROS */
#define PRIVATE static
#define PUBLIC
#define YEARBASE 1900
#define ISLEAP(Y) (((Y) % 4 == 0) && (((Y) % 100) || ((Y) % 400 == 0)))
#define MDAYS(Y, M) (daytabs[ISLEAP(Y)][M])
#define RAND_YEAR_MIN 1940
#define RAND_YEAR_MAX 2024

/*------------------------------------------------------*/
/* VARIABLES */
PRIVATE const int daytabs[][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
/*------------------------------------------------------*/
/* PRIVATE FUNCTIONS */

PRIVATE int is_valid_date(int d, int m, int y)
{
    return y >= YEARBASE &&
           m > 0 && m <= 12 &&
           d > 0 && d <= MDAYS(y, m);
}

PRIVATE Date *set(Date *p, int d, int m, int y)
{
    if (!is_valid_date(d, m, y))
    {
        return NULL;
    }
    p->d_ = d;
    p->m_ = m;
    p->y_ = y;
    return p;
}

PRIVATE int day_of_the_week(int d, int m, int y)
{
    // array with leading number of days values
    const static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

    // if month is less than 3 reduce year by 1
    if (m < 3)
        y -= 1;

    return ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7);
}

PRIVATE int totaldays(const Date *p)
{
    int sum = get_year_day(p);
    int y = get_year(p);
    //int month_max = 13;
    for (int i = YEARBASE; i < y; i++)
    {
        sum += ISLEAP(i) ? 366:365;
    }
    return sum;
}

PRIVATE Date* to_date(Date* p, int tdays){
    int y = YEARBASE;
    while(tdays > (ISLEAP(y)? 366:365)){
        tdays -= (ISLEAP(y)? 366:365);
        ++y;
    }
    int m = 1;
    while(tdays > MDAYS(y,m)){
        tdays -= MDAYS(y,m);
        ++m;
    } 
    int d = tdays;
    return set(p,d,m,y);  
}

/*------------------------------------------------------*/
/* PUBLIC FUNTCIONS */
/*------------------------------------------------------*/
/* get functions */
/*------------------------------------------------------*/
PUBLIC int get_year(const Date *p)
{
    return p->y_;
}
PUBLIC int get_month(const Date *p)
{
    return p->m_;
}
PUBLIC int get_month_day(const Date *p)
{
    return p->d_;
}
PUBLIC int get_week_day(const Date *p)
{
    int y = get_year(p);
    int m = get_month(p);
    int d = get_month_day(p);
    return day_of_the_week(d, m, y);
}

PUBLIC int get_year_day(const Date *p)
{
    int y = get_year(p);
    int m = get_month(p);
    int sum = get_month_day(p);
    for (int i = 1; i < m; ++i)
    {
        sum += MDAYS(y, i);
    }

    return sum;
}

/*------------------------------------------------------*/
/* set functions */
/*------------------------------------------------------*/

PUBLIC Date *set_date(Date *p, int d, int m, int y)
{
    return set(p, d, m, y);
}

/*
PUBLIC Date *set_date_by_str(Date *p, const char *str){
    int d = atoi(str);
    int m = atoi(str+3);
    int y = atoi(str+6);
    return set(p,d,m,y);
}
*/

PUBLIC Date *set_date_by_str(Date *p, const char *str)
{
    if (!p || !str)
        return NULL;

    char *str_dup = my_strdup(str);
    if (!str_dup)
    {
        printf("bellek yetersiz\n");
        free(str_dup);
        return NULL;
    }

    char *token = strtok(str_dup, "-");
    int cnt = 0;

    while (token)
    {
        switch (cnt)
        {
        case 0:
            p->d_ = atoi(token);
            break;
        case 1:
            p->m_ = atoi(token);
            break;
        case 2:
            p->y_ = atoi(token);
            break;
        default:
            free(str_dup);
            return NULL;
        }
        cnt++;
        token = strtok(NULL, "-");
    }

    if (cnt != 3)
    {
        free(str_dup);
        return NULL;
    }

    free(str_dup);
    return p;
}

PUBLIC Date *set_date_today(Date *p)
{
    time_t sec;
    time(&sec);
    struct tm *tm_struct = localtime(&sec);
    int d = tm_struct->tm_mday;
    int m = tm_struct->tm_mon + 1;
    int y = tm_struct->tm_year + 1900;
    return set(p, d, m, y);
}
PUBLIC Date *set_random_date(Date *p)
{
    int y = rand() % (RAND_YEAR_MAX - RAND_YEAR_MIN + 1) + (RAND_YEAR_MIN);
    int m = rand() % 12 + 1;
    int d = rand() % MDAYS(y, m) + 1;
    return set(p, d, m, y);
}
PUBLIC Date *set_day(Date *p, int d)
{
    return set(p, d, get_month(p), get_year(p));
}
PUBLIC Date *set_month(Date *p, int m)
{
    return set(p, get_month_day(p), m, get_year(p));
}
PUBLIC Date *set_year(Date *p, int y)
{
    return set(p, get_month_day(p), get_month(p), y);
}

/*------------------------------------------------------*/
/* utility functions */
/*------------------------------------------------------*/
int cmp_date(const Date *p1, const Date *p2)
{
    int y1 = get_year(p1);
    int m1 = get_month(p1);
    int d1 = get_month_day(p1);

    int y2 = get_year(p2);
    int m2 = get_month(p2);
    int d2 = get_month_day(p2);

    if (y1 != y2)
    {
        return y1 - y2;
    }
    if (m1 != m2)
    {
        return m1 - m2;
    }

    return d1 - d2;
}
int date_diff(const Date *pfrom, const Date *pto){
    return totaldays(pto) - totaldays(pfrom);
}
Date *n_days_after(Date *pdest, const Date *psource, int n){
    return to_date(pdest,totaldays(psource) + n);
}
Date *n_days_before(Date *pdest, const Date *psource, int n){
    return to_date(pdest,totaldays(psource) - n);
}

/*------------------------------------------------------*/
/* formatted input-output functions */
/*------------------------------------------------------*/
void print_date(const Date *p)
{
    PRIVATE const char *pmonths[] = {"", "Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran", "Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik"};
    PRIVATE const char *pdays[] = {"Pazar", "Pazartesi", "Sali", "Carsamba", "Persembe", "Cuma", "Cumatesi"};

    int d = get_month_day(p);
    int m = get_month(p);
    int y = get_year(p);

    printf("%d %s %d %s", d, pmonths[m], y, pdays[get_week_day(p)]);
}
PUBLIC Date *scan_date(Date *p)
{
    char new_date[] = {0};
    scanf("%s", new_date);
    return set_date_by_str(p, new_date);
}