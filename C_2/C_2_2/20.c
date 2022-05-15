#include <stdio.h>
int main20()
{
	/*在一组有序的数列中，寻找一个指定的数字所在的下标*/
	int d[] = {1,5,8,12,23,44,56,78,99,200};
	int find=12;
	int len = sizeof(d) / sizeof(d[0]);
	//折半查找（数组的数是有序排列）
	int begin = 0;//开始点
	int middle = 0;//中间点
	int end = len-1;//末尾点
	do
	{
		middle = (begin + end)>>1;
		if (d[middle] == find)
		{
			printf("下标是%2d\n",middle);
			break;
		}
		else if (d[middle] < find)//即数在middle下标的右边
		{
			begin = middle + 1;
		}
		else if (d[middle] > find)//即数在middle下标的左边
		{
			end = middle - 1;
		}

	} while (begin <= end);
	if (!(begin <= end))
	{
		printf("无法找到相应下标");
	}

	return 0;

}