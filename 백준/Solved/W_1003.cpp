#include <iostream>

using namespace std;

struct FiboCount {
    int zero = 0;
    int one = 0;
};

FiboCount dp[41];

// 상향식으로 미리 계산
void fibonacci(int n)
{
    // 0 기본값 = 0
    dp[0].zero = 1;
    dp[0].one = 0;
    // 1 기본값 = 1
    dp[1].zero = 0;
    dp[1].one = 1;
    
    for(int i=2; i<= n; i++)
    {
        dp[i].zero = dp[i-1].zero + dp[i-2].zero;
        dp[i].one = dp[i-1].one + dp[i-2].one;
    }
}

int main() {
    int t, n;
    cin >> t;

    // 문제 범위 40
    fibonacci(40);

    while (t--) {
        cin >> n;
        
        cout << dp[n].zero << " " << dp[n].one << endl;
    }
    return 0;
}