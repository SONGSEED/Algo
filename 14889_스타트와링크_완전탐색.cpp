#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int arr[21][21] = {0,};
int N = 0;
vector <int> team; //팀 조합 계산할 벡터 
vector <bool> visited; // 중복 계산 판단할 벡터 
int Min = 21470000;


void calculate_min(void)
{
	int start_team = 0, link_team = 0;

	for (int i = 0; i < N/2 - 1; i++)
	{
		for (int j = i; j < N/2 - 1; j++)
		{
			start_team = (arr[team[j]][team[j+1]] + arr[team[j+1]][team[j]]);
		//	printf("%d %d\n", team[j], team[j+1]);		
		}
	}
	for (int i = N/2; i < N - 1; i++)
	{
		for (int j = i; j < N - 1; j++)
		{
			link_team = (arr[team[j]][team[j+1]] + arr[team[j+1]][team[j]]);
		//	printf("%d %d\n", team[j], team[j+1]);
		}
	}
	
	if (Min > abs(start_team - link_team))
		Min = abs(start_team - link_team);
		
	return;	
}




void DFS(int cnt)
{
	if (cnt == N)
	{
	/*	for (int i = 0; i < N; i++)
		{
			printf("%d ", team[i]);
		}
		printf("\n");
	*/
		calculate_min();
	//	vector <int>::iterator iter;
		return;
	}
	
	for (int i = 0; i < N; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			team.push_back(i + 1);
			DFS(cnt + 1);
			team.pop_back();
			visited[i] = false;
		}
	}
	
	
}

int main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
		visited.push_back(false);
	}
	printf("\n");
	DFS(0);
	printf("%d\n", Min);
	
	return 0;
}
