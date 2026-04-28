#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> w(n + 1, 0);
    vector<int> v(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    // dp table
    vector<int> dp(k + 1, 0);

    // 상향식
    for (int i = 1; i <= n; i++)
    {
        // 무게를 역순으로 순회
        for (int j = k; j >= w[i]; j--)
        {
            // 기존 가치
            // 현재 물건 가치 + 남은 무게에 대한 이전의 최적 가치
            // 더 큰 값을 저장
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    // 결과 출력
    cout << dp[k] << endl;

    return 0;
}