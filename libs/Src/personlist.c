#include "personlist.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    Person per;
    struct Node *pnext;
} Node;

struct List
{
    Node *mpfirst;
    int mcount;
};

ListHandle create_list(void)
{
    ListHandle lh = malloc(sizeof(struct List));
    if (!lh)
    {
        return NULL;
    }
    lh->mpfirst = NULL;
    lh->mcount = 0;
    return lh;
}
void destroy_list(ListHandle lh)
{
    make_empty(lh);
    free(lh);
}

static Node *create_node(void)
{
    Node *p = malloc(sizeof(Node));
    if (!p)
    {
        printf("bellek yetersiz");
        exit(EXIT_FAILURE);
    }
    return p;
}

void push_front(ListHandle lh, const Person *p)
{
    Node *pnewnode = create_node();
    pnewnode->per = *p;
    pnewnode->pnext = lh->mpfirst;
    lh->mpfirst = pnewnode;
    lh->mcount++;
}
void pop_front(ListHandle lh)
{
    if (is_empty(lh))
    {
        printf("bos liste hatasi!");
        exit(EXIT_FAILURE);
    }
    Node *ptemp = lh->mpfirst;
    lh->mpfirst = lh->mpfirst->pnext;
    free(ptemp);
    --lh->mcount;
}
void get_first(ListHandle lh, Person *p)
{
    if (is_empty(lh))
    {
        printf("bos liste hatasi!");
        exit(EXIT_FAILURE);
    }
    *p = lh->mpfirst->per;
}
int get_size(ListHandle lh)
{
    return lh->mcount;
}
void print_list(ListHandle lh)
{
    for (Node *p = lh->mpfirst; p != NULL; p = p->pnext)
    {
        print_person(&p->per);
    }
    printf("\n-------------------------------\n");
}
void make_empty(ListHandle lh)
{
    while (!is_empty(lh))
    {
        pop_front(lh);
    }
}
int is_empty(ListHandle lh)
{
    return lh->mcount == 0;
}