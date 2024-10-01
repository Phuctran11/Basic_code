// Given a TEXT which consists of a sequence of words. Each word is defined to be a sequence of contiguous characters of the alphabet (a, ..., z, A, ..., Z) and digits (0, 1, ..., 9). Other special characters are considered as delimiters between words. 
// Write a program to count the number of occurrences o(w) of each word w of the given TEXT.
// Input
// The TEXT (each word of the TEXT has length <= 20)

// Output
// Each line contains a word w and o(w) (separated by a SPACE). The words (printed to lines of the stdout) are sorted in a lexicographic order. 

// Example
// Input
// abc  def abc 
// abc abcd def 

// Output 
// abc 3
// abcd 1
// def 2


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node{
    char word[20];
    int occ;
    struct node *left;
    struct node *right;
}node;

node *makenode( char u[])
{
    node *newnode = (node*)malloc(sizeof(node));

    strncpy(newnode->word, u, 19);
    newnode->word[19] = '\0';
    newnode->occ = 1;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *insert ( node *r, char *u)
{
    if ( r == NULL) return makenode(u);
    int c = strcmp(r->word,u);
    if (c == 0)
    {
        r->occ +=1;
        return r;
    }
    if (c<0)
    {
        r->right = insert(r->right, u);
    }
    else {
        r->left = insert(r->left, u);
    }
    return r;
    
}

node *input( node *r)
{
    char text[20];
    while ( scanf("%s", text) != EOF)
    {
        r = insert(r, text);
    }
    return r;
}

void printfresult( node *r)
{
    if ( r == NULL) return ;
    printfresult(r->left);
    printf("%s %d\n", r->word, r->occ);
    printfresult(r->right);
}

void freetree (node *r)
{
    if ( r == NULL) return;
    freetree( r->left);
    freetree( r->right);
    free(r);
    r =  NULL;
}

int main()
{
    node *root = NULL;
    root = input(root);
    printfresult(root);
    freetree(root);
    
}




