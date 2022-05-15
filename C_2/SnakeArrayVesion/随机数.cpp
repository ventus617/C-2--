#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main01()
{
	//随机数用法
	//1种子数
	srand((unsigned)time(0));
	//2随机数的范围
	printf("%d\n", rand());//
	printf("%d\n", rand() % 16+2);//2~17
	printf("%d\n", rand() % 18);//0~17
	return 0;
}