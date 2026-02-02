#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main()
{
    int n;
    int five = 0; //5kg 봉지
    int three = 0; // 3kg 봉지
    cin >> n;
    
    while(true){
        
        //5kg로 나누어 떨어지면 5kg로만 채움
        if(n%5 == 0){
            five = n/5;
            cout << five + three;
            return 0;
        }
        
        // 아니면 3kg 빼고 3kg 봉지 수 추가
        n -= 3;
        three ++;
        
        // 3kg으로만 채운 경우
        if (n == 0){
            cout << three;
            return 0;
        }
        
        // 3kg,5kg 조합으로 못 만들 경우
        else if(n < 0){
            cout << -1;
            return 0;
        }
    }
    
}