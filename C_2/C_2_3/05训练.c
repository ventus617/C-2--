#include <stdio.h>
int main05()
{

	
	/*
	1  有如下语句 int a[10] = {1,2,3,4,5,6,7,8,9,10};int *p = a;则数值为9的表达式是___b___

	a)   *p+9          b)       *(p+8)       c)       *p+=9          d)       p+7
    */
 

 

	/*
	2  若有定义语句：int a[3][6]；按在内存中存放的顺序，a数组的第10个元素是__d___

	a[0][3]                    b)       a[1][4]                    c)       a[0][4]                    d)       a[1][3]
	*/
 

 

/* 3  以下数组定义中错误的是__B____

                     A. int x[][3] = {0};                       B. int x[2][3] = {{1,2}, {3,4}, {5, 6}};

                     C. int x[][3] = {{1,2,3}, {4,5,6}};        D. int x[2][3] = {1,2,3,4,5,6};
*/

/*
 4  若有说明：int i,j=2, *p=&i;, 则能完成i=j赋值功能的语句是__a___

A）*p=*&j;          B)i=*p     C)i+&j;           D)i=**p;
*/
 

 

/*5 下列程序的运行结果是_1,4,_8____

int main()

{

           int a[5][2] = {0, 1,   2, 3, 4, 5,  6, 7, 8,  9 };

           int* p = a;

           int (*p2)[2] = &a[1];


           ++p;

           ++p2;

           printf("%d\n", *p);

           printf("%d\n", **p2);

           printf("%d\n", p2[1][2]);//连续存储

           *(*(p2+1)+2)

           return 0;

}
*/
 

 

/* 6 下面的程序输出结果为__20,_50_____

#include <stdio.h>

 int main()

{

           int a[] = {10,20,30,40,50};

           int *p = (int*)(&a+1);

           printf("%d %d\n",*(a+1),*(p-1));

           return 0;

}
*/

	return 0;
}