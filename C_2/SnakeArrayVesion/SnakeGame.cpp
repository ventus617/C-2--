#define _CRT_SECURE_NO_WARNINGS 1
#include <easyx.h>
#include <time.h>
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<graphics.h>

/*��Ϸ�������*/
void gamePaint();
/*��Ϸ��ʼ������*/
void gameInit();
/*��Ϸ��ʱ����*/
void gameInterval();
/*��Ϸ���̰���*/
void gameKeypress(int key);
/*��Ϸ��갴��*/
void gameMouseDown(int mouseX, int mouseY);
/*��Ϸ����Ҽ�����*/
void gameMouseRightDown(int mouseX, int mouseY);
/*��Ϸ���̧��*/
void gameMouseUp(int mouseX, int mouseY);
/*��Ϸ����ƶ�*/
void gameMousemove(int mouseX, int mouseY);

/*
��͸����ͼ�Ļ���
xΪҪ����ͼƬ��X���꣬yΪY����
*/
void drawImage(int  picture_x, int picture_y, IMAGE* picture);
/*����ͼƬ͸����
  �Ƕ�ת���ȣ�PI/180*�Ƕ�
  ����ת�Ƕȣ�180/PI*����
*/
void drawImageAlpha(int x0, int y0, IMAGE* img, double f);
/*����������ײ���
�����������Ƿ��ཻ��
 x1, y1, w1�� h1�ǵ�һ�����ε�xy��ߵ��ĸ�����
 x2, y2, w2�� h2�ǵڶ������ε�xy��ߵ��ĸ�����
 ����0�����ཻ ����1�����ཻ
*/
int testHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

/*����100��ÿ��100����ˢ�����½����ͼ��*/
int interval = 100;//TODO: 1 ���ö�ʱ��ʱ��������λ���룩
// TODO: 1 ���ô���: ��� �߶�
int screenWidth = 600;
int screenHeight = 600;
int stop = 0;//�Ƿ�ֹͣ��Ϸ
//-----------------------------------//
int times = 0;
/*��ʼ����Ϸ */
void initgame()
{
	srand((unsigned)time(NULL));//�������ʼ��
	setbkcolor(NULL);//����ɫ
	setbkmode(TRANSPARENT);// ���ñ������ģʽ: TRANSPARENTΪ͸��
	gameInit();
}
/*
	�����ͼ��ʾ����
*/


/*������ʾ��Ϸ����*/
void paint()
{
	BeginBatchDraw();//��˫����
	cleardevice();// ����

	gamePaint();
	//-----------------------------//
	EndBatchDraw();//�ر�˫����
}



/*��Ϸ����*/
void run()
{
	ExMessage msg;
	//ExMessage key;
	while (1)	// ��Ϸ��ѭ��  �ɽ���break ����ѭ��
	{
		if (peekmessage(&msg, -1, true))
		{
			switch (msg.message)
			{
			case WM_MOUSEMOVE://����ƶ�
				gameMousemove(msg.x, msg.y);
				break;
			case WM_LBUTTONDOWN://�������
				gameMouseDown(msg.x, msg.y);
				break;
			case WM_LBUTTONUP://���̧��
				gameMouseUp(msg.x, msg.y);
				break;
			case WM_LBUTTONDBLCLK://���˫��

				break;
			case WM_RBUTTONDOWN://�Ҽ�����

				break;
			case WM_RBUTTONUP://�Ҽ�̧��
				gameMouseRightDown(msg.x, msg.y);
				break;
			case WM_RBUTTONDBLCLK://�Ҽ�˫��

				break;
			case WM_KEYDOWN:
				gameKeypress(msg.vkcode);
				break;
			}
			paint();
			continue;
		}


		//------ʱ�䴦�� ��-----------//
		Sleep(1);
		times++;
		if (times % (interval / 10) != 0) {
			continue;
		}
		times = 0;
		if (stop)
		{
			break;
		}
		gameInterval();

		//-------------------------------//
		paint();// ˢ����ʾ��Ϸ����
	}
}



