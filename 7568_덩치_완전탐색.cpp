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
		scanf("%d %d",&x, &y); // ������,Ű �Է¹��� 
		v.push_back(pair<int, int>(x,y)); // ���Ϳ� �����Կ� Ű�� pair�� �Է� 
		res.push_back(1); // ����� ����� vector  
	}

	for (int i =0; i< N; i++)
	{
		for (int j=0; j < N; j++)
		{
			if (v[i].first < v[j].first && v[i].second < v[j].second) // ������ Ű�� �����԰� ������ Ŀ�� ��� ����  
				res[i]++;
		}
	}
	
	for(int i = 0; i < N; i++)
	{
		printf("%d ", res[i]);
	}
	return 0;

} 
