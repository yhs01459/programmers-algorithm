#include<iostream>
#include<string>
using namespace std;
//p�� y�� ���� 

bool py(string s) {
	bool answer = false;
	int countP=0;
	int countY=0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'p'||s[i]=='P') {
			countP++;
		}
		else if (s[i] == 'y'||s[i]=='Y') {
			countY++;
		}
	}
	if (countP == countY) {
		answer = true;
	}
	return answer;

}

int main() {
	string a;
	cin >> a;
	if (py(a) == true)
	{
		cout << "p�� y�� ������ �����մϴ�.";
	}
};
