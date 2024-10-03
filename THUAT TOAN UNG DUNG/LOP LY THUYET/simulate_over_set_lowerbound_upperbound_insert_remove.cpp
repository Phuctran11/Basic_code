// Description
// Given a set S of n integers a1, a2, ..., an. Perform a sequence of operations below:
// min_greater_equal v: return a minimum element of S which is greater or equal to v, and return NULL if no such element exists
// min_greater v: return a minimum element of S which is greater than v, and return NULL if no such element exists
// insert v: insert v into S
// remove v: remove v from S

// Input
// Line 1: contains a positive integer n (1 <= n <= 100000)
// Line 2: contains a1, a2, ..., an (1 <= ai <= 100000)
// Each subsequent line contains an operations described above.
// The input is terminated with a line containing #

// Output
// Write the result of each operation min_greater or min_greater_equal.

// Example
// Input
// 5
// 3 2 4 5 9 
// min_greater_equal 10
// min_greater 7
// min_greater_equal 7
// min_greater_equal 4
// insert 5
// insert 5
// min_greater 8
// min_greater 1
// min_greater_equal 6
// min_greater_equal 8
// #

// Output 
// NULL
// 9
// 9
// 4
// 9
// 2
// 9
// 9

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Hàm chèn nút vào cây
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

// Hàm tìm nút nhỏ nhất trong cây
Node* findMin(Node* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

// Hàm xóa nút khỏi cây
Node* remove(Node* node, int key) {
    if (!node) return node;
    if (key < node->key)
        node->left = remove(node->left, key);
    else if (key > node->key)
        node->right = remove(node->right, key);
    else {
        if (!node->left) return node->right;
        else if (!node->right) return node->left;
        Node* minNode = findMin(node->right);
        node->key = minNode->key;
        node->right = remove(node->right, minNode->key);
    }
    return node;
}

// Hàm tìm giá trị nhỏ nhất lớn hơn hoặc bằng v
Node* minGreaterEqual(Node* node, int v) {
    if (!node) return nullptr;
    if (node->key >= v) {
        Node* leftResult = minGreaterEqual(node->left, v);
        return leftResult ? leftResult : node;
    }
    return minGreaterEqual(node->right, v);
}

// Hàm tìm giá trị nhỏ nhất lớn hơn v
Node* minGreater(Node* node, int v) {
    if (!node) return nullptr;
    if (node->key > v) {
        Node* leftResult = minGreater(node->left, v);
        return leftResult ? leftResult : node;
    }
    return minGreater(node->right, v);
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        root = insert(root, a);
    }

    string operation;
    while (cin >> operation) {
        if (operation == "#") {
            break;
        } else if (operation == "min_greater_equal") {
            int v;
            cin >> v;
            Node* result = minGreaterEqual(root, v);
            if (result) {
                cout << result->key << endl;
            } else {
                cout << "NULL" << endl;
            }
        } else if (operation == "min_greater") {
            int v;
            cin >> v;
            Node* result = minGreater(root, v);
            if (result) {
                cout << result->key << endl;
            } else {
                cout << "NULL" << endl;
            }
        } else if (operation == "insert") {
            int v;
            cin >> v;
            root = insert(root, v);
        } else if (operation == "remove") {
            int v;
            cin >> v;
            root = remove(root, v);
        }
    }

    return 0;
}
