#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Data
{
    int x;
    int y;
    int distance;
};

int main()
{
    int m, n;
    cin >> m >> n;

    // m x n 사이즈
    vector<vector<int>> tomatos(n, vector<int>(m));
    queue<Data> q;
    int noTomato = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tomatos[i][j];

            if (tomatos[i][j] == 1)
            {
                q.push({ i, j, 0 });
            }
            else if (tomatos[i][j] == 0)
            {
                noTomato++;
            }
        }
    }

    int answer = 0;
    
    // BFS
    while (!q.empty())
    {
        Data cur = q.front();
        q.pop();

        int x = cur.x;
        int y = cur.y;
        int distance = cur.distance;
        
        if (distance > answer)
        {
            answer = distance;
        }

        // 상
        if (x - 1 >= 0 && tomatos[x - 1][y] == 0)
        {
            tomatos[x - 1][y] = 1;
            q.push({ x - 1, y, distance + 1 });
            noTomato--;
        }
        // 하
        if (x + 1 < n && tomatos[x + 1][y] == 0)
        {
            tomatos[x + 1][y] = 1;
            q.push({ x + 1, y, distance + 1 });
            noTomato--;
        }
        // 좌
        if (y - 1 >= 0 && tomatos[x][y - 1] == 0)
        {
            tomatos[x][y - 1] = 1;
            q.push({ x, y - 1, distance + 1 });
            noTomato--;
        }
        // 우
        if (y + 1 < m && tomatos[x][y + 1] == 0)
        {
            tomatos[x][y + 1] = 1;
            q.push({ x, y + 1, distance + 1 });
            noTomato--;
        }
    }

    if (noTomato > 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << answer << endl;
    }

    return 0;
}