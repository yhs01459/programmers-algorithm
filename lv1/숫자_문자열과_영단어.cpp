#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp;
    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] >= '0' && s[i] <= '9') { //숫자라면
            temp += s[i];
        }
        else if (s[i] == 'z') { // zero 인가 ?
            temp += '0';
            i = i + 3;
        }
        else if (s[i] == 'o') { //one 인가 ?
            temp += '1';
            i = i + 2;
        }
        else if (s[i] == 't'&&s[i+1]=='w') { //two 인가 ?
            temp += '2';
            i = i + 2;
        }
        else if (s[i] == 't' && s[i + 1] == 'h') { //three 인가 ?
            temp += '3';
            i = i + 4;
        }
        else if (s[i] == 'f' && s[i + 1] == 'o') { //four 인가 ?
            temp += '4';
            i = i + 3;
        }
        else if (s[i] == 'f' && s[i + 1] == 'i') { //five 인가 ?
            temp += '5';
            i = i + 3;
        }
        else if (s[i] == 's' && s[i + 1] == 'i') { //six 인가 ?
            temp += '6';
            i = i + 2;
        }
        else if (s[i] == 's' && s[i + 1] == 'e') { //seven 인가 ?
            temp += '7';
            i = i + 4;
        }
        else if (s[i] == 'e') { //eight 인가 ?
            temp += '8';
            i = i + 4;
        }
        else if (s[i] == 'n') { //nine 인가 ?
            temp += '9';
            i = i + 3;
        }
    }
    if (s[s.size() - 1] >= '0' && s[s.size() - 1] <= '9') { //마지막 인덱스가 숫자라면
        temp += s[s.size() - 1];
    }
    answer = stoi(temp);
   
    return answer;
}