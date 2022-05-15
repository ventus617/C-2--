#include <stdio.h>
int main ()
{
	/* 1 三维数组的声明  */
	int arr[3][4][5];//基本类型+维度
	/* 2 三维数组的初始化  */
	int arr1[3][4][5] = { 1,2,3,4 };
	int arr2[3][4][5] = { {1,2},{3,4} };
	int arr3[3][4][5] = { {{1},{2} }, { {3},{4} }};
	/* 3.1 三维数组的遍历:三维数组名+下标  */


	printf("%d %d %d\n",arr3,arr3+1,arr3+2);//这里的arr是面地址，arr是获得离其最近的首地址
	printf("%d %d %d\n",sizeof(*arr3),sizeof(*(arr3+1)),sizeof(*(arr3+2)));
	printf("%d %d %d\n", sizeof(arr3[0]), sizeof(arr3[1]), sizeof(arr3[2]));


	printf("%d %d %d\n",arr3[0]+0,arr3[0]+1,arr3[0]+2);//得到行地址
	printf("%d %d %d\n",sizeof(*(arr3[0]+0)),sizeof(*(arr3[0]+1)),sizeof(*(arr3[0]+2)));
	printf("%d %d %d\n", sizeof(arr3[0][0]), sizeof(arr3[0][1]), sizeof(arr3[0][2]));
	//不加* 相当于求地址的字节大小，32位则是4字节，加*相当于求其空间大小

	for (int m = 0; m < 3; m++)
	{
		for (int h = 0; h < 4; h++)
		{
			for (int i = 0; i < 5; i++)
			{
				printf("%d", arr3[m][h][i]);
			}
			printf("\n");
		}
		printf("\n");
	 }


	/* 3.2 三维数组的遍历:用int型变量的指针(列指针)  */
	int* plie = &arr3[1][0][0];
	printf("%d\n", *plie);
	int* pp = &arr3[1][1][1];
	printf("%d\n", *pp);
	//输出的是*plie 因为如果是plie就是个纯地址

	/* 3.3 三维数组的遍历:用int型指向一维数组的指针（行指针）  */
	int(* poor)[5] = (arr3[1]+1);//*(arr+1)+1 指向4时
	printf("%d\n", (*poor)[0]);
	int(*ppp)[5] = *arr3[1] + 1;
	printf("%d\n", (*ppp)[2]);
	/* 3.4 三维数组的遍历:用int型指向二维数组的指针（平面指针）  */
	int(*pmian)[4][5] = arr3 + 1;
	printf("%d\n",(*pmian)[1][0]);

	int(*pppp)[4][5] = arr3;
	printf("%d\n",*(pppp)[2][3] );
	/* 3.5 三维数组的遍历:用int型指向三维数组的指针（立体指针）  */
	int(*pli)[3][4][5] = &arr3;//arr是指向数组名，最近维度的地址，而&arr是整体，因此是指向整体整个维度的地址
	printf("%d\n",(*pli)[1][1][0]);

	int(*ppppp)[3][4][5] = &arr;
	printf("%d\n", (*ppppp)[2][3][3]);
	//参考地址[常量]=*（参考地址+常量）


	//指针实际就是存储的地址
	 
	return 0;
}