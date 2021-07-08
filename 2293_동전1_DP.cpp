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
		for(int j = coin[i]; j <= k; j++) // coin[i]������ �ִ� �������� j�� ���� �� �ִ� ����� �� ���� 
		{
			dp[j] += dp[j-coin[i]]; // coin[i]�� �ִ� �������� j�� ����� �ִ� ��츦 dp�� ���� 
									// ex) 1������ 3���� ������� dp[3] = dp[3] + dp[3-1]�� �ȴ�. 
									//������ ������� coin[i]�� ��������� ���� ����� ����Ǽ� ���� 
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
