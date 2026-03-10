#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // memo
    vector<int> dp(n + 1, -1);
    dp[1] = 0;
    
    // 목표 값 찾기
    for(int i=1; i<n; i++)
    {
        int nextNumbers[] = {i + 1, i * 2, i * 3};
        
        for (int next : nextNumbers) 
        {
            // 찾는값보다 크면 검증할 필요 X
            if (next <= n) {
                // 초기값이면 대입
                if (dp[next] == -1) {
                    dp[next] = dp[i] + 1;
                }
                // 초기값이 아니면 비교
                else 
                {
                    dp[next] = min(dp[next], dp[i] + 1);
                }
            }
        }
    }
    
    cout << dp[n];
    return 0;
}