#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) 
{
    int answer = 0;

    int n = triangle.size();
    
    // n 크기만큼 dp 배열
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // 기저값
    dp[0][0] = triangle[0][0];
    
    // 상향식
    // dp[i][j] = triangle[i][j] + max(dp[i−1][j−1],dp[i−1][j])
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            // 왼쪽 끝
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
            // 오른쪽 끝
            else if (j == i)
            {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            }
            // 가운데
            else
            {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
    }
    
    // 최댓값 찾기
    
    for (int i = 0; i < n; i++)
    {
        if (dp[n - 1][i] > answer)
        {
            answer = dp[n - 1][i];
        }
    }
    return answer;
}