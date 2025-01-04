/*------------------------------------------------------*/
/* INCLUDES */
#include "person.h"
#include <string.h>
#include <stdlib.h>
#include "nutility.h"
/*------------------------------------------------------*/
/* MACROS */
#define PRIVATE static
#define PUBLIC
/*------------------------------------------------------*/
/* VARIABLES */

/*------------------------------------------------------*/
/* PRIVATE FUNCTIONS */

/*------------------------------------------------------*/
/* PUBLIC FUNTCIONS */
Person* set_random_person(Person* p){
    p->id = rand();
    strcpy(p->name,get_random_name());
    strcpy(p->surname,get_random_name());
    set_random_date(&(p->bdate));
    return p;
}

void print_person(const Person* p){
    printf("id = %d name = %s surname = %s date = ",p->id,p->name,p->surname);
    print_date(&(p->bdate));
    putchar('\n');
}

int cmp_person(const Person* p1, const Person* p2){
    if(p1->id && p2->id){
        return p1->id - p2->id;
    }
    else{
        printf("invalid ids\n");
        return -999;
    }
}



/*------------------------------------------------------*/
