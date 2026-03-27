#include <iostream>
using namespace std;

static int cnt;

void cal(int cul, int target){
    if (cul > target) {
        return;
    }
    if (cul == target){
        cnt++;
    }
    cal(cul + 1, target);
    cal(cul + 2, target);
    cal(cul + 3, target);

}

int main() {
    int n,t;
    cin >> t;
    while(t--){
        cnt = 0;
        cin >> n;
        cal(0,n);
        cout << cnt << endl;
    }
    
}