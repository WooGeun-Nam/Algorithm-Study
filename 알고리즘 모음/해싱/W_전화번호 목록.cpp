#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    // 전화번호부 정렬
    sort(phone_book.begin(), phone_book.end());

    for (int i=0; i < phone_book.size() - 1; i++) {
        string cur = phone_book[i];
        string next = phone_book[i+1];
        bool check = true;
        // 접두어인지 체크
        for(int j=0; j<cur.size(); j++)
        {
            // 다른지 체크
            if(cur[j] != next[j]) 
            {
                check = false;
                break;
            }
        }
        
        // 접두어면 찾기 종료
        if(check)
        {
            answer = false;
            break;
        }
    }
    
    return answer;
}