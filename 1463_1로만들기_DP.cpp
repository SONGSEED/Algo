#include <cstdio>
#include <algorithm>
using namespace std;

int dp1[1000001]; //최소횟수 저장할 dp배열 
int dp2[1000001];
//top-down, recursion 
int solve1(int N)
{

	if ( N == 1) return 0;
	if ( dp1[N] > 0) return dp1[N];
	
	dp1[N] = solve1(N - 1) + 1;
	if ( N % 3 == 0) dp1[N] = min(solve1(N/3)+1, dp1[N]);
	if ( N % 2 == 0) dp1[N] = min(solve1(N/2)+1, dp1[N]);
	
	return dp1[N];
}
//bottom-up
void solve2(int N)
{
	dp2[1] = 0;
	
	for (int i = 2; i <= N; i++)
	{
		dp2[i] = dp2[i-1] + 1;
		if (i%3 == 0) dp2[i] = min(dp2[i/3]+1, dp2[i]);
		if (i%2 == 0) dp2[i] = min(dp2[i/2]+1, dp2[i]);
	}
}


int main(void)
{
	int N;
	scanf("%d",&N);
	
	solve1(N);
	solve2(N);
	
	printf("%d %d\n", dp1[N], dp2[N]);

	return 0;
}
