# Algorithm-Study

## 백준

## 01-19

### 1816

https://www.acmicpc.net/problem/1816

#### 에라토스테네스의 체 (소수 판별)

```
for (int i = 2; i * i <= N; i++) {
    if (isPrime[i]) {
        for (int j = i * i; j <= N; j += i) {
            isPrime[j] = false;
        }
    }
}
```

### 2755

https://www.acmicpc.net/problem/2755

## 01-26

### 2839

https://www.acmicpc.net/problem/2839

### 2606

https://www.acmicpc.net/problem/2606

## 02-02

### 22941

https://www.acmicpc.net/problem/22941
