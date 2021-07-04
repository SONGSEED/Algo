#include <stdio.h> // 5개중에 3개 뽑기
#include <vector>

using namespace std;

vector <int> v;
vector <int> result;
vector <bool> visited(5, false);

void dfs(int cnt)
{
    if (cnt == 3)
    {
        for (int i = 0; i < result.size(); i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
        return ;
    }

    for (int i = 0; i < 5; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            result.push_back(v[i]);
            dfs(cnt + 1);
            result.pop_back();
            visited[i] = false;
        }
    }
}



int main(void)
{
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

     dfs(0);

    return 0;
}