# Algorithm

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

---

- **DP (동적계획법)**
  - 특정 범위까지의 값을 구하기 위해서 그것과 다른 범위까지의 값을 이용하여 효율적으로 값을 구하는 알고리즘
  - Memoization : 동일한 계산을 반복할때, 이전에 계산한 결과값을 메모리에 저장하는 방식 ( 피보나치 수열 )
  - bottom-up (상향식) 방식과 top-down (하향식) 방식이 있다 -> 저장해 나가는 순서의 차이

---

- **백트래킹**

```
조건 까지 도달하면 끝까지 탐색하지 않고 순회를 종료하는 기법
```

---

- **완전탐색**
  - 어떤 문제를 해결하기 위해 모든 경우의 수를 시도하며 정답을 찾아가는 방법 (Brute-Force, 무차별 대입)

---

- **우선순위 큐 (Priority Queue)**
  - 들어오는 순서에 상관 없이 우선순위가 높은 데이터가 pop 되는 자료구조
  - 최솟값, 최댓값을 효율적으로 추려내는대 용이

---

- **이분탐색**

---
