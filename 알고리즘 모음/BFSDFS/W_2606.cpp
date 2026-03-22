#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    // 그래프 DFS, BFS
    int computer;
    int size;

    cin >> computer >> size;
    
    // 노드번호가 1부터
    vector<vector<int>> network(computer+1);
    
    for(int i=0; i<size; i++)
    {
        // 한쌍은 방향X 양쪽 연결
        int from;
        int to;
        cin >> from >> to;
        
        network[from].push_back(to);
        network[to].push_back(from);
    }
    
    // 감염여부
    vector<bool> virus(computer+1, false);
    // 1번 컴퓨터를 기준으로 탐색 본인 제외
    virus[1] = true;
    stack<int> search;
    search.push(1);
    
    // 전파된 횟수
    int answer = 0;
    while(!search.empty())
    {
        // 현재노드
        int cur = search.top();
        search.pop();
        
        // 연결된 노드에 전파
        for(int spread : network[cur])
        {
            if(virus[spread] == false) 
            {
                virus[spread] = true;
                answer++;
                search.push(spread);
            }
        }
    }
    
    cout << answer;
}