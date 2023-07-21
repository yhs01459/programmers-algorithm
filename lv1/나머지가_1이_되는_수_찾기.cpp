#include<iostream>
using namespace std;

int solution(int n) {
	/* 规过1 */
	/* 
	int x = 0;
	for(int 2 = 1;i<n;i++){
	  if(n%i==1){
		  x = i;
		  break;
	  }
	}*/

	/* 规过2 */
	int x = 2;
	while(x<n){
		if (n % x == 1) {
			break;
		}
		x++;
		}
	
	return x;
};

int main() {
	int n; 
	cin >> n; 
	int answer = solution(n);
	cout << answer;
}