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

    //report Ž��
    for (int i = 0; i < report.size(); i++) {

        //���ڿ� �Ľ�
        string from;
        string to;
        int blank = report[i].find(' ');
        from = report[i].substr(0, blank);
        to = report[i].substr(blank);

        xId[to].insert(from);
    }

    //xId Ž��
    for (auto i : xId) {
        if (i.second.size() >= k) { // �Ű�Ƚ���� k�� �̻��ΰ�?
            for (auto j : i.second) {
                userId[j]++;
            }
        }
    }

    //id_list Ž��
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
*   1. report �迭�� Ž���ϸ鼭 ���ڿ��Ľ� : ����id - �Ű��� ����id 
*   2. �Ľ��� ������ �̿��Ͽ� �Ű� ���� ���� id + �Ű��� ����id �� ����
*   3. �Ű�� ������ ������ ������ map Ž��
*       - Ž���� id�� map�� key���� ������ k �̻� �ΰ�?
*       - k �̻��� ��� �Ű��� ������ ī��Ʈ
*   4. id_list Ž���ϸ鼭 ī��Ʈ ������ ����ִ� map�� ���Ͽ� ���
*/