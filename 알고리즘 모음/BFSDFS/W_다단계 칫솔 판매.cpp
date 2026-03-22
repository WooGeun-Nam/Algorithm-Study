#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <cmath>

using namespace std;

struct Sell {
    string name;
    int money;
};

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
    
    stack<Sell> st;

    // seller 들 스택에 추가
    for (int i = seller.size() - 1; i >= 0; i--) {
        st.push({seller[i], amount[i] * 100});
    }

    while (!st.empty()) {
        Sell cur = st.top();
        st.pop();

        // 부모가 없거나 배분할 금액이 없다면 종료
        if (cur.name == "-" || cur.money == 0) continue;

        int giveMoney = cur.money / 10;      // 주는 돈 10%
        int myMoney = cur.money - giveMoney; // 남은 돈 90%

        // 남은 돈 추가
        money[cur.name] += myMoney;
        
        // 부모명 저장
        string nextSeller = node[cur.name];
        // 다음 노드
        st.push({nextSeller, giveMoney});
    }
    
    for(string name : enroll)
    {
        answer.push_back(money[name]);
    }
    
    return answer;
}