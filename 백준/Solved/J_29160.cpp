// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;


struct Player {
    int id;
    int p;
    int w;
};

int main()
{
    int n,k;
    int answer = 0;
    vector<Player> player; 
    cin >> n >>k;
    
    for (int i = 0; i < n; i++){
        int p,w;
        cin >> p >> w;
        player.push_back({i, p, w});
    }
    
    map<int,pair<int,int>> team;
    
    
    for (int i = 1; i < 12; i++) {
        team[i] = {0,0};
    }
    
    while(k--){
        for (int i = 0; i < n; i++){
            if(player[i].w >= team[player[i].p].second){
                team[player[i].p] = {player[i].id, player[i].w};
            }
        }
        for (int i = 1; i < 12; i++) {
           
            player[team[i].first].w -= 1;
            team[i].second -= 1;
            
            if(player[team[i].first].w < 0){
                player[team[i].first].w = 0;
                team[i].second = 0;
                
            }
        }
        
        

    }
    
    for (int i = 0; i < n; i++){
            if(player[i].w >= team[player[i].p].second){
                team[player[i].p] = {player[i].id, player[i].w};
            }
    }
    
    for (int i = 1; i < 12; i++) {
           
        answer += team[i].second;
            
    }
    
 
    

    cout << answer;
    
    
}


