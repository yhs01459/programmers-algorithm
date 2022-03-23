#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

//�Ҽ����� �˻� ���ִ� �Լ�
bool issosu(vector<char> v) {

    
    string s;
    for (int i = 0; i < v.size(); i++) {
        s.push_back(v[i]);
    }
    long a = stol(s); // �� �κ��� ������ n�� k������ �ٲ����� �ڸ����� int Ÿ������ ǥ���� �� �ִ� ������ �ξ� �Ѿ �� �ִٴ°��� ����
    if (a < 2) return false;
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;

}

//k������ �ٲ� ���ڿ��� �������ִ� �Լ� 
string changeNum(int a, int b) {
    string s = "";
    stack<char> stc;
    //10��
    while (a >= b) {
        
        stc.push((a % b)+'0');
        a = a / b;
    }
    stc.push(a+'0');

    while (!stc.empty()) {
        s.push_back(stc.top());
        stc.pop();
    }
    return s;
}

int solution(int n, int k) {
    int answer = 0;
    vector<char> v;
    string s = changeNum(n, k); //k������ ����

    // 0�� ������ �� ������ ����� ���� �Ҽ����� Ȯ��
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (!v.empty()) {
                if (issosu(v)) {
                    answer++;
                }
                v.clear();
            }
            else {
                continue;
            }
        }
        else {
            v.push_back(s[i]);
        }
    }

    // �������� 0�� ���������� ���Ϳ� ���� �����ִ� ��� ó��
    if (!v.empty()) {
        if (issosu(v)) {
            answer++;
        }
        v.clear();
    }
    return answer;
}

int main() {
    int n = 111;
    int k = 10;
    int answer = solution(n, k);
    cout << answer;
    return 0;
}

/*
*  1. ����n -> k������ ���� ( �Լ��� ������ش�. )  -> string ���� ��ȯ
*  2. string size��ŭ Ž���ϸ鼭 ���Ϳ� ����
*  3. 0�� ������ ���Ϳ� ����� ���� �Ҽ����� Ȯ�� -> �Ҽ��̸� count++; (string�� �Է¹޾� �Ҽ����� �ƴ��� Ȯ���ϴ� �Լ� )
*  4. �������� �ѹ� ������ ����� 0�� �ƴ϶�� �Ҽ��˻� �ѹ� �� ���ֱ�.
* 
*/