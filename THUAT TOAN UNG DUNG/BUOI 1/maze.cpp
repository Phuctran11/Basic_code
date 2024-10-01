//Tim so buoc di it nhat de thoat khoi me cung
#include <bits/stdc++.h>
using namespace std;
 
const int dx[] = {1, -1, 0, 0}; // Di chuyển xuống, lên, phải, trái
const int dy[] = {0, 0, 1, -1};
 
int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    r--; c--; // Chuyển sang chỉ số 0
 
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
 
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    q.push({r, c});
    visited[r][c] = true;
 
    int steps = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto current = q.front();
            q.pop();
            int x = current.first;
            int y = current.second;
 
            // Kiểm tra nếu đã ra ngoài mê cung
            if (x < 0 || x >= n || y < 0 || y >= m) {
                cout << steps << endl;
                return 0;
            }
 
            // Thêm các ô lân cận vào hàng đợi
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
 
                // Kiểm tra điều kiện biên
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    // Nếu ra ngoài mê cung, in ra số bước và kết thúc
                    cout << steps + 1 << endl;
                    return 0;
                }
 
                if (!visited[nx][ny] && A[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        steps++;
    }
 
    cout << '-1' << endl; // Không tìm thấy đường thoát
    return 0;
}