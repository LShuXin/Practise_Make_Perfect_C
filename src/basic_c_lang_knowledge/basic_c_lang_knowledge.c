#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basic_c_lang_knowledge.h"

///**
// * 考察点：1.数据输入格式控制：如果在 scanf 中的双引号中用到了特殊字符，那么在数据输入的时候必须原样输入；
//         2.EOF windows平台下，ctrl+z可以作为EOF（EOF为End Of File的缩写，在操作系统中表示资料源无更多的资料可读取。资料源通常称为档案或串流。通常在文本的最后存在此字符表示资料结束。）
// */
//void print_upper_case_blue()
//{
//    // 定义了一个整型数组，用于保存输入的数据 ；数组是保存同类型数据的序列，
//    // 数组的长度代表了该数组可以保存的该类型数据的个数；该数组可以最多保
//    // 存20个整数，根据题意，输入的数据不会超过20个
//    int date[21];
//
//    int n, m, ch, i = 0;
//    // n用来临时保存每次输入的数据，
//    // ch用来保存将要输出字符的asc码,实际上加上64才是
//    // i用作计数器 ，循环控制的时候使用
//    // m又是一个计数器
//    while (scanf("%d", &n) != EOF)
//    {
//        date[i] = n;
//        i++;
//    }
//
//    date[i] = NULL;
//
//    i = 0; //下面要从头开始打印
//    while(date[i])
//    {
//        for(m = 1; m <= date[i]-1;m++)//该L对应的n是几，这个L就有多少行
//        {   ch=m%26;  //超过了26个字母就重来
//            if(ch==0) {
//                ch=26;  //ch=26的时候是一种对特殊情况，此时对应Z，但是取余数后就成了0，需要单独设定为26
//            };
//            printf("%c\n",ch+64);//ch+26才是真正的字母的asc字符
//        }
//
//        for( int p=m;p<=date[i]+m-1;p++)  // date[i]+m-1-m= date[i]-1，代表该需要打印的列数L
//        {
//            ch=p%26;
//            if(ch==0) {
//                ch=26;
//            };
//            printf("%c",ch+64);
//        }
//
//        printf("\n\n"); //打完一个L 要换行，注意换行的个数
//        i++;//while语句特别容易忘记计数器的增长
//    }
//}









/**
 * 串的存储结构式
 */
// 1.定长顺序存储表示
// 预定义串的最大长度为255（什么是截断问题）
#define STRING_MEMORY_MAXSIZE 255
typedef struct {
    char ch[STRING_MEMORY_MAXSIZE];
    int length;
} SString;


// 2.堆存储的字符串
typedef struct {
    char *ch;
    int length;
} HString;

void string_memory()
{
    SString sstr;
    HString hstr;


    // 两种字符串赋值
    sstr.length = 7;
    strcpy(sstr.ch, "abcdefg");

    hstr.ch = (char*)malloc(7 * sizeof(char));
    if (hstr.ch)
    {
        hstr.length = 7;
        strcpy(hstr.ch, "abcdefg");
    }


    // 打印
    if (sstr.length != 0)
    {
        printf("%d %s\n", sstr.length, sstr.ch);
    }
    if (hstr.ch)
    {
        printf("%d %s", hstr.length, hstr.ch);
    }

}











void value_vs_address_vs_reference_value_swap(int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void value_vs_address_vs_reference_address_swap(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
// 注意，C++里面才有引用
//void value_vs_address_vs_reference_reference_swap(int &x, int &y) {
//    int temp;
//    temp = x;
//    x = y;
//    y = temp;
//}
void value_vs_address_vs_reference() {
    int a = 10;
    int b = 20;

    printf("a=%d b=%d\n", a, b);

    value_vs_address_vs_reference_value_swap(a, b);
    printf("a=%d b=%d\n", a, b);

    value_vs_address_vs_reference_address_swap(&a, &b);
    printf("a=%d b=%d\n", a, b);

    // value_vs_address_vs_reference_reference_swap(a, b);
    // printf("a=%d b=%d\n", a, b);
}









void return_in_while() {
    int i = 0;
    while (i++ < 10) {
        if (5 == i) {
            return;
        }
        printf("%d", i);
    }
}









void break_in_while() {
    int i = 0;
    while (i++ < 10) {
        if (5 == i) {
            break;
        }
        printf("%d", i);
    }
}








void continue_in_while() {
    int i = 0;
    while (i++ < 10) {
        if (5 == i) {
            continue;
        }
        printf("%d", i);
    }
}









void return_in_for() {
    for (int i = 1; i < 10; ++i) {
        if (5 == i) {
            return;
        }
        printf("%d", i);
    }
}









void break_in_for() {
    for (int i = 1; i < 10; ++i) {
        if (5 == i) {
            break;
        }
        printf("%d", i);
    }
}









void continue_in_for() {
    for (int i = 1; i < 10; ++i) {
        if (5 == i) {
            continue;
        }
        printf("%d", i);
    }
}


#define CONST_DEFINE_TYPEDEF_TRUE 1
#define CONST_DEFINE_TYPEDEF_FALSE 0
#define CONST_DEFINE_TYPEDEF_OK 1
#define CONST_DEFINE_TYPEDEF_SUCCESS 1
#define CONST_DEFINE_TYPEDEF_ERROR 0
#define CONST_DEFINE_TYPEDEF_INFEASIBLE -1
#define CONST_DEFINE_TYPEDEF_OVERFLOW -2

typedef int CONST_DEFINE_TYPEDEF_Status;
typedef char CONST_DEFINE_TYPEDEF_ElemType;
typedef struct CONST_DEFINE_TYPEDEF_Node {
    char data;
    struct CONST_DEFINE_TYPEDEF_Node *next;
} CONST_DEFINE_TYPEDEF_LNode, *CONST_DEFINE_TYPEDEF_LinkList;

// 为类型定义别名之后，原来的名字依然可以使用
struct CONST_DEFINE_TYPEDEF_Node CONST_DEFINE_TYPEDEF_node, *CONST_DEFINE_TYPEDEF_pNode;
// 用新的名字定义变量
CONST_DEFINE_TYPEDEF_LNode CONST_DEFINE_TYPEDEF_node1, *CONST_DEFINE_TYPEDEF_pNode1;
CONST_DEFINE_TYPEDEF_LinkList  CONST_DEFINE_TYPEDEF_linkList;

void const_define_typedef() {

}








// 判断是否为闰年
// 1.能被400整除的是闰年
// 2.能被4整除但不能被100整除的也是闰年
int day_st_in_a_year_for_the_given_date_check_year(int year) {
    if (year % 100 && year % 4 == 0 || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
};
void day_st_in_a_year_for_the_given_date(int year, int month, int day) {
    int data[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayCnt = 0;

    if (day_st_in_a_year_for_the_given_date_check_year(year)) {
        for (int i = 0; i < month - 1; ++i) {
            dayCnt += data[i];
        }
        if (month >= 3) {
            day += 1;
        }
        dayCnt += day;
    } else {
        for(int i = 0; i < month - 1; ++i)
        {
            dayCnt += data[i];
        }
        dayCnt += day;
    }


    printf("%d 年 %d 月 %d 日, 是该年的第 %d 天", year, month, day, dayCnt);
}