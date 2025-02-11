/*Description
Given 3 points on the plane A(xA, yA), B(xB, yB), C(xC, yC). Write a program to check if a point A is on the segment (BC)

Input
Line 1: contains a positive integer n (1 <= n <= 100000) - the number of testcases
Line i+1(i = 1, 2, ..., n): contains 6 integers xA, yA, xB, yB, xC, yC (values are between -10000 and 10000) of the ith testcase.
 
Output
Write in each line 1 if the answer of the corresponding testcase if true, and write 0,  otherwise.

Example
Input 
3
5 6 2 5 8 7
2 5 5 6 8 7
5 6 2 5 8 6

Output
1
0
0
*/

#include <iostream>

using namespace std;

bool check_segment(int xA, int yA, int xB, int yB, int xC, int yC) {
    return (xA - xB) * (yC - yB) == (xC - xB) * (yA - yB) && //kiểm tra 3 điểm thẳng hàng
            ((xB <= xA && xA <= xC) || (xB >= xA && xA >= xC)) && //kiểm tra xA nằm giữa xB và xC
            ((yB <= yA && yA <= yC) || (yB >= yA && yA >= yC)); //kiểm tra yA nằm giữa yB và yC
}

int main(){
    int n; cin >> n;
    for(int i =1; i<=n; i++){
        int xA, yA, xB, yB, xC, yC;
        cin >> xA >> yA >> xB >> yB >> xC >> yC;
        cout << check_segment(xA, yA, xB, yB, xC, yC) << endl;
    }
}