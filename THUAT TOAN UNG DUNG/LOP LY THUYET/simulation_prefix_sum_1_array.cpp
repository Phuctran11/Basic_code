// Description
// Given a sequence of integers a
// 1
// , a
// 2
// , . . ., a
// n
// . Perform a sequence of Q queries q(i,j) that returns the sum of a
// i
// , a
// i+1
// , . . ., a
// j
// .

// Input
// Line 1: contains a positive integer n (2 <= n <= 100000)
// Line 2: contains a
// 1
// , a
// 2
// , ..., a
// n
// . (1 <= a
// i 
// <= 1000)
// Line 3: contains a positive integer Q (1 <= Q <= 100000)
// Line 3 + k (k = 1, 2, ..., Q): contains 2 positive integers i and j (1 <= i < j <= n) of the k
// th
//  query
 
// Output
// Write in each line, the result of the corresponding query read from the input

// Example
// Input
// 5
// 5 8 7 1 9 
// 4
// 1 2
// 1 5
// 1 3
// 4 5

// Output 
// 13
// 30
// 20
// 10 

#include <bits/stdc++.h> 

using namespace std;

int main() 
{ 
    int n,q; cin >> n;
    int a[n+1], S[n+1];
    a[0] = 0;
    S[0] = 0;
    for ( int i = 1; i < n+1; i++){
        cin >> a[i];
    }
    cin >> q;
    
    for ( int i = 1; i < n+1; i++){
        S[i] = S[i - 1] + a[i];
    }
    for ( int i = 1; i<=q; i++){
        int a,b;
        cin >> a >> b;
        cout << S[b] - S[a-1] << endl;
    }
    return 0;
    
}
