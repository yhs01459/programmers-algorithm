
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, string> m1; // ������ȣ - �������ð�
    map<string, int> m2; // ������ȣ - �����ð�

    for (string str : records) {
        //���ڿ� �Ľ�
        int index = str.find(' ');
        string time = str.substr(0, index);
        string carNum = str.substr(index+1);
        int index2 = carNum.find(' ');
        string inOut = carNum.substr(index2 + 1);
        carNum = carNum.substr(0, index2);
        
        
        if (inOut == "IN") {
            m1.insert({ carNum, time });
        }
        else if (inOut == "OUT") {
            map<string, string>::iterator iter;
            iter = m1.find(carNum);
            string k = iter->second; 
            m1.erase(iter);
            int h = stoi(time.substr(0, 2));
            int min = stoi(time.substr(3, 2));

            h = h - stoi(k.substr(0, 2));
            min = min - stoi(k.substr(3, 2));
            if (min < 0) {
                min = 60 + min;
                h = h - 1;
            }
            min = h * 60 + min; //������ ����
            if (m2.find(carNum) == m2.end()) {
                m2.insert({ carNum , min });
            }
            else {
                m2[carNum] += min;
            }
            
        }
    }
    //������ ����� ������ ������ ����� ���� ���
   while (!m1.empty()) {
        map<string, string>::iterator iter;
        iter = m1.begin();
        int h = 23;
        int min = 59;
        h = h - stoi(iter->second.substr(0, 2));
        min = min - stoi(iter->second.substr(3, 2));
        min = h * 60 + min; //������ ����
        if (m2.find(iter->first) == m2.end()) {
            m2.insert({ iter->first , min });
        }
        else {
            m2[iter->first] += min;
        }
        m1.erase(iter);
    }
    
    //��ݰ��
   for (auto it = m2.begin(); it != m2.end(); it++) {
        int sum = 0;

        int t = it->second;
        if (t <= fees[0]) {
            sum = fees[1];
        }
        else {
            sum = fees[1];
            while (t - fees[0] >= fees[2]) {
                sum += fees[3];
                t = t - fees[2];
            }
            sum += fees[3];
        }
        answer.push_back(sum);
    }
    return answer;
}

int main() {
    vector<int> answer;
    vector<int> fees = { 180, 5000, 10, 600 };
    vector<string> records = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };
    answer = solution(fees, records);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
    }
}
/*
    - ���ڿ� �Ľ�
*   - IN�� ������ ������ȣ��, �ð��� ���
*   - OUT�� ������ ��ϵ� �������� ������ȣ�� Ȯ���ϰ� �ð��� ���
*   - ���� �ð��� ������ȣ�� MAP�� ����
*   - �ݺ� �� SET�� ���� �����ִٸ�, 23:59 �����ߴٰ� �����Ͽ� ��� �� �ٽ� MAP�� ����
*   - MAP�� ũ�⸸ŭ �ݺ��Ͽ� �� ������ȣ�� �����ð��� ���� ��������� ��� �� ANSWER ���Ϳ� ����
*/