#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    int temp = sqrt(n);
    if (pow(temp, 2) == n) {
        answer = pow(temp + 1, 2);
    }
    else {
        answer = -1;
    }
    return answer;
}