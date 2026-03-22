#include <iostream>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int start = n/5;
    int fiveKg = 0;
    int threeKg = 0;
    
    // 5킬로 봉지 최대치부터 아래로 검사
    for(int i=start; i>-1; i--)
    {
        int remain = n - (i * 5);
        
        // 남은 n이 3으로 나누어 떨어지면
        if(remain%3 == 0)
        {
            fiveKg = i;
            threeKg = remain/3;
            // 검사 종료
            break;
        }
    }
    
    int answer = fiveKg + threeKg;
    if(answer == 0) answer = -1;
    
    cout << answer;
}