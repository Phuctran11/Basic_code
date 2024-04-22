// Each node of a Binary Search Tree (BST) T has a key (keys of nodes must be all different).
// Perform a sequence of operations on a Binary Search Tree T (starting from empty BST) including:
// insert k: insert a new node having key = k into T
// preorder: print (in a new line) the sequence of keys of nodes of T visited by a Pre-Order traversal (elements are separated by a SPACE character)
// postorder: print (in a new line) the sequence of keys of nodes of T visited by a Post-Order traversal (elements are separated by a SPACE character)

// Input
// Each line contains a command of three above format
// The input is terminated by a line containing #
// Output
// Write the information of preorder, postorder commands described above

// Example
// Input
// insert 5
// insert 9
// insert 2
// insert 1
// preorder
// insert 8
// insert 5
// insert 3
// postorder
// #

// Output
// 5 2 1 9
// 1 3 2 8 9 5


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;

} node;

node *makenode ( int k)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = k;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *findnode ( node *r, int u)
{
    if (r == NULL) return NULL;
    if ( r->data == u) return r;
    else if (r->data > u)
    {
        node *tmp = findnode(r->left, u);
    } 
    else {
        return findnode(r->right, u);
    }
    
}


node  *insert(node *r, int k)
{
    if ( r == NULL) return makenode(k);
    node *tmp = findnode(r, k);
    if ( tmp != NULL) return r;
    
    if (k < r->data) {
        r->left = insert(r->left, k);
    }
    else {
        r->right = insert(r->right, k);
    }
    return r;
    
    
}

void preorder(node *r)
{
    if ( r == NULL) return;
    printf("%d ", r->data);
    preorder(r->left);
    preorder(r->right);
}

void postorder( node *r)
{
    if ( r == NULL) return;
    postorder( r->left);
    postorder( r->right);
    printf("%d ", r->data);
}

void freetree( node* r)
{
    if ( r == NULL) return;
    freetree(r->left);
    freetree(r->right);
    free(r);
    r = NULL;
}

int main()
{
    node *root = NULL;

    while(1)
    {
        char cmd[10];
        scanf("%s", cmd);
        if ( strcmp(cmd, "insert") == 0)
        {
            int k;
            scanf("%d", &k);
            root = insert(root, k);
        }
        else if (strcmp(cmd, "preorder") == 0)
        {
            preorder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "postorder") == 0){
            postorder(root);
            printf("\n");
        }
        else if (cmd[0] == '#')
        {
            break;
        }
    }
    freetree(root);
}

