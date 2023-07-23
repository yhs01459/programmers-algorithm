#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int sum(vector<int> v) { //������ ���� ���ϴ� �Լ�
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
    cin >> n; //n�� 3000 ���� ����
    answer = solution(n);
    cout << answer;



}