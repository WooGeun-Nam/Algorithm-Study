#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    for (int k = 0; k < wires.size(); k++) {
        vector<int> visited(n + 1, 0);
        vector<vector<int>> tree(n + 1);

        //전선 제거 트리
        for (int i = 0; i < wires.size(); i++) {
            if (i == k) continue;

            tree[wires[i][0]].push_back(wires[i][1]);
            tree[wires[i][1]].push_back(wires[i][0]);
        }

        int cnt = 0;
        stack<int> st;
        st.push(1);
        visited[1] = 1;

        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            cnt++;

            for (int j = 0; j < tree[cur].size(); j++) {
                int next = tree[cur][j];
                if (!visited[next]) {
                    visited[next] = 1;
                    st.push(next);
                }
            }
        }

        int tmp = abs(cnt - (n - cnt));
        answer = min(answer, tmp);
    }

    return answer;
}