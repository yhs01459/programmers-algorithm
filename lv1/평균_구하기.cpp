#include<iostream>
#include<vector>

using namespace std;

double average(vector<int> a) {
	double sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i];
	}
	double avg = sum / a.size();
	return avg;
}

int main() {
	vector<int> arr = { 1,2,3,4 };
	double answer;
	answer = average(arr);
	cout << answer;


}