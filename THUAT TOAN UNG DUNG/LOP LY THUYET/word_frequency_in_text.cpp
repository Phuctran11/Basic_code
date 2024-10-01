#include <iostream>
#include <string>
using namespace std;

struct Node {
    string word;
    int occ;
    Node *left;
    Node *right;

    Node(const string &u) : word(u), occ(1), left(nullptr), right(nullptr) {}
};

Node* insert(Node *r, const string &u) {
    if (r == nullptr) return new Node(u);
    if (r->word == u) {
        r->occ += 1;
        return r;
    }
    if (u < r->word) {
        r->left = insert(r->left, u);
    } else {
        r->right = insert(r->right, u);
    }
    return r;
}

Node* input(Node *r) {
    string text;
    while (cin >> text) {
        r = insert(r, text);
    }
    return r;
}

void printResult(Node *r) {
    if (r == nullptr) return;
    printResult(r->left);
    cout << r->word << " " << r->occ << endl;
    printResult(r->right);
}

void freeTree(Node *r) {
    if (r == nullptr) return;
    freeTree(r->left);
    freeTree(r->right);
    delete r;
}

int main() {
    Node *root = nullptr;
    root = input(root);
    printResult(root);
    freeTree(root);
    return 0;
}
