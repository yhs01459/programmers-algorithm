
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, string> in; // 차량번호 - 입출차시간
    map<string, int> parkingTime; // 차량번호 - 누적시간

    for (string str : records) {
        //문자열 파싱
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
            string inTime = iter->second;  // 입차 시간
            in.erase(iter);
            int h = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));

            h = h - stoi(inTime.substr(0, 2));
            minute = minute - stoi(inTime.substr(3, 2));
            if (minute < 0) {
                minute = 60 + minute;
                h = h - 1;
            }
            minute = h * 60 + minute; //분으로 통일
            if (parkingTime.find(carNum) == parkingTime.end()) {
                parkingTime.insert({ carNum , minute });
            }
            else {
                parkingTime[carNum] += minute;
            }
            
        }
    }

    //입차한 기록은 있으나 출차한 기록이 없는 경우
   while (!in.empty()) {
        map<string, string>::iterator iter;
        iter = in.begin();
        int h = 23;
        int minute = 59;
        h = h - stoi(iter->second.substr(0, 2));
        minute = minute - stoi(iter->second.substr(3, 2));
        minute = h * 60 + minute; //분으로 통일
        if (parkingTime.find(iter->first) == parkingTime.end()) {
            parkingTime.insert({ iter->first , minute });
        }
        else {
            parkingTime[iter->first] += minute;
        }
        in.erase(iter);
    }
    
    //요금계산
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
    - 문자열 파싱을 해준다. 시간 - 차량 번호 - 입차 및 출차 정보
*   - IN이 들어오면 차량번호와, 시간을 기록
*   - OUT이 들어오면 기록된 용지에서 차량번호를 확인하고 시간을 계산
*   - 계산된 시간과 차량번호를 MAP에 저장
*   - 반복 후 SET에 값이 남아있다면, 23:59 출차했다고 가정하여 계산 후 다시 MAP에 저장
*   - MAP의 크기만큼 반복하여 각 차량번호의 누적시간에 대한 주차요금을 계산 후 ANSWER 벡터에 저장
*/