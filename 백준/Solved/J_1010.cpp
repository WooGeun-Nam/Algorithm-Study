#include <iostream>
using namespace std;

int main(){
    int n, m, t;
    cin >> t;

    while(t--){
        long long answer = 1;
        cin >> n >> m;

        if (n > m - n) n = m - n;

        for (int i = 1; i < n+1; i++){
            answer = answer * (m - n + i) / i;
        }

        cout << answer << "\n";
    }
}