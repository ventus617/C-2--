#include <stdio.h>
int main08 ()
{
	//分析下面代码的执行结构，并通过调试器进行验证
	int a[4] = {1,2,3,4};
	int *ptr1=(int*)(&a+1 );
	int *ptr2 = (int*)((int)a+1 );
	//先强转为整数，再强转回地址，相当于加了一个字节 从0x00AFF8E4 变为0x00AFF8E5
	//然后再从高位输出，小端模式
	printf("%x, %x",ptr1[-1],*ptr2);//4，(0)2000000
	
	return 0;
}