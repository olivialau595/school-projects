// Olivia Lau
// September 7, 2016
// Compilers: Professor King
// Stack of Binary Trees
// binTree.c

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int bool;
#define true 1
#define false 0

struct element {
    struct node *binarytree;    // should be a pointer
    char name;
};

struct node {
    char data;
    struct node *left;
    struct node *right;
};

typedef struct element ELEMENT;
typedef struct node NODE;

ELEMENT mystack[MAX];
int size = -1;

void usermanual();
void push();
NODE* pop();
void printree(NODE*);
void add(char);
NODE* insert(NODE*, char);
int search(NODE*, char, int);

main () {
    int option = 1;
    char userinput;
    char symbol;

    NODE* root = NULL;
    ELEMENT first;
    size++;
    first.name = 'o';
    first.binarytree = insert(root, '8');
    mystack[size] = first;

    usermanual();

    while (option) {
        printf("\nEnter a command: ");
        scanf("%c", &userinput);
        userinput = toupper(userinput);

        switch (userinput) {
        case 'U':
            push();
            break;
        case 'O':
            pop();
            break;
        case 'A':
            printf("Enter symbol to add: ");
            scanf("%s", &symbol);
            add(symbol);
            break;
        case 'S':
            printf("Enter symbol to search: ");
            scanf("%s", &symbol);
            
            int found =-1;
            int i = size;
            do{
                found = search(mystack[i].binarytree, symbol, 0);
                printf("found is %d\n", found);
                i--;
            }while(i < size+1 && found == -1);
            
            if(found > -1)
                printf("Found %c at depth %d\n", symbol, found);
            break;
        case 'Q':
            option = 0;
            break;
        default:
            printf("Not a command\n");
            break;
        }

        scanf("%c", &userinput);
    }

    exit(0);
}


void usermanual() {
    printf("\nU: push an empty tree onto the stack");
    printf("\nO: pop the top tree off the stack");
    printf("\nA: add a symbol to the binary tree at the top of the stack");
    printf("\nS: search for a symbol");
    printf("\nQ: quit");
}


void push() {
    if (size == (MAX - 1)) {
        printf("Out of memory: stack is full\n");
        return;
    } else {
        ELEMENT elem;
        NODE *root = NULL;
        
        elem.name = 't';
        elem.binarytree = NULL;
        size++;
        mystack[size] = elem;
    }
    return;

}


void printtree(NODE *top)
{
    printf("Tree includes %c\n", top -> data);
    if(top -> left != NULL)
        printtree(top -> left);
    if(top -> right != NULL)
        printtree(top -> right);
}


NODE* pop() {
    NODE *top;
    if (size == 0) {
        printf("ERROR: Stack only contains base.\n");
        return NULL;
    } else {
        top = mystack[size].binarytree;
        size--;
        printtree(top);
        return top;
    }
}


void add( char symbol)
{
    mystack[size].binarytree = insert(mystack[size].binarytree, symbol);
    printf("Added %c into the tree\n", symbol);
    fflush(stdout);
    return;
    
}


NODE* insert(NODE *curr, char symbol)
{
    if (curr == NULL) {
        NODE *temp;
        temp = (NODE *) malloc(sizeof(NODE));
        temp -> data = symbol;
        temp -> left = NULL;
        temp -> right = NULL;

        printf("   current data is %c\n", temp -> data);
        printf("   size is %d\n", size);
        printf("   pointer is %p\n", temp);
        fflush(stdout);
        return temp;
    }

    if (curr -> data > symbol)
        curr -> left = insert(curr -> left, symbol);
    else if (curr -> data < symbol)
        curr -> right = insert(curr -> right, symbol);
    else
        printf("INFO: Tree already contains %c\n", symbol);

    return curr;
}


int search(NODE* tree, char symbol, int depth)
{
    printf("data is %c\n", tree -> data);
    if(tree == NULL) 
        return -1;
    else if(tree -> data == symbol)
        return depth;
    else if(tree -> data > symbol)
        search(tree -> left, symbol, depth+1);
    else
        search(tree -> right, symbol, depth+1);
}



