#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<vector<int>> map(n+1);
    vector<bool> visited(n+1,false);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            if (i == j) continue;
            if (computers[i][j] == 0) continue;
            int to = i + 1;
            int from = j + 1;
            map[to].push_back(from);
            map[from].push_back(to);
        }
    }

    for(int i = 1; i < n+1; i++){
        if(!visited[i]){
            
            answer ++;
            stack<int> st;
            st.push(i);
            visited[i] = true;

            while(!st.empty()){
                int cur = st.top();
                st.pop();
                
                for(int j = 0; j < map[cur].size(); j++){
                    if(!visited[map[cur][j]]){
                        visited[map[cur][j]] = true;
                        st.push(map[cur][j]);
                    }
                }
                    
            }
        }
    }
    

    return answer;
}