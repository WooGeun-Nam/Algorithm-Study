#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    int time = 0;
    int total = health;
    int count = 0;

    for (int i = 0; i < attacks[attacks.size()-1][0]+1; i++){
        time ++;
        int damage = attacks[count][1];
        int attack_time = attacks[count][0];
        if(attack_time == i){
            answer -= damage;
            count++;
            time = 0;
            if (answer<=0){
                return -1;
            }
        }
        else if(i != 0){
            answer += bandage[1];
            if(time == bandage[0]){
                answer += bandage[2];
                time = 0;
            }
            if(answer >= total){
               answer = total; 
            }
            
        }
    }
    return answer;
}