#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

//소수인지 검사 해주는 함수
bool isPrime(vector<char> v) {

    
    string str;
    for (int i = 0; i < v.size(); i++) {
        str.push_back(v[i]);
    }
    long num = stol(str); // 이 부분을 간과함 n을 k진수로 바꿨을때 자릿수가 int 타입으로 표현할 수 있는 범위를 훨씬 넘어설 수 있다는것을 간과
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

//k진수로 바꿔 문자열로 변경해주는 함수 
string changeNum(int a, int b) {
    string str = "";
    stack<char> temp;
    //10진
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
    string str = changeNum(n, k); //k진수로 변경

    // 0을 만나면 그 전까지 저장된 값이 소수인지 확인
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

    // 마지막에 0을 만나지못해 벡터에 값이 남아있는 경우 처리
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
*  1. 정수n -> k진수로 변경 ( 함수로 만들어준다. )  -> string 으로 변환
*  2. string size만큼 탐색하면서 벡터에 저장
*  3. 0을 만나면 벡터에 저장된 값이 소수인지 확인 -> 소수이면 count++; (string을 입력받아 소수인지 아닌지 확인하는 함수 )
*  4. 마지막에 한번 벡터의 사이즈가 0이 아니라면 소수검사 한번 더 해주기.
* 
*/