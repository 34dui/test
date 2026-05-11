#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h> //malloc
#include <string.h>
#include "basic1.h"
#include "basic_main.h"
//void print_value1(int k);  
enum color{red,yellow,green};//0,1,2
//也可以直接赋值，不赋值是连续的正整数
//enum color{red =3,yellow,green =9};//3,4,9
//可以在最后写上到底有多少数量
//enum color{red =3,yellow,green =9,num=3};//3,4,9


void get_value(int *p){
  int k=*p;
  printf("p的地址=%d\n",p);
  printf("p=%d\n",*p);
  k++;
  printf("p的地址=%d\n",p);
  printf("p=%d\n",*p);
  *p=k++;
  printf("p的地址=%d\n",p);
  printf("p=%d\n",*p);
}


void print_value(int k){
  printf("k=%d\n",k);
}


int mylen(char* s){
  //法1
  /* int idx=0;
  int cnt=0;
  while(s[idx]!='\0'){
      idx++;
      cnt++;
  }
  return cnt; */
  //法2
  /* int len=0;
  while(s[len++]);
  return len-1; */
  //法3
  char *p=s;
  while(*p!='\0'){
    p++;
  }
  return p-s;
}


int mycmp(char* s1,char* s2){
  while(*s1==*s2&&*s1!='\0'){
    s1++;
    s2++;
  }
  //也可以强制转成unsigned char
  //*(unsigned char*)s1
  //int diff = *(unsigned char*)s1-*(unsigned char*)s2;
  int diff = *s1-*s2;
  if(diff<0){
    return -1;
  }else if(diff==0){
    return 0;
  }
  else{
    return 1;
  }
}


char* mycpy(char* s1,char* s2){
  char* ret=s1;
  while(*s2!='\0'){
    *s1=*s2;
    s1++;
    s2++;
  }
  *s1 = '\0';   // 手动添加结尾符
  return ret;
}


struct date4{
  int year;
  int month;
  int day;
};


bool isleap(struct date4 d){
  //判断是否是闰年
  bool leap=false;
  if((d.year%4==0&&d.year%100!=0)||d.year%400==0){
    leap=true;
  }
  return leap;
}


int getlastday(struct date4 d){
  int days;
  const int lastday[]={31,28,31,30,31,30,31,31,30,31,30,31};
  //获取月最后一天是多少
  if (isleap(d)&&d.month==2){
    days=29;
  }
  else{
    days=lastday[d.month-1];
  }
  return days;
}


void get_today(struct date4 day){
  //直接用结构体，并不会改变main中的值
  printf("输入年 月 日\n");
  scanf("%d %d %d",&day.year,&day.month,&day.day);
  printf("此时today是%d-%d-%d\n",day.year,day.month,day.day);
}


void get_arr(char* arr){
  arr[0]='s';
}


struct date4 gettoday(void){
  struct date4 day;
  printf("输入年 月 日\n");
  scanf("%d %d %d",&day.year,&day.month,&day.day);
  return day;
}


struct date4 *in_today(struct date4 *today){
  printf("输入年 月 日\n");
  scanf("%d %d %d",&(*today).year,&today->month,&today->day);
  return today;
}


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
int global_test(void){
  printf("in %s global is:%d\n",__func__,global);
  int global=2;
  printf("in %s int global=2,global is:%d\n",__func__,global);
  return global;
}


int static_test(void){
  static int q=1;
  q++;
  printf("q is %d\n",q);
}


/* int* re_test(void){
  int i=2;

  return &i;
} */
void f(void){
  int k=10;
  printf("k =%d\n",k);
}

#define PI 3.14159
#define PI2 2*PI
#define format "%f\n"
#define prt printf(format,PI2);\
            printf(format,PI2)
#define square(x) ((x)*(x))


