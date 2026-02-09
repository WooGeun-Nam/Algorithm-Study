#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Data{
    int index;
    int value;
};

int solution(vector<int> numbers, int target) {
    
    int answer = 0;
    
    // 계산해야할 데이터
    stack<Data> dt;
    dt.push({0, numbers[0]});
    dt.push({0, -numbers[0]});
    
    while (!dt.empty()) {
        Data curData = dt.top();
        dt.pop();
        
        int index = curData.index;
        int value = curData.value;
        
        // 마지막 숫자까지의 합이 타겟인지 확인
        if(index == numbers.size() - 1)
        {
            if(value == target) answer++;
        }
        else
        {
            // 다음 인덱스
            int nextNumber = numbers[index+1];
            dt.push({index+1, value + nextNumber});
            dt.push({index+1, value - nextNumber});
        }
    }

    return answer;
}