#include <stdio.h>
#include "rbt-first.h"
int main(int argc, char const *argv[])
{
    const int n_tree = 8;
    int tree[] = {10, 9, 20, 1, 100, 98, 18, 23};

    node *root = NULL;
    for (short i = 0; i < n_tree; i++)
    {
        root = add(root, tree[i]);
    }

    printf("root: %d \n", root->data);
    printf("root->left: %d \n", root->left->data);
    printf("root->right: %d \n", root->right->data);
    printf("root->left->left: %d \n", root->left->left->data);

    inOrderTravel(root);
    printf("\n");
    preOrderTravel(root);
    printf("\n");
    postOrderTravel(root);
    printf("\n");

    printf("-------------------------ROTATION LEFT---------------------------------\n");
    root = rotationLeft(root); //Left Rotasyonu düzgün çalışıyormu bunu deniyorum
    inOrderTravel(root);
    printf("\n");
    preOrderTravel(root);
    printf("\n");
    postOrderTravel(root);
    printf("\n");

    printf("-------------------------ROTATION RIGHT---------------------------------\n");
    root = rotationRight(root); //Right Rotasyonu düzgün çalışıyormu bunu deniyorum
    inOrderTravel(root);
    printf("\n");
    preOrderTravel(root);
    printf("\n");
    postOrderTravel(root);
    printf("\n");

    //! Double Roatationlaı denemek için defterdeki örneği kullanacağım
    printf("-------------------------DOUBLE ROTATION---------------------------------\n");
    //const int n_tree2 = 8;
    int tree2[] = {4, 15, 16, 13, 3, 5, 2, 18};

    node *root2 = NULL;
    root2 = add(root2, tree2[0]);
    root2 = add(root2, tree2[1]);
    root2 = add(root2, tree2[2]);
    root2 = rotationLeft(root2);
    root2 = add(root2, tree2[3]);
    root2 = add(root2, tree2[4]);
    root2 = add(root2, tree2[5]);
    root2 = rotationLeftRight(root2);
    root2 = add(root2, tree2[6]);
    root2 = add(root2, tree2[7]);

    inOrderTravel(root2);
    printf("\n");
    preOrderTravel(root2);
    printf("\n");
    postOrderTravel(root2);
    printf("\n");

    return 0;
}