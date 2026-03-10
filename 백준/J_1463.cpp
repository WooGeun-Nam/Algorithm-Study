#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    queue<pair<int,int>> q;
    bool visited[1000010] = {false};

    // 연산 횟수
    q.push({n,0});
    visited[n] = true;

    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cur == 1){
            cout << cnt;
            break;
        }

        if(cur % 3 == 0 && !visited[cur/3]){
            q.push({cur/3, cnt+1});
            visited[cur/3] = true;
        }

        if(cur % 2 == 0 && !visited[cur/2]){
            q.push({cur/2, cnt+1});
            visited[cur/2] = true;
        }

        if(!visited[cur-1]){
            q.push({cur-1, cnt+1});
            visited[cur-1] = true;
        }
    }
}