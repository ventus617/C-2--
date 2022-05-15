#include <stdio.h>
int main01()
{
	/*  */

	/*0 数组的特性：长度固定 、 同类型、 有编号（先行后列），逻辑造型：表格矩阵状  */

	/* 1 二维数组声明生成： 类型 数组名[行数][列数]  */
	int arr[4][4];
	//在空间上创建其实是先行后列，相当于先举出一行，然后给出一行的列，再给下一行
	 
	/* 2 二维数组 内存原理*/
	//一维的一维

	/* 3 数组元素（成员）的使用：数组名[先行][后列]  */
	arr[0][0] = 0; arr[0][1] = 1; arr[0][2] = 0; arr[0][3] = 1;
	arr[1][0] = 1; arr[1][1] = 1; arr[1][2] = 0; arr[1][3] = 1;
	arr[2][0] = 1; arr[2][1] = 0; arr[2][2] = 1; arr[2][3] = 1;
	arr[3][0] = 0; arr[3][1] = 0; arr[3][2] = 1; arr[3][3] = 1;
	/* 4 注意事项：不要下标越界使用。  */

	/* 5 循环遍历 每个成员 */
	/*for (int h = 0; h < 4; h++)
	{
		for (int l = 0; l < 4; l++)
		{
			printf("%d",arr[h][l]);
		}
		printf("\n");
	}*/
	printf("%d 行 %d列\n", sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]) / sizeof(int));//sizeof（arr[0]）表示一行大小，sizeof（arr）表示整个矩阵大小

	for (int h = 0; h < sizeof(arr)/sizeof(arr[0]); h++)
	{
		for (int l = 0; l < sizeof(arr[h])/sizeof(int); l++)
		{
			printf("%d", arr[h][l]);
		}
		printf("\n");
	}
	return 0;
}