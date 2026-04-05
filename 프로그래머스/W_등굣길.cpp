#include <vector>

using namespace std;

// BFS도 가능하지만 방향제한으로 인해 DP가 효율적?
int solution(int m, int n, vector<vector<int>> puddles) 
{
    int answer = 0;
    
    // 1,1 좌표 기준 -> n+1, m+1 사이즈 배열
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // 웅덩이 : -1
    for (auto puddle : puddles)
    {
        dp[puddle[1]][puddle[0]] = -1;
    }
    
    // 기저값
    dp[1][1] = 1;
    
    // 상향식
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // 시작지점 pass
            if (i == 1 && j == 1) 
            {
                continue;
            }
            
            // 웅덩이칸이면 경로 불가 및 pass
            if (dp[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            
            // 집 = 1,1 / 학교 m,n 고정 오른쪽 아래 방향만 존재
            // 위에서 오는 경우의 수
            int up = dp[i - 1][j];
            // 왼쪽에서 오는 경우의 수
            int left = dp[i][j - 1];
            
            // 최단경로에서 나누기
            dp[i][j] = (up + left) % 1000000007;
        }
    }
    
    // 학교 위치의 값 정답으로 반환
    answer = dp[n][m];
    return answer;
}