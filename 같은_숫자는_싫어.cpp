#include<iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    answer.push_back(arr[0]);
    
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != answer.back()) {
            answer.push_back(arr[i]);
        }

    }
   

    return answer;
}
int main() {
    vector<int> numbers = { 1,1,3,3,0,1,1 };
    vector<int> answer;
    answer = solution(numbers);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
    }

    
}