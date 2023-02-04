#include<iostream>
#include <string>
#include <vector>

using namespace std;



int solution(vector<int> numbers) {
    int answer = 0;
    vector<bool> flag = { 0,0,0,0,0,0,0,0,0,0 };

    for (int i = 0; i < numbers.size(); i++) { //numbers 배열에 없는 값 찾기
        if (flag[numbers[i]]==false) {
            flag[numbers[i]] = true;
        }
    }


    for (int i = 0; i <10; i++) {
        if (flag[i] == 0) {
            answer += i;
        }
    }


    return answer;
}

int main() {
    vector<int> numbers = {1,2,3,4,6,7,8,0};
    int ans = 0;
    ans = solution(numbers);
    cout << ans;
}