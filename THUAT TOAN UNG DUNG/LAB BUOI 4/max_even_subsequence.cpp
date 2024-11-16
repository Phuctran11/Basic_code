#include <iostream>
#include <algorithm>
#include <climits> //sử dụng hằng số giới hạn của kiểu dữ liệu long long

using namespace std;
const int N = 1e6+1;
int n;
long long a[N];// mảng số
long long S0[N], S1[N];// lưu tổng số chẵn và tổng số lẻ
bool B0[N], B1[N];//theo dõi tổng chẵn hay tổng lẽ có tồn tại hay ko

void input(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
}

void solve(){
    if (a[0] % 2 == 0){ // kiểm tra số đầu tiên chẵn hay lẻ và tạo mang mảng lưu trữ tổng
        S0[0] = a[0];
        B0[0] = true;
        B1[0] = false;
    } else {
        S1[0] = a[0];
        B0[0] = false;
        B1[0] = true;
    }

    for (int i = 1; i<n; i++){
        if (a[i] % 2 == 0){ //xử lý số chẵn
            if (B0[i-1]){ //nễu có tổng chẵn trước đó
                if (S0[i-1] > 0){
                    S0[i] = S0[i-1] + a[i];
                } else {
                    S0[i] = a[i]; // nếu tổng chẵn < 0 thì gán bằng số hiện tại
                }
                B0[i] = true;
            } else{ // nếu không có tổng chẵn trước đó
                S0[i] = a[i];
                B0[i]=true;
            }

            if (B1[i-1]){ // nếu có tổng lẻ trước đó
                S1[i] = S1[i-1] + a[i];
                B1[i] = true;
            } else{
                B1[i]= false;
            }

        } else{ // xử lý số lẻ
            if(B1[i-1]){ // nếu có tổng lẻ trước đó
                S0[i] = S1[i-1] + a[i];
                B0[i] = true;
            } else {
                B0[i] = false;
            }

            if(B0[i-1]){ // nếu có tổng chẵn trước đó
                if(S0[i-1] >0){
                    S1[i] = S0[i-1] + a[i];
                } else{
                    S1[i] = a[i];
                }
                B1[i]= true;
            } else {
                S1[i] = a[i];
                B1[i] = true;
            }
        }
    }

    long long ans = -1e18;
    for (int i=0; i<n; i++){
        if (B0[i] && ans < S0[i]){
            ans = S0[i]; // tìm tổng lớn nhất của số chẵn
        }
    }

    if (ans % 2 != 0) { // nếu tổng lớn nhất là số lẻ thì tìm số lẻ nhỏ nhất để trừ
        long long smallestOdd = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 != 0) {
                smallestOdd = min(smallestOdd, a[i]); // tìm số lẻ nhỏ nhất
            }
        }
        if (smallestOdd != LLONG_MAX) {
            ans -= smallestOdd;
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}