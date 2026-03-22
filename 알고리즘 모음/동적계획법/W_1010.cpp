#include <iostream>
#include <vector>

using namespace std;

// m개 중 n개의 조합을 뽑는 경우의 수
// mCn = m! / n!(m-n)!
long long combination(int n,int m) {
    long long result = 1;
    
    int topNumber = m;
    for(int i=1; i<=n; i++)
    {
        result *= topNumber;
        result /= i;
        topNumber--;
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    for(int i=0; i<t; i++)
    {
        int n, m;
        cin >> n >> m;
        long long result = combination(n, m);
        cout << result << endl;
    }

    return 0;
}