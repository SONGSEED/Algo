#include <cstdio>
using namespace std;

int n, k;
int dp[100001];
int coin[101] = {0,};

void solved(void)
{
	dp[0] = 1;
	
	for (int i =1; i<=n; i++)
	{
		for(int j = coin[i]; j <= k; j++) // coin[i]번쨰에 있는 동전으로 j를 만들 수 있는 경우의 수 구함 
		{
			dp[j] += dp[j-coin[i]]; // coin[i]에 있는 동전으로 j를 만들수 있는 경우를 dp에 저장 
									// ex) 1원으로 3원을 만드려면 dp[3] = dp[3] + dp[3-1]이 된다. 
									//현재의 결과에서 coin[i]를 사용했을때 남은 결과의 경우의수 더함 
		}
	}
}


int main(void)
{
	scanf("%d %d",&n,&k);	
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&coin[i]);	
	}
	solved();
	
	printf("%d\n",dp[k]);
	return 0;
}
