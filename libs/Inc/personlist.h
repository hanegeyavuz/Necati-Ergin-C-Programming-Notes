#ifndef PERSONLIST_H
#define PERSONLIST_H

#include "person.h"


void push_front(const Person* p);
void pop_front(Person* p);
void get_first(Person* p);
int get_size(void);
void print_list(void);
void make_empty(void);
int is_empty(void);

#endif //PERSONLIST_H