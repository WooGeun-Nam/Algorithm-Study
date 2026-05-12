#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) 
{
    // 테이블은 모두 정수 타입 및 2차원 행렬
    // 열 : col , 행 : 튜플
    // 첫번째 열은 기본키
    
    // col번째 값을 기준으로 오름차순, col 값이 같으면 첫번째 값을 기준으로 오름차순
    sort(data.begin(), data.end(), [col](const vector<int>& a, const vector<int>& b) {
        // a 행, b 행 비교 및 정렬
        // col 값 비교 후 값이 다르면 오름차순
        if (a[col - 1] != b[col - 1]) {
            return a[col - 1] < b[col - 1];
        }

        // 값이 같으면 내림차순
        return a[0] > b[0]; 
    });
    
    int answer = 0;
    // S_i = i번째 행 의 튜플들에 대해서 i 로 나눈 나머지의 합
    for(int i = 0; i < data.size(); i++)
    {
        int sum = 0;
        // 행값 (i)
        int row = i + 1;
        if(row >= row_begin && row <= row_end)
        {
            for(int j = 0; j < data[i].size(); j++)
            {
                sum += data[i][j] % row;
            }
            
            // xor 누적
            answer = answer ^ sum;
        }
    }
    
    
    return answer;
}