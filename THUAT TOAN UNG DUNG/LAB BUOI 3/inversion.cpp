#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;

int const MOD = 1e9+7;
int n, a[maxn];
int temp[maxn];

//ham hop nhat 2 mang va tra ve so luong cap nghich dao khi hop nhat
int merge(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int inv_count = 0;

    while ((i <= mid ) && (j <= right)) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            inv_count = (inv_count + (mid +1- i)) % MOD;
        }
    }
    //cop nhung phan tu con lai cua nua ben trai vao mang trung gian
    while (i <= mid )
        temp[k++] = a[i++];
    //cop nhung phan tu con lai cua nua ben phai vao mang trung gian
    while (j <= right)
        temp[k++] = a[j++];
    //cop nhung phan tu da duoc hop nhat vao mang goc
    for (i = left; i <= right; i++)
        a[i] = temp[i];

    return inv_count;
}

int mergeSort(int left, int right){
    int mid, inv_count = 0;
    if(right > left){
        mid = (right + left) / 2;
        inv_count = (inv_count+ mergeSort(left, mid)) % MOD;
        inv_count = (inv_count+ mergeSort(mid+1, right)) % MOD;
        inv_count = (inv_count+ merge(left, mid, right))%MOD;
    }
    return inv_count;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for ( int i = 1; i<= n; i++){
        cin >> a[i];
    }
    cout << mergeSort(1, n);
    return 0;
}