#ifndef BASIC_MAIN_H
#define BASIC_MAIN_H


enum color{red,yellow,green};//0,1,2
//也可以直接赋值，不赋值是连续的正整数
//enum color{red =3,yellow,green =9};//3,4,9
//可以在最后写上到底有多少数量
//enum color{red =3,yellow,green =9,num=3};//3,4,9
void get_value(int *p);
void print_value(int k);
int mylen(char* s);
int mycmp(char* s1,char* s2);
char* mycpy(char* s1,char* s2);
struct date4{
  int year;
  int month;
  int day;
};
bool isleap(struct date4 d);
int getlastday(struct date4 d);
void get_today(struct date4 day);
void get_arr(char* arr);
struct date4 gettoday(void);
struct date4 *in_today(struct date4 *today);

//自定义数据类型
//typedef long int64_t;
//int64_t num;<-->long num
typedef struct date4{
  int year;
  int month;
  int day;
}date;
/*typedef struc{
  int year;
  int month;
  int day;
}date;*/
// date day={1234,12,1};


typedef union library{
  int id;
  char name[sizeof(int)];
}lib;


int global=12;
int global_test(void);
int static_test(void);
//int* re_test(void);
void f(void);
#define PI 3.14159
#define PI2 2*PI
#define format "%f\n"
#define prt printf(format,PI2);\
            printf(format,PI2)
#define square(x) ((x)*(x))


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