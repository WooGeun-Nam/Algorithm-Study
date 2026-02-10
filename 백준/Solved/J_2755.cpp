#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct user{
    string name;
    int hak;
    string score;
};

float solution(vector<user> v){
    float result = 0.0;
    int sum = 0;
    for (int i = 0; i < v.size(); i++){
        float s = 0.0;
        if      (v[i].score == "A+") s = 4.3;
        else if (v[i].score == "A0") s = 4.0;
        else if (v[i].score == "A-") s = 3.7;
        else if (v[i].score == "B+") s = 3.3;
        else if (v[i].score == "B0") s = 3.0;
        else if (v[i].score == "B-") s = 2.7;
        else if (v[i].score == "C+") s = 2.3;
        else if (v[i].score == "C0") s = 2.0;
        else if (v[i].score == "C-") s = 1.7;
        else if (v[i].score == "D+") s = 1.3;
        else if (v[i].score == "D0") s = 1.0;
        else if (v[i].score == "D-") s = 0.7;
        else                         s = 0.0;
        result += s * v[i].hak;
        sum += v[i].hak;
        
    }
    result = result / sum;
    return result;
}



int main()
{   
    int n;
    string name;
    int hak;
    string score;
    vector<user> v;
    cin >> n;
    
    for (int i =0; i<n; i++){
        cin >> name;
        cin >> hak;
        cin >> score;
        v.push_back({name,hak,score});
    }
    float num = solution(v);
    cout << fixed <<  setprecision(2) << num;

    return 0;
}