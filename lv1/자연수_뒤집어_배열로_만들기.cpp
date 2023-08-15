#include<iostream>
#include<vector>
using namespace std;


vector<int> answer(long long n) {
	vector<int> temp;
	while (n>0) {
		int temp2;
		temp.push_back(n%10);
		n /= 10;
	}
};
int main() {
	long long  n;
	cin >> n;
	vector<int> ans;
	ans = answer(n);
}