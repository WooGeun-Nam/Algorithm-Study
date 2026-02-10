#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    
    // n : 선수 수 , k : k년 만큼 진행
    int n, k;
    cin >> n >> k;
    
    // 포지션은 11까지 존재 하므로 11+1
    vector<priority_queue<int>> player(12);
    
    // 선수 수 만큼 입력 받기
    // 선수별 포지션, 선수 가치
    for(int i=0; i<n; i++)
    {
        int position;
        int value;
        cin >> position >> value;
        
        player[position].push(value);
    }
    
    // K년 까지 선수 가치 하락 계산
    for(int i=0; i<k; i++)
    {
        for(int j=1; j<=11; j++)
        {
            // 해당 포지션에 선수가 1명이라도 있으면 계산
            if (!player[j].empty()) {
                int value = player[j].top();
                player[j].pop();
                if (value > 0) value--;
                player[j].push(value);
            }
        }
    }
    
    int answer = 0;
    // 마지막 선수 가치가 가장 높은 선수 선발
    for(int i=1; i<=11; i++)
    {
        if (!player[i].empty()) {
            answer += player[i].top();
        }
    }
    
    cout << answer;
    
    return 0;
}