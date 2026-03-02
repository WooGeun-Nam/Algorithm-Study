#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 정점개수 n, 간선 개수 m, 시작 정점 v
    int n, m;
    
    cin >> n >> m;
    
    vector<vector<int>> node(n + 1);
    vector<bool> used(n + 1, false);
    
    int answer = 0;
    
    for(int i=0; i<m; i++)
    {
        int from, to;
        cin >> from >> to;
        
        node[from].push_back(to);
        node[to].push_back(from);
    }
    
    for(int i=1; i<=n; i++)
    {
        // 방문하지 않은 정점이면 검사 시작
        if(used[i] == false)
        {
            // 연결요소 + 1
            answer++;
            
            // 연결된 모든 정점을 방문 처리
            queue<int> qu;
            qu.push(i);
            
            while (!qu.empty())
            {
                int cur = qu.front();
                qu.pop();
        
                if (used[cur]) continue;
        
                used[cur] = true;
        
                for (int next : node[cur])
                {
                    if (!used[next])
                    {
                        qu.push(next);
                    }
                }
            }
        }
    }
    
    cout << answer;
    
    return 0;
}