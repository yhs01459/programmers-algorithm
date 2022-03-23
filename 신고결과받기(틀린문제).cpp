#include<iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>;

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    
    map<string, int> userId;
    map<string, set<string>> xId;

    //report 탐색
    for (int i = 0; i < report.size(); i++) {

        //문자열 파싱
        string from;
        string to;
        int blank = report[i].find(' ');
        from = report[i].substr(0, blank);
        to = report[i].substr(blank);

        xId[to].insert(from);
    }

    //xId 탐색
    for (auto i : xId) {
        if (i.second.size() >= k) { // 신고횟수가 k번 이상인가?
            for (auto j : i.second) {
                userId[j]++;
            }
        }
    }

    //id_list 탐색
    for (int i = 0; i < id_list.size(); i++) {
        if (userId.find(id_list[i])!=userId.end()) {
            answer.push_back(userId[id_list[i]]);
        }
        else {
            answer.push_back(0);
        }
    }
    return answer;
}

int main() {
    vector<string> v1 = { "muzi", "frodo", "apeach", "neo" };
    vector<string> v2 = { "muzi frodo", "muzi frodo", "neo frodo" };
    vector<int> answer = solution(v1, v2, 2);

    for (int i = 0; i < answer.size(); i++) {
        cout << v1[i]<<" : "<<answer[i] << endl;
    }
}

/*
*   1. report 배열을 탐색하면서 문자열파싱 : 유저id - 신고한 유저id 
*   2. 파싱한 정보를 이용하여 신고를 받은 유저 id + 신고한 유저id 들 저장
*   3. 신고된 유저의 정보를 저장한 map 탐색
*       - 탐색한 id가 map에 key값의 개수가 k 이상 인가?
*       - k 이상인 경우 신고한 유저들 카운트
*   4. id_list 탐색하면서 카운트 정보가 담겨있는 map과 비교하여 출력
*/