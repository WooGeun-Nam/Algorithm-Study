#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    int n,m;
    int cnt = 0;
    cin >> n >> m;
    
    vector<vector<int>> map(n+1);
    vector<bool> visited(n+1,false);
    
    for(int i = 0; i < m; i++){
        int to,from;
        cin >> to >>from;
        map[to].push_back(from);
        map[from].push_back(to);
    }

    for(int i = 1; i < n+1; i++){
        if(!visited[i]){
            
            cnt ++;
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
    cout << cnt;   
    
}