int main()
{
   /*   int a, b;
    printf("输入两个整数\n"); // 输入两个整数
    scanf("%d %d", &a, &b);
    printf("两数之和为：%d\n", a + b); */

    //2026-04-09，写一个找零钱程序，输入商品价格和支付金额，输出找零金额
   /*  int price = 0, pay = 0, rest = 0;
    printf("输入商品价格和支付金额\n");
    scanf("%d %d",&price, &pay);
    rest =pay - price;
    if (rest<0) {
      printf("支付金额不足");
    }
    else if (rest==0) {
      printf("商品价格和支付金额相同，无需找零。");
    }
    else{
      printf("找%d元\n",rest);
      printf("找%d元\n",&rest); //输出地址
    } */

    //2026-04-09，写一个程序，输入两个整数，输出其平均值，保留后3位小数
    /* int num1 = 0,num2 = 0;
    float avg = 0;
    printf("输入两个整数\n");
    scanf("%d %d",&num1,&num2);
    avg = (num1+num2)/2.0;
    printf("平均值为：%.3f",avg); */
    
    //猜数游戏
/*     srand(time(0));
    int number = rand()%10, guest = -1,count = 0;
    printf("输入猜的数\n");
    //while 

    while (guest !=number ){
        printf("猜错了,重新猜\n");
        count++;
        scanf("%d",&guest);
    }
    printf("猜对了，是%d,猜了%d次",number,count);  */
    //do-while
   
  /*   do{
        scanf("%d",&guest);
        count++;
        if(guest !=number){

          printf("猜错了,重新猜\n");
        }
    }while(guest !=number);
    printf("猜对了，是%d,猜了%d次",number,count); */
    
    //找素数break and continue
    /* int num,isprime=1;
    scanf("%d",&num);
    for(int i=2;i<=num-1;i++){
      if(num%i==0){
        isprime=0;
        break;
      }
    }
    if (isprime==1){
      printf("%d是素数",num);
    }
    else{
      printf("%d不是素数",num);
    } */
/*     int num,isprime=1;
    scanf("%d",&num);
    printf("%d的因素有：\n",num);
    for(int i=2;i<=num-1;i++){
      if(num%i==0){
        isprime=0;
        printf("%d\n",i);
        continue;
        //break;
      }
      
    }
    if (isprime==1){
      printf("%d是素数",num);
    }
    else{
      printf("%d不是素数",num);
    }  */
    
    //goto,1角,2角,5角凑x元
   /*  int one,two,five,num,count=0;
    scanf("%d",&num);
    for(one=0;one<=num*10;one++){
       for(two=0;two<=num*5;two++){
          for(five=0;five<=num*2;five++){
            if(one+two*2+five*5==num*10){
              //count++;
              //printf("%d个一角,%d个二角,%d个五角可以凑出%d元\n",one,two,five,num);
              printf("找到一种方式，%d个一角,%d个二角,%d个五角可以凑出%d元\n",one,two,five,num);
              goto out;
            }
        }
      }
    }
    printf("有%d种方式",count);
    out:
    return 0; */

    /* //整数分解，12345-->1 2 3 4 5
    int num,weishu=1,temp,shunxu;
    scanf("%d",&num);
    temp=num;
    //找到num的位数
    while(temp>9){
      temp=temp/10;
      weishu=weishu*10;
    }
   //printf("%d",weishu);
   //整数分解，12345-->1 2 3 4 5
   do{
      shunxu=num/weishu;
      //printf("shunxu是%d,weishu:%d,num:%d\n",shunxu,weishu,num);
      printf("%d\n",shunxu);
      num=num%weishu;
      weishu=weishu/10;
   }while(weishu>0); */


    //最大公约数
   /*  int num1,num2,max=1,i=2;
    printf("输入两个正整数\n");
    scanf("%d %d",&num1,&num2);
    while(num1>1){
      for(i=2;i<=num1;i++){
        if(num1%i==0&&num2%i==0){
          max=max*i;
          break;
        }
      }

      num1=num1/i;
      num2=num2/i;
    }
    printf("%d",max); */
    
    //水仙花数
   /*  int n,sum=0,temp,max=1;
    //scanf("%d",&n);
    n=3;
    //求最大
    for(int i=0;i<n;i++){
      max=max*10;
    }
    for(int i=max/10;i<max;i++){
       int temp1=i;
       int cnt=0;
      while(cnt<n){
        int cnt1=0;
        int temp2;
        temp =temp1%10; 
        temp1=temp1/10;
        temp2=temp;
        while(cnt1<n-1){
          temp=temp*temp2;
          cnt1++;
        }
        sum= sum+temp;
        cnt++;
      }
      //printf("%d\n",sum);
      if(sum==i){
        printf("%d\n",sum);
      }
      sum=0;
    } */
      
    
     //打印九九乘法表
      /* int n=9;
     for(int i=1;i<=n;i++){
      for(int j=1;j<=i;j++){
        printf("%d*%d=%d",j,i,i*j);
        if (i*j>9){
          printf("   ");
        }
        else{
          printf("    ");
        }
      }
      printf("\n");
     }  */


   /* 
    //假设我们只有 5 张牌：S3、H5、C1、D13 和 J2。
    //给定一个洗牌顺序 {4, 2, 5, 3, 1}，
    //结果将是：J2, H5, D13, S3, C1。
    //如果我们再次重复洗牌，结果将是：C1, H5, S3, J2, D13。
void swap(int n,int state[]){
    char* temp[54]={0};
    char* chushi[54]={
    "S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
    "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
    "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
    "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
    "J1","J2"
};
    for(int j=0;j<n;j++){
        //进行一轮交换，
        for (int i=0;i<54;i++){
            temp[state[i]-1]=chushi[i];
        }
        for (int i=0;i<54;i++){
            chushi[i]=temp[i];
        }
    }
    for (int i=0;i<54;i++){
        if(i==53){
            printf("%s",chushi[i]);
        }
        else{
            printf("%s ",chushi[i]);
        }
    }
    //return chushi;
}
int main(){
    //char s='s',h='h',c='c',d='d',j='j';
    int n;
    int state[54]={0};
    scanf("%d",&n);
    for (int i=0;i<54;i++){
        scanf("%d",&state[i]);
    }
        swap(n,state);
        //printf("%d\n",state[i]);
    return 0;
} */
    //构造素数表
    //1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    //2 3 5 7 9 11 13 15，去掉2的倍数
    //2 3 5 7 11 13，去掉3的倍数
    //2 3 5 7 11 13，去掉5的倍数
    //2 3 5 7 11 13，去掉7的倍数
    //2 3 5 7 11 13，去掉11的倍数
    //2 3 5 7 11 13，去掉13的倍数


    //指针
    /* int i=1;
    get_value(&i);
    print_value(i); */

    //字符串
 /*    int i = 0;
    //指针指向只读数据段（.rodata），
    // 不可修改，s[0] = 'B' 会导致段错误
    char *s = "Hello World";
    // s[0] = 'B';        // 注释掉的危险操作
    //同上，且编译器可能将相同字面量合并，使 s 和 s2 指向同一地址
    // 同样不可修改
    char *s2 = "Hello World";
    //栈上的局部数组，内容由字符串常量复制而来	
    // 可修改，s3[0] = 'B' 正常执行
    char s3[] = "Hello World";

    printf("i  = %p\n", &i);
    printf("s  = %p\n", s);
    printf("s2 = %p\n", s2);
    printf("s3 = %p\n", s3);

    s3[0] = 'B';
    printf("Here! s3[0] = %c\n", s3[0]);
 */


    //字符串
   /*  char word[8];
    char word2[8];//最多存7个字符，结尾\0
    //高地址  word[0] ... word[7]  (0x...a8 ~ 0x...af)
    //低地址  word2[0] ... word2[7] (0x...a0 ~ 0x...a7)
    //word 数组的最后一个字节 word[7] 位于地址 0x...af，
    //紧接着的下一个字节（地址 0x...a0）就是 word2[0]
    //第二次 scanf 的结束符 \0 正好覆盖了 word 数组的第一个字符
    scanf("%s",word);
    scanf("%s",word2);
    //输入12345678 12345678
    printf("word:%s\nword2:%s\n",word,word2);
    printf("word:%p\nword2:%p",&word,&word2);
    printf("word[0] ASCII value: %d\n", word[0]);  // 应该输出 0 
    //安全的方式
    //如果超出，下一次输出紧跟着
    //输入12345678
    scanf("%7s",word);
    scanf("%7s",word2);
    //输出word: 1234567
    //输出word：8
    //输入12345678 89
    //输出输出word: 1234567
    //输出word：8
    printf("word:%s\nword2:%s\n",word,word2); */


   /*  // 指针数组：字符串常量不可改
    char *s[] = {"Hello", "World"};
    // s[0][0] = 'h';     // 段错误！
    s[0] = "Hi";          // 可重新指向其他字符串
    printf("%s %zu\n", s[0], sizeof(s)); // "Hi" 输出，sizeof=16（64位系统，2个指针）

    // 二维数组：内容可改，大小固定
    char a[][6] = {"Hello", "World"};
    a[0][0] = 'h';        //  合法修改
    // a[0] = "Hi";       // 编译错误：数组名不可赋值
    printf("%s %zu\n", a[0], sizeof(a)); // "hello" 输出，sizeof=12（2行×6字节） */
    
    //putchar getchar
   /*  int s;
    while((s=getchar())!=EOF){
      putchar(s);
    } */


    //stelen，不包含\0、


    /* char s1[] = "hello";
    printf("strlen:%zu\n",strlen(s1));
    printf("sizeof:%zu\n",sizeof(s1)/sizeof(s1[0]));
    //自定义函数实现
    printf("mylen:%d\n",mylen(s1)); */


    //strcmp
    //由于不同编译器原因，有些返回ASCLL码差值，有些返回0，1，-1
    //这里返回0，1，-1
/*     char s1[] = "hello";
    char s2[] = "hello";
    char s3[] = "iello";
    char s4[] = "dgell";
    char s5[] = "hello ";
    printf("strcmp:%d\n",strcmp(s1,s2));
    printf("strcmp:%d\n",strcmp(s1,s3));
    printf("strcmp:%d\n",strcmp(s1,s4));
    printf("strcmp:%d\n",strcmp(s1,s5));
    //自定义函数实现
    printf("mycmp:%d\n",mycmp(s1,s2));
    printf("mycmp:%d\n",mycmp(s1,s3));
    printf("mycmp:%d\n",mycmp(s1,s4));
    printf("mycmp:%d\n",mycmp(s1,s5)); */

    //strcpy,注意数组越界
    /* char s2[] = "world";
    char s1[] = "hello";
    //char guard[10] = "GUARD"; 
    //char guard1[10] = "GUARD1"; 
    char s3[] = "world!!!!";
    //char guard2[10] = "GUARD2"; 
    char s4[] = "word";
    printf("strcpy s2:%s\n",strcpy(s1,s2));
    printf("strcpy s3:%s\n",strcpy(s1,s3));
    printf("strcpy s4:%s\n",strcpy(s1,s4));
    printf("s1:%s\n",s1);
    printf("s2:%s\n",s2);
    printf("s3:%s\n",s3);
    printf("s4:%s\n",s4);
    printf("s1: %p\n", s1);
    printf("s2: %p\n", s2);
    printf("s3: %p\n", s3);
    printf("s4: %p\n", s4);
    //自定义函数实现
    mycpy(s1, "hello");
    mycpy(s2, "world");
    mycpy(s3, "world!!!!");
    mycpy(s4, "word");
    printf("------自定义函数实现------\n");
    printf("mycpy s2:%s\n",mycpy(s1,s2));
    printf("mycpy s3:%s\n",mycpy(s1,s3));
    printf("mycpy s4:%s\n",mycpy(s1,s4)); */


    //枚举 
    //enum也可以作为类似int char的数据类型
    /* enum color t=red;
    printf("%d\n",t);

    int color=-1;
    char* colorname=NULL;
    printf("输入0-2以内的整数\n");
    scanf("%d",&color);
    switch(color){
      case red: colorname="red";break;
      case yellow: colorname="yellow";break;
      case green: colorname="green";break;
      default: colorname="unknow";break;
    }
    printf("%s\n",colorname); */


    //结构体 struct
    //结构体如果声明在函数内部，是局部变量
    //如果想要在其他函数使用，要将其声明在函数外部
    //1、结构的三种声明与初始化
   /*  struct date{
      int year;
      int month;
      int day;
    };
    //匿名，不可再用，如声明day3
    struct {
      int year;
      int month;
      int day;
    }day1,day2;
    struct date3{
      int year;
      int month;
      int day;
    }p1;
    struct date day={2025,4,21};
    //没有写day的值，默认为0
    //注意是.month，而不是month
    struct date day_1={.year=2025,.month=4};

    //对应法2
    //day1 = (struct {int year,month,day;}){2025,4,21}; 错误
    //struct day2={2025,4,21};
    //通用写法，三种结构体均可以用
    day1.year = 2025;
    day1.month = 4;
    day1.day = 21;
    //或者在结构体中直接初始化
    struct {
      int year;
      int month;
      int day;
    }day1={2025,4,21},day2;
    day2=day1;

    // 注意：p1, p2 已经存在，不能再写 "struct date3 p1;"
    //struct date3 day1={2025,4,21};错误
    p1=(struct date3){2025,4,21};
    printf("今天是：%d-%d-%d\n",day.year,day.month,day.day);
    printf("未初始化day：%d-%d-%d\n",day_1.year,day_1.month,day_1.day);

    //2、结构与函数
    //利用结构体写一个函数，给出今天日期，输出明天日期
    struct date4 today={2000,2,28};
    //直接用结构体，并不会改变main中的值
    //和数组不同，结构体传递的是值而不是地址
    //char test[]="123";
    //printf("%s\n",test);
    //get_arr(test);
    //get_today(today);
    //可以再函数中创建一个结构体再返回
    today=gettoday();
    printf("新建结构体这里的是：%d-%d-%d\n",today.year,today.month,today.day);
    //也可以用指针
    in_today(&today);
    printf("指针这里的是：%d-%d-%d\n",today.year,today.month,today.day);
    //也可以用指针
    //printf("数组是%s\n",test);


    //3、结构中的结构
    struct date4 today1[] ={
      {2025,2,28},{2000,2,29},{2000,2,28},{2025,12,31}
    };
    today=today1[0];
    struct date4 tomorrow;
    if(today.day!=getlastday(today)){
      //不是最后一天
      tomorrow.day=today.day+1;
      tomorrow.month=today.month;
      tomorrow.year=today.year;
    }else if(today.day==getlastday(today)&&today.month==12){
      //是最后一天，且是12月
      tomorrow.day=1;
      tomorrow.month=1;
      tomorrow.year=today.year+1;
    }
    else{
      //是最后一天，但不是12月
      tomorrow.day=1;
      tomorrow.month=today.month+1;
      tomorrow.year=today.year;
    }
    printf("明天是：%d-%d-%d\n",tomorrow.year,tomorrow.month,tomorrow.day); */
   

    //联合 union
/*     lib book;
    book.id=12345;
    //0x39(9), 0x30(0), 0x00('\0'), 0x00,括号内为对应ascii码
    printf("id:%d,name:%s\n",book.id,book.name);
    strcpy(book.name, "abc"); // 将 "abc" 复制到 name 数组中
    //'a' (0x61), 'b' (0x62), 'c' (0x63), '\0' (0x00)
    //小端存储
    //book.name="abc";这是给数组改名，不行
    printf("id:%d,name:%s\n",book.id,book.name);
    book.id=12345;
    printf("id:%d,name:%s\n",book.id,book.name); */

    //输出为：
    //id:12345,name:90
    //id:6513249,name:abc
    //id:12345,name:90

    //这是因为联合体的所有成员共用同一块内存
    //大小取决于最大成员。对任一成员的修改都会影响其他成员的内容。
    //这也是和结构的区别


    //全局变量
    
    /* printf("in %s global is:%d\n",__func__,global);//__func__:当前函数名
    //在函数中重定义 int global=2 ，并不会改变其值，出来后即释放
    global_test();
    printf("agn in %s global is:%d\n",__func__,global); */


    //static
    //特殊的全局变量，和全局变量在一个连续的地址
    //全局生存期，局部作用域
    //只初始化一次
    /* static_test();
    static_test();
    static_test(); */

    //返回局部变量地址是危险的
    /* int *p=re_test();
    printf("*p =%d\n",*p);
    f();
    printf("*p=%d\n",*p); */

    // 宏
    //记得括号
    //整个式子要括号，所有变量要括号

    //#define s1(x) (x*5)
    //#define s2(x) (x)*5
    //printf("s1():%d\n",s1(2+1))<-->2+1*5
    //printf("s1():%d\n",1/s2(2))<-->1/2*5
   /*  prt;
    printf("square():%d\n",square(2)); */

    //多文件运行与调试
    /* int k=1;
    for (k=1;k<10;k++){
            print_value1(k);
    } */
    //如果只想每个某个函数只在当前文件用，加上static即可
    //对于全局变量也是如此
    //想要所有文件用同一个全局变量，加上extern
    //print_value1(gall);

    //由于c语言不能重复定义，如int k;int k;
    //而在引言.h头文件时，很难避免重复引用同一头文件
    //因此，在头文件中，使用
    //#ifndef BASIC_H
    //#define BASIC_H
    //#endif
    //来避免


    //链表
    /* NODE *head=NULL;
    int number;
    do{
      scanf("%d",&number);
      if(number!=-1){
        //建立节点
        NODE *p=(NODE*)malloc(sizeof(NODE));
        p->id=number;
        p->next=NULL;
        //找到尾节点
        NODE *last=head;
        if(last){
        while(last->next){
          last=last->next;
        }
        //添加节点
        last->next=p;
        }
        else{
          head=p;
        }
      }
    }while(number!=-1);
    //遍历
    if(head!=NULL){
      NODE *t=head;
      while(t->next){
        printf("%d\n",t->id);
        t=t->next;
      }
      printf("%d\n",t->id);
    } */
    //函数与链表
    LIST p;
    p.head=p.tail=NULL;
    int number;
    do{
      scanf("%d",&number);
      if(number!=-1){
        add(&p,number);
      }
    }while(number!=-1);
    //遍历
    NODE* pp=p.head;
    for(;pp;pp=pp->next){
      printf("%d\n",pp->id);
    }

    // 找到值为3的节点并删除
    pp = p.head;
    NODE *q = NULL;
    int flag = 0;                    // 0 表示未找到

    while (pp) {
        if (pp->id == 3) {
            flag = 1;
            if (q == NULL) {          // 删除头节点
                p.head = pp->next;
            } else {                  // 删除中间/尾节点
                q->next = pp->next;
            }
            free(pp);
            printf("找到了并删除\n");
            break;
        }
        q = pp;
        pp = pp->next;
    }

    if (!flag) {
        printf("没找到\n");
    }
    //遍历
    pp=p.head;
    for(;pp;pp=pp->next){
      printf("%d\n",pp->id);
    }
    return 0; 
}
void add(LIST* plist, int number) {
    NODE *t = (NODE*)malloc(sizeof(NODE));
    t->id = number;
    t->next = NULL;

    if (plist->tail) {                  // 链表非空
        plist->tail->next = t;          // 当前尾节点链接新节点
        plist->tail = t;                // 更新尾指针到新节点
    } else {                            // 链表为空
        plist->head = t;                // 头尾都指向新节点
        plist->tail = t;
    }
}