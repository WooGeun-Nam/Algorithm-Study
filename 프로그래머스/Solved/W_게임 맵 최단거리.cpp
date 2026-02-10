#include <vector>
#include <queue>
using namespace std;

// 0 = 벽, 1 = 길, 2 = visited
struct Data{
    int x;
    int y;
    int distance;
};

int solution(vector<vector<int>> maps)
{
    // queue 가 빌때까지 answer 를 찾지 못하면 -1
    int answer = -1;
    
    int n = maps.size();
    int m = maps[0].size();
    
    queue<Data> dt;
    dt.push({0, 0, 1});
    
    maps[0][0] = 2; // 시작 지점 방문 처리
    
    while(!dt.empty())
    {
        Data cur = dt.front();
        dt.pop();
        
        int x = cur.x;
        int y = cur.y;
        int distance = cur.distance;
        
        // 목적지 도착 체크 n,m
        if(x == n-1 && y == m-1)
        {
            // 가장 먼저 도착한 지점에서 검색 종료
            answer = distance;
            break;
        }
        
        // 상
        if(x-1 >= 0 && maps[x-1][y] == 1)
        {
            maps[x-1][y] = 2;
            dt.push({x-1, y, distance + 1});
        }
        // 하
        if(x+1 < n && maps[x+1][y] == 1)
        {
            maps[x+1][y] = 2;
            dt.push({x+1, y, distance + 1});
        }
        // 좌
        if(y-1 >= 0 && maps[x][y-1] == 1)
        {
            maps[x][y-1] = 2;
            dt.push({x, y-1, distance + 1});
        }
        // 우
        if(y+1 < m && maps[x][y+1] == 1)
        {
            maps[x][y+1] = 2;
            dt.push({x, y+1, distance + 1});
        }
    }
    
    return answer;
}