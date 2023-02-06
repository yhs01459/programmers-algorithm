#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    vector<int> temp = d;
    sort(temp.begin(), temp.end()); //������������ ����
    int count = 0;
    int sum = 0;
    if (d.size() == 1) { // �μ��� �Ѱ��� ���
        if (d[0] <= budget) {
            answer = 1;
        }
    }
    else { //�μ��� 2�� �̻�
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