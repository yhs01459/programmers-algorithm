#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

//�Ҽ����� �˻� ���ִ� �Լ�
bool isPrime(vector<char> v) {

    
    string str;
    for (int i = 0; i < v.size(); i++) {
        str.push_back(v[i]);
    }
    long num = stol(str); // �� �κ��� ������ n�� k������ �ٲ����� �ڸ����� int Ÿ������ ǥ���� �� �ִ� ������ �ξ� �Ѿ �� �ִٴ°��� ����
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

//k������ �ٲ� ���ڿ��� �������ִ� �Լ� 
string changeNum(int a, int b) {
    string str = "";
    stack<char> temp;
    //10��
    while (a >= b) {
        
        temp.push((a % b)+'0');
        a = a / b;
    }
    temp.push(a+'0');

    while (!temp.empty()) {
        str.push_back(temp.top());
        temp.pop();
    }
    return str;
}

int solution(int n, int k) {
    int answer = 0;
    vector<char> v;
    string str = changeNum(n, k); //k������ ����

    // 0�� ������ �� ������ ����� ���� �Ҽ����� Ȯ��
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0') {
            if (!v.empty()) {
                if (isPrime(v)) {
                    answer++;
                }
                v.clear();
            }
            else {
                continue;
            }
        }
        else {
            v.push_back(str[i]);
        }
    }

    // �������� 0�� ���������� ���Ϳ� ���� �����ִ� ��� ó��
    if (!v.empty()) {
        if (isPrime(v)) {
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