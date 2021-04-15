#include <stdio.h>
#include <stdlib.h>
#include "rbt-first.h"

int main(int argc, char const *argv[])
{
    node* root = init(15); 
    insert(root, 20);
    insert(root, 9);
    insert(root, 12);
    insert(root, 11);
    insert(root, 21);
    insert(root, 17);
    insert(root, 18);
    insert(root, 0);

    printf("root: %d\n",root->data);
    in_order_travelsal(root);// Sol Root Sağ 
    printf("\n");
    pre_order_travelsal(root);// Root Sağ Sol
    printf("\n");
    post_order_travelsal(root);//Sol Sağ Orta
    printf("\n");

    printf("%d is there in tree: %s\n",0, is_there(root, 0) ? "Var":"Yok");

    
    //TODO: min veya max sonucu tek düğüm olduğunda hata veriyor (fix delete'e girilen x değeri NULL olursa).
    //TODO:Silinecek düğümün sağ alt ağacında tek eleman varsa veya hiç eleman yoksa (NULL) hata veriyor.
    //delete(&root, 12); //Doğru çalışıyor.
    //delete(&root, 11); //Doğru çalışıyor.
    //delete(&root, 12); //Doğru çalışıyor.

    root = delete(root, 15); //root'da doğru çalışıyor

    printf("root: %d\n",root->data);

    in_order_travelsal(root);// Sol Root Sağ 
    printf("\n");
    pre_order_travelsal(root);// Root Sağ Sol
    printf("\n");
    post_order_travelsal(root);//Sol Sağ Orta
    printf("\n");

    node_d* tree_str = init(3.33);
    printf("treee_str: %F\n", tree_str->data);


    return 0;
}