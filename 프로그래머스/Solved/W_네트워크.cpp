#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<vector<int>> node(n, vector<int>(n, 0));
    
    // 방문처리용 배열
    vector<bool> visited(n, false);
    
    queue<int> qu;
    
    for(int i=0; i<n; i++)
    {
        // 현재 체크하는 노드가 방문한 노드면 pass
        if(visited[i]) continue;
        
        // 시작노드 큐에 추가
        qu.push(i);
        
        // 연결된 네트워크를 방문 노드로 변환
        while(!qu.empty())
        {
            int cur = qu.front();
            qu.pop();
            
            if(visited[cur]) continue;
            visited[cur] = true;
            
            // 연결된 노드 다음 큐에 추가
            for(int j=0; j<computers[cur].size(); j++)
            {
                // 기준 노드는 다음큐에 추가 X
                if(cur == j) continue;
                if(computers[cur][j] == 1) qu.push(j);
            }
        }
        
        // 네트워크 추가
        answer++;
    }
    
    return answer;
}