/*����͸������ͼ*/
void drawImage(int  picture_x, int picture_y, IMAGE* picture) //xΪ����ͼƬ��X���꣬yΪY����
{

	// ������ʼ��
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //��ȡpicture���Դ�ָ��
	int picture_width = picture->getwidth(); //��ȡpicture�Ŀ�ȣ�EASYX�Դ�
	int picture_height = picture->getheight(); //��ȡpicture�ĸ߶ȣ�EASYX�Դ�
	int graphWidth = getwidth();       //��ȡ��ͼ���Ŀ�ȣ�EASYX�Դ�
	int graphHeight = getheight();     //��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
	int dstX = 0;    //���Դ������صĽǱ�

	// ʵ��͸����ͼ ��ʽ�� Cp=��p*FP+(1-��p)*BP �� ��Ҷ˹���������е���ɫ�ĸ��ʼ���
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //���Դ������صĽǱ�
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA��͸����
			int sr = ((src[srcX] & 0xff0000) >> 16); //��ȡRGB���R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //���Դ������صĽǱ�
				if (dstX < 0) continue;
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //��ʽ�� Cp=��p*FP+(1-��p)*BP  �� ��p=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //��p=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //��p=sa/255 , FP=sb , BP=db
			}
		}
	}
}
/*����ͼƬ͸����*/
void drawImageAlpha(int x0, int y0, IMAGE* img, double f)
{
	//���ͼƬ�ߴ�
	int qwidth, qheight;
	qwidth = img->getwidth();
	qheight = img->getheight();


	//PͼΪ����ͼ,RSΪĿ��ͼƬ
	static IMAGE RS(qwidth, qheight);
	static IMAGE P(qwidth, qheight);


	//����ͼ�Ļ���
	getimage(&P, x0, y0, qwidth, qheight);


	//��ȡָ�룬��Ϊ͸���ȼ���
	DWORD* M = GetImageBuffer(&P);
	DWORD* N = GetImageBuffer(img);
	DWORD* R = GetImageBuffer(&RS);


	// ����������ͼģʽ�������˸����
	BeginBatchDraw();


	//�����븳ֵ
	int i, j;
	for (i = 0; i < qheight; i++) {
		for (j = 0; j < qwidth; j++) {
			int r, g, b;
			int ij;
			//����
			ij = i * qwidth + j;
			r = (int)((GetRValue(N[ij])) * (1 - f) + GetRValue(M[ij]) * f);
			g = (int)((GetGValue(N[ij])) * (1 - f) + GetGValue(M[ij]) * f);
			b = (int)((GetBValue(N[ij])) * (1 - f) + GetBValue(M[ij]) * f);
			R[ij] = RGB(r, g, b);
		}
	}


	//����ͼƬ���ͷ��ڴ�
	putimage(x0, y0, &RS);
	FlushBatchDraw();// ����
}
//������������Ƿ�����ײ
int testHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	return !(x1 + w1 < x2 ||
		y1 + h1 < y2 ||
		x2 + w2 < x1 ||
		y2 + h2 < y1);
}
// ��������������Ϸ
int main()
{
	initgraph(screenWidth, screenHeight, SHOWCONSOLE);
	initgame();					// ��ʼ����Ϸ
	paint();// ˢ����ʾ��Ϸ����

	flushmessage();		// �����껺����
	while (_kbhit()) _getch();	// ��ռ��̻�����
	run();						// ��ʼ��Ϸ
	closegraph();//�ر�ͼ�λ�
	return 0;
}


//--------------���ŵľ����� ����Ϊ���� ��רҵ ���------------------// 
//TODO: 2 ȫ�ֱ�������λ�� 
IMAGE imgBG;
IMAGE imgApple;
IMAGE imgBody;
IMAGE imgHead[4];

