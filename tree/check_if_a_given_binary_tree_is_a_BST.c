// Each node of a binary tree has a field key which is the key of the node. Build a binary tree and check if the tree is a binary search tree (BST), and compute the sum of keys of nodes of the given tree (keys of the nodes are distinct and in the range 1, 2, …, 105)
// Input
// •Line 1 contains MakeRoot u: make the root of the tree having id = u
// •Each subsequent line contains: AddLeft or AddRightcommands with the format
// •AddLeft u v: create a node having id = u, add this node as a left-child of the node with id = v (if not exists)
// •AddRight u v: create a node having id = u, add this node as a right-child of the node with id = v (if not exists)
// •The last line contains * which marks the end of the input
// Output
// •Write two integers z and s in which s is the sum of keys of nodes of the tree and z = 1 if the tree is a BST and z = 0, otherwise
// Example
// Input
// MakeRoot 4
// AddRight 5 4
// AddLeft 3 4
// AddRight 8 5
// AddLeft 1 3
// AddLeft 7 8
// AddLeft 6 7
// AddRight 2 1
// AddRight 10 8
// AddLeft 9 10
// *
// Output
// 1 55


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//dinh nghia cau truc mot node cua cay nhi phan
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} node;

//tao mot node moi
node* makenode(int k){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = k;
    newnode->left = NULL;
    newnode->right = NULL;
return newnode;
}

int maxValue(struct node* node)
{
    if (node == NULL) {
        return 0;
    }
 
    int leftMax = maxValue(node->left);
    int rightMax = maxValue(node->right);
 
    int value = 0;
    if (leftMax > rightMax) {
        value = leftMax;
    }
    else {
        value = rightMax;
    }
 
    if (value < node->data) {
        value = node->data;
    }
 
    return value;
}
 
int minValue( node* node)
{
    if (node == NULL) {
        return 1000000000;
    }
 
    int leftMax = minValue(node->left);
    int rightMax = minValue(node->right);
 
    int value = 0;
    if (leftMax < rightMax) {
        value = leftMax;
    }
    else {
        value = rightMax;
    }
 
    if (value > node->data) {
        value = node->data;
    }
 
    return value;
}
 
/* Returns true if a binary tree is a binary search tree */
int isBST(node* node)
{
    if (node == NULL)
        return 1;
 
    /* false if the max of the left is > than us */
    if (node->left != NULL && maxValue(node->left) > node->data)
        return 0;
 
    /* false if the min of the right is <= than us */
    if (node->right != NULL && minValue(node->right) < node->data)
        return 0;
 
    /* false if, recursively, the left or right is not a BST
     */
    if (!isBST(node->left) || !isBST(node->right))
        return 0;
 
    /* passing all that, it's a BST */
    return 1;
}

int sum ( node *r)
{
    if ( r == NULL ) return 0;
    return r->data + sum(r->left) + sum(r->right);
}

//tim kiem 1 node co gia tri x tren cay nhi phan
node* findnode(node *r,int x){
    if(r == NULL)return NULL;
    if(r->data == x)return r;
    node *p = findnode(r->left,x);
    if(p != NULL)return p;
    return findnode(r->right,x);
}

void addleftchild(node *r, int u, int v){
    node *h = findnode(r,u);
    if(h == NULL  ) return;
    if (h ->left != NULL) return;
    node *newnode = makenode(v);
    h->left = newnode;
    
}

//them node con ben phai cho node ton tai
void addrightchild(node *r,int u,int v){
    node *h = findnode(r,u);
    if(h == NULL  ) return;
    if ( h->right != NULL) return;
    node *newnode = makenode(v);
    h->right = newnode;
   
}

//giai phong bo nho
void freeTree(node* r){
    if(r == NULL) return;
    freeTree(r->left);
    freeTree(r->right);
    free(r); r = NULL;
}

int main(){
    node *root = makenode(10);
    
    
    while(1){
        char cmd[256];
        scanf("%s", cmd);
        if( cmd[0] == '*') 
        {
            printf ( "%d %d\n", isBST(root), sum(root));
            break;
        }
        else if ( strcmp(cmd,"MakeRoot") == 0)
        {
            int x;
            scanf("%d",&x);
            root->data = x;
        }
        else if (strcmp(cmd,"AddLeft") == 0) 
        {
            int u,v;
            scanf("%d %d",&u,&v);
            addleftchild(root,v,u);
        }
        else if (strcmp(cmd,"AddRight") == 0) 
        {
            int a,b;
            scanf("%d %d",&a,&b);
            addrightchild(root,b,a);
        }
        
    }
    
    freeTree(root);
}
