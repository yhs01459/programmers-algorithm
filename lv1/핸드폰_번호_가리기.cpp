#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string phone_number) {
    string answer = "";
    vector<char> v;
    int count = 0;
    for (int i = phone_number.size() - 1; i > -1; i--) {
        if (count == 4) {
            v.push_back('*');
        }
        else {
            count++;
            v.push_back(phone_number[i]);
        }
    }
    for (int i = v.size() - 1; i > -1;i--) {
        answer += v[i];

    }
    return answer;

}

int main() {
    string a = "123123123123";
    string b;
    b = solution(a);
    cout << b;

}