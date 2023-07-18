#include<iostream>
#include<vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for (int i = 0; i < n; i++) {
        answer.push_back(x + x * i);
    }
    return answer;
}

int main() {
    int x;
    int n;
    cin >> x>>n;
    vector<long long> answer = solution(x, n);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
    }
    
}