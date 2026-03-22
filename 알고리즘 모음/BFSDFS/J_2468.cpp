#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int n;
    set<int> s;
    int result = 1;
    cin >> n;
    
    vector<int> area;
    vector<vector<int>> map(n, vector<int>(n));
    // vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
            s.insert(map[i][j]);
        }
    }
    
    int mx[4] = {-1, 1, 0, 0};
    int my[4] = {0, 0, -1, 1};
    for (int h : s){
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(map[i][j] > h && !visited[i][j]){
                    cnt ++;
                    stack<pair<int,int>> st;
                    st.push({i,j});
                    visited[i][j] = true;

                    while(!st.empty()){
                        auto [x,y] = st.top();
                        st.pop();
                        for(int k = 0; k < 4; k++){
                            int xp = x + mx[k];
                            int yp = y + my[k];
                            
                            if(xp < 0 || xp >= n|| yp < 0 || yp >= n) continue;
                            if(visited[xp][yp]) continue;
                            if(map[xp][yp] <= h) continue;
                            
                            visited[xp][yp] = true;
                            st.push({xp, yp});
                        }
                    }
                }
            }
        }
        result = max(result, cnt);
    }
    cout << result << endl;
}

