#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int arr[21][21] = {0,};
int N = 0;
vector <bool> visited(21); // 중복 계산 판단할 벡터 
int Min = 21470000;
vector <int> start, link; //팀 조합 계산할 벡터 

void calculate_min(void)
{
	int start_score = 0, link_score = 0;
	
	for(int i = 0; i < N; ++i)
	{
		if (visited[i] == true)
			start.push_back(i);
		else
			link.push_back(i);
	}
	
	for (int i = 0; i < (N/2); ++i)
	{
		for (int j = 0; j < (N/2); ++j)
		{//start, link팀 능력치의 합  
			start_score += arr[start[i]][start[j]];
			link_score += arr[link[i]][link[j]];
		}
	}
	 //최소값 구하기  
	
	start.clear();
	link.clear();

	Min = min(Min,abs(start_score - link_score));
	return ;
}


void DFS(int idx, int cnt)
{
	// 팀 2개로 나누기  
	if (cnt == (N / 2))
	{
		calculate_min();
		return;
	}
	
	for (int i = idx; i < N; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			DFS(i + 1, cnt + 1); // i + 1; 
			visited[i] = false;
		}
	}
		
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	DFS(0, 0);
	printf("%d\n", Min);
	
	return 0;
}
