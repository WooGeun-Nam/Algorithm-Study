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
    
    vector<vector<int>> map(n, vector<int>(n, 0));
    
    vector<int> answer;
    
    for(int i=0; i<n; i++)
    {
        string line;
        cin >> line;
        
        for(int j=0; j<n; j++)
        {
            // char 값을 int 로 저장
            map[i][j] = line[j] - '0';
        }
    }
    
    // 아파트 한동 씩 점검
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            // 현재동이 단지에 속해있지 않고, 아파트면 점검
            if(map[i][j] == 1)
            {
                // 단지 추가
                int apartSize = 0;
                
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
                    
                    // 1이 아니면 아파트가 아니거나 점검한 칸이므로 pass
                    if (map[x][y] != 1) continue;
                    
                    // 점검완료 : 2
                    map[x][y] = 2;
                    // 단지 크기 추가
                    apartSize++;
            
                    // 4방향 전이 추가
                    if(x-1 >= 0) qu.push({x-1, y});
                    if(x+1 < n) qu.push({x+1, y});
                    if(y-1 >= 0) qu.push({x, y-1});
                    if(y+1 < n) qu.push({x, y+1});
                }
                
                // 단지 구성이 끝났을때 정답에 추가
                answer.push_back(apartSize);
            }
        }
    }
    
    // 정렬
    sort(answer.begin(), answer.end());
    
    // 정답 출력
    cout << answer.size() << endl;
    for(int i : answer)
    {
        cout << i << endl;
    }
    
    return 0;
}