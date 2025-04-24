#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
// #define FORMAT "%d,%d\n" // 宏替换
#define FORMAT "%d\n%s\n%f\n%f\n%f\n"
#define LEN sizeof(struct dynamicList) // sizeof为求字节数运算符
struct person                          // 声明结构体
{
    char name[20];
    int count;
} leader[3] = {"Li", 0, "Zhang", 0, "Liu", 0};

struct student
{
    int num;
    char name[20];
    float score[3];
} stu = {12345, "Li Li", 67.5, 89, 78.6};

struct list
{
    long num;
    float score;
    struct list *next;
};

// 建立动态链表
struct dynamicList
{
    long num;
    float score;
    struct dynamicList *next;
};
int listNum; // listNum为全局变量，文本文件模块中各函数均可使用
int inerNum;
struct dynamicList *creat(state) // 定义函数，此函数返回一个指向链表起始的指针,函数首部在括号内写void表示本函数没有形参，若有则进行传参
{
    struct dynamicList *head;    // 声明head为结构体dynamicList的头地址指针变量
    struct dynamicList *p1, *p2; // 声明p1与p2为指向dynamicList的指针变量
    if (state)
    {
        listNum = 0;
    }
    else
    {
        inerNum = 0;
    }
    // 开辟一个新单元
    // 使用*malloc(unsigned int size)函数在内存的动态存储区中分配一个长度为size的连续空间，若此函数未能执行则返回NULL（空指针）
    // malloc返回的是不指向任何类型数据的指针（void *）
    p1 = p2 = (struct dynamicList *)malloc(LEN); // 而p1、p2是指向struct dynamicList类型数据的指针变量，因此必须用强制类型转换的方法使指针的基类型改变为struct dynamicList类型
    if (state)
    {
        printf("Plese input need create list:");
    }
    else
    {
        printf("Plese input need insert list:");
    }
    scanf("%d,%f", &p1->num, &p1->score);
    head = NULL;
    while (p1->num != 0)
    {
        if (state)
        {
            listNum = listNum + 1;
            if (listNum == 1)
                head = p1; // 第一次循环时赋给head头地址
            else
                p2->next = p1;
            p2 = p1;
            p1 = (struct dynamicList *)malloc(LEN);
            scanf("%d,%f", &p1->num, &p1->score);
        }
        else
        {
            inerNum = inerNum + 1;
            if (inerNum == 1)
                head = p1; // 第一次循环时赋给head头地址
            else
                p2->next = p1;
            p2 = p1;
            p1 = (struct dynamicList *)malloc(LEN);
            scanf("%d,%f", &p1->num, &p1->score);
        }
    } // p1指向新节点，p2指向链表最后一个结点，把p1所指的结点连接在p2所指的结点后，用p2->next=p1来实现
    p2->next = NULL; // 最后使p2指向空结点结束

    return (head); // head已定义为指针变量，指向struct dynamicList类型数据，因此返回的是链表的头地址
}

// 输出链表
void printList(struct dynamicList *head)
{
    struct dynamicList *p;
    printf("\nNow,These %d record are:\n", listNum + inerNum);
    p = head;
    if (head != NULL)
        do
        {
            printf("%d%8.1f\n", p->num, p->score);
            p = p->next;
        } while (p != NULL);
}

// 删除链表结点
struct dynamicList *del(struct dynamicList *head, long delNum)
{
    struct dynamicList *p1, *p2;
    if (head == NULL)
    {
        printf("\nlist null!\n");
    }
    else
    {
        p1 = head;
        while (delNum != p1->num && p1->next != NULL) // 判断p1指向的不是所要找的结点，并且后面还有结点的时候
        {
            p2 = p1;
            p1 = p1->next; // p1后移一个结点
        }
        if (delNum == p1->num) // 判断当前结点是否为需要删除的结点
        {
            if (p1 == head)
            {
                head = p1->next; // 若p1指向的是首结点（也就是需要删除的是首个结点），把第二个结点地址赋予head（相当于把第二个结点当头地址，而第一个结点在头地址之前就不计算在链表之内）
            }
            else
            {
                p2->next = p1->next; // 否则将下一结点地址赋给前一结点地址（就是跳过需要删除的结点，使其不计算在链表之内，达成删除结点效果）
                printf("delete:%d\n", delNum);
            }
            listNum--;
        }
        else
        {
            printf("%dnot been found!\n", delNum); // 找不到该节点
        }
    }
    return (head);
}

