﻿#include <stdio.h>
#include <string.h>
// #define FORMAT "%d,%d\n" // 宏替换
void main()
{
    // 二维数组地址指针
    // int a[3][4] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
    // printf(FORMAT, a, *a);
    // printf(FORMAT, a[0], *(a + 0));
    // printf(FORMAT, &a[0], &a[0][0]);
    // printf(FORMAT, a[1], a + 1);
    // printf(FORMAT, &a[1][0], *(a + 1) + 0);
    // printf(FORMAT, a[2], *(a + 2));
    // printf(FORMAT, &a[2], a + 2);
    // printf(FORMAT, a[1][0], *(*(a + 1) + 0));

    // 用指针变量输出二维数组元素的值
    // int a[3][4] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
    // int *p;
    // for (p = a[0]; p < a[0] + 12; p++)
    // {
    //     if ((p - a[0]) % 4 == 0) // 一个内容占用4个字节
    //         printf("\n");
    //     printf("%8d %d %d", *p, a[0], p);
    // }
    // printf("\n");

    // 输出二维数组任一行任一列元素的值
    // int a[3][4] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
    // int (*p)[4], i, j; // (*p)[4]表示p为一个指针变量，它只能指向包含4个整型元素的一维数组 // 不可写成*p[4]，会变成指针数组
    // p = a;
    // scanf("i=%d,j=%d", &i, &j);
    // printf("a[%d,%d]=%d\n", i, j, *(*(p + i) + j));                                // 由于p是指向一维数组的指针变量，因此p+1就是指向下一行
    // printf("&a[%d,%d]=%d &a[%d,%d]=%d\n", i, j, &a[i, j], i, j + 1, &a[i, j + 1]); // 16字节？？

    // 字符串复制
    // char a[] = "I am a boy.", b[20]; // 声明b数组为20位元素数组
    // int i;
    // for (i = 0; *(a + i) != '\0'; i++) // 循环检查字符串结束字符'\0'
    //     *(b + i) = *(a + i);           // 复制每个字符给b数组,a+1和b+1为地址+1
    // *(b + i) = '\0';                   // 循环结束时在b字符串数组的末尾加上'\0'结束字符
    // printf("string a is:%s\n", a);
    // printf("string b is:");
    // for (i = 0; b[i] != '\0'; i++)
    //     printf("%c", b[i]);
    // printf("\n");

    // 指针变量处理复制
    // char a[] = "I am a boy.", b[20], *p1, *p2; // 声明b数组为20位元素数组,声明指针变量p1和p2
    // int i;
    // p1 = a, p2 = b;                 // 声明p1指向a，p2指向b
    // for (; *p1 != '\0'; p1++, p2++) // 循环检查字符串结束字符'\0'
    //     *p2 = *p1;                  // 复制每个字符给b数组(*p2),p1++和p2++为地址+1
    // *p2 = '\0';                     // 循环结束时在b(*p2)字符串数组的末尾加上'\0'结束字符
    // printf("string a is:%s\n", a);
    // printf("string b is:");
    // for (i = 0; b[i] != '\0'; i++)
    //     printf("%c", b[i]);
    // printf("\n");

    // 用带下标的字符指针变量引用字符串中的字符
    // char *a = "I love China!"; // 声明字符串
    // int i;
    // printf("The sixth character is %c\n", a[5]); // 直接用数组下标表示
    // for (i = 0; a[i] != 0; i++)                  // 用数组形式循环判断，依次输出整个字符串
    //     printf("%c", a[i]);
    // printf("\n");

    // 求a和b中的大者(通常写法)
    // int max(int, int);
    // int a, b, c;
    // scanf("%d,%d", &a, &b);
    // printf("a=%d,b=%d\n", a, b);
    // c = max(a, b);
    // printf("a=%d,b=%d,max=%d\n", a, b, c);

    // 求a和b中的大者(指针变量写法)
    // int max(int, int);
    // // 定义p是一个指向函数的指针变量，该函数有两个整型参数，函数值为整型
    // int (*p)(int, int); // 注意*p两侧括号不能省略，表示p先是指针变量，然后才与后面的函数(int, int)结合，表示其指针变量指向函数，函数返回的值为整型int
    // // 如为*p(int, int)，则其函数返回值为指向整型变量的指针
    // int a, b, c;
    // p = max; // 将函数max的入口地址赋给指针变量p，函数名代表该函数的入口地址，调用*p就是调用max函数
    // scanf("%d,%d", &a, &b);
    // c = (*p)(a, b); // 与c=max(a, b)等价，就是用指针形式实现函数调用
    // printf("a=%d,b=%d,max=%d\n", a, b, c);

    // 输入学生序号，输出学生全部成绩，用指针函数来实现
    // float score[][4] = {{60, 70, 80, 90}, {56, 89, 67, 88}, {34, 78, 90, 66}};
    // float *search(float (*pointer)[4], int n);
    // float *p;
    // int i, m;
    // printf("enter the number of student:");
    // scanf("%d", &m); // m为需要寻找的学生序号
    // printf("The scores of No.%d are:\n", m);
    // // p是指向列元素的指针变量
    // p = search(score, m);            // 这里的score为指针，为score数组的的首行地址
    // for (i = 0; i < 4; i++)          // 循环输出一个学生4门学科成绩
    //     printf("%5.2f\t", *(p + i)); // *(p + i)表示该学生第i门课程的成绩,%5.2表示显示5位并空2格显示
    // printf("\n");

    // 找出其中不及格课程的学生及其学号
    // float score[][4] = {{60, 70, 80, 90}, {56, 89, 67, 88}, {34, 78, 90, 66}};
    // float *search(float (*pointer)[4]); // 声明search函数返回值为指针变量（地址）
    // float *p;                           // 声明p为指针变量
    // int i, j;
    // for (i = 0; i < 3; i++)
    // {
    //     p = search(score + i); // score + i表示score首行地址+i，也就是score的第几行，循环每个学生
    //     if (p == *(score + i)) // 判断返回的指针变量是否与指向本行的指针变量相等（本行的首位地址），若相等则为不合格学生
    //     {
    //         printf("No.%d scores:\n", i);
    //         for (j = 0; j < 4; j++)
    //             printf("%5.2f\t", *(p + j)); // 循环得出不合格学生成绩
    //         printf("\n");
    //     }
    // }

    // 将若干字符串按字母顺序（由小到大）输出
    // {
    //     void sort(char *name[], int);
    //     void print(char *name[], int);
    //     char *name[] = {"Follow me", "BASIC", "Great Wall", "FORTRAN", "Computer design"};
    //     int n = 5;
    //     sort(name, n);
    //     print(name, n);
    // }

    // 使用指向指针的指针（字符串数组）
    char *name[] = {"Follow me", "BASIC", "Great Wall", "FORTRAN", "Computer design"};
    char **p; // 指针变量p是指向一个字符指针变量（即指向字符型数据的指针变量），p是指向指针的指针变量
    int i;
    for (i = 0; i < 5; i++)
    {
        p = name + i;        // 使p指向name数组的i号元素name[i]
        printf("%p\n", p);   // p为指针变量，指向name数组的i号元素
        printf("%s\n", *p);  // *p是name[i]的值
        printf("%d\n", **p); // **p为字符串数组name[i][0]的ASCII值
    }

    // 指向整型数据或实型数据
    // int a[5] = {1, 3, 5, 7, 9};
    // int *num[5], i;
    // int **p;
    // for (i = 0; i < 5; i++)
    // {
    //     num[i] = &a[i]; // 将数组a中每个元素地址赋给num数组，指针数组的元素只能存放地址
    //     printf("%d\n", *num[i]);
    // }
    // p = num + 2; // 指针数组的元素只能存放地址
    // printf("%p\n", *p);  // *p是p指向num数组中各元素的地址，也就是间接指向a数组中各元素的地址
    // printf("%d\n", **p); // **P是p指向num数组中各元素的值，也就是间接指向a数组中各元素的值
}

