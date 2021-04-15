#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "rbt-first.h"

const short RBT_BLACK = 0;
const short RBT_RED = 1;

//! Yardımcı Fonksiyonlar: Rotate, min, max, min node, min max, transplant, travel 
void leftRotate(node **root, node *x)
{ //TODO: İsmi LEFT olmasına rağmen anlatım biraz garip bu nedenle kullanılan yerleri bir karşılaştır.
    node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;

    if (x->parent == NULL)
        root = &y; //! DETAYLI DÜŞÜN
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    
    y->left = x;
    x->parent = y;
}
void rightRotate(node **root, node *x)
{
    node *y = x->left;
    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;
    y->parent = x->parent;

    if (x->parent == NULL)
        root = &y; //! DETAYLI DÜŞÜN
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right = x;
    x->parent = y;
}
node* minimum_node(node *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}
node* maximum_node(node *node)
{
    while (node->right != NULL)
        node = node->right;
    return node;
}
void transplant(node **root, node *u, node *v)
{
    if (u->parent == NULL)
        (*root) = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else if (u == u->parent->right)
        u->parent->right = v;
    if (v != NULL)
        v->parent = u->parent;
}
int minimum(node* root){
    return minimum_node(root)->data;
}
int maximum(node* root){
    return maximum_node(root)->data;
}
node* find_node(node* root, int data){
    if (root == NULL)
        return NULL;
    else if (root->data == data)
        return root;
    else if (data > root->data)
        return find_node(root->right, data);
    else
        return find_node(root->left, data);
}
int is_there(node* root, int data)
{
    // find node NULL döndüyse yani bulamadı ise NULL && 1 -> 0 döndürür, eğer bulduysa yani null dışında birey döndüyse all && 1 ->1 döndürür. 
    return find_node(root, data) && 1;
}

//! Veri tiplerine bağlı dolaşımlar
void travelsal_error(node* root){
    printf("Hatalı Bir veri tipi yada ağaç olmayan bir yapı girdisinde bulundunuz");
}

// int
void in_order_travelsal_int(node *root)
{
    if (root == NULL)
        return;
    in_order_travelsal_int(root->left);
    printf("%d [%c] ", root->data, root->color == RBT_RED ? 'R':'B'); //a > b ? a : b;
    in_order_travelsal_int(root->right);
}
void pre_order_travelsal_int(node *root)
{
    if (root == NULL)
        return;
    printf("%d [%c] ", root->data, root->color == RBT_RED ? 'R':'B'); //a > b ? a : b;
    pre_order_travelsal_int(root->right);
    pre_order_travelsal_int(root->left);
}
void post_order_travelsal_int(node *root)
{
    if (root == NULL)
        return;
    post_order_travelsal_int(root->left);
    post_order_travelsal_int(root->right);
    printf("%d [%c] ", root->data, root->color == RBT_RED ? 'R':'B'); //a > b ? a : b;
}
/*
//float
void in_order_travelsal_float(node *root)
{
    if (root == NULL)
        return;
    in_order_travelsal_float(root->left);
    printf("%f [%c] ", root->data, root->color == RBT_RED ? 'R':'B'); //a > b ? a : b;
    in_order_travelsal_float(root->right);
}
void pre_order_travelsal_float(node *root)
{
    if (root == NULL)
        return;
    printf("%f [%c] ", root->data, root->color == RBT_RED ? 'R':'B'); //a > b ? a : b;
    pre_order_travelsal_float(root->right);
    pre_order_travelsal_float(root->left);
}
void post_order_travelsal_float(node *root)
{
    if (root == NULL)
        return;
    post_order_travelsal_float(root->left);
    post_order_travelsal_float(root->right);
    printf("%f [%c] ", root->data, root->color == RBT_RED ? 'R':'B'); //a > b ? a : b;
}
*/
//! Eleman ekleme
void fix_insert(node **root, node *child)
{
    node *uncle = NULL;
    /*Babanın rengi kırmızsı ve eklenen düğüm her ha zaman kırmızı 
    bu ndenele kırmızının çocuğu kırmızı oldu ve düzeltilmeye ihtiyaç var
    */
    if (child == (*root) || child->parent == NULL)
    {
        (*root)->color = RBT_BLACK;
        return;
    }
    if (child->parent->parent == NULL)
        return;

    while (child->parent->color == RBT_RED)
    {
        if (child->parent == child->parent->parent->right)
        {
            uncle = child->parent->parent->left;
            if (uncle != NULL && uncle->color == RBT_RED)
            {
                uncle->color = RBT_BLACK;
                child->parent->color = RBT_BLACK;
                child->parent->parent->color = RBT_RED;
                child = child->parent->parent;
            }
            else
            {
                if (child == child->parent->left)
                {
                    child = child->parent;
                    rightRotate(root, child);
                }
                child->parent->color = RBT_BLACK;
                child->parent->parent->color = RBT_RED;
                leftRotate(root, child->parent->parent);
            }
        }
        else
        {
            uncle = child->parent->parent->right;
            if (uncle != NULL && uncle->color == RBT_RED)
            {
                uncle->color = RBT_BLACK;
                child->parent->color = RBT_BLACK;
                child->parent->parent->color = RBT_RED;
                child = child->parent->parent;
            }
            else
            {
                if (child == child->parent->right)
                {
                    child = child->parent;
                    leftRotate(root, child);
                }
                child->parent->color = RBT_BLACK;
                child->parent->parent->color = RBT_RED;
                rightRotate(root, child->parent->parent);
            }
        }
        if (child == (*root))
        {
            break;
        }
    }
    (*root)->color = RBT_BLACK;
}

