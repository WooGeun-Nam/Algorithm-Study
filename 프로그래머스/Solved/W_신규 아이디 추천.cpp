#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {

    // 알파벳소문자, 숫자, -_. 만 가능
    // 1,2단계 처리
    for(int i=new_id.size()-1; i>=0; i--)
    {
        char c = new_id[i];
        // 대문자 -> 소문자
        if(c >= 'A' && c <= 'Z') new_id[i] = tolower(new_id[i]);
        // 소문자일때
        else if (c >= 'a' && c <= 'z');
        // 숫자일때
        else if (c >= '0' && c <= '9');
        // 아니면 특수문자
        else 
        {
            // 해당 문자가 허용 문자인지 체크
            bool symbol = (c == '-' || c == '_' || c == '.');
            if(!symbol) new_id.erase(i, 1);
        }
    }
    
    // 3단계 처리
    for(int i=new_id.size()-1; i>=1; i--)
    {
        // 다음자리도 . 이면 현재자리 제거
        if(new_id[i] == '.' && new_id[i-1] == '.') new_id.erase(i, 1);
    }
    
    // 4단계 처리
    if(new_id[0] == '.') new_id.erase(0, 1);
    if(new_id[new_id.size()-1] == '.') new_id.erase(new_id.size()-1, 1);
    
    // 5단계 처리
    if(new_id.empty()) new_id = "a";
    
    // 6단계 처리
    if(new_id.size() >= 16) new_id.erase(15);
    if(new_id[new_id.size()-1] == '.') new_id.erase(new_id.size()-1, 1);
    
    // 7단계 처리
    while (new_id.size() < 3)
    {
        new_id += new_id.back();
    }
    
    return new_id;
}