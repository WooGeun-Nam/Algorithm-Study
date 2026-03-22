#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    int friendsCount = friends.size();
    unordered_map<string, int> friendList;
    
    // 친구들 코드 해시
    for(int i=0; i<friendsCount; i++)
    {
        friendList.insert(make_pair(friends[i], i));
    }
    
    // 선물지수 배열 0으로 초기화
    vector<vector<int>> giftPoint(friendsCount, vector<int>(friendsCount, 0));
    
    // gifts 배열 계산
    for(int i=0; i<gifts.size(); i++)
    {
        size_t spaceIndex = gifts[i].find(' ');
        
        string give = gifts[i].substr(0, spaceIndex);
        string receive = gifts[i].substr(spaceIndex + 1);
        
        giftPoint[friendList.at(give)][friendList.at(receive)]++;
    }
    
    // 선물 지수 계산
    for(int i=0; i<friendsCount; i++)
    {
        int givePoint = 0;
        int receivePoint = 0;
        for(int j=0; j<friendsCount; j++)
        {
            if(i != j)
            {
                givePoint += giftPoint[i][j];
                receivePoint += giftPoint[j][i];
            }
        }
        giftPoint[i][i] = givePoint - receivePoint;
    }
    
    // 실제 선물받기 계산
    for(int i=0; i<friendsCount; i++)
    {
        int giftCount = 0;
        // 친구간 서로 계산
        for(int j=0; j<friendsCount; j++)
        {
            if(i != j)
            {
                // 준거
                int give = giftPoint[i][j];
                // 받은거
                int receive = giftPoint[j][i];
                // 선물갯수가 같고 선물지수가 크면 받기
                if(give == receive && giftPoint[i][i] > giftPoint[j][j]) 
                    giftCount++;
                // 선물을 많이 줬다면 받기
                else if(give > receive) giftCount++;
            }
        }
        
        if(giftCount > answer) answer = giftCount;
    }
    
    return answer;
}