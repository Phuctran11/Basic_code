#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int a[n+1][m+1];
    int s[n+1][m+1];
    for ( int i = 0; i<=n; i++){
        s[i][0] = 0;
        a[i][0] = 0;
    }
    for (int j=0; j<=0; j++){
        s[0][j] = 0;
        a[0][j] = 0;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        }
    }
    int k; cin >> k;
    for (int i=0; i<k; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << s[c][d] - s[a-1][d] - s[c][b-1] + s[a-1][b-1] << endl;
    }
    return 0;
}