#include <stdio.h>
int main03()
{
	int a=1,b=2,c=3,d=4,i;
	// ָ�����͵������ƣ�ָ�����顣 ÿ�������Ա����ָ�������
	int * p[4]={&a,&b,&c,&d};
	//p��������
	//int * ��ʾ����ָ��
	//[n]��ʾ����

	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", *p[i]);
	}
	 //* p[i]=>*(*(p+i))
	 
	return 0;
}