#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> w = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
    vector<int> d = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int sum = 0;
    for (int i = 0; i < a-1; i++) { //0~11
        sum += d[i];
    }
    sum += b;

    answer = w[sum % 7];

    return answer;
}