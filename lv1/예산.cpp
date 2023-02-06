#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    vector<int> temp = d;
    sort(temp.begin(), temp.end()); //오름차순으로 정렬
    int count = 0;
    int sum = 0;
    if (d.size() == 1) { // 부서가 한개인 경우
        if (d[0] <= budget) {
            answer = 1;
        }
    }
    else { //부서가 2개 이상
        sum = temp[0];
        count += 1;
        for (int i = 0; i < temp.size() - 1; i++) {
            int next = temp[i + 1];
            if (sum + next <= budget) {
                sum += next;
                count++;
            }
            else {
                break;
            }
        }
        answer = count;
    }
    
   

    return answer;
}