// 求a和b中的大者max函数
int max(int x, int y)
{
    int z;
    if (x > y)
        z = x;
    else
        z = y;
    return (z);
}

// 输入学生序号，输出学生全部成绩*search函数
// float *search(float (*pointer)[4], int n) // pointer为指向包含4个元素的一维数组的指针变量，如pointer + 1指向score数组序号为1的行
// {
//     float *pt; // 声明pt指针
//     // pointer为主函数main中score二维数组的地址（起始地址score[0][4]），pointer + n为选择二维数组中一维数组（哪一行）的序号，指向score数组序号为pointer + n的行
//     pt = *(pointer + n); // *(pointer + n)指向score数组的n行0列（注意score也是指向行的指针，而不是指向列的指针），它是一个指针
//     // pt = (*pointer + n);
//     // 若为pt = (*pointer + n),则表示二维数组中a[0][1]开始的4个元素的值,因为*pointer固定为score[0]，再+n则表示从第一行的0位开始计算，pt变为指向元素指针
//     return (pt); // 返回一个指向列元素的指针变量
// }

// 找出其中不及格学生的学号和分数*search函数
float *search(float (*pointer)[4]) // pointer为指向包含4个元素的一维数组的指针变量，如pointer + 1指向score数组序号为1的行
{
    int i;
    float *pt;
    pt = *(pointer + 1); // *(pointer + 1)指向score数组的下一行第0列（也就是本行末尾）（*(pointer + 1)为指针变量）
    for (i = 0; i < 4; i++)
        // *pointer + i为指针变量
        if (*(*pointer + i) < 60) // *(*pointer + i)表示search函数传入的实参*pointer为指定的行数，再+i表示指向指定行数的第i个元素
            pt = *pointer;        // 如果不及格，则返回本行的指针变量
    return (pt);
}

// 将若干字符串按字母顺序（由小到大）输出sort函数和print函数
void sort(char *name[], int n)
{
    char *temp;
    int i, j, k;
    for (i = 0; i < n - 1; i++) // 5个字符串，输入5所以需要n-1
    {
        k = i;
        for (j = i + 1; j < n; j++)           // 循环下一个字符串
            if (strcmp(name[k], name[j]) > 0) // name[k]为对照字符串，name[j]为对比字符串
                k = j;                        // 如果name[k] > name[j]，则k = j表示j的位置往前调
        if (k != i)                           // 循环后判断是否k值变化，变化就表示有位置前调动作
        {
            // 位置对调操作
            temp = name[i];
            name[i] = name[k];
            name[k] = temp;
        }
    }
}
void print(char *name[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%s\n", name[i]);
}