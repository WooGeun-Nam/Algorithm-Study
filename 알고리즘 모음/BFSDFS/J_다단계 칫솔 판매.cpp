#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    unordered_map<string,string> m;
    unordered_map<string,int> result;
    
    for (int i = 0; i < (int)enroll.size(); i++) {
        m[enroll[i]] = referral[i];
        result[enroll[i]] = 0;
    }

    for (int i = 0; i < seller.size(); i++) {
        string cur = seller[i];
        int money = amount[i] * 100;

        while (cur != "-" && money > 0) {
            int givemoney = money / 10;        
            int mymoney = money - givemoney;      

            result[cur] += mymoney;

            cur = m[cur];
            money = givemoney;
        }
    }

    for (int i = 0; i < enroll.size(); i++) {
        answer.push_back(result[enroll[i]]);
    }
    return answer;
}