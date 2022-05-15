#include <stdio.h>
int main03()
{
	int a=1,b=2,c=3,d=4,i;
	// 指针类型的数组简称：指针数组。 每个数组成员都是指针变量。
	int * p[4]={&a,&b,&c,&d};
	//p是数组名
	//int * 表示整形指针
	//[n]表示数量

	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", *p[i]);
	}
	 //* p[i]=>*(*(p+i))
	 
	return 0;
}