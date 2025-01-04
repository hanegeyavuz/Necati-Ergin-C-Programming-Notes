#ifndef PERSON_H
#define PERSON_H

#include "date.h"

typedef struct 
{
    int id;
    char name[20];
    char surname[24];
    Date bdate;
}Person;


Person* set_random_person(Person* p);
void print_person(const Person* p);
int cmp_person(const Person* p1, const Person* p2);


#endif