# Algorithm-Study (백준)

---

## Week 1 (~01/19)

|  No. | Problem               |     Tag     | Status | Link                                 |
| ---: | :-------------------- | :---------: | :----: | ------------------------------------ |
| 1816 | 암호 키               | 소수 / 수학 |   ✅   | https://www.acmicpc.net/problem/1816 |
| 2755 | 이번학기 평점은 몇점? |    구현     |   ✅   | https://www.acmicpc.net/problem/2755 |

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

## Week 2 (~01/26)

|  No. | Problem   | Tag | Status | Link                                 |
| ---: | :-------- | :-: | :----: | ------------------------------------ |
| 2839 | 설탕 배달 |     |        | https://www.acmicpc.net/problem/2839 |
| 2606 | 바이러스  |     |        | https://www.acmicpc.net/problem/2606 |

---

## Week 3 (~02/02)

|   No. | Problem           | Tag | Status | Link                                  |
| ----: | :---------------- | :-: | :----: | ------------------------------------- |
| 22941 | RPG 마스터 오명진 |     |        | https://www.acmicpc.net/problem/22941 |
