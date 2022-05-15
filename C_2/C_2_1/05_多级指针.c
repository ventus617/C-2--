#include <stdio.h>
int main05()
{
 
	/*
	 多级指针又称为：指向指针的指针。
	*/

	int age = 8;
	int* p = &age;
	int** pp = &p;//**是指向了*指针类型的指针
	int*** ppp = &pp;//***是指向了**
	int**** pppp = &ppp;//****是指向了***
	printf("%d\n",****pppp);//先是*pppp,再是**pppp,再是***pppp,最后是****pppp
	 

	return 0;
}