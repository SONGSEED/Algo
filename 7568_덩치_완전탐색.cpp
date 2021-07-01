#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int x,y;
	vector <pair<int, int> > v;
	vector <int> res;
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d",&x, &y); // 몸무게,키 입력받음 
		v.push_back(pair<int, int>(x,y)); // 벡터에 몸무게와 키를 pair로 입력 
		res.push_back(1); // 등수를 계산한 vector  
	}

	for (int i =0; i< N; i++)
	{
		for (int j=0; j < N; j++)
		{
			if (v[i].first < v[j].first && v[i].second < v[j].second) // 상대방의 키와 몸무게가 나보다 커야 등수 증가  
				res[i]++;
		}
	}
	
	for(int i = 0; i < N; i++)
	{
		printf("%d ", res[i]);
	}
	return 0;

} 
