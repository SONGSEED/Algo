#include <stdio.h>
#include <vector>
vector <int> oper(4);  
int max = INT_MIN;
int min = INT_MAX;

int main(void)
{
	int N;
	scanf("%d", &N);
	vector <int> v(N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &v[i]);
	}
	
	for(int i = 0; i < 4; i++)
	{
		scanf("%d", &oper[i]);
	}
	
	
	return 0;
}