// 插入链表结点
struct dynamicList *insert(struct dynamicList *head, struct dynamicList *in) // 需要插入的结点内容传入in链表形参
{
    struct dynamicList *p0, *p1, *p2;
    p1 = head; // p1指向当前头结点
    p0 = in;   // p0指向需要插入的结点链表的头结点
    if (in != NULL)
    {
        if (head == NULL) // 若头结点为空（链表没有结点）
        {
            head = p0; // 将需插入的结点的链表头结点赋给当前头结点
        }
        else
        {
            if (p0->num < p1->num) // 在p1前插入
            {
                p0 = head;
                p1 = p0->next;
            }
            while (p0->num > p1->num && p1->next != NULL)
            {
                p2 = p1;       // 使p2指向刚才p1指向的结点
                p1 = p1->next; // p1后移一个结点
            }
            if (p0->num <= p1->num) // 当p1的num值加至p0的num值之后时执行插入动作
            {
                p2->next = p0; // 使p2结尾指向p0`
                p0->next = p1; // 使p0结尾指向p1完成插入
            }
            else
            { // 在结尾进行插入动作
                p1->next = p0;
                p0->next = NULL;
            }
        }
    }
    return (head);
}

// 写入、读出一组或多组数据
struct student_type // 声明结构体
{
    char name[10];
    int num;
    int age;
    char addr[15];
} stud[4]; // 输入4个数据
// 执行从stu_dat文件中读入数据并输出到stu_list文件中
void load()
{
    FILE *fp;
    int i;
    if ((fp = fopen("stu_dat", "rb")) == NULL) // 打开stu_dat文件并判断是否有这个文件
    {
        printf("cannot open infile\n");
        return;
    }
    for (i = 0; i < 4; i++)
    {
        if (fread(&stud[i], sizeof(struct student_type), 1, fp) != 1)
        {
            if (feof(fp)) // feof(fp)用来判断文件是否真的结束，如果文件结束则返回值为1，否则为0
            {
                fclose(fp); // 文件结束后关闭文件
                return;
            }
            printf("file read error\n");
        }
    }
    fclose(fp);
}
void save()
{
    FILE *fp;
    int i;
    if ((fp = fopen("stu_list", "wb")) == NULL) // 判断是否存在此文件,并输出打开一个二进制文件
    {
        printf("cannot open file\n");
        return;
    }
    for (i = 0; i < 4; i++)
    {
        if (fwrite(&stud[i], sizeof(struct student_type), 1, fp) != 1) // 执行并判断fwrite是否调用成功
        {
            printf("file write error\n");
        }
    }
    fclose(fp);
}
void read()
{
    int i;
    FILE *fp;
    fp = fopen("stu_list", "rb"); // 因为写入为二进制写入(wb)，所以要为输入打开一个二进制文件
    for (i = 0; i < 4; i++)
    {
        fread(&stud[i], sizeof(struct student_type), 1, fp); // 读取fp指向的文件内容
        printf("%-10s %4d %4d %-15s\n", stud[i].name, stud[i].num, stud[i].age, stud[i].addr);
    }
    fclose(fp);
}

