#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    //대문자 -> 소문자
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    //문자 제거
    for(int i = 0; i < new_id.size(); i++){
        if((new_id[i] >='a' && new_id[i] <= 'z')||(new_id[i] >='0' && new_id[i] <= '9') ||new_id[i] == '-'||new_id[i] == '_'||new_id[i] == '.'){
        }else{
            new_id.erase(new_id.begin()+i);
            i--;
        }
    }
    //연속 .제거
    int cnt = 0;
    for(int i = 0; i < new_id.size(); i++){
        
        if(new_id[i] == '.'){
            cnt ++;
        }
        if(cnt == 2){
            new_id.erase(new_id.begin()+i);
            cnt -= 1;
            i--;
        }
        if(new_id[i] != '.'){
            cnt = 0;
        }
    }
    // . 처음 끝
    if(new_id.front() == '.'){
        new_id.erase(new_id.begin());
    }
    if(new_id.back() == '.'){
        new_id.erase(new_id.end()-1);
    }
    // 빈문자
    if(new_id.empty()){
       new_id.push_back('a');
    }
    // 16자 이상
    if(new_id.size() >= 16){
        new_id.erase(15,new_id.size()-1);
        if(new_id.back() == '.'){
            new_id.erase(new_id.end()-1);
        }
    }
    //2자 이하
    if(new_id.size() <= 2){
        while(new_id.size() < 3){
            new_id.push_back(new_id.back());
        }
    }
    answer = new_id;
    return answer;
}