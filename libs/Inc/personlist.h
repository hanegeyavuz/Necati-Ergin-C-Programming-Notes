#ifndef PERSONLIST_H
#define PERSONLIST_H

#include "person.h"

struct List;
typedef struct List* ListHandle;

ListHandle create_list(void);
void destroy_list(ListHandle);

void push_front(ListHandle lh, const Person* p);
void pop_front(ListHandle lh);
void get_first(ListHandle lh, Person* p);
int get_size(ListHandle lh);
void print_list(ListHandle lh);
void make_empty(ListHandle lh);
int is_empty(ListHandle lh);

#endif //PERSONLIST_H