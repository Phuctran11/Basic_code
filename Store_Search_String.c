// A database contains a sequence of key k1, k2, ..., kn which are strings (1<=n<=100000). Perform a sequence of actions of two kinds:
// · find k: find and return 1 if k exists in the database, and return 0, otherwise
// · insert k: insert a key k into the database and return 1 if the insertion is successful (k does not exist in the database) and return 0 if the insertion is failed (k exists in the database)
// Note that the length of any key is greater than 0 and less than or equal to 50.
// Input
// Two blocks of information. The first block contains a key of (k1,k2,...,kn) in each line. The first block is terminated with a line containing *. The second block is a sequence of actions of two finds described above: each line contains 2 string: cmd and k in which cmd = find or insert and k is the key (parameter of the action). The second block is terminated with a line containing ***. Note that the number of actions can be up to 100000.
// Output
// Each line contains the result (0 or 1) of the corresponding action.
// Example
// Input
// computer
// university
// school
// technology
// phone
// *
// find school
// find book
// insert book
// find algorithm
// find book
// insert book
// ***
// Output
// 1
// 0
// 1
// 0
// 1
// 0




#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int result;

typedef struct node{
    char word[50];
    struct node *left;
    struct node *right;

} node;

node *makenode( const char *u)
{
    node *newnode = (node*)malloc(sizeof(node));
    strncpy(newnode->word, u, 49);
    newnode->word[49] = '\0';
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *insertword ( node *r, const char *u)
{
    if ( r == NULL) 
    {
        // result = 1;
        return makenode(u);
    }

    int c = strcmp(r->word, u);
    if ( c == 0)
    {
        // result = 0;
        return r;
    }
    else if ( c < 0)
    {
        r->right = insertword(r->right, u);
    }
    else {
        r->left = insertword( r->left, u);
    }
    return r;

}


int findword ( node *r, const char *u)
{
    if ( r == NULL) return 0;
    int c = strcmp( r->word, u);
    if ( c == 0)
    {
        return 1;
    }
    else if ( c < 0)
    {
        return findword(r->right, u);
    }
    else {
        return findword(r->left, u);
    }
}

void freetree( node *r)
{
    if ( r == NULL) return;
    freetree( r->left);
    freetree( r->right);
    free(r);
    r = NULL;
}

int main()
{
    node *root = NULL;
    //nhap du lieu
    while (1)
    {
        char text[256];
        scanf("%s", text);
        if( text[0] == '*') break;
        else root = insertword(root, text);
    }

    //thuc hien cau lenh
    while ( 1 )
    {
        
        result = 0; //khoi tao lai gia tri ton tai
        char cmd[256];
        scanf ("%s", cmd);
        if ( strcmp(cmd, "***") == 0) break;
        else if ( strcmp(cmd, "insert") == 0)
        {
            char tu1[50];
            scanf("%s", tu1);
            if (findword(root, tu1) == 0)
            {
                root = insertword(root, tu1);
                printf("1\n");
            }
            else printf("0\n");
            
        }
        else if ( strcmp(cmd, "find") == 0)
        {
            char tu2[50];
            scanf("%s", tu2);
            printf("%d\n", findword(root, tu2));
        }
    }
    freetree(root);
}