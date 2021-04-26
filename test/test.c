#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    pre_order_travelsal_int(root);// Root Sağ Sol
    printf("\n");
    post_order_travelsal_int(root);//Sol Sağ Orta
    printf("\n");

    printf("%d is there in tree: %s\n",0, is_there(root, 0) ? "Var":"Yok");
    printf("%d is there in tree: %s\n",142, is_there(root, 31) ? "Var":"Yok");

    printf("int minimum: %d\n", min(root));
    printf("int maximum: %d\n", max(root));


    printf("----DOUBLE----\n");
    node_d* root_d = init(3.32);
    insert(root_d, 2.34);
    insert(root_d, 8.14);
    insert(root_d, 4.75);
    insert(root_d, 2.25);
    insert(root_d, 14.87);
    insert(root_d, 4.55);
    printf("root_d: %f\n",root_d->data);
    in_order_travelsal(root_d);
    printf("\n");

    printf("double minimum: %F\n", min(root_d));
    printf("double maximum: %F\n", max(root_d));
    printf("%.2F is there in tree: %s\n",3.21, is_there(root_d, 3.21) ? "Var":"Yok");
    printf("%.2F is there in tree: %s\n",3.32, is_there(root_d, 3.32) ? "Var":"Yok");


    //TODO: min veya max sonucu tek düğüm olduğunda hata veriyor (fix delete'e girilen x değeri NULL olursa).
    //TODO:Silinecek düğümün sağ alt ağacında tek eleman varsa veya hiç eleman yoksa (NULL) hata veriyor.
    //delete(&root, 12); //Doğru çalışıyor.
    //delete(&root, 11); //Doğru çalışıyor.
    //delete(&root, 12); //Doğru çalışıyor.

    //root = delete(root, 15); //root'da doğru çalışıyor

//! String işlemlerinde hata var, yeni eklendiğinde sadece root ve en son kalıyor
//TODO: Yukarıdaki hata sanırım döndürme fonksyonundaki root ataması nedeniyle oluşuyor

    printf("----STRING----\n");
    node_s* root_s = init("ha");
    insert(root_s, "da");
    insert(root_s, "ia");
    insert(root_s, "ea");
    insert(root_s, "ka");
    insert(root_s, "na");
    insert(root_s, "za");
    printf("root_s: %s\n",root_s->data);
    printf("root_s->right: %s\n",root_s->right->data);
    in_order_travelsal(root_s);
    printf("\n");
    printf("string minimum: %s\n", min(root_s));
    printf("string maximum: %s\n", max(root_s));
    printf("%s is there in tree: %s\n", "mahmut", is_there(root_s, "mahmut") ? "Var":"Yok");
    printf("%s is there in tree: %s\n", "za", is_there(root_s, "za") ? "Var":"Yok");

    /*
    switch (strcmp("Emre", "Amre"))
    {
    case 0:
        printf("Eşit.\n");
        break;

    case 1:
        printf("1.Daha büyük.\n");
        break;

    case -1:
        printf("2.Daha büyük.\n");
        break;
    }
    */
    return 0;
}