#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 10의6승 이하의 소수
    vector<int> primeNumber;
    primeNumber.push_back(2);
    
    for(int i=3; i<1000000; i+=2)
    {
        bool isPrime = true;
        for(int j = 0; j < primeNumber.size(); j++)
        {
            int prime = primeNumber[j];
            
            if(prime * prime > i) break;
            
            if(i % prime == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime) primeNumber.push_back(i);
    }
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        long passKey;
        cin >> passKey;
        
        // 100만 이하 소수중에 나누어지면 100만 이하의 소수가 소인수
        bool isPassKey = true;
        for(int j=0; j<primeNumber.size(); j++)
        {
            int prime = primeNumber[j];
            
            if (prime * prime > passKey) break;
            
            if(passKey % primeNumber[j] == 0)
            {
                isPassKey = false;
                break;
            }
        }
        if(isPassKey) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}