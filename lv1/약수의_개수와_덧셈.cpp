#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    vector<int> plus;
    vector<int> minus;
    for (int i = left; i <= right; i++) {
        int count = 0; // 약수의 개수
        for (int j = 1; j <= i; j++) {
            if (i%j==0) { // i나누기 j를 했을 때 나머지가 0이면 j는 i의 약수
                count++;
            }
        }
        if (count % 2 == 0) { //약수의 개수가 짝수면 plus 벡터에 홀수면 minus 벡터에 저장
            plus.push_back(i);
        }
        else {
            minus.push_back(i);
        }
    }

    //조건에 맡게 계산해준다.
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