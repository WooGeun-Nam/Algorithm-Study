#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static vector<bool> isPrime(10000000, true);

// 에라토스테네스의체
void MakePrime()
{
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2; i*i<isPrime.size(); i++)
    {
        // 소수면
        if (isPrime[i])
        {
            for(int j=i*i; j<isPrime.size(); j+=i) isPrime[j] = false;
        }
    }
}

int solution(string numbers) {
    vector<int> number;
    
    sort(numbers.begin(), numbers.end());
    
    // numbers 로 만들 수 있는 경우의수 (순열 순서상관O)
    do
    {
        string num = "";
        for(int i=0; i<numbers.size(); i++)
        {
            num += numbers[i];
            number.push_back(stoi(num));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    sort(number.begin(), number.end());
    number.erase(unique(number.begin(), number.end()), number.end());
    
    // 입력범위 내 소수 미리 만들기
    MakePrime();
    
    int answer = 0;
    for(int i=0; i<number.size(); i++)
    {
        if(isPrime[number[i]]) answer++;
    }
    
    return answer;
}