#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 10; 
int H, W; 
pair<int, int> rectangles[MAX_SIZE]; 
bool mark[100][100]; 

bool check(int vx, int vy, int hk, int wk) {
    
    if (vx + wk > W || vy + hk > H) return false;
    for (int i = vx; i < vx + wk; i++)
        for (int j = vy; j < vy + hk; j++)
            if (mark[i][j]) return false; 
    return true;
}

void doMark(int vx, int vy, int hk, int wk, bool mark_value) {
    
    for (int i = vx; i < vx + wk; i++)
        for (int j = vy; j < vy + hk; j++)
            mark[i][j] = mark_value;
}

bool Try(int k) {
    if (k == MAX_SIZE || rectangles[k].first == 0) return true; 
    for (int vx = 0; vx <= W; vx++) {
        for (int vy = 0; vy <= H; vy++) {
            int hk = rectangles[k].first;
            int wk = rectangles[k].second;
           
            if (check(vx, vy, hk, wk)) {
                doMark(vx, vy, hk, wk, true); 
                if (Try(k + 1)) return true; 
                doMark(vx, vy, hk, wk, false); 
            }
            
            if (check(vx, vy, wk, hk)) {
                doMark(vx, vy, wk, hk, true); 
                if (Try(k + 1)) return true; 
                doMark(vx, vy, wk, hk, false); 
            }
        }
    }
    return false; 
}

int main() {
    cin >> H >> W; 
    int n;
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> rectangles[i].first >> rectangles[i].second; 
    }
    
    
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            mark[i][j] = false;

    
    if (Try(0)) {
        cout << 1 << endl; 
    } else {
        cout << 0 << endl; 
    }
    return 0;
}