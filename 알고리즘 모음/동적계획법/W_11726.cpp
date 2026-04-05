#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // n 크기 만큼 (테케 1회)
    vector<int> dp(n + 1, 0);

    // 초기값 설정
    dp[1] = 1;
    if (n >= 2)
    {
        // 세로2개
        // 가로2개
        // 2x2 정사각형1개
        dp[2] = 3;
    }

    // 상향식
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
    }

    cout << dp[n] << endl;

    return 0;
}