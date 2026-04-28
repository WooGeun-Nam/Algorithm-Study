#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) 
{
    if (N == number) return 1;

    // 각 단계마다 만들어지는 숫자 뭉치를 담을 바구니
    // 정렬이 필요 없으므로 unordered_set 사용
    vector<unordered_set<int>> dp(9);

    int baseValue = 0;
    for (int i = 1; i <= 8; i++) 
    {
        baseValue = baseValue * 10 + N;
        dp[i].insert(baseValue);
    }

    // 상향식으로 조합 생성
    for (int i = 1; i <= 8; i++) 
    {
        for (int j = 1; j < i; j++) 
        {
            // dp[j]와 dp[i-j]의 모든 원소를 꺼내 조합
            for (int x : dp[j]) 
            {
                for (int y : dp[i - j]) 
                {
                    dp[i].insert(x + y);
                    dp[i].insert(x - y);
                    dp[i].insert(x * y);
                    if (y != 0) dp[i].insert(x / y);
                }
            }
        }

        // 목표 숫자가 바구니에 들어있는지 확인
        if (dp[i].count(number)) 
        {
            return i;
        }
    }

    return -1;
}