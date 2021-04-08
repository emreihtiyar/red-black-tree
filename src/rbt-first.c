#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "rbt-first.h"

const short RBT_BLACK = 0;
const short RBT_RED = 1;

node *add(node *root, int data)
{
    if (root == NULL)//ilk ekleme yani root boşsa
    {
        root = (node *)malloc(sizeof(node));
        root->color = RBT_BLACK;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        return root;
    }

    if (data > root->data) //gelen veri düğümden büyükse
    {
        if (root->right == NULL)//bulunduğum düğümün sağı boşsa 
        {//boş olduğundan buraya ekle
            node *tmp = (node *)malloc(sizeof(node));
            tmp->color = RBT_RED;
            tmp->data = data;
            tmp->left = NULL;
            tmp->right = NULL;
            tmp->parent=root;
            root->right = tmp;
            if (root->parent->left->color == RBT_RED){/*Renk Kontrolu yap*/}
            return root;
        }
        else
        {//sağ boş değil o zaman sağ taraf boş oluncaya kadar git
            root->right = add(root->right, data);
            return root;
        }
    }
    else //gelen veri düğümden küçükse
    {
        if (root->left == NULL)//bulunduğum düğümün sol boşsa
        {//boş olduğundan buraya ekle
            node *tmp = (node *)malloc(sizeof(node));
            tmp->color = RBT_RED;
            tmp->data = data;
            tmp->left = NULL;
            tmp->right = NULL;
            tmp->parent=root;
            root->left = tmp;
            if (root->parent->right->color == RBT_RED){/*Renk Kontrolu yap*/}
            
            return root;
        }
        else
        {//sol boş değil o zaman sol taraf boş oluncaya kadar git
            root->left = add(root->left, data);
            return root;
        }
    }
}

void inOrderTravel(node *root)
{
    if (root == NULL)
        return;
    inOrderTravel(root->left);
    printf("%d[%d] ", root->data, root->color);
    inOrderTravel(root->right);
}
void preOrderTravel(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrderTravel(root->right);
    preOrderTravel(root->left);
}
void postOrderTravel(node *root)
{
    if (root == NULL)
        return;
    postOrderTravel(root->left);
    postOrderTravel(root->right);
    printf("%d ", root->data);
}

node* rotationLeft(node* root){
    node* x = root;
    node* b = root->right->left;
    
    root = root->right;
    x->right=b;
    root->left = x;
    
    return root;
}
node* rotationRight(node* root){
    node* x = root;
    node* a = root->left->right;
    
    root = root->left;
    x->left=a;
    root->right = x;
    
    return root;
}

node* rotationRightLeft(node* root){
    node* x = root;
    node* y = root->right;
    node* z = root->right->left;
    node* c = z->left;
    node* d = z->right;

    root = z;
    x->right = c;
    y->left=d;
    root->left=x;
    root->right=y;

    return root;
}

node* rotationLeftRight(node* root){
    node* x = root;
    node* y = root->left;
    node* z = root->left->right;
    node* c = z->left;
    node* d = z->right;

    root = z;
    x->left = d;
    y->right=c;
    root->right=x;
    root->left=y;

    return root;
}