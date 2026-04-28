// LCS : 최장 공통 부분 수열 <-> LIS : 최장 증가 부분 수열
// LCS : 모든 원소들이 연결(붙어)되어 있지 않아도 됨
// 두 개의 문자열의 비교 (공통 찾기) vs 한 개의 배열에 증가하는 순서

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    // DP table
    // dp[i][j]: s1의 i번째, s2의 j번째 문자까지 비교했을 때의 최대 길이
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // 상향식으로 표 채우기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 두 문자가 같은 경우: 공통 문자 발견
            if (s1[i - 1] == s2[j - 1]) {
                // 대각선 왼쪽 위(이전 상태) 결과에 1을 더함
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // 두 문자가 다른 경우: 기존 기록 유지
            else {
                // 위쪽(dp[i-1][j])과 왼쪽(dp[i][j-1]) 중 더 큰 값을 선택
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    cout << dp[n][m] << endl;

    return 0;
}