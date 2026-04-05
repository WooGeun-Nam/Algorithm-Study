#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int BFS(int start, int n, const vector<vector<int>>& connected) 
{
    int count = 0;
    vector<bool> visit(n + 1, false);
    queue<int> q;

    q.push(start);
    visit[start] = true;
    count++;

    while (!q.empty()) 
    {
        int cur = q.front();
        q.pop();

        for (int next : connected[cur]) 
        {
            if (!visit[next]) 
            {
                visit[next] = true;
                q.push(next);
                count++;
            }
        }
    }
    return count;
}

void disconnect(vector<int>& towers, int target) 
{
    // 값 찾아서 삭제
    towers.erase(remove(towers.begin(), towers.end(), target), towers.end());
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    // 2차원 배열에 번호에 맞게 변경
    vector<vector<int>> connected(n + 1);
    for (auto& wire : wires) 
    {
        connected[wire[0]].push_back(wire[1]);
        connected[wire[1]].push_back(wire[0]);
    }

    // 연결을 하나씩 끊어 보며 확인
    for (auto& wire : wires) 
    {
        int startPoint1 = wire[0];
        int startPoint2 = wire[1];

        // 연결 끊기
        disconnect(connected[startPoint1], startPoint2);
        disconnect(connected[startPoint2], startPoint1);

        // 한쪽영역 노드 개수세기
        int count1 = BFS(startPoint1, n, connected);
        int count2 = n - count1; // 반대 영역 개수
        
        // 최솟값인지 확인
        answer = min(answer, abs(count1 - count2));

        // 노드 다시 연결
        connected[startPoint1].push_back(startPoint2);
        connected[startPoint2].push_back(startPoint1);
    }

    return answer;
}