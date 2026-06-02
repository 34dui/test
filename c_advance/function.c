#include "data_struct.h"
#include <stdlib.h>

void insert_list_with_dummy(const int N,const int target,int flag,slist* list){
/*
 * 
 * @param list 指向链表结构体的指针
          N 要插入的数
          target 在此前/后插入
          flag 1后0前
 */
    if(list->head->next==NULL)return;
    NFL *add =(NFL*)malloc(sizeof(NFL));
    add->data=N;
    add->next=NULL;
    NFL *prev = list->head;
    NFL *curr = list->head->next;
    while(curr!=NULL&&curr->data!=target){
        prev=curr;
        curr=curr->next;
    }
    //没找到
    if(curr==NULL){
        free(add);
        return;
    }
    //后插考虑尾节点，前插考虑头节点
    if(flag==1){
        add->next=curr->next;
        curr->next=add;
        if(add->next==NULL){
            list->tail=add;
        }
    }else{
        add->next=curr;
        prev->next = add;     // 无论 prev 是哑节点还是普通节点，都正确
    }
}

void insert_list(const int N,const int target,int flag,slist* list){
/*
 * 
 * @param list 指向链表结构体的指针
          N 要插入的数
          target 在此前/后插入
          flag 1后0前
 */
    if(list->head==NULL)return;
    NFL *add =(NFL*)malloc(sizeof(NFL));
    add->data=N;
    add->next=NULL;
    NFL *prev = NULL;
    NFL *curr = list->head;
    while(curr!=NULL&&curr->data!=target){
        prev=curr;
        curr=curr->next;
    }
    //没找到
    if(curr==NULL){
        free(add);
        return;
    }
    if(flag==1){
        add->next=curr->next;
        curr->next=add;
        if(add->next==NULL){
            list->tail=add;
        }
    }else{
        add->next=curr;
        if(prev==NULL){
            list->head=add;
        }else{
            prev->next=add;
        }
    }
}

void del_list_with_dummy( const int N,slist* list) {
    if (list->head == NULL) return;
    NFL *prev = list->head;
    NFL *curr = list->head->next;
    while (curr != NULL && curr->data != N) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) return; // 未找到
    prev->next = curr->next;
    if (curr == list->tail) {
        list->tail = prev;
    }
    free(curr);
}

void del_list(const int N,slist* list) {
    if (list->head == NULL) return;

    NFL *prev = NULL;
    NFL *curr = list->head;
    while(curr!=NULL&&N!=curr->data){
        prev=curr;
        curr=curr->next;
    }
    if(curr==NULL)return;
    if(prev == NULL){
        list->head = curr->next;
    } else {
        prev->next = curr->next;
    }
    if(curr == list->tail){
        list->tail = prev;   // 删除唯一结点时，prev==NULL，tail 被正确设为 NULL
    }
    free(curr);
}

void init_list_with_dummy(slist* list){
/*
 * 初始化带头结点的链表
 * @param list 指向链表结构体的指针
 * 创建哑结点（data = -1, next = NULL），头尾指针均指向该哑结点
 */
    NFL* dummy=(NFL*)malloc(sizeof(NFL));
    dummy->data=-1;
    dummy->next=NULL;
    list->tail=dummy;
    list->head=dummy;
}

NFL* find_list(const int N,slist* list){
/*
 * 在链表中查找值为 N 的结点
 * @param N   要查找的目标值
 * @param list 指向链表结构体的指针
 * @return 若找到则返回结点指针，否则返回 NULL
 * 注意：查找包含哑结点（data = -1），通常不会匹配正常数据
 */
    NFL* p=list->head;
    //带dummp
    //NFL* p=list->head->next;
    while(p){
        if(p->data==N){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

void free_list(slist* list){
/*
 * 释放链表所有结点（包括哑结点）
 * @param list 指向链表结构体的指针
 * 遍历链表依次释放内存，最后将头尾指针置为 NULL
 */
    NFL* p=list->head;
    while(p){
        NFL *tmp = p;
        p = p->next;
        free(tmp);
    }
    list->head=list->tail=NULL;
}

void create_slist_tail_with_dummp(const int data,slist* list){
/*
 * 尾插法创建结点（链表带头结点）
 * @param data 新结点的数据值
 * @param list 指向链表结构体的指针
 * 前提：链表已通过 init_list 初始化，包含哑结点
 * 新结点插入到当前尾结点之后，并更新尾指针
 */
    NFL* t=(NFL*)malloc(sizeof(NFL));
    t->data=data;
    t->next=NULL;
    list->tail->next=t;
    list->tail=t;
}

void create_slist_tail(const int data,slist* list){

    NFL* t=(NFL*)malloc(sizeof(NFL));
    t->data=data;
    t->next=NULL;
    if(list->head==NULL){
        list->head=list->tail=t;
    }
    else{
        list->tail->next=t;
        list->tail=t;
    }
}

void create_slist_head_with_dummpy(const int data,slist* list){
/*
 * 头插法创建结点（链表带头结点）
 * @param data 新结点的数据值
 * @param list 指向链表结构体的指针
 * 前提：链表已通过 init_list 初始化，包含哑结点
 * 新结点插入到哑结点之后（即链表头部），若原链表仅含哑结点，则同时更新尾指针指向新结点
 */
    NFL *p=(NFL*)malloc(sizeof(NFL));
    p->data=data;
    //p->next=NULL;
    p->next=list->head->next;
    list->head->next=p;
    if(list->head==list->tail){
        //tail指向第一个，也即是链表最后一个
        list->tail=p;
    }

}

void create_slist_head(const int data,slist* list){
    NFL *p=(NFL*)malloc(sizeof(NFL));
    p->data=data;
    p->next=NULL;
    if(list->head==NULL){
        //第一个数据
        list->head=p;
        list->tail=p;
    }
    else{
        p->next=list->head;
        list->head=p;
    }
}

int find_arr(const int N,const int length,int arr[] ){
  /*
    N:查找数字
    length:数组长度
    arr:数组
  */
    for(int i=0;i<length;i++){
        if(arr[i]==N){
            return i;
        }
    }
    return -1;
}
int del_arr(const int N,const int length,int arr[] ){
    /*
    N:删除数字
    length:数组长度
    arr:数组
  */
    for(int i=0;i<length;i++){
        if(arr[i]==N&&i!=length-1){
           for(int j=i;j<length-1;j++) {
            arr[j]=arr[j+1];
           }
           return 1;
        }
        else if(arr[i]==N&&i==length-1){
            arr[length-1]='\0';
            return 1;
        }
    }
    return -1;
}

int insert_arr(const int N,const int length,int arr[] ,const int num,int flag){
    /*
    N:插入数字
    length:数组长度
    arr:数组
    num:在那个数字前后插入
    flag：0前1后
    */
    if(length>=maxsize){
        return -1;
    }
    int xiabiao=-1;
    xiabiao=find_arr(num,length,arr);

    if(xiabiao!=-1){
        xiabiao=(flag==0)?xiabiao:xiabiao+1;
        for(int i=length;i>xiabiao;i--){
            arr[i]=arr[i-1];
        }
        arr[xiabiao]=N;
        return 1;
    }
    return -2;
}