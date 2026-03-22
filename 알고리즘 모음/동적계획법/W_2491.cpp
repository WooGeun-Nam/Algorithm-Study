#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> numbers;
    
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        int number;
        cin >> number;
        numbers.push_back(number);
    }
    
    int maxCount = 1; // n-1 로 검증하기 때문에 최소길이 1
    int upCount = 1;  // 증가수열
    int downCount = 1; // 감소수열
    
    for(int i=0; i<n-1; i++) {
        // 커지는 경우
        if(numbers[i] < numbers[i+1]) 
        {
            upCount++;
            downCount = 1; // 감소수열 초기화
        }
        // 작아지는 경우
        else if(numbers[i] > numbers[i+1]) 
        {
            downCount++;
            upCount = 1; // 증가수열 초기화
        }
        // 이전값과 같을 때
        else 
        {
            upCount++;
            downCount++;
        }

        // maxCount 갱신
        if(upCount > maxCount) maxCount = upCount;
        if(downCount > maxCount) maxCount = downCount;
    }
    
    cout << maxCount;
}