/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


Constraints:

1 <= n <= 45
*/

#include <iostream>

using namespace std;

class Solution {
    public:
        int climbStairs(int n) {
            if(n <= 2) return n;
            int dp[n+1]; //dp[i] to save distinct ways to to climb to the step i
            // create initial value
            dp[1] = 1; // step 1 has 1 ways
            dp[2] = 2; // step 2 has 2 ways
            // using dynamic programming
            // recurrence formula(cong thuc truy hoi): dp[i] = dp[i-1] + dp[i-2]
            for(int i = 3; i<=n; i++){
                dp[i] = dp[i-1] + dp[i-2];
            }
            return dp[n];
        }
    };

int main() {
    Solution s;
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;
    cout << "Number of distinct ways to climb to the top: " << s.climbStairs(n) << endl;
    return 0;
}