#include <stdio.h>
int main01()
{
	/*0 数组的特性：长度固定 、 同类型、 有编号  */

	/* 1 一维数组声明生成： 类型 数组名[长度]  */
	 //数组array：
	//1.扩展类型--基本类型变量的扩展
	//2.多个变量的集合
	int a;
	int arr[5];
	/* 2 数组元素（成员）的使用：[下标]  */
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	/* 3 注意事项：不要下标越界使用。 
		arr[5]=9;
		arr[-1]=7;
	
	*/
	/*计算数组长度*/
	printf("%d %d %d \n",sizeof(arr),sizeof(arr[0]),sizeof(arr)/sizeof(arr[0]));
	int len = sizeof(arr) / sizeof(arr[0]);
	//意思就是利用数组的数据类型相同，其所占字节数相同，因此数组长度等于 总字节数 除 单个成员所占字节数
	/*4 循环遍历 每个成员 */
	for (int i=0;i<5;i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}