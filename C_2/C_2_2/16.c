#include<stdio.h>
int main16()
//{
//	
//	int ds[] = {1,2,3,4,5,6,7,8,9,19,36,78};
//	int i,j;
//	int len=sizeof(ds)/sizeof(ds[0]);
//	int find=19;
//	/*寻找指定数字在数组中首次出现的下标*/
//	//顺序查找
//	int index = -1;
//	for (i = 0; i < len; i++)
//	{
//		if (find == ds[i])
//		{
//			index = i;
//			break;
//		}
//	}
//	printf("下标是%d",index);
//	return 0;
//}
int main()
{

	int ds[] = { 1,5,8,12,23,44,56,78,99,200 };
	int arr[201];
	int len = sizeof(ds) / sizeof(ds[0]);
	int find;
	scanf("%d", &find);
	/*寻找指定数字在数组中首次出现的下标*/
	int l = 0, r = len - 1;
	while (l < r)
	{
		int mid = r - ((r - l) >> 1);
		if (ds[mid] >= find)r = mid;
		else l = mid + 1;
	}printf("%d\n", l);
	for (int i = 0; i < len; i++)
	{
		arr[ds[i]] = i;
	}printf("%d\n", arr[find]);
	return 0;
}