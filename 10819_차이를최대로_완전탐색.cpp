#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

vector <int> result;
vector <int> A;
vector <bool> visited;

int N, Max = 0, sum;

void DFS(int cnt)
{
	if (cnt == N)
	{
		sum  = 0;
		for (int i = 0; i < result.size() - 1; i++)
		{
			sum += abs(result[i] - result[i + 1]);
		}
		if ( Max < sum)
			Max = sum;
		return;
	}
	
	for (int i = 0; i < N; i++)
	{
		if(visited[i] == false)
		{
			visited[i] = true;
			result.push_back(A[i]);
			DFS(cnt + 1);
			result.pop_back();
			visited[i] = false;
		}
	}
}


int main(void)
{
	int input;
	scanf("%d", &N);

	
	for (int i=0; i < N; i++)
	{
		scanf("%d", &input);
		A.push_back(input);
		visited.push_back(false);
	}
	
	DFS(0); 
	printf("%d\n", Max);
	return 0;
}
