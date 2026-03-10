#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;



int main() {
    int n,t;
    cin >> t;

    while(t--){
    cin >> n;
    vector<pair<int,int>> v(41);

    v[0] = {1,0};
    v[1] = {0,1};

    for(int i=2;i<=n;i++){
        v[i].first = v[i-1].first + v[i-2].first;
        v[i].second = v[i-1].second + v[i-2].second;
    }

    cout << v[n].first << " " << v[n].second << endl;
    }
    
}