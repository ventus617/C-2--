#include <stdio.h>
int main01()
{
	//1 ʲô���ڴ��ַ

	//2 ��ַ������㣺&ȡ������ռ�ֽڵ��׵�ַ  * ���ݵ�ַȡֵ

	int a = 5;
	printf("%d %p\n",&a,&a);

	//�õ� �ڴ�ռ��ֵ
	printf("%d %d\n",a,*&a);

	return 0;
}