node *add(node *root, int data)
{
    if (root == NULL) //ilk ekleme yani root boşsa
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
        if (root->right == NULL) //bulunduğum düğümün sağı boşsa
        {                        //boş olduğundan buraya ekle
            node *tmp = (node *)malloc(sizeof(node));
            tmp->color = RBT_RED;
            tmp->data = data;
            tmp->left = NULL;
            tmp->right = NULL;
            tmp->parent = root;
            root->right = tmp;

            return root;
        }
        else
        { //sağ boş değil o zaman sağ taraf boş oluncaya kadar git
            root->right = add(root->right, data);
            return root;
        }
    }
    else //gelen veri düğümden küçükse
    {
        if (root->left == NULL) //bulunduğum düğümün sol boşsa
        {                       //boş olduğundan buraya ekle
            node *tmp = (node *)malloc(sizeof(node));
            tmp->color = RBT_RED;
            tmp->data = data;
            tmp->left = NULL;
            tmp->right = NULL;
            tmp->parent = root;
            root->left = tmp;
            
            return root;
        }
        else
        { //sol boş değil o zaman sol taraf boş oluncaya kadar git
            root->left = add(root->left, data);
            return root;
        }
    }
}
void insert_int(node **rootAdres, int data)
{ //!Geri dönüşü void olan bir ekleme fonksyonu
    node *root = (*rootAdres);
    if ((root) == NULL) //İlk ekleme yani Root düğümünün eklenmesi
    {
        //Yeni bir node oluştur ve root artık bu node'u göstersin
        node *temp = (node *)malloc(sizeof(node));
        temp->color = RBT_BLACK;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        temp->parent = NULL;
        (*rootAdres) = temp;
        return;
    }
    node *iterParent = NULL;
    node *iter = root;
    //iter NULL oluncaya kadar devam et bu sayede gelen datayı yerleştireceğimiz yeri buluruz
    while (iter != NULL)
    {
        iterParent = iter; //iterin Parent'ını tutmak parent atamasında ve gelen datayı yerleştirmede işe yarayacak
        if (data > iter->data)
            iter = iter->right;
        else
            iter = iter->left;
    }
    //Create New Node
    node *temp = (node *)malloc(sizeof(node));
    temp->color = RBT_RED; //Yeni düğüm KIRMIZI
    temp->data = data;
    temp->parent = iterParent; // yeni düğümünün parent'ı iterin parentı yani NULL olan yaprağın atası
    temp->left = NULL;
    temp->right = NULL;

    //iter NULL'idi ve yeni düğüm iterin parent'ının altına eklenecekti bunun nereye ekleneceğini buluyoruz
    if (data > iterParent->data)
        iterParent->right = temp;
    else
        iterParent->left = temp;

    // if the grandparent is null, simply return
    if (temp->parent->parent == NULL)
    {
        return;
    }

    fix_insert(rootAdres, temp);
}

void insert_float(node **rootAdres, float data)
{ //!Geri dönüşü void olan bir ekleme fonksyonu
    node *root = (*rootAdres);
    if ((root) == NULL) //İlk ekleme yani Root düğümünün eklenmesi
    {
        //Yeni bir node oluştur ve root artık bu node'u göstersin
        node *temp = (node *)malloc(sizeof(node));
        temp->color = RBT_BLACK;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        temp->parent = NULL;
        (*rootAdres) = temp;
        return;
    }
    node *iterParent = NULL;
    node *iter = root;
    //iter NULL oluncaya kadar devam et bu sayede gelen datayı yerleştireceğimiz yeri buluruz
    while (iter != NULL)
    {
        iterParent = iter; //iterin Parent'ını tutmak parent atamasında ve gelen datayı yerleştirmede işe yarayacak
        if (data > iter->data)
            iter = iter->right;
        else
            iter = iter->left;
    }
    //Create New Node
    node *temp = (node *)malloc(sizeof(node));
    temp->color = RBT_RED; //Yeni düğüm KIRMIZI
    temp->data = data;
    temp->parent = iterParent; // yeni düğümünün parent'ı iterin parentı yani NULL olan yaprağın atası
    temp->left = NULL;
    temp->right = NULL;

    //iter NULL'idi ve yeni düğüm iterin parent'ının altına eklenecekti bunun nereye ekleneceğini buluyoruz
    if (data > iterParent->data)
        iterParent->right = temp;
    else
        iterParent->left = temp;

    // if the grandparent is null, simply return
    if (temp->parent->parent == NULL)
    {
        return;
    }

    fix_insert(rootAdres, temp);
}


