#include <stdio.h>
#include <stdlib.h>
static int count = 0;
struct Node
{
    int data;
    struct Node *right, *left;
};

struct Node *creat_Node(int data)
{
    struct Node *sanjay = (struct Node *)malloc(sizeof(struct Node));
    sanjay->data = data;
    sanjay->left = NULL;
    sanjay->right = NULL;
    return sanjay;
}

void inOrder(struct Node *sanajy)
{
    if (sanajy != NULL)
    {
        inOrder(sanajy->left);
        printf("%d\t", sanajy->data);
        inOrder(sanajy->right);
    }
}

int checkBinarySearchTree(struct Node *sanjay)
{

    struct Node *pur = NULL;
    if (sanjay != NULL)
    {

        checkBinarySearchTree(sanjay->left);

        if (pur->data <= sanjay->data)
        {
            printf("Not a binary search tree\n");
            return 0;
        }
        pur = sanjay;
        checkBinarySearchTree(sanjay->right);
    }
    else
    {
        printf("Binary search tree \n");
        return 1;
    }
}

//
// struct Node* searchElement(struct Node *Sanjay,int valu){
void searchElement(struct Node *Sanjay, int valu)
{
    // printf("call search\n");
    if (Sanjay != NULL)
    {

        if (Sanjay->data == valu)
        {
            printf("Element present in Binary Search Tree : %d \n", Sanjay->data);
            count++;
            return;
        }
        searchElement(Sanjay->left, valu);
        searchElement(Sanjay->right, valu);
    }
    //  else{
    //     return NULL;
    //  }
}
void main()
{
    struct Node *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10;
    p1 = creat_Node(9);
    p2 = creat_Node(4);
    p3 = creat_Node(11);
    p4 = creat_Node(2);
    p5 = creat_Node(7);
    p6 = creat_Node(15);
    p7 = creat_Node(5);
    p8 = creat_Node(8);
    p9 = creat_Node(14);
    p10 = creat_Node(9);

    // connect Node

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p5->left = p7;
    p5->right = p8;
    p3->right = p6;
    p6->left = p9;

    inOrder(p1);
    printf("\n");
    // checkBinarySearchTree(p1);
    printf("\n");

    searchElement(p1, 11);
    if (!count)
    {
        printf("Element not found \n");
    }
}