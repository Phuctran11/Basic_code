#include <stdio.h>
#define Max 100

int n, M, T;
int heso[Max];
int x[Max];
int count = 0;

int check(int v, int k) {
    if (k < n) return 1;
    return T + v * heso[k] == M;
}

void Try(int k) {
    for (int v = 1; v <= (M - T) / heso[k]; v++) {
        if (check(v, k)) {
            x[k] = v;
            T = T + x[k] * heso[k];
            if (k == n) count++;
            else Try(k + 1);
            T = T - x[k] * heso[k];
        }
    }
}

int main() {
    T = 0;
    
    scanf("%d", &n);
    scanf("%d", &M);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &heso[i]);
    }
    Try(1);
    printf("%d\n", count);
    return 0;
}