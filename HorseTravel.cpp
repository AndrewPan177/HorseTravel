// HorseTravel.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#pragma warning(disable:4996)

//�������̴�С
#define N 6

//����������߷�
int fx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int fy[8] = { 2,1,-1,-2,-2,-1,1,2 };

//�������·��
struct path {
	int x;
	int y;
};

struct path path[N*N];						//�洢���߹���·��
int mCouter = 0;							//�洢���߹��Ĳ���
int ChessBoard[N][N];						//�洢���̵�λ�ã�δ�߹�Ϊ0���߹�Ϊ1

//�ж��Ƿ������Ѿ��߹�
bool Check(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N || ChessBoard[x][y] != 0)
		return false;						//�����߽磬���ش���
	else
		return true;
}

void HorseTravel(int x, int y) {
	int xnext = 0, ynext = 0;	
	for (int i = 0; i < 8; i++) {			//�����һ��λ��
		xnext = x + fx[i];
		ynext = y + fy[i];

		if (Check(xnext, ynext)) {			//������δ������ʱ
			ChessBoard[xnext][ynext] = 1;	//��ʾ�Ѿ�����
			path[mCouter].x = xnext;		//�洢���·��
			path[mCouter].y = ynext;
			mCouter++;						//��¼��Ĳ���

			if (mCouter != N*N - 1) 		//����Ĳ���δ�ܱ�����������ʱ���ݹ�
				HorseTravel(xnext, ynext);
			else 
				break;	
		}
	}
}

int main()
{
	int x, y;//��ĳ�ʼ����
	printf("Input the x (0<x<%d): ", N);
	scanf("%d", &x);
	printf("Input the y (0<y<%d): ", N);
	scanf("%d", &y);

	//��ʼ��ChessBoard[N][N],Ϊ0��δ�߹�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			ChessBoard[i][j] = 0;
	}

	HorseTravel(x, y);

	//��·����ӡ
	printf("The Path of Horse Traversal is:\n");
	for (int i = 0; i < N*N; i++) {
		printf("(%d,%d)\t", path[i].x, path[i].y);
	}
	printf("\n");
    return 0;
}