void main()
// 运用把两个文件名一起输入的方式实现复制
// void main(int argc, char *argv[]) // argc为参数数量，*argv[]为指向装载参数的数组指针
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
    // char *name[] = {"Follow me", "BASIC", "Great Wall", "FORTRAN", "Computer design"};
    // char **p; // 指针变量p是指向一个字符指针变量（即指向字符型数据的指针变量），p是指向指针的指针变量
    // int i;
    // for (i = 0; i < 5; i++)
    // {
    //     p = name + i;        // 使p指向name数组的i号元素name[i]
    //     printf("%p\n", p);   // p为指针变量，指向name数组的i号元素
    //     printf("%s\n", *p);  // *p是name[i]的值
    //     printf("%d\n", **p); // **p为字符串数组name[i][0]的ASCII值
    // }

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

    // 结构体应用（结构体可以声明在main函数外）
    // int i, j;
    // char leader_name[20]; // 声明输入名
    // for (i = 0; i < 5; i++)
    // {
    //     scanf("%s", leader_name);
    //     for (j = 0; j < 3; j++)
    //         if (strcmp(leader_name, leader[j].name) == 0) // 输入名与结构体内名字相比，如全等则相对结构体内count元素++
    //             leader[j].count++;
    // }
    // printf("\n");
    // for (i = 0; i < 3; i++)
    //     printf("%5s:%d\n", leader[i].name, leader[i].count); // 循环输出结构体内各元素

    // 指向结构体变量的指针的应用
    // struct student
    // {
    //     long num;
    //     char name[20];
    //     char sex;
    //     float score;
    // };
    // struct student stu_1;
    // struct student *p; // 声明p为指向student结构体的指针变量
    // p = &stu_1;        // 将结构体stu_1的首地址赋给指针变量p，使其能够指向stu_1结构体
    // stu_1.num = 89101;
    // strcpy(stu_1.name, "Li Lin"); // 字符串复制
    // stu_1.sex = 'M';              // 这里的'M'为字符，需要用%c输出而不能用%s输出
    // stu_1.score = 89.5;
    // printf("No.:%1d\nname:%1s\nsex:%1c\nscore:%1f\n", stu_1.num, stu_1.name, stu_1.sex, stu_1.score);
    // printf("No.:%1d\nname:%1s\nsex:%1c\nscore:%1f\n", (*p).num, (*p).name, (*p).sex, (*p).score);
    // printf("No.:%1d\nname:%1s\nsex:%1c\nscore:%1f\n", p->num, p->name, p->sex, p->score); // 可以用->表示p所指向的结构体变量中的各成员

    // 指向结构体数组的指针
    // struct student
    // {
    //     int num;
    //     char name[20];
    //     char sex;
    //     int age;
    // };
    // struct student stu[3] =
    //     {
    //         {10101, "Li Lin", 'M', 18},
    //         {10102, "Zhang Fun", 'M', 19},
    //         {10104, "Wang Min", 'F', 20}};
    // struct student *p; // 声明p为指向student结构体的指针变量
    // printf("  No.     Name         sex        age\n");
    // for (p = stu; p < stu + 3; p++) // 将stu数组的首地址赋给指针变量p，使p可以指向stu数组
    //     printf("%5d%10s%10c%12d\n", p->num, p->name, p->sex, p->age); // (++p)->num使p自加1，然后得到指向元素中num成员值；(p++)->num是先得到p->num的值，然后使p自加1指向stu[1]

    // 用结构体变量作函数参数（指针）
    // void printStu(struct student *); // 形参类型为指向结构体的指针变量
    // printStu(&stu);                  // 实参为stu的起始地址，传参时将stu的起始地址传给指针变量p，这样就能使p指向stu

    // 建立和输出链表（静态链表）
    // struct list a, b, c, *head, *p;
    // a.num = 10101;
    // a.score = 89.5;
    // b.num = 10103;
    // b.score = 90;
    // c.num = 10107;
    // c.score = 85;
    // head = &a;     // 将结点a的起始地址赋给头指针head
    // a.next = &b;   // 将结点b的起始地址赋给a结点的next成员
    // b.next = &c;   // 将结点c的起始地址赋给b结点的next成员
    // c.next = NULL; // c结点的next成员不存放其他结点地址
    // p = head;      // 使p指针指向a结点（头指针）
    // do
    // {
    //     printf("%1d%5.1f\n", p->num, p->score); // 输出p指向的结点的数据
    //     p = p->next;                            // 使p指向下一结点
    // } while (p != NULL); // 输出完c结点后p值为NULL
    // // do while相当于until事件，当····时结束循环

    // 建立并输出动态链表
    // long delNum;
    // struct dynamicList *listHead;
    // struct dynamicList *delHead;
    // struct dynamicList *iner;
    // struct dynamicList *inserList;
    // listHead = creat(1); // 调用creat()函数后建立了一个单向动态链表，其返回值为指向头指针的指针变量
    // printList(listHead);
    // // 删除结点
    // // printf("Plese input need delete number:");
    // // scanf("%d", &delNum);
    // // delHead = del(listHead, delNum);
    // // printList(delHead);
    // // 插入结点
    // iner = creat(0);
    // printList(iner);
    // inserList = insert(listHead, iner);
    // printList(inserList);

    // 使用枚举方法处理5色球每次取3球不同色的不同取法并输出排列情况
    // enum color
    // {
    //     red,
    //     yellow,
    //     blue,
    //     white,
    //     black
    // };
    // enum color i, j, k, pri;
    // int n, loop;
    // n = 0;
    // for (i = red; i <= black; i++)
    // {
    //     for (j = red; j <= black; j++)
    //     {
    //         if (i != j)
    //         {
    //             for (k = red; k <= black; k++)
    //             {
    //                 if ((k != i) && (k != j))
    //                 {
    //                     n = n + 1; // 判断三色不同色后取法+1
    //                     printf("%-4d", n);
    //                     for (loop = 1; loop <= 3; loop++) // 取出第几个球是什么颜色的循环
    //                     {
    //                         switch (loop) // 循环取出的第几个球，将i，j，k值依次赋给pri
    //                         {
    //                         case 1:
    //                             pri = i;
    //                             break;
    //                         case 2:
    //                             pri = j;
    //                             break;
    //                         case 3:
    //                             pri = k;
    //                             break;
    //                         default:
    //                             break;
    //                         }
    //                         switch (pri) // 循环取出球的颜色，根据pri的值依次输出球的颜色
    //                         {
    //                         case red:
    //                             printf("%-10s", "red");
    //                             break;
    //                         case yellow:
    //                             printf("%-10s", "yellow");
    //                             break;
    //                         case blue:
    //                             printf("%-10s", "blue");
    //                             break;
    //                         case white:
    //                             printf("%-10s", "white");
    //                             break;
    //                         case black:
    //                             printf("%-10s", "black");
    //                             break;
    //                         default:
    //                             break;
    //                         }
    //                     }
    //                     printf("\n");
    //                 }
    //             }
    //         }
    //     }
    // }
    // printf("\ntotal:%5d\n", n);

    // 循环位移
    // unsigned a, b, c;
    // int n;
    // scanf("a=%o,n=%d", &a, &n);
    // b = a << (32 - n); // 32位系统左移n位，先将a右端n位放到b的高n位中
    // c = a >> n; // 再将a右移n位，其左面高位n位补0
    // c = c | b; // 或位运算
    // printf("%o\n%o", a, c);

    // 键入字符，逐个送到磁盘上，直到输入一个#为止
    // FILE *fp;
    // char ch, fileName[10];
    // scanf("%s", fileName);                   // 先输入文件名，这里的fileName可以直接写成常量模式直接指定打开哪个文件
    // if ((fp = fopen(fileName, "w")) == NULL) // 文件名为空时关闭文件结束程序
    // {
    //     printf("cannot open file\n");
    //     exit(0);
    // }
    // ch = getchar(); // 此语句用来接收在执行scanf语句时最后输入的回车符
    // ch = getchar(); // 接收输入的第一个字符
    // while (ch != '#')
    // {
    //     fputc(ch, fp);  // 将ch字符输出到fp所指的文件中
    //     putchar(ch);    // 这是个宏定义，相当于#define putchar(c) fputc(c,stdout)
    //     ch = getchar(); // 循环接收输入的字符
    // }
    // putchar(10); // 向屏幕输出一个换行符
    // fclose(fp);  // 关闭文件

    // 将一个磁盘文件中的信息复制到另一个磁盘文件中
    // FILE *in, *out;
    // char inFile[10], outFile[10];
    // printf("Enter the inFile name:\n");
    // scanf("%s", inFile);
    // printf("Enter the outFile name:\n");
    // scanf("%s", outFile);
    // if ((in = fopen(inFile, "r")) == NULL) // 只读,先给指针变量in赋值再判断是否为NULL
    // {
    //     printf("cannot open inFile\n");
    //     exit(0); // 结束程序
    // }
    // if ((out = fopen(outFile, "w")) == NULL) // 只写,先给指针变量out赋值再判断是否为NULL
    // {
    //     printf("cannot open outFile\n");
    //     exit(0); // 结束程序
    // }
    // while (!feof(in)) // 当in指向的文件读出字符不为EOF时执行动作
    // {
    //     fputc(fgetc(in), out); // fgetc(in)先读出字符，返回一个字符当作fputc()的第一个实参进行复制操作
    // }
    // fclose(in);  // 关闭in指向的文件
    // fclose(out); // 关闭out指向的文件
    // printf("Copy complete!");

    // 运用把两个文件名一起输入的方式实现复制
    // FILE *in, *out;
    // char ch;
    // // 三个参数，第一个参数为本程序编译后生成的exe文件名；第二个参数为需要读取的文件名；第三个参数为需要写入的文件名
    // if (argc != 3) // 这样可以在控制台直接输入例如本程序：Ctest.exe in.c out.c
    // {
    //     printf("You forgot to enter a fileName\n");
    //     exit(0);
    // }
    // // 只写
    // if ((in = fopen(argv[1], "r")) == NULL)
    // {
    //     printf("cannot open inFile\n");
    //     exit(0);
    // }
    // // 只读
    // if ((out = fopen(argv[2], "w")) == NULL)
    // {
    //     printf("cannot open outFile\n");
    //     exit(0);
    // }
    // while (!feof(in))
    // {
    //     fputc(fgetc(in), out);
    // }
    // fclose(in);
    // fclose(out);
    // printf("Copy complete!");

    // 写入、读出一组或多组数据
    int i;
    // for (i = 0; i < 4; i++) // 循环输入全局变量stud结构体内各值
    // {
    //     scanf("%s,%d,%d,%s", stud[i].name, &stud[i].num, &stud[i].age, stud[i].addr);
    // }
    load(); // 执行从stu_dat文件中读入数据并输出到stu_list文件中
    save(); // 执行保存结构体内容
    read(); // 输出文件内容
}

// 求a和b中的大者max函数
// int max(int x, int y)
// {
//     int z;
//     if (x > y)
//         z = x;
//     else
//         z = y;
//     return (z);
// }

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

// 结构体变量作函数参数
void printStu(struct student *p) // 注意struct student声明要写在main函数外部，否则此处调用不到会报错 // 注意形参类型
{
    printf(FORMAT, p->num, p->name, p->score[0], p->score[1], p->score[2]); // 用指针变量调用各成员的值
    printf("\n");
}