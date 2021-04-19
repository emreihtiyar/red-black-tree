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

    printf("----DOUBLE----\n");
    node_d* root_d = init(3.32);
    insert(root_d, 2.34);
    insert(root_d, 4.55);
    insert(root_d, 2.25);
    insert(root_d, 4.75);
    insert(root_d, 8.14);
    insert(root_d, 14.87);
    printf("root_d: %f\n",root_d->data);
    in_order_travelsal(root_d);
    printf("\n");

    printf("----STRING----\n");
    node_s* root_s = init("hatice");
    insert(root_s, "emre");
    insert(root_s, "arab");
    printf("root_s: %s\n",root_s->data);
    in_order_travelsal(root_s);
    printf("\n");

    return 0;
}