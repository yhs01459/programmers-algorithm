#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> temp = arr;
    if (arr.size() > 1) {
        sort(temp.begin(), temp.end(), comp); // �������� ����
        int min = temp.back(); 
        for (int i = 0; i < arr.size(); i++) { // ���� ���� �� �����Ͽ� answer �迭�� ����
            if (min == arr[i]) {

            }
            else {
                answer.push_back(arr[i]);
            }
            
        }
    }
    else {
        answer.push_back(-1);
    }




    return answer;
}

int main() {
    vector<int> v = { 1,2,4,3 };
    vector<int> ans = solution(v);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }

}