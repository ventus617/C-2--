#include<stdio.h>
#include<stdlib.h>
int main18 ()
{
	int ds[20];
	int i,j;
	int len=sizeof(ds)/sizeof(ds[0]);
	for(i=0;i<len;i++)
	{
		ds[i]=rand()%100;
		printf("%d,",ds[i]);
	}
	printf("\n");
	/*对数组成员 按 从小到大的顺序进行排序*/
	//冒泡排序是里面依次排，这里是从锁定一个排
	int temp = 0;
	for (int suo = 0; suo < len-1; suo++)//锁定一个数，和后面数比一圈，所以锁的个数不包括最后一个
	{
		for (int bijiao=suo+1;bijiao<len;bijiao++)//和锁定的后一个数比较，并且会比较到最后一个数，即找到最小的
		{
			if (ds[suo] > ds[bijiao])
			{
				temp = ds[suo];
				ds[suo] = ds[bijiao];
				ds[bijiao] = temp;
			}
		}
	}
	for (i = 0; i < len; i++)
	{
		printf("%d ",ds[i]);
	}

	return 0;
}