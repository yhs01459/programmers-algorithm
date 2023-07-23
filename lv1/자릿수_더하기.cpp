#include<iostream>

using namespace std;

int solution(int n) {
	int sum = 0;
	if (n < 10) {
		return n;
	}
	else {
		while ((n / 10)>0) {
			sum += (n % 10);
			n = n / 10;
		}
		return sum+n;
	}
}

int main() {
	int n = 987;
	cout << solution(n);
}