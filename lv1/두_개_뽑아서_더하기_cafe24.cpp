#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    map<int, int> m;

    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {

            if (m[numbers[i] + numbers[j]] == 0) {
                m[(numbers[i] + numbers[j])]++;
                answer.push_back(numbers[i] + numbers[j]);

            }
        }
    }

    sort(answer.begin(), answer.end());



    return answer;
}