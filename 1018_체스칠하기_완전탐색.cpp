#include <stdio.h>
#include <vector>
#include <string>

using namespace std;
char board[51][51] = {0,};
//���� �ΰ��� ����  
char result1[8][9] = {"WBWBWBWB", //�������� �ι��� 
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"};

char result2[8][9] = { "BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"};

int check_result1(int x, int y);
int check_result2(int x, int y);

int main()
{
//	FILE *pFile = NULL;
//	pFile  = fopen("../Test.txt", "r");

	int N,M;
	int min = 64; 
	int cnt = 0;

	//fscanf(pFile,"%d %d\n", &N, &M);
	scanf("%d %d\n",&N,&M); 

	//���忡 �� �Է� , �迭�� '\n' ���� ���°� �� 
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
//			fscanf(pFile,"%c",&board[i][j]);
			scanf("%c",&board[i][j]);
		}
		scanf("\n"); //���� �Է� �������� , fflush(stdin); -> fflush�� �Է°��� ���� ���� ���°͵� ����
//		fscanf(pFile, "\n");
	}

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			cnt = 0;
			if ( check_result1(i, j) > check_result2(i, j))
			{
				cnt = check_result2(i, j);
			}
			else
			{
				cnt = check_result1(i, j);
			}
			if ( cnt < min)
				min = cnt;
		}
	}

	printf("%d\n",min);
//	fclose(pFile);
	return 0;
}

int check_result1(int x, int y)
{
	int cnt = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i + x][j + y] != result1[i][j])
				cnt++;
		}
	}

	return cnt;
}

int check_result2(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i + x][j + y] != result2[i][j])
				cnt++;
		}
	}

	return cnt;
}
