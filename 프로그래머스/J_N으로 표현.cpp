#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    vector<set<int>> dp(9);
    
    for (int i = 1; i <= 8; i++) {

        int numbers = 0;
        for (int j = 0; j < i; j++) {
            numbers = numbers * 10 + N;
        }
        dp[i].insert(numbers);

        for (int j = 1; j < i; j++) {
            for (int a : dp[j]) {
                for (int b : dp[i - j]) {
                    
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    // b가 0이 아닌 경우
                    if (b != 0) {
                        dp[i].insert(a / b);
                    }
                }
            }
        }

        // 현재 카운트 숫자 확인
        if (dp[i].count(number)) {
            return i;
        }
    }

    return -1;
}