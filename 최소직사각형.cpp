#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    vector<int> row;
    vector<int> col;
    
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] > sizes[i][1]) {
            row.push_back(sizes[i][0]);
            col.push_back(sizes[i][1]);
        }
        else
        {
            row.push_back(sizes[i][1]);
            col.push_back(sizes[i][0]);
        }
    }
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());

    answer = row.back() * col.back();


    return answer;


}