#include <stdio.h>
int main12 ()
{
	/*���������Ա���ܺ��Ƕ���*/
	float ds[]={1,2,3,4,5,6,7,8,9,10 };
	float sum =0.f;
	int i;
	for(i=0;i<10;i++)
	{
		sum+=ds[i];
	}
	printf("%.0f\n",sum);
	return 0;
}