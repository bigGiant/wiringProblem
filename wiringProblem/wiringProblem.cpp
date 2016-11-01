// wiringProblem.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int m = 8;
int n = 8;
int grid[10][10];
int indexcount = 0;
struct Position
{
	int row;
	int col;
};
void showPath()
{
	for (int i = 0; i<10; i++)
	{

		for (int j = 0; j<10; j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}
	cout << "------------------" << endl;
}
bool FindPath(Position start, Position finish, int &PathLen, Position  *&path)
{
	//��������λ��start��Ŀ��λ��finish����̲���·�����ҵ���̲���·���򷵻�true�����򷵻�false  

	if ((start.row == finish.row) && (start.col == finish.col))
	{
		PathLen = 0;
		cout << "start=finish" << endl;
		return true;
	} //start=finish  
	  //���÷������С�Χǽ��  
	  //��ʼ��ͼ��-1Ϊδ����  
	for (int i = 1; i<9; i++)
	{
		for (int j = 1; j<9; j++)
			grid[i][j] = -1;

	}

	//����赲��  
	grid[2][3] = -2;

	for (int i = 0; i <= m + 1; i++)
		grid[0][i] = grid[n + 1][i] = -2; //�����͵ײ�  
	for (int i = 0; i <= n + 1; i++)
		grid[i][0] = grid[i][m + 1] = -2; //���������  
										  //��ʼ�����λ��  
	cout << "����ͼ" << endl;
	showPath();
	Position offset[4];
	offset[0].row = 0;
	offset[0].col = 1;//��  
	offset[1].row = 1;
	offset[1].col = 0;//��  
	offset[2].row = 0;
	offset[2].col = -1;//��  
	offset[3].row = -1;
	offset[3].col = 0;//��  
	int NumOfNbrs = 4;//���ڷ�����  
	Position here, nbr;
	here.row = start.row;
	here.col = start.col;
	grid[start.row][start.col] = 0;
	//��ǿɴ﷽��λ��  
	cout << "����ǰͼ" << endl;
	showPath();

	queue<Position> Q;
	do  //������ڿɴ﷽��  
	{
		for (int I = 0; I<NumOfNbrs; I++)
		{
			nbr.row = here.row + offset[I].row;
			nbr.col = here.col + offset[I].col;
			if (grid[nbr.row][nbr.col] == -1)
			{
				//�÷���δ�����  
				//cout<<grid[nbr.row][nbr.col]<<endl;//��ʾ·��ֵ  
				grid[nbr.row][nbr.col] = grid[here.row][here.col] + 1;
				//cout<<nbr.col<<"   "<<nbr.row<<endl;//��ʾ����  
			}
			if ((nbr.row == finish.row) && (nbr.col == finish.col)) break; //��ɲ���  
			Q.push(nbr);
		}

		//�Ƿ񵽴�Ŀ��λ��finish��  
		if ((nbr.row == finish.row) && (nbr.col == finish.col)) break;//��ɲ���  
																	  //��������Ƿ�ǿգ�  
		if (Q.empty()) return false;//�޽�  
		here = Q.front();
		Q.pop();//ȡ��һ����չ���  


		indexcount++;
		// cout<<"��һ�ڵ�"<<indexcount<<endl;  
	} while (true);
	
	//������̲���·��  
	PathLen = grid[finish.row][finish.col];
	path = new Position[PathLen];
	//��Ŀ��λ��finish��ʼ����ʼλ�û���  
	here = finish;
	for (int j = PathLen - 1; j >= 0; j--)
	{
		path[j] = here;
		//��ǰ��λ��  
		for (int i = 0; i<NumOfNbrs; i++)
		{
			nbr.row = here.row + offset[i].row;
			nbr.col = here.col + offset[i].col;
			if (grid[nbr.row][nbr.col] == j)
			{
				// cout<<j<<endl;  
				break;
			}
		}
		here = nbr;//��ǰ�ƶ�  
	}
	return PathLen;
}
int main()
{
	Position start;
	start.col = 1;
	start.row = 1;
	cout << "�������" << endl;
	cout << start.col << " " << start.row << endl;
	Position finish;
	finish.row = 3;
	finish.col = 4;
	cout << "���߽�����" << endl;
	cout << finish.col << " " << finish.row << endl;
	int PathLen = 0;
	Position *path;

	FindPath(start, finish, PathLen, path);
	cout << "���ߺ�·��ͼ" << endl;
	showPath();
	cout << "·��" << endl;
	for (int i = 0; i<PathLen; i++)
	{
		cout << path[i].col << " " << path[i].row << endl;
	}
	cout << "�����������!" << endl;
	return 0;
}
