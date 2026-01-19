# Algorithm-Study

## 백준

### 1816

https://www.acmicpc.net/problem/1816

```
for (int i = 2; i * i <= N; i++) {
    if (isPrime[i]) {
        for (int j = i * i; j <= N; j += i) {
            isPrime[j] = false;
        }
    }
}
에라토스테네스의 체 (소수 판별)
```

### 2755

https://www.acmicpc.net/problem/2755

### 2839

https://www.acmicpc.net/problem/2839

### 2606

https://www.acmicpc.net/problem/2606
