/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> t;
    
            for(int i = 0; i < numRows; i++){
                vector<int> row(i+1, 1);
    
                for(int j = 1; j<i; j++){
                    row[j] = t[i-1][j-1] + t[i-1][j];
                }
    
                t.push_back(row);
            }
            return t;
        }
    };

int main(){
    Solution s;
    int numRows = 5;
    vector<vector<int>> result = s.generate(numRows);
    
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}