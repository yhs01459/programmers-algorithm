#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    vector<int> plus;
    vector<int> minus;
    for (int i = left; i <= right; i++) {
        int count = 0; // ����� ����
        for (int j = 1; j <= i; j++) {
            if (i%j==0) { // i������ j�� ���� �� �������� 0�̸� j�� i�� ���
                count++;
            }
        }
        if (count % 2 == 0) { //����� ������ ¦���� plus ���Ϳ� Ȧ���� minus ���Ϳ� ����
            plus.push_back(i);
        }
        else {
            minus.push_back(i);
        }
    }

    //���ǿ� �ð� ������ش�.
    for (int i = 0; i < plus.size(); i++) {
        answer += plus[i];
    }
    for (int i = 0; i < minus.size(); i++) {
        answer -= minus[i];
    }
    

    return answer;
}

int main() {
    int a = 13;
    int b = 17;
    cout<<solution(13, 17);
}