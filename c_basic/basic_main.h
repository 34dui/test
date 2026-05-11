#ifndef BASIC_MAIN_H
#define BASIC_MAIN_H
typedef struct _node{
    int id;
    struct _node *next;
}NODE;

typedef struct list{
    NODE* head;
    NODE* tail;
}LIST;

void add(LIST* plist,int number);
#endif