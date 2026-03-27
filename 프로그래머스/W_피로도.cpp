#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct State 
{
    int k;
    int count;           
    vector<bool> visit;
};

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int n = dungeons.size();
    
    stack<State> s;

    // 초기 상태 push
    s.push({k, 0, vector<bool>(n, false)});

    while (!s.empty()) 
    {
        State cur = s.top();
        s.pop();

        // 확인 한 던전 수 최대인지 확인
        answer = max(answer, cur.count);

        // 다음 갈 수 있는 던전 확인
        for (int i = 0; i < n; i++) 
        {
            // 방문하지 않고 피로도 조건이 맞는 던전
            if (!cur.visit[i] && cur.k >= dungeons[i][0]) 
            {
                vector<bool> next_visit = cur.visit;
                next_visit[i] = true;
                
                s.push({
                    cur.k - dungeons[i][1], // 남은 피로도
                    cur.count + 1,          // 탐험 횟수
                    next_visit              // 방문기록 전달
                });
            }
        }
    }

    return answer;
}