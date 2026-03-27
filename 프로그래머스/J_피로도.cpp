#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

static int answer;  

void search(int cnt, int start, int k, vector<int> v, vector<vector<int>> dungeons) {
    
    answer = max(answer, cnt);

    if (k >= dungeons[start][0]) {
        k -= dungeons[start][1];
        cnt++;
        v[start] = 1;

        answer = max(answer, cnt);

        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 0) {
                search(cnt, i, k, v, dungeons);
            }
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {

    for (int i = 0; i < dungeons.size(); i++) {
        vector<int> v(dungeons.size(), 0);
        search(0, i, k, v, dungeons);
    }
    
    return answer;
}