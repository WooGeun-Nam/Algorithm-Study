#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) 
{   
    // 이용자 수 m 명 마다 서버 1대 추가로 필요
    // k = 한번 증설된 서버가 운영해야 하는 시간
    // n = 증설된 서버의 개수
    // 최소 서버 개수는 해당 시간 유저에 비례해서 n = p/m
    
    int server = 0;
    int addCount = 0;
    // 반납시간 저장 배열
    vector<int> reduce(players.size(), 0);
    
    // 24시간
    for(int i=0; i<players.size(); i++)
    {
        // 회수할 서버가 있다면 회수 처리
        if(reduce[i] > 0)
        {
            server -= reduce[i];
        }
        
        // 필요한 서버 수 확인
        int need = players[i] / m;
        
        // 서버가 부족하면 증설
        if(server < need)
        {
            int diff = need - server;
            // 증설 횟수
            addCount += diff;
            // 현재 서버 수
            server += diff;
            // 회수 시점
            if(i+k < players.size()) reduce[i+k] = diff;
        }
    }
    
    return addCount;
}