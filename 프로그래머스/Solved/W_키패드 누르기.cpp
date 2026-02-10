#include <string>
#include <vector>

using namespace std;

int calDistance(int posX, int posY, int nextX, int nextY)
{
    int maxX = max(posX, nextX);
    int minX = min(posX, nextX);
    
    int maxY = max(posY, nextY);
    int minY = min(posY, nextY);
    
    return (maxX-minX) + (maxY-minY);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    // 123 456 789 *0#
    // * = 10, # = 11
    // 147* 왼손, 369# 오른손
    int leftPos = 10;
    int rightPos = 11;
    vector<pair<int, int>> keypad =
    {
        {4, 2}, {1, 1}, {1, 2}, {1, 3},
        {2, 1}, {2, 2}, {2, 3}, {3, 1},
        {3, 2}, {3, 3}, {4, 1}, {4, 3}
    };
    
    for(int i=0; i<numbers.size(); i++)
    {
        // false : left , true : right
        bool pressButton = false;
        int num = numbers[i];
        if(num == 1 || num == 4 || num == 7) pressButton = false;
        else if(num == 3 || num == 6 || num == 9) pressButton = true;
        
        // 중간 키패드면 검증 로직
        else 
        {
            int nextPosX = keypad[num].first;
            int nextPosY = keypad[num].second;
            
            int leftPosX = keypad[leftPos].first;
            int leftPosY = keypad[leftPos].second;
            
            int rightPosX = keypad[rightPos].first;
            int rightPosY = keypad[rightPos].second;
            
            // 거리 계산
            int leftDis = calDistance(leftPosX, leftPosY, nextPosX, nextPosY);
            int rightDis = calDistance(rightPosX, rightPosY, nextPosX, nextPosY);
            
            // 두손의 거리가 같으면 hand 처리
            if(leftDis == rightDis)
            {
                if(hand == "left") pressButton = false;
                else pressButton = true;
            }
            else if(leftDis < rightDis) pressButton = false;
            else pressButton = true;
        }
        
        // 버튼 누르기
        if(!pressButton) 
        {
            answer += "L";
            leftPos = num;
        }
        else
        {
            answer += "R";
            rightPos = num;
        }
    }
    
    return answer;
}