// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include<vector>
#include<string>
#include<set>
#include <queue>

using namespace std;


int main()
{
    int n, p;
    cin >> n >> p;
    
    
    vector<vector<int>> v; //컴퓨터 쌍
    set<int> s; //중복 없이 바이러스 컴퓨터 수
    queue<int> q; 

    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    
    // 1번 컴퓨터 부터
    q.push(1); 
    s.insert(1);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < p; i++) {
            int a = v[i][0];
            int b = v[i][1];

            //  cur이 a일때 b가 set에 없으면 넣기
            if (a == cur && s.find(b) == s.end()) {
                s.insert(b);
                q.push(b);
            }
            // cur이 b일때 a가 set에 없으면 넣기
            else if (b == cur && s.find(a) == s.end()) {
                s.insert(a);
                q.push(a);
            }
        }
    }
    
    // 1번컴 빼고
    cout << s.size() - 1 ;
    
    return 0;
}