node* init(int data){
        node* root = (node *)malloc(sizeof(node));
        root->color = RBT_BLACK;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        return root;
}

//!Silme işlemi
void fix_delete(node **rootAdress, node *x)
{ //TODO: x NULL geldiğinde hata oluyor bu durumu değerlendir
    node *s;
    node *root = (*rootAdress);
    //printf("fix_delete \n");
    /*
    if (x == root)
    {
        node* leftMax = maximum_node(x->left);
        leftMax->parent->right = leftMax->left;
        if (leftMax->left != NULL)
            leftMax->left->parent = leftMax->parent;
        root = leftMax;
        leftMax->parent = NULL;
        x=leftMax;
    }
    */
    while (x != root && x->color == RBT_BLACK)
    {
        if (x == x->parent->left)
        {
            perror("fix_delete->if\n");
            s = x->parent->right;
            if (s->color == RBT_RED)
            {
                //case 3.1
                perror("fix_delete->if->if\n");
                s->color = RBT_BLACK;
                x->parent->color = RBT_RED;
                leftRotate(rootAdress, x->parent);
                s = x->parent->right;
            }

            if (s->left->color == RBT_BLACK && s->right->color == RBT_BLACK)
            {
                //case 3.2
                perror("fix_delete->if->if2\n");
                s->color = RBT_RED;
                x = x->parent;
            }
            else
            {
                if (s->right->color == RBT_BLACK)
                {
                    // case 3.3
                    perror("fix_delete->else->if\n");
                    s->left->color = RBT_BLACK;
                    s->color = RBT_RED;
                    rightRotate(rootAdress, s);
                    s = x->parent->right;
                }
                //case 3.4
                perror("fix_delete->if->else->case3.4\n");
                s->color = x->parent->color;
                x->parent->color = RBT_BLACK;
                s->right->color = RBT_BLACK;
                leftRotate(rootAdress, x->parent);
                x = root;
            }
        }
        else
        {
            perror("fix_delete->else\n");
            s = x->parent->left;
            if (s->color == RBT_RED)
            {
                //case 3.1
                perror("fix_delete->else->if\n");
                s->color = RBT_BLACK;
                x->parent->color = RBT_RED;
                rightRotate(rootAdress, x->parent);
                s = x->parent->left;
            }

            if (s->right->color == RBT_BLACK && s->right->color == RBT_BLACK)
            {
                // case 3.2
                perror("fix_delete->else->if2\n");
                s->color = RBT_RED;
                x = x->parent;
            }
            else
            {
                if (s->left->color == RBT_BLACK)
                {
                    // case 3.3
                    perror("fix_delete->else->else\n");
                    s->right->color = RBT_BLACK;
                    s->color = RBT_RED;
                    leftRotate(rootAdress, s);
                    s = x->parent->left;
                }
                //case 3.4
                perror("fix_delete->else->case3.4\n");
                s->color = x->parent->color;
                x->parent->color = RBT_BLACK;
                s->left->color = RBT_BLACK;
                rightRotate(rootAdress, x->parent);
                x = root;
            }
        }
    }
    x->color = RBT_BLACK;
}
void delete(node **rootAdress, int key)
{
    node *root = (*rootAdress);
    node *x = NULL;
    node *y = NULL;
    node *z = NULL;

    while (root != NULL)
    {
        if (root->data == key)
        {
            z = root;
            break;
        }
        if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    if (z == NULL)
    {
        printf("Couldn't find key in the tree\n");
        return;
    }

    //printf("x\n");
    y = z;
    short y_orginal_color = y->color;
    //printf("xx\n");
    if (z->left == NULL) 
    {
    //silinecek düğümün solu boş bu nedenle, silinen düğüm yerine sağ alt düğüm yazılır.
        x = z->right;
        //printf("if->transplant öncesi\n");
        transplant(rootAdress, z, z->right);
        //printf("if->transplant sonrası\n");
    }
    else if (z->right == NULL)
    {
        //silinecek düğümün sağı boş bu nedenle, silinen düğüm yerine sol alt düğüm yazılır.
        x = z->left;
        //printf("else if->transplant öncesi\n");
        transplant(rootAdress, z, z->left);
        //printf("else if->transplant sonrası\n");
    }
    else
    {
        y = minimum_node(z->right);
        y_orginal_color = y->color;
        x = y->right;
        //printf("y: %d\n", y->data);
        if (y->parent == z)
        {
            if (x != NULL)
                x->parent = y;
        }
        else
        {
            transplant(rootAdress, y, y->right);
            y->right = z->right;
            if (y->right != NULL)
                y->right->parent = y;
        }
        transplant(rootAdress, z, y);
        y->left = z->left;
        if (y->left != NULL)
            y->left->parent = y;
        y->color = z->color;
    }

    free(z);
/*
    if (x == NULL)
    {
        fix_delete(rootAdress, y);
        return;
    }
    
*/
    if (y_orginal_color == RBT_BLACK)
    {
        //printf("fix delete öncesi\n");
        fix_delete(rootAdress, x);
        //printf("fix delete sonrası\n");
    }
}

//!DENEMELER
void leftRotate2(node* root, node *x)
{ //TODO: İsmi LEFT olmasına rağmen anlatım biraz garip bu nedenle kullanılan yerleri bir karşılaştır.
    node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y; //! DETAYLI DÜŞÜN
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}
void rightRotate2(node* root, node *x)
{
    node *y = x->left;
    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;
    y->parent = x->parent;

    if (x->parent == NULL)
        root = y; //! DETAYLI DÜŞÜN
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right = x;
    x->parent = y;
}

void fix_insert2(node* root, node *child)
{
    node *uncle = NULL;
    /*Babanın rengi kırmızsı ve eklenen düğüm her ha zaman kırmızı 
    bu ndenele kırmızının çocuğu kırmızı oldu ve düzeltilmeye ihtiyaç var
    */
    if (child == root || child->parent == NULL)
    {
        root->color = RBT_BLACK;
        return;
    }
    if (child->parent->parent == NULL)
        return;

    while (child->parent->color == RBT_RED)
    {
        if (child->parent == child->parent->parent->right)
        {
            uncle = child->parent->parent->left;
            if (uncle != NULL && uncle->color == RBT_RED)
            {
                uncle->color = RBT_BLACK;
                child->parent->color = RBT_BLACK;
                child->parent->parent->color = RBT_RED;
                child = child->parent->parent;
            }
            else
            {
                if (child == child->parent->left)
                {
                    child = child->parent;
                    rightRotate2(root, child);
                }
                child->parent->color = RBT_BLACK;
                child->parent->parent->color = RBT_RED;
                leftRotate2(root, child->parent->parent);
            }
        }
        else
        {
            uncle = child->parent->parent->right;
            if (uncle != NULL && uncle->color == RBT_RED)
            {
                uncle->color = RBT_BLACK;
                child->parent->color = RBT_BLACK;
                child->parent->parent->color = RBT_RED;
                child = child->parent->parent;
            }
            else
            {
                if (child == child->parent->right)
                {
                    child = child->parent;
                    leftRotate2(root, child);
                }
                child->parent->color = RBT_BLACK;
                child->parent->parent->color = RBT_RED;
                rightRotate2(root, child->parent->parent);
            }
        }
        if (child == root)
        {
            break;
        }
    }
    root->color = RBT_BLACK;
}
void insert2(node* root, int data)
{ //!Geri dönüşü void olan bir ekleme fonksyonu
    /*if (root == NULL) //İlk ekleme yani Root düğümünün eklenmesi
    {
        //Yeni bir node oluştur ve root artık bu node'u göstersin
        node *temp = (node *)malloc(sizeof(node));
        temp->color = RBT_BLACK;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        temp->parent = NULL;
        root = temp;
        return root;
    }*/
    node *iterParent = NULL;
    node *iter = root;
    //iter NULL oluncaya kadar devam et bu sayede gelen datayı yerleştireceğimiz yeri buluruz
    while (iter != NULL)
    {
        iterParent = iter; //iterin Parent'ını tutmak parent atamasında ve gelen datayı yerleştirmede işe yarayacak
        if (data > iter->data)
            iter = iter->right;
        else
            iter = iter->left;
    }
    //Create New Node
    node *temp = (node *)malloc(sizeof(node));
    temp->color = RBT_RED; //Yeni düğüm KIRMIZI
    temp->data = data;
    temp->parent = iterParent; // yeni düğümünün parent'ı iterin parentı yani NULL olan yaprağın atası
    temp->left = NULL;
    temp->right = NULL;

    //iter NULL'idi ve yeni düğüm iterin parent'ının altına eklenecekti bunun nereye ekleneceğini buluyoruz
    if (data > iterParent->data)
        iterParent->right = temp;
    else
        iterParent->left = temp;

    // if the grandparent is null, simply return
    if (temp->parent->parent == NULL)
    {
        return;
    }

    fix_insert2(root, temp);
}