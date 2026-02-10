#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    // 구현
    int hp = health;
    
    int healCharge = bandage[0];
    int healAmount = bandage[1];
    int healAddition = bandage[2];
    
    
    int time = 1;
    for(int i=0; i<attacks.size(); i++)
    {
        int attackTime = attacks[i][0];
        int attackDamage = attacks[i][1];
        
        int charge = 0;
        while(time <= attackTime)
        {
            // 적 공격
            if(time == attackTime)
            {
                
                hp -= attackDamage;
                time++;
                // 사망 확인
                if(hp <= 0) return -1;
                break;
            }
            // 공격타임이 아닐 때 힐
            hp += healAmount;
            charge++;
            
            // 충전 후 추가힐
            if(charge >= healCharge)
            {
                hp += healAddition;
                charge = 0;
            }
            
            // 최대체력 보정
            if(hp > health) hp = health;
            time++;
        }
    }
    
    return hp;
}