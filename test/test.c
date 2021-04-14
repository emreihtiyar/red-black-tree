#include <stdio.h>
#include <stdlib.h>
#include "rbt-first.h"

int main(int argc, char const *argv[])
{
    node* root=NULL;
    
    insert(&root, 15);
    insert(&root, 20);
    insert(&root, 9);
    insert(&root, 12);
    insert(&root, 11);
    insert(&root, 21);
    insert(&root, 17);
    insert(&root, 18);

    printf("root: %d\n",root->data);
    inOrderTravel(root);// Sol Root Sağ 
    printf("\n");
    preOrderTravel(root);// Root Sağ Sol
    printf("\n");
    postOrderTravel(root);//Sol Sağ Orta
    printf("\n");

/*
    printf("root: %d\n",root->data);
    printf("root->right: %d\n",root->right->data);
    printf("root->left: %d\n",root->left->data);
    printf("root->left->right: %d\n",root->left->right->data);
    printf("root->left->right->left: %d\n",root->left->right->left->data);
*/
    
    //TODO: min veya max sonucu tek düğüm olduğunda hata veriyor (fix delete'e girilen x değeri NULL olursa).
    //TODO:Silinecek düğümün sağ alt ağacında tek eleman varsa veya hiç eleman yoksa (NULL) hata veriyor.
    //delete(&root, 12); //Doğru çalışıyor.
    //delete(&root, 11); //Doğru çalışıyor.
    //delete(&root, 12); //Doğru çalışıyor.

    delete(&root, 15); //root'da doğru çalışıyor

    printf("root: %d\n",root->data);

    inOrderTravel(root);// Sol Root Sağ 
    printf("\n");
    preOrderTravel(root);// Root Sağ Sol
    printf("\n");
    postOrderTravel(root);//Sol Sağ Orta
    printf("\n");

    return 0;
}