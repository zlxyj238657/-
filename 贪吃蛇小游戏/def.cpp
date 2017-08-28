#include"def.h"
#include<Windows.h>
#include<iostream>
#include<time.h>
using namespace std;
int row, col, c, r, score = 0, Snake_iLen = 3;
char screenrid[MAXROW][MAXCOL] = {};
int Snake_Start_col = 1, Snake_Start_row = 1;
const char RIGHT_KEY = 'd', LEFT_KEY = 'a', UP_KEY = 'w', DOWN_KEY = 's';
char direction;
struct Snake_Segement{
	short x;
	short y;
}Snake[100];
void gotoxy(int x, int y)

{
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void drawline(int row, int col)
{
	gotoxy(row, col);
	for (int i = 0; i < MAXCOL + 1; i++)
		cout << "=" ;
	cout << endl;
}
void drawlineVertical(int row, int col)
{
	gotoxy(row, col);
	for (int i = 0; i < MAXROW + 1; i++)
	{
		gotoxy(row, i);
		cout << "|";
		cout << endl;
	}
}
void ShowScore()
{
	gotoxy(MAXCOL / 2 - 2, MAXROW + 1);
	cout << "score:" << score << endl;
}
//种子的产生
void CreatFood()
{
	//全局变量是指在程序开头的说明部分定义和说明的量。它的作用域分为两种情况：
	//(1)在全局变量和局部变量不同名时，其作用域是整个程序。
	//(2)在全局变量和局部变量同名时，全局变量的作用域不包含同名局部变量的作用域。
	//所以下面程序中row和col和全局变量的同名变量不同
	////c和r和全局变量的同名变量相同
	//for (int i = 0; i < Snake_iLen; i++)
	//{
		//if (row != Snake[i].x && col != Snake[i].y) continue;
		//else
		//{
	srand((int)time(NULL));     //每次执行种子不同，生成不同的随机数
	int row = rand() % 24 + 1;
	r = row;
	int col = rand() % 49 + 1;
	c = col;
	gotoxy(col, row);
	screenrid[row][col] = '*';
	cout << screenrid[row][col];
	gotoxy(0, 28);
		//}
}
//蛇身的增加
void AddSegement()
{
	switch (direction)
	{
	}
}
//游戏框架
//蛇身的显示
void  ShowSnake(int x,int y)
{
	gotoxy(x, y);
	cout << "O" << endl;
}
void GameFrame()
{
	//下面开始做框架
	for (row = 0; row < MAXROW; row++)
	{
		for (col = 0; col < MAXCOL; col++)
			screenrid[row][col] = ' ';
	}
	//初始化蛇体
	for (int i = 0; i < Snake_iLen; i++)
	{
		Snake[i].x = Snake_Start_row;
		Snake[i].y = Snake_Start_col + i;
		ShowSnake(Snake[i].y, Snake[i].x);
	}
	//CreatFood();
	drawline(1, 0);
	drawline(1, MAXROW);
	drawlineVertical(0, 0);
	drawlineVertical(MAXCOL+2, 0);
	ShowScore();
	//初始化蛇体

	//cout << endl;
	cout << "SNAKE GAME:LEFT=a;RIGHT=d;UP=w;DOWN=s;EXIT=x;" << endl;
}
