#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right, *left;
};

struct Node *createNode(int data)
{
    struct Node *sanjay = (struct Node *)malloc(sizeof(struct Node));
    if (sanjay != NULL)
    {
        sanjay->data = data;
        sanjay->left = NULL;
        sanjay->right = NULL;
        return sanjay;
    }
    else
    {
        printf("Memory fULL\n");
        return NULL;
    }
}

void inOrderShow(struct Node *sanjay)
{
    if (sanjay != NULL)
    {
        inOrderShow(sanjay->left);
        printf("%d\t", sanjay->data);
        inOrderShow(sanjay->right);
    }
}

struct Node *inorderPre(struct Node *sanjay)
{
    sanjay = sanjay->left;
    while (sanjay->right != NULL)
    {
        sanjay = sanjay->right;
    }

    return sanjay;
}

struct Node *delete_A_Node(struct Node *sanjay, int key)
{
    struct Node *inpre = NULL;

    if (sanjay == NULL)
    {
        return NULL;
    }

    if (sanjay->left == NULL && sanjay->right == NULL)
    {
        free(sanjay);
        return NULL;
    }

    if (key < sanjay->data)
    {
        // delete_A_Node(sanjay->left,key);
        sanjay->left = delete_A_Node(sanjay->left, key);
    }

    else if (key > sanjay->data)
    {
        //    delete_A_Node(sanjay->right,key);
        sanjay->right = delete_A_Node(sanjay->right, key);
    }

    else
    {
        inpre = inorderPre(sanjay);
        sanjay->data = inpre->data;
        //    delete_A_Node(sanjay->left,inpre->data);
        sanjay->left = delete_A_Node(sanjay->left, inpre->data);
    }
}

void main()
{
    struct Node *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10;
    p1 = createNode(9);
    p2 = createNode(4);
    p3 = createNode(11);
    p4 = createNode(2);
    p5 = createNode(7);
    p6 = createNode(15);
    p7 = createNode(5);
    p8 = createNode(8);
    p9 = createNode(14);
    p10 = createNode(10);

    // connect node to each other

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p5->left = p7;
    p5->right = p8;
    p3->right = p6;
    p6->left = p9;
    p3->left = p10;

    inOrderShow(p1);
    printf("\n");

    delete_A_Node(p1, 9);
    printf("\n");
    inOrderShow(p1);
}