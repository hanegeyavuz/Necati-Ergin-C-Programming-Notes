#include "personlist.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    Person per;
    struct Node* pnext;
}Node;

static Node* gpfirst = NULL;
static int gcount = 0;

static  Node* create_node(void){
    Node* p = malloc(sizeof(Node));
    if(!p){
        printf("bellek yetersiz");
        exit(EXIT_FAILURE);
    }
    return p;
}

void push_front(const Person* p){}
void pop_front(Person* p){}
void get_first(Person* p){}
int get_size(void){
    return gcount;
}
void print_list(void){}
void make_empty(void){}
int is_empty(void){
    return gpfirst == NULL;
}