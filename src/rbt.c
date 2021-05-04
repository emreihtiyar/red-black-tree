#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "rbt.h"


//! Yardımcı Fonksiyonlar: Rotate, min, max, min node, min max, transplant, travel 
//! Bu Fonksiyonlardaki gereksiz tekrarları kaldırmalıyız, bu haliyle DRY prensibine uymuyor.
void left_rotate_int(node_i* root, node_i* x)
{//node türü ve int değeri için Sola döndürme fonksiyonu
    node_i* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}
void left_rotate_float(node_f* root, node_f* x)
{//node_F türü ve float değeri için Sola döndürme fonksiyonu
    node_f *y = x->right;
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
void left_rotate_double(node_d* root, node_d* x)
{//node_d türü ve double değeri için Sola döndürme fonksiyonu
    node_d* y = x->right;
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
void left_rotate_str(node_s* root, node_s* x)
{//node_s türü ve string değeri için Sola döndürme fonksiyonu
    node_s* y = x->right;
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

void right_rotate_int(node_i* root, node_i* x)
{//node türü ve int değeri için Sağa döndürme fonksiyonu
    node_i* y = x->left;
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
void right_rotate_float(node_f* root, node_f* x)
{//node_f türü ve float değeri için Sağa döndürme fonksiyonu
    node_f *y = x->left;
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
void right_rotate_double(node_d* root, node_d* x)
{//node_d türü ve double değeri için Sağa döndürme fonksiyonu
    node_d* y = x->left;
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
void right_rotate_str(node_s* root, node_s* x)
{//node_s türü ve string değeri için Sağa döndürme fonksiyonu
    node_s* y = x->left;
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


node_i* minimum_node_int(node_i* root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}
node_f* minimum_node_float(node_f* root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}
node_d* minimum_node_double(node_d *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}
node_s* minimum_node_str(node_s *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}


node_i* maximum_node_int(node_i* root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}
node_f* maximum_node_float(node_f* root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}
node_d* maximum_node_double(node_d* root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}
node_s* maximum_node_str(node_s* root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}


int minimum_int(node_i* root){
    printf("file-func: %s->%s-> ",__FILE__,__func__);
    return minimum_node_int(root)->data;
}
float minimum_float(node_f* root){
    printf("file-func: %s->%s-> ",__FILE__,__func__);
    return minimum_node_float(root)->data;
}
double minimum_double(node_d* root){
    printf("file-func: %s->%s-> ",__FILE__,__func__);
    return minimum_node_double(root)->data;
}
char* minimum_str(node_s* root){
    printf("file-func: %s->%s-> ",__FILE__,__func__);
    return minimum_node_str(root)->data;
}

int maximum_int(node_i* root){
    printf("file-func: %s->%s-> ",__FILE__,__func__);
    return maximum_node_int(root)->data;
}
float maximum_float(node_f* root){
    printf("file-func: %s->%s-> ",__FILE__,__func__);
    return maximum_node_float(root)->data;
}
double maximum_double(node_d* root){
    printf("file-func: %s->%s-> ",__FILE__,__func__);
    return maximum_node_double(root)->data;
}
char* maximum_str(node_s* root){
    printf("file-func: %s->%s-> ",__FILE__,__func__);
    return maximum_node_str(root)->data;
}


node_i* find_node_int(node_i* root, int data){
    if (root == NULL)
        return NULL;
    else if (root->data == data)
        return root;
    else if (data > root->data)
        return find_node_int(root->right, data);
    else
        return find_node_int(root->left, data);
}
node_f* find_node_float(node_f* root, float data){
    if (root == NULL)
        return NULL;
    else if (root->data == data)
        return root;
    else if (data > root->data)
        return find_node_float(root->right, data);
    else
        return find_node_float(root->left, data);
}
node_d* find_node_double(node_d* root, double data){
    if (root == NULL)
        return NULL;
    else if (root->data == data)
        return root;
    else if (data > root->data)
        return find_node_double(root->right, data);
    else
        return find_node_double(root->left, data);
}
node_s* find_node_str(node_s* root, char* data){
    if (root == NULL)
        return NULL;
    else if (strcmp(root->data, data) == 0) //root->data == data
        return root;
    else if (strcmp(data, root->data) > 0)//data > root->data
        return find_node_str(root->right, data);
    else
        return find_node_str(root->left, data);
}

int find_int(node_i* root, int data)
{
    printf("file-func: %s->%s-> ",__FILE__,__func__);
    // find node NULL döndüyse yani bulamadı ise NULL && 1 -> 0 döndürür, eğer bulduysa yani null dışında birey döndüyse all && 1 ->1 döndürür. 
    return find_node_int(root, data) && 1;
}
int find_float(node_f* root, float data)
{
    printf("file-func: %s->%s-> ",__FILE__,__func__);
    // find node NULL döndüyse yani bulamadı ise NULL && 1 -> 0 döndürür, eğer bulduysa yani null dışında birey döndüyse all && 1 ->1 döndürür. 
    return find_node_float(root, data) && 1;
}
int find_double(node_d* root, double data)
{
    printf("file-func: %s->%s-> ",__FILE__,__func__);
    // find node NULL döndüyse yani bulamadı ise NULL && 1 -> 0 döndürür, eğer bulduysa yani null dışında birey döndüyse all && 1 ->1 döndürür. 
    return find_node_double(root, data) && 1;
}
int find_str(node_s* root, char* data)
{
    printf("file-func: %s->%s-> ",__FILE__,__func__);
    // find node NULL döndüyse yani bulamadı ise NULL && 1 -> 0 döndürür, eğer bulduysa yani null dışında birey döndüyse all && 1 ->1 döndürür. 
    return find_node_str(root, data) && 1;
}


//! Veri tiplerine bağlı dolaşımlar
void travelsal_error(node_i* root){
    printf("Hatalı Bir veri tipi yada ağaç olmayan bir yapı girdisinde bulundunuz");
}

void in_order_travelsal_int(node_i* root)
{
    if (root == NULL)
        return;
    in_order_travelsal_int(root->left);
    printf("%d [%c] ", root->data, root->color == RED ? 'R':'B'); //a > b ? a : b;
    in_order_travelsal_int(root->right);
}
void pre_order_travelsal_int(node_i* root)
{
    if (root == NULL)
        return;
    printf("%d [%c] ", root->data, root->color == RED ? 'R':'B'); //a > b ? a : b;
    pre_order_travelsal_int(root->right);
    pre_order_travelsal_int(root->left);
}
void post_order_travelsal_int(node_i* root)
{
    if (root == NULL)
        return;
    post_order_travelsal_int(root->left);
    post_order_travelsal_int(root->right);
    printf("%d [%c] ", root->data, root->color == RED ? 'R':'B'); //a > b ? a : b;
}
void in_order_travelsal_float(node_f *root)
{
    if (root == NULL)
        return;
    in_order_travelsal_float(root->left);
    printf("%.2f [%c] ", root->data, root->color == RED ? 'R':'B'); //a > b ? a : b;
    in_order_travelsal_float(root->right);
}
void in_order_travelsal_double(node_d *root)
{
    if (root == NULL)
        return;
    in_order_travelsal_double(root->left);
    printf("%.2F [%c] ", root->data, root->color == RED ? 'R':'B'); //a > b ? a : b;
    in_order_travelsal_double(root->right);
}
void in_order_travelsal_string(node_s *root)
{
    if (root == NULL)
        return;
    in_order_travelsal_string(root->left);
    printf("%s [%c] ", root->data, root->color == RED ? 'R':'B'); //a > b ? a : b;
    in_order_travelsal_string(root->right);
}


//! init Fonksiyonları
node_i* init_int(int data){
    node_i* root = (node_i*)malloc(sizeof(node_i));
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
void fix_insert_int(node_i* root,node_i* child)
{
    node_i* uncle = NULL;
    /*Babanın rengi kırmızsı ve eklenen düğüm her ha zaman kırmızı 
    bu ndenele kırmızının çocuğu kırmızı oldu ve düzeltilmeye ihtiyaç var
    */
    if (child == root || child->parent == NULL)
    {
        //root'a gelinmişse rengin siyah yapılıp çıkılması yeterli
        root->color = BLACK;
        return;
    }
    if (child->parent->parent == NULL)
        return;

    while (child->parent->color == RED)
    {//Benim Ve Babamın renkleri kırmızı ise o zaman düzeltmeye ihtiyaç var
        if (child->parent == child->parent->parent->right)
        {//babam dedemin sağındaysa o zaman amcam solundadır
            uncle = child->parent->parent->left;
            if (uncle != NULL && uncle->color == RED)
            {//amcam ve babamı siyah yap dedeyi kırmızı yap
                uncle->color = BLACK;
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                child = child->parent->parent;
            }
            else
            {
                if (child == child->parent->left)
                {//Ben babamın solundaysam sağa döndür 
                    child = child->parent;
                    right_rotate_int(root, child);
                }
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                left_rotate_int(root, child->parent->parent);
            }
        }
        else
        {
            uncle = child->parent->parent->right;
            if (uncle != NULL && uncle->color == RED)
            {//amcam ve babamı sitah yap dedeyi kırmızı yap
                uncle->color = BLACK;
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                child = child->parent->parent;
            }
            else
            {
                if (child == child->parent->right)
                {//Ben babamın sağındaysam sola döndür 
                    child = child->parent;
                    left_rotate_int(root, child);
                }
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                right_rotate_int(root, child->parent->parent);
            }
        }
        if (child == root)
        {
            break;
        }
    }
    root->color = BLACK;
}
void fix_insert_float(node_f* root, node_f* child)
{
    node_f* uncle = NULL;
    /*Babanın rengi kırmızsı ve eklenen düğüm her ha zaman kırmızı 
    bu ndenele kırmızının çocuğu kırmızı oldu ve düzeltilmeye ihtiyaç var
    */
    if (child == root || child->parent == NULL)
    {//root'a gelinmişse rengin siyah yapılıp çıkılması yeterli
        root->color = BLACK;
        return;
    }
    if (child->parent->parent == NULL)
        return;

    while (child->parent->color == RED)
    {//Benim Ve Babamın renkleri kırmızı ise o zaman düzeltmeye ihtiyaç var
        if (child->parent == child->parent->parent->right)
        {//babam dedemin sağındaysa o zaman amcam solundadır
            uncle = child->parent->parent->left;
            if (uncle != NULL && uncle->color == RED)
            {//amcam ve babamı siyah yap dedeyi kırmızı yap
                uncle->color = BLACK;
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                child = child->parent->parent;
            }
            else
            {
                if (child == child->parent->left)
                {//Ben babamın solundaysam sağa döndür 
                    child = child->parent;
                    right_rotate_float(root, child);
                }
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                left_rotate_float(root, child->parent->parent);
            }
        }
        else
        {
            uncle = child->parent->parent->right;
            if (uncle != NULL && uncle->color == RED)
            {//amcam ve babamı siyah yap dedeyi kırmızı yap
                uncle->color = BLACK;
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                child = child->parent->parent;
            }
            else
            {
                if (child == child->parent->right)
                {//Ben babamın sağındaysam sola döndür 
                    child = child->parent;
                    left_rotate_float(root, child);
                }
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                right_rotate_float(root, child->parent->parent);
            }
        }
        if (child == root)
        {
            break;
        }
    }
    root->color = BLACK;
}
void fix_insert_double(node_d* root, node_d* child)
{
    node_d* uncle = NULL;
    /*Babanın rengi kırmızsı ve eklenen düğüm her ha zaman kırmızı 
    bu ndenele kırmızının çocuğu kırmızı oldu ve düzeltilmeye ihtiyaç var
    */
    if (child == root || child->parent == NULL)
    {//root'a gelinmişse rengin siyah yapılıp çıkılması yeterli
        root->color = BLACK;
        return;
    }
    if (child->parent->parent == NULL)
        return;

    while (child->parent->color == RED)
    {//Benim Ve Babamın renkleri kırmızı ise o zaman düzeltmeye ihtiyaç var
        if (child->parent == child->parent->parent->right)
        {//babam dedemin sağındaysa o zaman amcam solundadır
            uncle = child->parent->parent->left;
            if (uncle != NULL && uncle->color == RED)
            {//amcam ve babamı siyah yap dedeyi kırmızı yap
                uncle->color = BLACK;
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                child = child->parent->parent;
            }
            else
            {
                if (child == child->parent->left)
                {//Ben babamın solundaysam sağa döndür 
                    child = child->parent;
                    right_rotate_double(root, child);
                }
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                left_rotate_double(root, child->parent->parent);
            }
        }
        else
        {
            uncle = child->parent->parent->right;
            if (uncle != NULL && uncle->color == RED)
            {//amcam ve babamı siyah yap dedeyi kırmızı yap
                uncle->color = BLACK;
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                child = child->parent->parent;
            }
            else
            {
                if (child == child->parent->right)
                {//Ben babamın sağındaysam sola döndür 
                    child = child->parent;
                    left_rotate_double(root, child);
                }
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                right_rotate_double(root, child->parent->parent);
            }
        }
        if (child == root)
        {
            break;
        }
    }
    root->color = BLACK;
}
void fix_insert_str(node_s* root, node_s* child)
{
    node_s* uncle = NULL;
    /*Babanın rengi kırmızsı ve eklenen düğüm her ha zaman kırmızı 
    bu ndenele kırmızının çocuğu kırmızı oldu ve düzeltilmeye ihtiyaç var
    */
    if (child == root || child->parent == NULL)
    {//root'a gelinmişse rengin siyah yapılıp çıkılması yeterli
        root->color = BLACK;
        return;
    }
    if (child->parent->parent == NULL)
        return;

    while (child->parent->color == RED)
    {//Benim Ve Babamın renkleri kırmızı ise o zaman düzeltmeye ihtiyaç var
        if (child->parent == child->parent->parent->right)
        {//babam dedemin sağındaysa o zaman amcam solundadır
            uncle = child->parent->parent->left;
            if (uncle != NULL && uncle->color == RED)
            {//amcam ve babamı siyah yap dedeyi kırmızı yap
                uncle->color = BLACK;
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                child = child->parent->parent;
            }
            else
            {
                if (child == child->parent->left)
                {//Ben babamın sağındaysam sola döndür 
                    child = child->parent;
                    right_rotate_str(root, child);
                }
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                left_rotate_str(root, child->parent->parent);
            }
        }
        else
        {
            uncle = child->parent->parent->right;
            if (uncle != NULL && uncle->color == RED)
            {//amcam ve babamı siyah yap dedeyi kırmızı yap
                uncle->color = BLACK;
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                child = child->parent->parent;
            }
            else
            {
                if (child == child->parent->right)
                {//Ben babamın sağındaysam sola döndür 
                    child = child->parent;
                    left_rotate_str(root, child);
                }
                child->parent->color = BLACK;
                child->parent->parent->color = RED;
                right_rotate_str(root, child->parent->parent);
            }
        }
        if (child == root)
        {
            break;
        }
    }
    root->color = BLACK;
}


void insert_int(node_i* root, int data)
{ //!Geri dönüşü void olan bir ekleme fonksyonu
    node_i* iterParent = NULL;
    node_i* iter = root;
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
    node_i* temp = (node_i*)malloc(sizeof(node_i));
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

    fix_insert_int(root, temp);
}
void insert_float(node_f* root, float data)
{ //!Geri dönüşü void olan bir ekleme fonksyonu
    node_f* iterParent = NULL;
    node_f* iter = root;
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
    node_f* temp = (node_f*)malloc(sizeof(node_f));
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

    fix_insert_float(root, temp);
}
void insert_double(node_d* root, double data)
{ //!Geri dönüşü void olan bir ekleme fonksyonu
    node_d* iterParent = NULL;
    node_d* iter = root;
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
    node_d* temp = (node_d*)malloc(sizeof(node_d));
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

    fix_insert_double(root, temp);
}
void insert_str(node_s* root, char* data)
{ //!Geri dönüşü void olan bir ekleme fonksyonu
    node_s* iterParent = NULL;
    node_s* iter = root;
    //iter NULL oluncaya kadar devam et bu sayede gelen datayı yerleştireceğimiz yeri buluruz
    while (iter != NULL)
    {
        iterParent = iter; //iterin Parent'ını tutmak parent atamasında ve gelen datayı yerleştirmede işe yarayacak
        if (strcmp(data, iter->data) > 0) //büyükse
            iter = iter->right;
        else  //küçükse
            iter = iter->left;
    }
    //Create New Node
    node_s* temp = (node_s*)malloc(sizeof(node_s));
    temp->color = RED; //Yeni düğüm KIRMIZI
    temp->data = data;
    temp->parent = iterParent; // yeni düğümünün parent'ı iterin parentı yani NULL olan yaprağın atası
    temp->left = NULL;
    temp->right = NULL;

    //iter NULL'idi ve yeni düğüm iterin parent'ının altına eklenecekti bunun nereye ekleneceğini buluyoruz
    if (strcmp(data, iterParent->data) > 0)
        iterParent->right = temp;
    else
        iterParent->left = temp;

    // if the grandparent is null, simply return
    if (temp->parent->parent == NULL)
    {
        return;
    }

    fix_insert_str(root, temp);
}