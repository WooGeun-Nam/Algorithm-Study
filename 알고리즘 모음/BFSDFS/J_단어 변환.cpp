#include <string>
#include <vector>
#include <queue> 
using namespace std;


bool match(string a, string b){
    bool result = false;
    int cnt = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] != b[i]) cnt++;
        if(cnt > 1) break;
    }
    if (cnt == 1) result = true;

    return result;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> visited(words.size(),false);
    queue<pair<string,int>> q;
    q.push({begin,0});
    while (!q.empty()){
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur == target){
            answer = cnt;
            break;  
        }
        for(int i = 0; i < words.size(); i++){
            if(!visited[i] && match(cur,words[i])){
                visited[i] = true;
                q.push({words[i],cnt+1});
            }
        } 
    }
    return answer;
}