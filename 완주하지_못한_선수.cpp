//완주하지 못한 선수
#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> map1;
       
    for (int i = 0; i < participant.size(); i++) {
        map1[participant[i]]++;
    }
    for (int i = 0; i < completion.size(); i++) {
        map1[completion[i]]--;
    }
    
    for (int i = 0; i < participant.size(); i++) {
        if (map1[participant[i]] != 0) {
            answer = participant[i];
            break;
        }
    }
    

    return answer;
}

int main() {
    
    vector<string> p = {"a","b","a","c"}; // 참여자
    vector<string> c = {"b","c","a"}; // 완주자

    string fail = "";

    fail = solution(p, c);
    cout << fail;

}

