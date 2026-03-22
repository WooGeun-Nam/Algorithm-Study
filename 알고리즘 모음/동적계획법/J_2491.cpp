#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

int main() {

    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    if (N == 1) {
        cout << 1 << "\n";
        return 0;
    }

    int inc = 1, dec = 1;     
    int max_dist = 1;

    for (int i = 0; i < N - 1; i++) {
    
        if (v[i] >= v[i + 1]) {
            dec++;
        }
        else {
            dec = 1;
        }

        if (v[i] <= v[i + 1]) {
            inc++;
        }
        else {
            inc = 1;
        }

        max_dist = max(max_dist, max(inc, dec));
    }

    cout << max_dist << "\n";
    return 0;
}