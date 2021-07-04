#include <stdio.h> // 5개중에 3개 뽑기
#include <vector>

using namespace std;

vector <int> v;
vector <bool> visited(5, false);

void dfs(int idx, int cnt)
{
    if (cnt == 3)
    {
        for (int i = 0; i < 5; i++)
        {
            if (visited[i] == true)
                printf("%d ", v[i]);
        }
        printf("\n");
        return ;
    }

    for (int i = idx; i < 5; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            dfs(i , cnt + 1);
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

     dfs(0, 0);

    return 0;
}