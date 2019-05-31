// HorseTravel.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#pragma warning(disable:4996)

//设置棋盘大小
#define N 6

//象棋中马的走法
int fx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int fy[8] = { 2,1,-1,-2,-2,-1,1,2 };

//马遍历的路径
struct path {
	int x;
	int y;
};

struct path path[N*N];						//存储马走过的路径
int mCouter = 0;							//存储马走过的步数
int ChessBoard[N][N];						//存储棋盘的位置，未走过为0，走过为1

//判断是否出界或已经走过
bool Check(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N || ChessBoard[x][y] != 0)
		return false;						//超出边界，返回错误
	else
		return true;
}

void HorseTravel(int x, int y) {
	int xnext = 0, ynext = 0;	
	for (int i = 0; i < 8; i++) {			//马的下一步位置
		xnext = x + fx[i];
		ynext = y + fy[i];

		if (Check(xnext, ynext)) {			//界内且未遍历过时
			ChessBoard[xnext][ynext] = 1;	//表示已经遍历
			path[mCouter].x = xnext;		//存储马的路径
			path[mCouter].y = ynext;
			mCouter++;						//记录马的步数

			if (mCouter != N*N - 1) 		//当马的步数未能遍历整个棋盘时，递归
				HorseTravel(xnext, ynext);
			else 
				break;	
		}
	}
}

int main()
{
	int x, y;//马的初始坐标
	printf("Input the x (0<x<%d): ", N);
	scanf("%d", &x);
	printf("Input the y (0<y<%d): ", N);
	scanf("%d", &y);

	//初始化ChessBoard[N][N],为0是未走过
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			ChessBoard[i][j] = 0;
	}

	HorseTravel(x, y);

	//将路径打印
	printf("The Path of Horse Traversal is:\n");
	for (int i = 0; i < N*N; i++) {
		printf("(%d,%d)\t", path[i].x, path[i].y);
	}
	printf("\n");
    return 0;
}