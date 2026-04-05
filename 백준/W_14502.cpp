#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pos
{
    int x;
    int y;
};

int main()
{
    int n, m;
    cin >> n >> m;

    // n x m
    vector<vector<int>> originMap(n, vector<int>(m));
    vector<Pos> zeroList;
    vector<Pos> viruses;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> originMap[i][j];
            
            // 빈칸 좌표
            if (originMap[i][j] == 0)
            {
                zeroList.push_back({ i, j });
            }
            // 바이러스 좌표
            else if (originMap[i][j] == 2)
            {
                viruses.push_back({ i, j });
            }
        }
    }

    int answer = 0;
    int zeroSize = zeroList.size();

    // 벽 3개 경우의 수 i, j, k
    for (int i = 0; i < zeroSize; i++)
    {
        for (int j = i + 1; j < zeroSize; j++)
        {
            for (int k = j + 1; k < zeroSize; k++)
            {
                // 데이터 복사
                vector<vector<int>> map = originMap;
                
                // 벽 설치
                map[zeroList[i].x][zeroList[i].y] = 1;
                map[zeroList[j].x][zeroList[j].y] = 1;
                map[zeroList[k].x][zeroList[k].y] = 1;

                // BFS 바이러스 확산
                queue<Pos> qu;
                for (Pos v : viruses)
                {
                    qu.push(v);
                }

                vector<vector<bool>> visit(n, vector<bool>(m, false));

                while (!qu.empty())
                {
                    Pos cur = qu.front();
                    qu.pop();

                    int x = cur.x;
                    int y = cur.y;

                    // 방문했거나 벽인 경우 pass
                    if (visit[x][y]) continue;
                    if (map[x][y] == 1) continue;

                    visit[x][y] = true;
                    if (map[x][y] == 0)
                    {
                        map[x][y] = 2;
                    }

                    // 4방향 체크
                    if (x - 1 >= 0) qu.push({ x - 1, y });
                    if (x + 1 < n) qu.push({ x + 1, y });
                    if (y - 1 >= 0) qu.push({ x, y - 1 });
                    if (y + 1 < m) qu.push({ x, y + 1 });
                }

                // 안전 영역 개수 계산
                int safeArea = 0;
                for (int r = 0; r < n; r++)
                {
                    for (int c = 0; c < m; c++)
                    {
                        if (map[r][c] == 0)
                        {
                            safeArea++;
                        }
                    }
                }

                // 크면 갱신
                if (safeArea > answer)
                {
                    answer = safeArea;
                }
            }
        }
    }
    
    cout << answer << endl;

    return 0;
}