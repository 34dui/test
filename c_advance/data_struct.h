#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#define maxsize 10
typedef struct node_for_list {
    int data;
    struct node_for_list* next;
}NFL;
typedef struct singly_list{
    NFL* head;
    NFL* tail;
}slist;


#endif