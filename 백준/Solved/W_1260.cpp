#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& node, int start)
{
    stack<int> st;
    vector<bool> visit(node.size(), false);

    st.push(start);

    while (!st.empty())
    {
        int cur = st.top();
        st.pop();

        if (visit[cur]) continue;

        visit[cur] = true;
        cout << cur << " ";

        // 스택은 먼저 추가되는 값이 마지막에 계산하므로 역순
        for (int i=node[cur].size()-1; i>=0; i--)
        {
            int next = node[cur][i];
            if (!visit[next])
            {
                st.push(next);
            }
        }
    }
    cout << endl;
}

void bfs(vector<vector<int>>& node, int start)
{
    queue<int> qu;
    vector<bool> visit(node.size(), false);

    qu.push(start);

    while (!qu.empty())
    {
        int cur = qu.front();
        qu.pop();

        if (visit[cur]) continue;

        visit[cur] = true;
        cout << cur << " ";

        // 작은 번호부터 방문
        for (int i=0; i<node[cur].size(); i++)
        {
            int next = node[cur][i];
            if (!visit[next])
            {
                qu.push(next);
            }
        }
    }
    cout << endl;
}

int main() {
    // 정점개수 n, 간선 개수 m, 시작 정점 v
    int n, m, v;
    
    cin >> n >> m >> v;
    
    vector<vector<int>> node(n + 1);
    
    for(int i=0; i<m; i++)
    {
        int from, to;
        cin >> from >> to;
        
        node[from].push_back(to);
        node[to].push_back(from);
    }
    
    // 정점 번호가 작은 것을 먼저 방문 => 정렬
    for (int i = 1; i <= n; i++)
    {
        sort(node[i].begin(), node[i].end());
    }
    
    dfs(node, v);
    bfs(node, v);
    
    return 0;
}