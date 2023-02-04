#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    for (int i = 0; i < absolutes.size(); i++) {
        
        if (signs[i]) { //양수 인 경우
            answer += absolutes[i];
        }
        else { //음수 인 경우
            answer+= absolutes[i] * (-1);
        }
    }


    return answer;
}


int main() {
    int sum;
    vector<int> ab;
    vector<bool>si;
    sum = solution(ab, si);
    cout << sum;
}