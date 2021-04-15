#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "rbt-first.h"

/*
const short BLACK = 0;
const short RED = 1;
*/

//! Yardımcı Fonksiyonlar: Rotate, min, max, min node, min max, transplant, travel 

void leftRotate(node* root, node *x)
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
void rightRotate(node* root, node *x)
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
node* transplant(node *root, node *u, node *v)
{
    if (u->parent == NULL)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else if (u == u->parent->right)
        u->parent->right = v;
    if (v != NULL)
        v->parent = u->parent;

    return root;
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
    printf("%d [%c] ", root->data, root->color == RED ? 'R':'B'); //a > b ? a : b;
    in_order_travelsal_int(root->right);
}
void pre_order_travelsal_int(node *root)
{
    if (root == NULL)
        return;
    printf("%d [%c] ", root->data, root->color == RED ? 'R':'B'); //a > b ? a : b;
    pre_order_travelsal_int(root->right);
    pre_order_travelsal_int(root->left);
}
void post_order_travelsal_int(node *root)
{
    if (root == NULL)
        return;
    post_order_travelsal_int(root->left);
    post_order_travelsal_int(root->right);
    printf("%d [%c] ", root->data, root->color == RED ? 'R':'B'); //a > b ? a : b;
}
//float
void in_order_travelsal_float(node_f *root)
{
    if (root == NULL)
        return;
    in_order_travelsal_float(root->left);
    printf("%.2f [%c] ", root->data, root->color == RED ? 'R':'B'); //a > b ? a : b;
    in_order_travelsal_float(root->right);
}
//double
void in_order_travelsal_float(node_d *root)
{
    if (root == NULL)
        return;
    in_order_travelsal_float(root->left);
    printf("%.2F [%c] ", root->data, root->color == RED ? 'R':'B'); //a > b ? a : b;
    in_order_travelsal_float(root->right);
}
//string
void in_order_travelsal_float(node_s *root)
{
    if (root == NULL)
        return;
    in_order_travelsal_float(root->left);
    printf("%s [%c] ", root->data, root->color == RED ? 'R':'B'); //a > b ? a : b;
    in_order_travelsal_float(root->right);
}


//! init Fonksiyonları
node* init_int(int data){
        node* root = (node *)malloc(sizeof(node));
        root->color = BLACK;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        return root;
}
node_d* init_double(double data){
        node_d* root = (node_d *)malloc(sizeof(node_d));
        root->color = BLACK;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        return root;
}
node_f* init_float(float data){
        node_f* root = (node_f *)malloc(sizeof(node_f));
        root->color = BLACK;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        return root;
}
node_s* init_string(char* data){
        node_s* root = (node_s *)malloc(sizeof(node_s));
        root->color = BLACK;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        return root;
}

//! Eleman ekleme
void fix_insert(node* root, node *child)
{
    node *uncle = NULL;
    /*Babanın rengi kırmızsı ve eklenen düğüm her ha zaman kırmızı 
    bu ndenele kırmızının çocuğu kırmızı oldu ve düzeltilmeye ihtiyaç var
    */
    if (child == root || child->parent == NULL)
    {
        root->color = BLACK;
        return;
    }
    if (child->parent->parent == NULL)
        return;

    while (child->parent->color == RED)
    {
        if (child->parent == child->parent->parent->right)
        {
            uncle = child->parent->parent->left;
            if (uncle != NULL && uncle->color == RED)
            {
                uncle->color = BLACK;
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                child = child->parent->parent;
            }
            else
            {
                if (child == child->parent->left)
                {
                    child = child->parent;
                    rightRotate(root, child);
                }
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                leftRotate(root, child->parent->parent);
            }
        }
        else
        {
            uncle = child->parent->parent->right;
            if (uncle != NULL && uncle->color == RED)
            {
                uncle->color = BLACK;
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                child = child->parent->parent;
            }
            else
            {
                if (child == child->parent->right)
                {
                    child = child->parent;
                    leftRotate(root, child);
                }
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                rightRotate(root, child->parent->parent);
            }
        }
        if (child == root)
        {
            break;
        }
    }
    root->color = BLACK;
}

