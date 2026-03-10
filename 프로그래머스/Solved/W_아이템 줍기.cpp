#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pos
{
    int x;
    int y;
    int dist;
};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    // 제한사항 50, 미리 맵 생성, 계산 편의를 위해 102크기로
    vector<vector<int>> map(102, vector<int>(102, 0));
    
    int mapX = 0;
    int mapY = 0;
    
    // 사각형 영역 설정
    for(int n=0; n<rectangle.size(); n++)
    {
        int minX = rectangle[n][0]*2;
        int minY = rectangle[n][1]*2;
        int maxX = rectangle[n][2]*2;
        int maxY = rectangle[n][3]*2;
        
        // 맵 크기 최신화
        mapX = max(mapX, maxX);
        mapY = max(mapY, maxY);
        
        // 사각형 영역 Fill
        for(int i=minX; i<=maxX; i++)
        {
            for(int j=minY; j<=maxY; j++)
            {
                map[i][j] = 1;
            }
        }
    }
    
    // 사각형 내부를 0으로 (외곽선만 남기기)
    for(int n=0; n<rectangle.size(); n++)
    {
        for(int i=rectangle[n][0]*2+1; i<rectangle[n][2]*2; i++)
        {
            for(int j=rectangle[n][1]*2+1; j<rectangle[n][3]*2; j++)
            {
                map[i][j] = 0;
            }
        }
    }
    
    // 최단거리 BFS
    queue<Pos> q;
    q.push({characterX*2, characterY*2, 0});
    map[characterX*2][characterY*2] = 2;
    
    while(!q.empty())
    {
        Pos cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        int dist = cur.dist;
        
        // 현재 위치가 아이템 위치면 종료
        if(x == itemX*2 && y == itemY*2)
        {
            answer = dist/2;
            break;
        }
        
        // 외곽선만 이동 가능
        // 이동 및 방문처리(2로)
        if(x-1 >= 0 && map[x-1][y] == 1) 
        {
            map[x-1][y] = 2;
            q.push({x-1, y, dist+1});
        }
        if(x+1 <= 101 && map[x+1][y] == 1) 
        {
            map[x+1][y] = 2;
            q.push({x+1, y, dist+1});
        }
        if(y-1 >= 0 && map[x][y-1] == 1) 
        {
            map[x][y-1] = 2;
            q.push({x, y-1, dist+1});
        }
        if(y+1 <= 101 && map[x][y+1] == 1) 
        {
            map[x][y+1] = 2;
            q.push({x, y+1, dist+1});
        }
    }
    
    return answer;
}