#include <stdio.h>
int main05()
{
 
	/*
	 �༶ָ���ֳ�Ϊ��ָ��ָ���ָ�롣
	*/

	int age = 8;
	int* p = &age;
	int** pp = &p;//**��ָ����*ָ�����͵�ָ��
	int*** ppp = &pp;//***��ָ����**
	int**** pppp = &ppp;//****��ָ����***
	printf("%d\n",****pppp);//����*pppp,����**pppp,����***pppp,�����****pppp
	 

	return 0;
}