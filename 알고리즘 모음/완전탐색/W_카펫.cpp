#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // 노란색 개수로 만들 수 있는 사각형 경우의 수
    for (int i = 1; i <= yellow; i++) 
    {
        // 노란색 개수가 i로 나누어 떨어지면
        // == 직사각형이 만들어질 때
        if (yellow % i == 0) 
        {
            int yellowH = i;
            int yellowW = yellow / i;
            
            // 갈색 개수가 노란색 직사각형에 맞으면 정답
            if (2 * yellowW + 2 * yellowH + 4 == brown) 
            {
                answer.push_back(yellowW + 2);
                answer.push_back(yellowH + 2);
                return answer;
            }
        }
    }
    
    return answer;
}