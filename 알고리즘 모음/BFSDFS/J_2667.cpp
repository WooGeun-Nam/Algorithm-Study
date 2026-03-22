#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int cnt = 0;
    cin >> n;
    
    vector<int> area;
    vector<vector<int>> map(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            map[i][j] = s[j] - '0';
        }
    }
    
    int mx[4] = {-1, 1, 0, 0};
    int my[4] = {0, 0, -1, 1};
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 1 && !visited[i][j]){
                
                cnt ++;
                stack<pair<int,int>> st;
                st.push({i,j});
                visited[i][j] = true;
                int h = 0;
                while(!st.empty()){
                    auto [x,y] = st.top();
                    st.pop();
                    for(int k = 0; k < 4; k++){
                        int xp = x + mx[k];
                        int yp = y + my[k];
                        
                        if(xp < 0 || xp >= n|| yp < 0 || yp >= n) continue;
                        if(visited[xp][yp]) continue;
                        if(map[xp][yp] == 0) continue;
                        
                        visited[xp][yp] = true;
                        st.push({xp, yp});
                    }
                    h++;
                }
                area.push_back(h);
            }
        }
    }
    cout << cnt <<endl;
    sort(area.begin(), area.end());
    for(int i = 0; i < cnt; i++){
        cout << area[i] << "\n";
    }
}