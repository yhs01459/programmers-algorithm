#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') { //공백인가 ?
            answer += ' ';
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') { //대문자인가 ?
            if (s[i] + n > 'Z') {
                char temp = s[i] + n;
                answer += temp - ('Z' - 'A') - 1;
            }
            else {
                answer += s[i] + n;
            }

        }
        else { //소문자 인가 ?
            if (s[i] + n > 'z') {
                char temp = s[i] + n;
                answer += temp - ('z' - 'a') - 1;
            }
            else {
                answer += s[i] + n;
            }
        }
    }
    return answer;
}