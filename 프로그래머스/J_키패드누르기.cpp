#include <string>
#include <vector>
#include <map> 
#include <cmath>

using namespace std;

/*
00 01 02
10 11 12
20 21 22
30 31 33
*/

string solution(vector<int> numbers, string hand) {
    string answer = "";
    map<int, pair<int, int>> pose;
    
    // 숫자키 매핑
    pose[1]={0,0}; pose[2]={0,1}; pose[3]={0,2}; 
    pose[4]={1,0}; pose[5]={1,1}; pose[6]={1,2}; 
    pose[7]={2,0}; pose[8]={2,1}; pose[9]={2,2}; 
    pose[0]={3,1};
    
    // *, #
    pair<int, int> left = {3,0};
    pair<int, int> right = {3,2};
    
    
    
    for (int i = 0; i < numbers.size(); i++){
        
        // 1,4,7 무조건 left
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer.push_back('L');
            
            //왼손 위치
            left = pose[numbers[i]];
        }
        
        // 3,6,9 무조건 right
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer.push_back('R');
            
            //오른손 위치
            right = pose[numbers[i]];
        }
        else{
            
            // R -> 누를 번호와 오른손 간의 거리, L -> 누를 번호와 왼손간의 거리
            int R = abs(right.first - pose[numbers[i]].first) + abs(right.second - pose[numbers[i]].second);
            int L = abs(left.first - pose[numbers[i]].first) + abs(left.second - pose[numbers[i]].second);
            if(R < L ){
                answer.push_back('R');
                right = pose[numbers[i]];
            }
            else if(R > L ){
                answer.push_back('L');
                left = pose[numbers[i]];
            }
            else{
                if(hand == "right"){
                    answer.push_back('R');
                    right = pose[numbers[i]];
                } else{
                    answer.push_back('L');
                    left = pose[numbers[i]];
                }
            }
        }
    }
    return answer;
}



