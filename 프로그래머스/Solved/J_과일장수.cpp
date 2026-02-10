#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int boxes = score.size() / m ;
    sort(score.begin(),score.end(),greater<int>());
    if (boxes !=0){
       for(int i = 0; i < boxes; i++){
        answer += score[(i+1)*m-1] * m ;
        
        } 
    }
    else{
        answer = 0;
    }
    
    return answer;
}

