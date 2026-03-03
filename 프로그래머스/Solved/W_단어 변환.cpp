#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

struct Data {
    string word;
    int count;
};

int solution(string begin, string target, vector<string> words) {
    
    // 정답이 있는지 체크하고 로직 시작
    bool noAnswer = true;
    for(int i=0; i<words.size(); i++)
    {
        if(target == words[i]) noAnswer = false;
    }
    if(noAnswer) return 0;
    
    int answer = 0;
    
    unordered_map<string, vector<string>> nearWord;
    
    // words들의 다음 단어 미리 찾기
    for(int i=0; i<words.size(); i++)
    {
        for(int j=i+1; j<words.size(); j++)
        {
            string curWord = words[i];
            string findWord = words[j];
            
            // 각 자리가 다른지 확인
            int diffCount = 0;
            for(int z=0; z<curWord.size(); z++)
            {
                if(curWord[z] != findWord[z]) diffCount++;
            }
            
            // 한자리만 다른 경우 다음 단어에 추가
            if(diffCount == 1) 
            {
                // 효율성을 위해 양방향 추가
                nearWord[curWord].push_back(findWord);
                nearWord[findWord].push_back(curWord);
            }
        }
    }
    
    // begin 기준도 추가
    for(int i=0; i<words.size(); i++)
    {
        int diffCount = 0;
        string findWord = words[i];
        for(int z = 0; z < begin.size(); z++) {
            if(begin[z] != findWord[z]) diffCount++;
        }
        if(diffCount == 1) nearWord[begin].push_back(findWord);
    }
    
    queue<Data> qu;
    qu.push({begin, 0});
    
    while (!qu.empty())
    {
        Data cur = qu.front();
        qu.pop();
        
        string curWord = cur.word;
        int curCount = cur.count;
        
        // 현재 단어가 찾는 단어면 종료
        if(curWord == target)
        {
            answer = curCount;
            break;
        }
        
        // 다음 단어 추가
        for(int i=0; i<nearWord[curWord].size(); i++)
        {
            string nextWord = nearWord[curWord][i];
            qu.push({nextWord, curCount + 1});
        }
    }
    
    return answer;
}