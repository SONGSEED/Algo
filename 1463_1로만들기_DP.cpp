#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1000001];

int solve(int N)
{
	int cnt;
	
	if ( N == 1) return 0;
	if ( dp[N] > 0) return dp[N];
	
	cnt = solve(N - 1) + 1;
	if ( N % 3 == 0) cnt = min(solve(N/3)+ 1, cnt);
	if ( N % 2 == 0) cnt = min(solve(N/2) +1, cnt);
	
	dp[N] = cnt;
	
	return cnt;
}


int main(void)
{
	int N;
	scanf("%d",&N);
	
	solve(N);
	
	printf("%d\n", dp[N]);
	return 0;
}
