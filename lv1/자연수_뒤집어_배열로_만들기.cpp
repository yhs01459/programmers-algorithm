#include<iostream>
#include<vector>

using namespace std;

vector<int> solution(long long n) {
	vector<int> answer;
	while (n >= 10) {
		answer.push_back(n % 10);
		n /= 10;
	}
	answer.push_back(n);
	
	return answer;
};

int main() {
	long long n;
	cin >> n;
	vector<int> ans;
	ans = solution(n);
	if (!ans.empty())
	{
		for (int i = 0;i < ans.size();i++) {
			cout << ans[i];
		}
	}
	else {
		cout << "배열이 비어있습니다.";
	}
	
};

