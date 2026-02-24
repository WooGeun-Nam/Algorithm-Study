#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int m,n,k;
        int cnt = 0;
        cin >> m >> n >> k;
        
        vector<vector<int>> map(n, vector<int>(m,0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (int i = 0; i < k; i++){
            int num1,num2;
            cin >> num1 >> num2;
            map[num2][num1] = 1 ;
        }
        
        int mx[4] = {-1, 1, 0, 0};
        int my[4] = {0, 0, -1, 1};
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(map[i][j] == 1 && !visited[i][j]){
                    
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
                            
                            if(xp < 0 || xp >= n|| yp < 0 || yp >= m) continue;
                            if(visited[xp][yp]) continue;
                            if(map[xp][yp] == 0) continue;
                            
                            visited[xp][yp] = true;
                            st.push({xp, yp});
                        }

                    }

                }
            }
        }
        cout << cnt <<endl;
    } 
}