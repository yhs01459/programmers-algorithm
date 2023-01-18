#include<string>
#include <iostream>
#include<vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> v;
    v.push_back(s[0]);
    for (int i = 1; i < s.size(); i++) {
       if (s[i] == ')' && v.back() == '(') {
          v.pop_back();
       }
       else {
          v.push_back(s[i]);
       }
        

    }
    if (!v.empty())
    {
        answer = false;
    }
    return answer;
}
int main() {
    bool answer;
    string s = ")()(";
    answer = solution(s);
    cout << answer;


}