#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp;
    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] >= '0' && s[i] <= '9') { //���ڶ��
            temp += s[i];
        }
        else if (s[i] == 'z') { // zero �ΰ� ?
            temp += '0';
            i = i + 3;
        }
        else if (s[i] == 'o') { //one �ΰ� ?
            temp += '1';
            i = i + 2;
        }
        else if (s[i] == 't'&&s[i+1]=='w') { //two �ΰ� ?
            temp += '2';
            i = i + 2;
        }
        else if (s[i] == 't' && s[i + 1] == 'h') { //three �ΰ� ?
            temp += '3';
            i = i + 4;
        }
        else if (s[i] == 'f' && s[i + 1] == 'o') { //four �ΰ� ?
            temp += '4';
            i = i + 3;
        }
        else if (s[i] == 'f' && s[i + 1] == 'i') { //five �ΰ� ?
            temp += '5';
            i = i + 3;
        }
        else if (s[i] == 's' && s[i + 1] == 'i') { //six �ΰ� ?
            temp += '6';
            i = i + 2;
        }
        else if (s[i] == 's' && s[i + 1] == 'e') { //seven �ΰ� ?
            temp += '7';
            i = i + 4;
        }
        else if (s[i] == 'e') { //eight �ΰ� ?
            temp += '8';
            i = i + 4;
        }
        else if (s[i] == 'n') { //nine �ΰ� ?
            temp += '9';
            i = i + 3;
        }
    }
    if (s[s.size() - 1] >= '0' && s[s.size() - 1] <= '9') { //������ �ε����� ���ڶ��
        temp += s[s.size() - 1];
    }
    answer = stoi(temp);
   
    return answer;
}