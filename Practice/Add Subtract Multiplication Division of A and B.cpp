#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100005];
int degree[100005], saturation[100005], colors[100005];

int DSatur() {
    // Khởi tạo mảng chứa số đỉnh kề với đỉnh i
    memset(degree, 0, sizeof(degree));
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // Khởi tạo mảng chứa màu của từng đỉnh,
    // ban đầu toàn bộ các đỉnh chưa được tô màu
    memset(colors, -1, sizeof(colors));

    // Đánh dấu các đỉnh đã được tô màu
    set<int> used_colors;

    // Tính độ bậc sắp xếp giảm dần
    for(int i = 1; i <= n; i++) 
        saturation[i] = 0;
    for(int i = 1; i <= n; i++) {
        for(auto v : adj[i]) {
            if(i != v) {
                saturation[i]++;
            }
        }
    }

    // Lặp lại cho đến khi tất cả các đỉnh đều được tô màu
    while (find(colors+1, colors+n+1, -1) != colors+n+1) {
        int max_degree = -1;
        int vertex = -1;

        // Tìm đỉnh có độ bậc lớn nhất và
        // chưa được tô màu hoặc có độ bậc bằng nhau thì chọn đỉnh có độ bậc sắp xếp giảm dần cao nhất
        for(int i = 1; i <= n; i++) {
            if(colors[i] == -1 && degree[i] > max_degree) {
                max_degree = degree[i];
                vertex = i;
            } else if (colors[i] == -1 && degree[i] == max_degree && saturation[i] > saturation[vertex]) {
                vertex = i;
            }
        }

        // Tìm màu cho đỉnh được chọn
        set<int> available_colors;
        for(auto neighbor : adj[vertex]) {
            if(colors[neighbor] != -1) {
                available_colors.insert(colors[neighbor]);
            }
        }

        // Chọn màu và cập nhật các biến
        int color = 0;
        for(int i = 1; i <= n; i++) {
            if(available_colors.find(i) == available_colors.end()) {
                color = i;
                break;
            }
        }
        colors[vertex] = color;
        used_colors.insert(color);

        for(auto neighbor : adj[vertex]) {
            degree[neighbor]--;
            saturation[neighbor]++;
        }

        degree[vertex] = -1;
    }

    // Trả về số màu ít nhất cần tô và màu của từng đỉnh
    return used_colors.size();
}

int main() {
    cin >> n >> m;
    int num_colors = DSatur();

    // Đưa ra số màu cần thiết và các đỉnh và màu tương ứng

for(int i = 1; i <= n; i++) {
cout << "Dinh " << i << ": Mau " << colors[i] << endl;
}
cout << "So mau can thiet: " << num_colors << endl;
return 0;
}
