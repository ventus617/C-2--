#include <stdio.h>
int main03()
{
	/* 0.二维数组在内存中的存储形态 */
	int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	/* 1.用int指针遍历数组元素,证明二维数组在内存中是连续的 */
	int* p = &arr[0][0];


	for ( int i=0;i<3*4 ;i++ )
	{
		printf("%d %d\n", p, *p);//这里不写*p++，因为是从右向左计算赋值，所以p不为当前地址，为下一个地址，但值没影响
		p++;
	}
	/* 2.数组名的用法*/

	//**：得到某行的空间的地址
	// 
	// 
		//A：得到 某行的首地址
	printf("%d %d %d\n",arr,arr+1,arr+2);


		//B：得到 某行的存储空间,因此可以sizeof求大小,打印的是空间的首地址
	printf("%d %d %d\n",*(arr+0),*(arr+1),*(arr+2));
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);

	//参考地址[偏移量]==*（参考地址+偏移量）



	printf("%d %d %d\n",sizeof(*arr),sizeof(*(arr+1)),sizeof(*(arr+2)));


	//相当于行也是一种地址，只不过是根据内容有地址跨越（比如arr+1，是往下增加了4个4字节内容）


	//arr+1,是加的arr中 单行的字节数,arr[0]+1,是加的arr中 单个的字节数

	//arr+i相当于到了某层楼
	//*（arr+i）相当于从该楼层下电梯
	// 
	// 
	// 
	// 
	// 
	// 
	// 
		//C：得到某行内--某列的地址
	printf("%d %d %d\n",*(arr+1)+0,*(arr+1)+1,*(arr+1)+2);
	printf("%d %d %d\n", arr[0] + 0, arr[1] + 1, arr[2] + 2);




		//D：得到某行 某列的存储空间
	printf("%d %d %d\n", *(arr[1] + 0), *(arr[1] + 1), *(arr[1] + 2));
	printf("%d %d %d\n", arr[1][0], arr[1][1],arr[1][2]);



		//E：跨度整个二维数组 
	 

	printf("%d %d %d %d\n",arr,arr+1,&arr,&arr+1);
	//逻辑和一维一样


	/*3 . 利用指向一维数组的指针 遍历每一行的首地址*/

	int(*p_line)[4] = arr;//arr代表第0行的地址，这是数组指针，p_line指向一行的内容
	for (int h = 0; h < 3; h++)
	{
		printf("%d \n", p_line++);
	}
	 
	/*4 . 利用指向一维数组的指针 遍历每一行 每一个元素成员*/

	int(*p_line_4)[4] = arr;
	for (int h = 0; h < 3; h++)
	{
		for (int i = 0; i < 4; i++)
		{
			printf("%d %d \n", (*p_line_4)[i], *((*p_line_4) + i));
		}
		p_line_4++;
	}

	/*5 . 利用指向二维数组的指针 遍历每一行 每一个元素成员*/
	int(*p_all_4)[3][4] =&arr;//相当于指向面
	for (int h=0;h<3;h++)
	{
		for (int i = 0; i < 4; i++)
		{
			printf("%d %d %d \n",arr[h][i],*(*((*p_all_4)+h)+i),(*p_all_4)[h][i]);
		}
	}
	 
	return 0;
}




	//二维数组arr[3][4]中
	//&arr[1]和arr[1]
	// arr[1]实际上就是*（arr+1），即地址空间
	// 
	// &arr[1]实际上就是arr+1，即地址
	// 
	//数组名一维的就是首元素地址，二维就是首行的首元素地址，arr
	//加* 一维就是取当前的地址的存储空间（首元素的值），
	// 
	// 
	// 二维就是进入当前行的首元素的地址 *arr 
	// 二维再加**arr就是取得该行首元素的存储空间（即取值）
	// 
	// 
	// 指针实际上是存的地址，所以对应存储地址数据
	//p++ 是根据其p自己的类型来决定移动多少字节的
	// 
	// 	   针对于一个变量来说
	//&arr表示该空间的地址
	//arr表示该空间
	//*arr表示获得该空间的使用权，相当于获得空间存储的内容
