#include <cstdio>

int main(void)
{
	int N,M;
	int arr[100] = {0,};
	int sum = 0, max = 0;
	scanf("%d %d",&N, &M);
	
	for(int i = 0; i < N; i++)
	{
		scanf("%d ", &arr[i]);	
	}
	
	for(int i = 0; i < N - 2; i++)
	{
		for(int j = i + 1; j < N - 1; j++)
		{
			for(int k = j + 1; k < N; k++)
			{
				sum = arr[i] + arr[j] + arr[k];
				if (sum <= M && sum < max)
					max = sum;
			}
		}
	}
	printf("%d\n", max);
	return 0;
}
