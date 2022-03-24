
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, string> in; // ������ȣ - �������ð�
    map<string, int> parkingTime; // ������ȣ - �����ð�

    for (string str : records) {
        //���ڿ� �Ľ�
        int blank = str.find(' ');
        string time = str.substr(0, blank);
        string carNum = str.substr(blank+1);
        int blank2 = carNum.find(' ');
        string inOut = carNum.substr(blank2 + 1);
        carNum = carNum.substr(0, blank2);
        
        
        if (inOut == "IN") {
           in.insert({ carNum, time });
        }
        else if (inOut == "OUT") {
            map<string, string>::iterator iter;
            iter = in.find(carNum);
            string inTime = iter->second;  // ���� �ð�
            in.erase(iter);
            int h = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));

            h = h - stoi(inTime.substr(0, 2));
            minute = minute - stoi(inTime.substr(3, 2));
            if (minute < 0) {
                minute = 60 + minute;
                h = h - 1;
            }
            minute = h * 60 + minute; //������ ����
            if (parkingTime.find(carNum) == parkingTime.end()) {
                parkingTime.insert({ carNum , minute });
            }
            else {
                parkingTime[carNum] += minute;
            }
            
        }
    }

    //������ ����� ������ ������ ����� ���� ���
   while (!in.empty()) {
        map<string, string>::iterator iter;
        iter = in.begin();
        int h = 23;
        int minute = 59;
        h = h - stoi(iter->second.substr(0, 2));
        minute = minute - stoi(iter->second.substr(3, 2));
        minute = h * 60 + minute; //������ ����
        if (parkingTime.find(iter->first) == parkingTime.end()) {
            parkingTime.insert({ iter->first , minute });
        }
        else {
            parkingTime[iter->first] += minute;
        }
        in.erase(iter);
    }
    
    //��ݰ��
   for (auto it = parkingTime.begin(); it != parkingTime.end(); it++) {
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
    - ���ڿ� �Ľ��� ���ش�. �ð� - ���� ��ȣ - ���� �� ���� ����
*   - IN�� ������ ������ȣ��, �ð��� ���
*   - OUT�� ������ ��ϵ� �������� ������ȣ�� Ȯ���ϰ� �ð��� ���
*   - ���� �ð��� ������ȣ�� MAP�� ����
*   - �ݺ� �� SET�� ���� �����ִٸ�, 23:59 �����ߴٰ� �����Ͽ� ��� �� �ٽ� MAP�� ����
*   - MAP�� ũ�⸸ŭ �ݺ��Ͽ� �� ������ȣ�� �����ð��� ���� ��������� ��� �� ANSWER ���Ϳ� ����
*/