# Algorithm-Study

---

### Notes

- **에라토스테네스의 체 (소수 판별)**

```cpp
for (int i = 2; i * i <= N; i++) {
    if (isPrime[i]) {
        for (int j = i * i; j <= N; j += i) {
            isPrime[j] = false;
        }
    }
}
```

---

- **BFS / DFS**
  - BFS : Queue (front)
  - DFS : Stack (top)

```cpp
    stack<int> st;
    vector<bool> visit(node.size(), false);

    st.push(start);

    while (!st.empty())
    {
        int cur = st.top();
        st.pop();

        if (visit[cur]) continue;

        visit[cur] = true;

        // 노드 검사 push
        for (int i=node[cur].size()-1; i>=0; i--)
        {
            int next = node[cur][i];
            if (!visit[next])
            {
                st.push(next);
            }
        }
    }
```

- **백트래킹**

```
조건 까지 도달하면 끝까지 탐색하지 않고 순회를 종료하는 기법
```

---

- **이분탐색**

---
