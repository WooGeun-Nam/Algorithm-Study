#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // int 는 2의31승-1 범위 이므로 연산 시 오버플로우 발생
    long long hp;
    long long atk;
    long long mobHp;
    long long mobAtk;
    // 스킬 조건
    long long P;
    // 회복량
    long long S;

    cin >> hp >> atk >> mobHp >> mobAtk;
    cin >> P >> S;
    
    // 용사가 적을 때려야 하는 턴 수
    // 소수점 계산 후 올림
    long long turn = (long long)ceil((double)mobHp / atk);
    
    // 죽기전 회차까지 계산
    hp -= mobAtk * (turn - 1);
    mobHp -= atk * (turn - 1);
    
    // 마지막 공격 전 스킬 체크
    if (mobHp >= 1 && mobHp <= P) {
        // 회복 후 남은 턴 수 계산
        turn = (long long)ceil((double)(mobHp + S) / atk);
    }
    else {
        // 회복하지 않으면 남은 턴은 1번
        turn = 1;
    }
    
    // 최종 전투 용사 턴 까지 계산
    hp -= mobAtk * (turn - 1);
    mobHp -= atk * turn;
    
    // 용사가 살아 있다면 승리
    if (hp > 0)
        cout << "Victory!";
    else
        cout << "gg";

    return 0;
}