#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    unordered_map<string, double> gradeTable = {
        {"A+", 4.3}, {"A0", 4.0}, {"A-", 3.7},
        {"B+", 3.3}, {"B0", 3.0}, {"B-", 2.7},
        {"C+", 2.3}, {"C0", 2.0}, {"C-", 1.7},
        {"D+", 1.3}, {"D0", 1.0}, {"D-", 0.7},
        {"F", 0.0}
    };

    // 과목 수
    int count;
    cin >> count;

    double sumCredit = 0;
    double sumGrade = 0;

    // 과목명 / 학점 credit / 성적 grade
    // (Sum = 학점*성적) / 총학점
    // Sum 누적 & 학점누적
    for(int i = 0; i < count; i++)
    {
        string name;
        double credit;
        string grade;

        cin >> name >> credit >> grade;

        sumCredit += credit;

        double gradeValue = gradeTable.at(grade);
        sumGrade += credit * gradeValue;
    }

    double answer = sumGrade / sumCredit;
    answer = floor(answer * 100.0 + 0.5) / 100.0;

    cout << fixed;
    cout.precision(2);
    cout << answer;
}