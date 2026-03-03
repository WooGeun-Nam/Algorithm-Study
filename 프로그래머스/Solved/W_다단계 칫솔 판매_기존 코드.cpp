#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    // enroll 총 조직원
    // referral 연결
    unordered_map<string, string> node;
    unordered_map<string, int> money(0);
    
    int index = 0;
    for(string name : enroll)
    {
        node[enroll[index]] = referral[index];
        index++;
    }
    
    for(int i=0; i<seller.size(); i++)
    {
        string curSeller = seller[i];
        int sellMoney = amount[i] * 100;
        
        while(true)
        {
            if(curSeller == "-" || sellMoney == 0) break;
            
            string nextSeller = node[curSeller];
            int giveMoney = sellMoney / 10;
            
            money[curSeller] += sellMoney - giveMoney;
            sellMoney = giveMoney;
            curSeller = nextSeller;
        }
    }
    
    for(string name : enroll)
    {
        answer.push_back(money[name]);
    }
    
    return answer;
}