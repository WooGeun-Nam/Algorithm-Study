#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Pos{
    int x;
    int y;
};

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> originalMap(n, vector<int>(n, 0));
    
    // 최대 높이
    int maxHeight = 0;
    
    int answer = 0;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int x;
            cin >> x;
            
            maxHeight = max(maxHeight, x);
            originalMap[i][j] = x;
        }
    }
    
    int curHeight = maxHeight - 1;
    
    while(curHeight >= 0)
    {
        // 다음 높이 계산을 위해 맵을 복사해서 사용
        vector<vector<int>> map;
        map = originalMap;
        
        // 안전영역 개수
        int safeArea = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(map[i][j] > curHeight)
                {
                    // 안전영역 개수 추가
                    safeArea++;
                    
                    // 연결된 모든 정점 방문 처리
                    queue<Pos> qu;
                    // 현재 좌표를 출발지점으로
                    qu.push({i, j});
                    
                    while (!qu.empty())
                    {
                        Pos cur = qu.front();
                        qu.pop();
                        int x = cur.x;
                        int y = cur.y;
                        
                        // 물에 잠긴영역이면 pass
                        if (map[x][y] <= curHeight) continue;
                        
                        // 점검완료 : 0 , 잠긴영역 처리 되게끔
                        map[x][y] = 0;
                
                        // 4방향 전이 추가
                        if(x-1 >= 0) qu.push({x-1, y});
                        if(x+1 < n) qu.push({x+1, y});
                        if(y-1 >= 0) qu.push({x, y-1});
                        if(y+1 < n) qu.push({x, y+1});
                    }
                }
            }
        }
        
        // 최대 안전영역 개수 체크
        answer = max(answer, safeArea);
        
        // 다음 계산할 높이 감소
        curHeight--;
    }
    
    cout << answer;
    
    return 0;
}