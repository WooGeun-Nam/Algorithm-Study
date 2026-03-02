#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    map<string, vector<string>> node;
    
    for (int i = 0; i < tickets.size(); i++)
    {
        string from = tickets[i][0];
        string to = tickets[i][1];
        node[from].push_back(to);
    }
    
    // 정렬
    for (auto& [from, dest] : node)
    {
        sort(dest.begin(), dest.end(), greater<string>());
    }
    
    stack<string> st;
    st.push("ICN");
    
    while (!st.empty())
    {
        string current = st.top();
        
        // 갈 곳이 있다면 계속 이동
        if (!node[current].empty())
        {
            string next = node[current].back();
            // 사용한 티켓 제거
            node[current].pop_back();
            st.push(next);
        }
        else
        {
            // 더 이상 갈 곳 없을 때 경로에 추가
            answer.push_back(current);
            st.pop();
        }
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}