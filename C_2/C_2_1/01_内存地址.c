#include <stdio.h>
int main01()
{
	//1 什么是内存地址

	//2 地址相关运算：&取变量所占字节的首地址  * 根据地址取值

	int a = 5;
	printf("%d %p\n",&a,&a);

	//得到 内存空间的值
	printf("%d %d\n",a,*&a);

	return 0;
}