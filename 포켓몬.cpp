#include<iostream>
#include <vector>
#include<map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> pocket;
    for (int i = 0; i < nums.size(); i++) {
        pocket[nums[i]]++;
    }
    
    if (pocket.size() >= nums.size()/2) {
        answer = nums.size() / 2;
    }
    else {
        answer = pocket.size();
    }


    
    return answer;
}

int main() {
    vector<int> nums = {1,1,2,3};
    int answer = solution(nums);
    cout << answer;
    
}