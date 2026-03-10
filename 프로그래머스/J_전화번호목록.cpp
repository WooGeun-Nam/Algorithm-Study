#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i + 1 < (int)phone_book.size(); i++) {
        string a = phone_book[i];
        string b = phone_book[i + 1];
        
        if (b.compare(0, a.size(), a) == 0) return false;
    }
    return true;
}