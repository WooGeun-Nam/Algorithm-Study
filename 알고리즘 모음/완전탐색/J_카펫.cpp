#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
공식 : brown + yellow의 약수를 구함
약수 쌍 중 큰값 * 2 + (작은값-2) * 2 가 해당 행렬의 테두리 칸 수임.
따라서 약수 쌍 중 큰값 * 2 + (작은값-2) * 2가 brown과 같으면 됨.
*/
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int weight, height; 
    for(int i = 2; i * i <= (brown+yellow); i++){
        if((brown+yellow) % i == 0){
            weight = (brown+yellow) / i;
            height = i;
            int outside = weight * 2 + (height-2) * 2;
            if(outside == brown) {
                answer.push_back(weight);
                answer.push_back(height);
                break;
            }
        }
    }
    
    return answer;
}

