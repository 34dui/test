#include <stdio.h>
#include "data_struct.h"
#include "function.h"
int main(){
    //顺序表，查找，删除，插入
    int num;
    int arr[maxsize]={0,1,2,3,4,5,6,7,8,9};
    num=find_arr(9,10,arr);
    printf("%d\n",arr[num]);
    del_arr(9,10,arr);
    insert_arr(3,9,arr,5,1);
    insert_arr(3,10,arr,5,1);
    for(int i=0;i<maxsize;i++){
        printf("%d\n",arr[i]);
    }
    printf("shunxubiao\n");
    //单链表，头插，尾插，查找，删除，插入
    int data;
    slist first_list;
    first_list.head=first_list.tail=NULL;
    printf("输入数字\n");
    scanf("%d",&data);
    while(data>0){
        //头插法
        //create_slist_head(data,&first_list);
        //尾插法
        create_slist_tail(data,&first_list);
        scanf("%d",&data); 
    }
    //遍历
    NFL *list_head=first_list.head;
    for(;list_head!=NULL;list_head=list_head->next){
        printf("%d\n",list_head->data);
    }
    //free_list(&first_list);
    if (first_list.head == NULL && first_list.tail == NULL) {
    printf("链表已释放（头尾指针已置空）\n");
    }
    //查找
    NFL* p_find=NULL;
    p_find=find_list(3,&first_list);
    if(p_find){
        printf("找到了\n");
        printf("%d\n",p_find->data);
    }
    else{
        printf("没找到\n");
    }
    //删除
    del_list(3,&first_list);
        //遍历
    list_head=first_list.head;
    for(;list_head!=NULL;list_head=list_head->next){
        printf("%d\n",list_head->data);
    }
    printf("删除完成\n");
    //插入
    insert_list(100,2,1,&first_list);
    insert_list(101,2,1,&first_list);
    insert_list(1000,1,0,&first_list);
    insert_list(1001,1,0,&first_list);
    printf("插入完成\n");
        //遍历
    list_head=first_list.head;
    for(;list_head!=NULL;list_head=list_head->next){
        printf("%d\n",list_head->data);
    }
    return 0;
}