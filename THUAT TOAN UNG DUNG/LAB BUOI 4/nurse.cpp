#include <iostream>
using namespace std;

const int N = 1e3+2, MOD =  1e9+7;
int n, k1, k2, f[N][2], res;

void input(){
    cin >> n >> k1 >> k2;

}

void proccess(){
    f[0][0] = f[0][1] =1; 
    // f[i][0] la so cach lap lich den ngay thu i va ngay thu i la ngay nghi
    // f[i][1] la so cach lap lich den ngay thu i va ngay thu i la ngay ket thuc cua mot dot lam viec
    for (int i = 1; i<= n; i++){
        for(int j = k1; j<=k2; j++){
            if(i-j < 0) break;
            f[i][1] += f[i-j][0];
            f[i][1] %= MOD;
        }
        f[i][0] = f[i-1][1];
    }
    res = (f[n][0] + f[n][1]) % MOD;
    cout << res << endl;

}

int main(){
    input();
    proccess();
    return 0;
}
