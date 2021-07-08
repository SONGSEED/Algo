#include <cstdio>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, k;
int dp[100001];
int coin[101];

void solved()
{
	dp[0] = 0;
	for(int i = 1; i <=n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			dp[j] = min(dp[j],dp[j-coin[i]]+1);
		}
	}
	
	if ( dp[k] == 100001)
		printf("-1\n");
	else
		printf("%d\n", dp[k]);
}

int main(void)
{
	scanf("%d %d",&n,&k);	
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&coin[i]);	
	}
	fill(dp, dp+100001, 100001);
	solved();
    
	return 0;
}
