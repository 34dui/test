#ifndef FUNCTION_H
#define FUNCTION_H

int find_arr(const int N,const int length,int arr[] );
int del_arr(const int N,const int length,int arr[] );
int insert_arr(const int N,const int length,int arr[] ,const int num,int flag);
void init_list_with_dummy(slist* list);
void create_slist_head(const int data,slist* list);
void create_slist_head_with_dummpy(const int data,slist* list);
void create_slist_tail(const int data,slist* list);
void create_slist_tail_with_dummp(const int data,slist* list);
void free_list(slist* list);
void insert_list(const int N,const int target,int flag,slist* list);
void insert_list_with_dummy(const int N,const int target,int flag,slist* list);


void del_list_with_dummy(const int N,slist* list) ;
void del_list(const int N,slist* list) ;
NFL* find_list(const int N,slist* list);
#endif