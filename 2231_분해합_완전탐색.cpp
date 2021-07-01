#include <iostream>
using namespace std;

int main()
{
	int N;
	int res, tmp;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		tmp = i;
		res = i;
		while ( tmp > 0 )
		{
			res += tmp % 10;
			tmp = tmp / 10;
		}
		
		if ( N == res)
		{
			printf("%d", i);
			return 0;
		}
	}
	
	return 0;
}
