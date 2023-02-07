#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    for (int i = 0; i < t.size() - (p.size() - 1); i++) {
        if (stol(p) >= stol(t.substr(i, p.size()))) {
            answer++;
        }
    }
    return answer;
}