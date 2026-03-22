#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int num){
    // 2보다 작으면 소수 x
    if(num < 2){
        return false;
    }
    
    // 소수 찾기 루트 num 까지만 나누어보면 됨
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            return false;
        }
    }
    
    return true;
}


int solution(string numbers) {
    int answer = 0;
    
    //permutation 할때 오름차순 정렬 필요
    sort(numbers.begin(), numbers.end());
    
    // 중복 없이 경수의 수 넣기
    set<int> nums;
    
    while(true){
        int num = 0;
        
        for(int i = 0; i < numbers.size(); i++){
            // 1의 자리 수부터 끝까지
            num = num * 10 + (numbers[i]-'0');
            nums.insert(num);
        }
        
        //조건문에서 next_permutation 한번 동작
        if(!next_permutation(numbers.begin(), numbers.end())){
            break;
        }
    }
    
    // set에 있는 수 소수 판별
    for(auto x : nums){
        if(isPrime(x)){
            answer ++;
        }
    }
    
    return answer;
}