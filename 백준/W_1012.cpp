#include <iostream>
#include <queue>

using namespace std;

struct Pos{
    int x;
    int y;
};

int main() {
    int test;
    cin >> test;
    
    for(int t=0; t<test; t++)
    {
        // x, y, 배추 개수
        int m, n, k;
        cin >> m >> n >> k;
        
        int answer = 0;
    
        // 2차원 배열 MxN 사이즈를 0으로 초기화
        vector<vector<int>> map(m, vector<int>(n, 0));
        
        for(int i=0; i<k; i++)
        {
            int x, y;
            cin >> x >> y;
            
            map[x][y] = 1;
        }
        
        // 전체 밭을 한칸씩 점검
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                // 현재칸이 배추가 심어져있고 점검받지 않은 칸이면
                if(map[i][j] == 1)
                {
                    // 지렁이추가
                    answer++;
                    
                    // 연결된 모든 정점(배추)를 방문 처리
                    queue<Pos> qu;
                    // 현재 좌표를 출발지점으로
                    qu.push({i, j});
                    
                    while (!qu.empty())
                    {
                        Pos cur = qu.front();
                        qu.pop();
                        int x = cur.x;
                        int y = cur.y;
                        
                        // 1이 아니면 배추가 아니거나 점검한 칸이므로 pass
                        if (map[x][y] != 1) continue;
                        
                        // 점검완료 : 2
                        map[x][y] = 2;
                
                        // 4방향 전이 추가
                        if(x-1 >= 0) qu.push({x-1, y});
                        if(x+1 < m) qu.push({x+1, y});
                        if(y-1 >= 0) qu.push({x, y-1});
                        if(y+1 < n) qu.push({x, y+1});
                    }
                }
            }
        }
        
        cout << answer << endl;
    }
    
    return 0;
}