int fangxiang=1;//��ͷ�ķ��� 1�� 2�� 3�� 0��
int appleLie ;//ƻ��������
int appleHang ;//ƻ��������
int snakehang[100] = {10,11,12,13,14};
int snakelie[100] = { 10,10,10,10,10 };
int snakeLength = 5;
//TODO: 3 ��Ϸ��ʼ��λ��  
void gameInit()
{
	srand((unsigned)time(0));
	appleLie = rand() % 16 + 2;
	appleHang = rand() % 16 + 2;


	loadimage(&imgBG, L".\\she\\bg.bmp");
	loadimage(&imgApple, L".\\she\\apple.bmp");
	loadimage(&imgBody, L".\\she\\body.bmp");
	TCHAR str[100];
	for (int i=0;i<4;i++)
	{
		_stprintf(str, L".\\she\\head%d.bmp", i);
		loadimage(imgHead +i, str);
	}
}
//TODO: 4 ��ͼ����λ��  
void gamePaint()
{

	putimage(0, 0, &imgBG);
	putimage(appleLie * 30, appleHang * 30, &imgApple);//ǰ�����У���������
	putimage(snakelie[0] * 30, snakehang[0] * 30, imgHead + fangxiang);//�״������ϵ�
	//�������������
	for (int i = 1; i < snakeLength; i++)
	{
		putimage(snakelie[i] * 30, snakehang[i] * 30, &imgBody);
	}
}
//TODO: 5 ��ʱ����λ��
void gameInterval()
{
	//TODO:T ��
	// ��β����׷ͷ��ʵ���ƶ�
	for (int i=snakeLength-1;i>0;i--)
	{
		snakehang[i] = snakehang[i - 1];
		snakelie[i] = snakelie[i - 1];
	}
	

	//��ͷ���ƶ�
	switch (fangxiang)
	{
	case 0:
		snakelie[0]++;
		break;
	case 1:
		snakehang[0]--;
		break;
	case 2:
		snakelie[0]--;
		break;
	case 3:
		snakehang[0]++;
		break;
	default:
		break;
	}
	if (snakehang[0]==appleHang
		&&snakelie[0]==appleLie)//TODO: T �ܳ�
	{
		//TODO: T �䳤
		snakeLength++;
		//TODO: T ������ƻ��
		appleHang = rand() % 16 + 2;
		appleLie = rand() % 16 + 2;
	}
	if (snakehang[0] == 0 
		|| snakehang[0] == 19 
		|| snakelie[0] == 0 
		|| snakelie[0] == 19)//TODO: T �ܳ���
	{
		//TODO:T gameover
		stop = 1;
	}
	if (snakehang[0] || snakelie[0])//TODO: T ��ҧ�Լ�
	{//TODO: T gameover
		for (int i = 2; i < snakeLength; i++)
		{
			if (snakehang[0] == snakehang[i] 
				&& snakelie[0] == snakelie[i])
			{
				stop = 1;
			}
		}
	}
	//int nengyao = 0;//���費��ҧ�Լ�
	//for (int j=1;j<snakeLength;j++)
	//{
	//	if (snakehang[0] == snakehang[j]
	//		&& snakelie[0] == snakelie[j])
	//	{
	//		nengyao = 1;
	//		break;
	//	}
	//}
	//if (nengyao)
	//{
	//	stop=1;
	//}
}
//TODO: 6 ������̿���λ��
void gameKeypress(int key)
{
	switch (key)
	{
	case VK_LEFT:
		if (fangxiang !=0)
		{
			//printf("������ ��\n");
			fangxiang = 2;
		}
		break;
	case VK_RIGHT:
		if (fangxiang != 2)
		{
			//printf("������ ��\n");
			fangxiang = 0;
		}
		break;
	case VK_UP:
		if (fangxiang != 3)
		{
			fangxiang = 1;
		}
		//printf("������ ��\n");
		break;
	case VK_DOWN:
		if (fangxiang!=1)
		{
			fangxiang = 3;
		}
		//printf("������ ��\n");
		break;
	}


}

//TODO: 7 ����������λ��
void gameMouseDown(int mouseX, int mouseY)
{
	printf("������ �����\n");

}
void gameMouseUp(int mouseX, int mouseY)
{
	printf("������ �����\n");
}
void gameMousemove(int mouseX, int mouseY)
{

}

void gameMouseRightDown(int mouseX, int mouseY)
{

}