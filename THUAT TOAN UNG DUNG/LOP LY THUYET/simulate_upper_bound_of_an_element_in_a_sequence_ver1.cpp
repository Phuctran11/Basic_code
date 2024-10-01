// Input
// Line 1: contains n (1 <= n <= 100000)
// Line 2: contains a1, a2, ..., an (1 <= ai <= 1000000)
// Each subsequent line contains a query of format above. The input is terminated with a line containing #

// Output
// Write in each line the result of the corresponding query.
 
// Example
// Input
// 5
// 4 8 2 3 7 
// next 2
// next 7
// next 9
// next 6
// next 1
// #

// Output 
// 3
// 8
// -1
// 7
// 2


#include <iostream>
#include <string>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;

    Node(int v) : value(v), left(nullptr), right(nullptr) {} //Tao mot node moi co gia tri dau vao la v va co 2 con tro null ban dau
};

Node* insert(Node* node, int v){
    if ( node == nullptr) return new Node(v);

    if (v < node->value){
        node->left = insert(node->left, v);
    } else {
        node->right = insert(node -> right, v);
    }
    return node;
}

int get_result(Node* node, int k){
    int x = -1;
    while (node != nullptr){
        if (node->value > k){
            x = node->value;
            node = node->left;
        } else{
            node = node->right;
        }
    }
    return x;
}

int main(){
    int n;
    cin >> n;
    string command;
    Node* root = nullptr;
    for (int i = 0; i<n; i++){
        int value;
        cin >> value;
        root = insert(root, value);
    }
    while(true){
        cin >> command;
        if (command == "#") break;
        if (command == "next"){
            int k;
            cin >> k;
            cout << get_result(root, k) << endl;
        }
    }
    return 0;
}