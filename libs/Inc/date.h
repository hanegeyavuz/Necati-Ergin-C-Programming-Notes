#ifndef DATE_H /* for multiple inclusion */
#define DATE_H

typedef struct
{
    int d_;
    int m_;
    int y_;
} Date;
/* set functions */
Date *set_date(Date *p, int d, int m, int y);
Date *set_date_by_str(Date *p, const char *str);
Date *set_date_today(Date *p);
Date *set_random_date(Date *p);
Date *set_day(Date *p, int d);
Date *set_month(Date *p, int m);
Date *set_year(Date *p, int y);

/* get functions */
int get_year(const Date *p);
int get_month(const Date *p);     /* 0 = Ocak*/
int get_week_day(const Date *p);  /* 0-7 scale -> 0 = Pazar */
int get_month_day(const Date *p); /* 1-31 */
int get_year_day(const Date *p);  /* 0-365 */

/*utility functions*/
int cmp_date(const Date *p1, const Date *p2);
int date_diff(const Date *pfrom, const Date *pto);
Date *n_days_after(Date *pdest, const Date *psource, int n);
Date *n_days_before(Date *pdest, const Date *psource, int n);
/*formatted input-output functions*/
void print_date(const Date *p);
Date *scan_date(Date *p);

#endif /* DATE_H */