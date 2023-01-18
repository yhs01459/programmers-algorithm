#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> student1 = { 1,2,3,4,5 };
	vector<int> student2 = { 2,1,2,3,2,4,2,5};
	vector<int> student3 = { 3,3,1,1,2,2,4,4,5,5 };

	vector<int> count = { 0,0,0 };

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == student1[i % student1.size()]) count[0]++;
		if (answers[i] == student2[i % student2.size()]) count[1]++;
		if (answers[i] == student3[i % student3.size()]) count[2]++;
	}
	vector<int> temp = count;
	sort(temp.begin(), temp.end());
	int max = 0;
	max = temp.back();
	for (int i = 0; i < 3; i++) {
		if (max == count[i]) {
			
			answer.push_back(i+1);
		}
	}

	return answer;
}
int main() {
	vector<int> answer{ 1,2,3,4,5 };

	answer = solution(answer);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}
}

