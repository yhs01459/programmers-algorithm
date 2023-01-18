#include<iostream>
#include <map>
#include <string>
#include <vector>


using namespace std;

bool solution(vector<string> phone_book) {
    map<string, int> map1;
    bool answer = true;
    for (int i = 0; i < phone_book.size(); i++) {
        map1[phone_book[i]] = 1;
    }
    for (int i = 0; i < phone_book.size(); i++) {
        string phone_number = "";
        for (int j = 0; j, phone_book[i].size(); j++) {
            phone_number += phone_book[i][j];
            if (map1[phone_number] && phone_number != phone_book[i]) { 
                answer = false;
                break;
            }
        }
    }
    return answer;
}

int main() {
    vector<string> sample = { "119", "97674223", "1195524421" };
    bool answer = true;
    cout << answer;
}