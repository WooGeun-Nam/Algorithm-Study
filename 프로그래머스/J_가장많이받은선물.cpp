#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int n = friends.size(); 
    string send, receive;
    map<string, int> Fnum; 
    vector<vector<int>> giftMatrix(n, vector<int>(n, 0)); // 0으로 채운 n x n 행렬 선언
    vector<int> giftNums(n,0);  // 받을 선물 수
    vector<int> giftscore(n,0); // 선물 지수
    
    // 친구들을 숫자로 인덱싱
    for(int i = 0; i < n ; i++){
        Fnum[friends[i]] = i;
    }
    
    // stringstream으로 공백 나누고 친구Index를 알고 있으니 입출력 예시 처럼 행렬 생성
    for (int i = 0; i < gifts.size(); i++){
        stringstream ss(gifts[i]);
        ss >> send >> receive;
        giftMatrix[Fnum[send]][Fnum[receive]] += 1;
    }
    
    // 선물 지수 계산
    for (int i =0; i < n; i++){
        int s = 0; 
        int r = 0;
        
        // 보낸 선물 수 계산
        for (int j = 0; j < n; j++){
            s += giftMatrix[i][j];
        }
        
        // 받은 선물 수 계산
        for (int j = 0; j < n; j++){
            r += giftMatrix[j][i];
        }
        
        // 선물 지수
        giftscore[i] = (s - r);   
    }
    
    // 받을 선물 계산
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            
            // 친구 i가 친구 j보다 선물을 더 보냈을 때
            if (giftMatrix[i][j] > giftMatrix[j][i]){
                giftNums[i]++;
            } 
            
            // 친구 j가 친구 i보다 선물을 더 보냈을 때
            else if (giftMatrix[i][j] < giftMatrix[j][i]){
                giftNums[j]++;
            }
            
            // 두 사람이 선물을 주고받은 기록이 하나도 없거나 주고받은 수가 같을때
            else {
                
                // 친구 i의 선물 지수 > 친구 j의 선물 지수
                if (giftscore[i] > giftscore[j]){
                    giftNums[i]++;
                } 
                
                // 친구 j의 선물 지수 > 친구 i의 선물 지수
                else if (giftscore[i] < giftscore[j]){
                    giftNums[j]++;
                }
            }
        }
    }
    
    // 가장 큰 받을 선물 수 찾기
    for (int i = 0; i < giftNums.size(); i++){
        if(giftNums[i]>answer){
            answer = giftNums[i];
        }
    }
    
    return answer;
}