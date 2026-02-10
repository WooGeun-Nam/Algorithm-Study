#include <string>
#include <vector>

using namespace std;

static int answer;
static int tar;
static vector<int> nums;

void DFS(int index, int sum) {
    if (index == nums.size()) {
        if (sum == tar) {
            answer++;
        }
        return;
    }

    // + 
    DFS(index + 1, sum + nums[index]);
    // - 
    DFS(index + 1, sum - nums[index]);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    nums =  numbers;
    tar = target;
    
    //처음 부터 +,- 선택하기 때문에 sum 0 시작
    DFS(0,0);
    return answer;
}