#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    // DP table
    vector<int> dp(k + 1, 0);

    // 기저 : 0원 = 1가지
    dp[0] = 1;

    // 상향식
    // 동전의 종류를 하나씩 추가
    for (int i = 0; i < n; i++)
    {
        int currentCoin = coins[i];
        
        // 동전의 개수제약 X
        // 현재 동전으로 만들 수 있는 금액부터 목표 금액까지 순차적으로 확인
        for (int j = currentCoin; j <= k; j++)
        {
            // 현재 경우의 수 :  currentCoin을 뺀 값의 경우의 수
            dp[j] = dp[j] + dp[j - currentCoin];
        }
    }
    
    cout << dp[k] << endl;

    return 0;
}