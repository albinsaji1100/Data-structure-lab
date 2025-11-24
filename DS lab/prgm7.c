#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lchild, *rchild;
};

struct node *insert(struct node *root, int data)
{
    struct node *t1, *t2, *t;
    t1 = root;
    t2 = (struct node*)0;

    while (t1 != (struct node*)0 && t1->data != data)
    {
        t2 = t1;
        if (data < t1->data)
            t1 = t2->lchild;
        else
            t1 = t2->rchild;
    }

    if (t1 != (struct node*)0)
        printf("Duplicate");
    else
    {
        t = (struct node*)malloc(sizeof(struct node));
        t->data = data;
        t->lchild = t->rchild = (struct node*)0;  

        if (root == (struct node*)0)
            root = t;
        else
        {
            if (data < t2->data)
                t2->lchild = t;
            else
                t2->rchild = t;
        }
        printf("%d is inserted", data);
    }
    return root;
}

void inorder(struct node *root)
{
    if (root != (struct node*)0)
    {
        inorder(root->lchild);
        printf("%d\t", root->data);
        inorder(root->rchild);
    }
}

struct node *search(struct node *root, int item)   

