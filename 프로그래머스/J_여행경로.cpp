#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    //티켓을 내림차순으로 정렬
    sort(tickets.begin(), tickets.end(), greater<vector<string>>());
    
    //출발지 -> 목적지 맵 생성
    unordered_map<string, vector<string>> m;
    for(int i = 0; i < tickets.size(); i++){
        m[tickets[i][0]].push_back(tickets[i][1]);
    }

    stack<string> st;
    st.push("ICN");
    
    while (!st.empty()) {
        string cur = st.top();
        
        if (m[cur].empty()) {
            answer.push_back(cur);
            st.pop();
        } 
     
        else {
            st.push(m[cur].back());
            m[cur].pop_back();
        }
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}