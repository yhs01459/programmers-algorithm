#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int sum(vector<int> v) { //벡터의 합을 구하는 함수
    int s = 0; 
    for (int i = 0; i < v.size(); i++) {
        s += v[i];
    }
    return s;
}

int solution(int n) {
    int answer = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
        }
    }
    answer = sum(v);
    return answer;
}

int main() {
    int answer;
    int n;
    cin >> n; //n은 3000 이하 정수
    answer = solution(n);
    cout << answer;



}