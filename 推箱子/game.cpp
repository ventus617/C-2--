#include <stdio.h>
#include<graphics.h>
int main()
{
	initgraph(30*10,30*10);

	IMAGE imgs[4];
	loadimage(imgs+0, L".\\image\\0.GIF");
	loadimage(imgs+1, L".\\image\\1.GIF");
	loadimage(imgs+2, L".\\image\\2.GIF");
	loadimage(imgs+3, L".\\image\\3.GIF");
	int ges[10][10] = {
	   { 2,2,1,1,1,1,1,1,2,2 },
	   { 2,2,1,0,0,0,0,1,2,2 },
	   { 2,2,1,0,0,0,0,1,1,1 },
	   { 1,1,1,0,0,0,0,0,0,1 },
	   { 1,0,0,0,0,0,0,1,1,1 },
	   { 1,0,0,0,0,0,0,1,2,2 },
	   { 1,1,1,1,1,0,0,1,2,2 },
	   { 2,2,2,2,1,0,0,1,2,2 },
	   { 2,2,2,2,1,1,1,1,2,2 },
	   { 2,2,2,2,2,2,2,2,2,2 }
	};
	for (int h=0 ;h<10 ; h++)
	{
		for (int k = 0; k < 10; k++)
		{
			putimage(k*30,h*30, imgs +ges[h][k]);
		}
	}

	system("pause");
	return 0;
}