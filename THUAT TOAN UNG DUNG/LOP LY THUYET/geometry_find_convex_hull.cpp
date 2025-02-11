/*Description
Given a set of points P1, P2, ..., Pn on the plane: point Pi has coordinate (xi,yi).
Compute the convex hull of the given points: The convex hull is a subset of the given points that forms a convex polygon that contains all the given points.

Input
Line 1: contains a positive integer n (3 <= n <= 100000)
Line i+1 (i = 1, 2, ..., n): contains 2 integers xi, yi (-1000 <= xi, yi <= 1000)

Output 
Line 1: writes the number of points of the convex hull found 
Subsequent lines, each line contains 2 integers which are the x-coordinate and y-coordinate of a point of the convex hull found 

Example 
Input 
6
4 5
5 3
5 6
2 5
8 7
3 7

Output
4
5 3
8 7
3 7
2 5

TÌM BAO LỒI CỦA 1 TẬP HỢP ĐIỂM VÀ LIỆT KÊ CÁC ĐIỂM NẰM TRÊN ĐƯỜNG BAO LỒI
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc lưu tọa độ của một điểm
struct Point {
    int x, y;
};

// Hàm tiện ích để lấy phần tử kế tiếp từ trên cùng của ngăn xếp (stack)
Point nextToTop(vector<Point>& S) {
    Point p = S.back();  // Lấy phần tử trên cùng của ngăn xếp
    S.pop_back();        // Loại bỏ phần tử đó
    Point res = S.back(); // Lấy phần tử kế tiếp
    S.push_back(p);      // Đưa phần tử đã lấy ra trở lại ngăn xếp
    return res;
}

// Hàm tiện ích để hoán đổi hai điểm
void swap(Point& p1, Point& p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// Hàm tiện ích tính bình phương khoảng cách giữa hai điểm
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Hàm xác định hướng quay của bộ ba điểm (p, q, r)
// Trả về:
// 0 -> Ba điểm thẳng hàng
// 1 -> Quay theo chiều kim đồng hồ (Clockwise)
// 2 -> Quay ngược chiều kim đồng hồ (Counterclockwise)
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// Hàm so sánh để sắp xếp các điểm dựa trên điểm tham chiếu `p0`
bool compare(Point p1, Point p2, Point p0) {
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return distSq(p0, p2) >= distSq(p0, p1);  // Nếu thẳng hàng, chọn điểm xa hơn
    return o == 2;
}

// Hàm tìm bao lồi của tập điểm
void convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return;  // Không thể tạo bao lồi nếu số điểm nhỏ hơn 3

    // Tìm điểm có hoành độ nhỏ nhất (hoặc tung độ nhỏ nhất nếu có cùng hoành độ)
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
            ymin = points[i].y;
            min = i;
        }
    }

    // Đưa điểm có hoành độ nhỏ nhất lên vị trí đầu tiên
    swap(points[0], points[min]);

    // Sắp xếp các điểm còn lại theo hướng quay quanh `p0`
    Point p0 = points[0];
    sort(points.begin() + 1, points.end(), [p0](Point p1, Point p2) {
        return compare(p1, p2, p0);
    });

    // Khởi tạo ngăn xếp chứa 3 điểm đầu tiên
    vector<Point> S;
    S.push_back(points[0]);
    S.push_back(points[1]);
    S.push_back(points[2]);

    // Xử lý các điểm còn lại
    for (int i = 3; i < n; i++) {
        // Loại bỏ các điểm không cần thiết khi không quay ngược chiều kim đồng hồ
        while (S.size() > 1 && orientation(nextToTop(S), S.back(), points[i]) != 2)
            S.pop_back();
        S.push_back(points[i]);
    }

    // In ra kết quả
    cout << S.size() << endl;
    for (auto& p : S)
        cout << p.x << " " << p.y << endl;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);

    // Nhập tọa độ của n điểm
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // Tìm và in bao lồi
    convexHull(points);

    return 0;
}
