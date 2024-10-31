// Given a sequence of n integers a=a
// 1, . . ., an. A subsequence of a consists of contiguous elements of a 
// (for example, ai, ai+1, . . . ,aj). 
// The weight of a subsequence is defined to be the sum of its elements. 
// A subsequence is called even-subsequnce if its weight is even. 
// Find the even-subsequence of a having largest weight.
// Example
// Input
// 4
// 1  2  -3  4
// Output
// 4

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX 1000000
int a[MAX];
int n;

int MaxLeft(int i, int m){
    int ans = a[m], sum = 0;
    for ( int k = m; k >= i; k--){
        sum += a[k];
        ans = max(ans, sum);
    }
    return ans;
}

int MaxRight(int m, int j){
    int ans = a[m], sum = 0;
    for (int k = m; k<= j; k++){
        sum += a[k];
        ans = max(ans, sum);
    }
    return ans;
}

int SubSeqMax(int i, int j){
    if ( i==j) return a[i];
    int m = (i+j)/2;
    int wL = SubSeqMax(i,m);
    int wR = SubSeqMax(m+1,j);

    int wLM = MaxLeft(i, m);
    int wRM = MaxRight(m+1, j);
    int wM = wLM + wRM;

    return max(max(wL, wR), wM);

}


int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int maxWeight = SubSeqMax(0, n-1);
    if(maxWeight % 2 == 0){
        cout << maxWeight << endl;
    } else {
        int smallestOdd = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 != 0) {
                smallestOdd = min(smallestOdd, a[i]);
            }
        }
        
        if (smallestOdd == INT_MAX) {
            cout << "NOT_FOUND" << endl;
        } else {
            cout << maxWeight - smallestOdd << endl;
        }
    }

    return 0;
}

