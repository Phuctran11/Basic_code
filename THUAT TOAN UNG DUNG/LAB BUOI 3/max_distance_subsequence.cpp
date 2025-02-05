/*Description
Given N elements (2≤ N ≤100,000) on a straight line at positions x
1
,…, x
N
 (0≤ x
i 
≤1,000,000,000).
The distance of a subset of N elements is defined to be the minimum distance between two elements.
Find the subset of N given elements containing exactly C elements such that the distance is maximal.
Input
The first line contains a positive integer T (1 <= T <= 20) which is the number of test cases. 
Subsequent lines are T test cases with the following format:
Line 1: Two space-separated integers: N and C
Lines 2: contains  x1, x
2
, . . . , x
N

Output
For each test case output one integer: the distance of the subset found.

Example
input
1
5 3
1 2 8 4 9
output
3

Explain: Jonh can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.
*/

#include <bits/stdc++.h>
#define MAXN  1000005
using namespace std;

int t;
int n, c, a[MAXN];

bool check( int distance){
    int sl = 1;
    int i = 1, j = 2;
    while (i<n){
        while (j<=n && a[j] - a[i] < distance) ++j;
        if ( j<= n) sl++;
        if ( sl>=c) return true;
        i = j;
        j++;
    }
    return false;
}

int MaxDistance(){
    int l = 0, r = a[n] - a[1];
    while ( l<=r){
        int mid = (l+r)/2;
        if ( check(mid)) l = mid+1;
        else r = mid -1;
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--){
        cin >> n >> c;
        for (int i = 1; i<=n; i++){
            cin >> a[i];
        }
        sort(a+1, a+n+1);
        cout << MaxDistance() << endl;
    }
    return 0;
}