void insert_int(node* root, int data)
{ //!Geri dönüşü void olan bir ekleme fonksyonu
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
    temp->color = RED; //Yeni düğüm KIRMIZI
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

    fix_insert(root, temp);
}

//!Silme işlemi
void fix_delete(node *root, node *x)
{ //TODO: x NULL geldiğinde hata oluyor bu durumu değerlendir
    node *s;
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
    while (x != root && x->color == BLACK)
    {
        if (x == x->parent->left)
        {
            perror("fix_delete->if\n");
            s = x->parent->right;
            if (s->color == RED)
            {
                //case 3.1
                perror("fix_delete->if->if\n");
                s->color = BLACK;
                x->parent->color = RED;
                leftRotate(root, x->parent);
                s = x->parent->right;
            }

            if (s->left->color == BLACK && s->right->color == BLACK)
            {
                //case 3.2
                perror("fix_delete->if->if2\n");
                s->color = RED;
                x = x->parent;
            }
            else
            {
                if (s->right->color == BLACK)
                {
                    // case 3.3
                    perror("fix_delete->else->if\n");
                    s->left->color = BLACK;
                    s->color = RED;
                    rightRotate(root, s);
                    s = x->parent->right;
                }
                //case 3.4
                perror("fix_delete->if->else->case3.4\n");
                s->color = x->parent->color;
                x->parent->color = BLACK;
                s->right->color = BLACK;
                leftRotate(root, x->parent);
                x = root;
            }
        }
        else
        {
            perror("fix_delete->else\n");
            s = x->parent->left;
            if (s->color == RED)
            {
                //case 3.1
                perror("fix_delete->else->if\n");
                s->color = BLACK;
                x->parent->color = RED;
                rightRotate(root, x->parent);
                s = x->parent->left;
            }

            if (s->right->color == BLACK && s->right->color == BLACK)
            {
                // case 3.2
                perror("fix_delete->else->if2\n");
                s->color = RED;
                x = x->parent;
            }
            else
            {
                if (s->left->color == BLACK)
                {
                    // case 3.3
                    perror("fix_delete->else->else\n");
                    s->right->color = BLACK;
                    s->color = RED;
                    leftRotate(root, s);
                    s = x->parent->left;
                }
                //case 3.4
                perror("fix_delete->else->case3.4\n");
                s->color = x->parent->color;
                x->parent->color = BLACK;
                s->left->color = BLACK;
                rightRotate(root, x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}
node* delete(node *root, int key)
{
    node *x = NULL;
    node *y = NULL;
    node *z = NULL;
    node* iter = root;

    while (iter != NULL)
    {
        if (iter->data == key)
        {
            z = iter;
            break;
        }
        if (key > iter->data)
        {
            iter = iter->right;
        }
        else
        {
            iter = iter->left;
        }
    }

    if (z == NULL)
    {
        printf("Couldn't find key in the tree\n");
        return root;
    }

    y = z;
    short y_orginal_color = y->color;
    //printf("xx\n");
    if (z->left == NULL) 
    {
    //silinecek düğümün solu boş bu nedenle, silinen düğüm yerine sağ alt düğüm yazılır.
        x = z->right;
        root = transplant(root, z, z->right);
    }
    else if (z->right == NULL)
    {
        //silinecek düğümün sağı boş bu nedenle, silinen düğüm yerine sol alt düğüm yazılır.
        x = z->left;
        root = transplant(root, z, z->left);
    }
    else
    {
        y = minimum_node(z->right);
        y_orginal_color = y->color;
        x = y->right;
        if (y->parent == z)
        {
            if (x != NULL)
                x->parent = y;
        }
        else
        {
            root = transplant(root, y, y->right);
            y->right = z->right;
            if (y->right != NULL)
                y->right->parent = y;
        }
        root = transplant(root, z, y);
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
    if (y_orginal_color == BLACK)
    {
        //printf("fix delete öncesi\n");
        fix_delete(root, x);
        //printf("fix delete sonrası\n");
    }
    return root;
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
