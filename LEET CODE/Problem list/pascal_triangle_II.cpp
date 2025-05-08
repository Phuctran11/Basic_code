/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]

Constraints:

0 <= rowIndex <= 33
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int> row(rowIndex + 1, 1); //the row[i] has i + 1 elements
    
            for(int i = 1; i<rowIndex; i++){
                for(int j = i; j>0; j--){
                    row[j] = row[j] + row[j-1];
                }
            }
            return row;
    
        }
    };

int main(){
    Solution s;
    int rowIndex = 4;
    vector<int> result = s.getRow(rowIndex);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}