#if !defined(__RB__)
#define __RB__

enum COLOR { RED, BLACK };

typedef struct Node{
    int data;
    short color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} node;

typedef struct Node_float{
    float data;
    short color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} node_f;

/*
typedef struct red_black_tree{
    node* tree;
    node* (*init)(int data);
    void (*insert)(node** root, int data);
    void (*insert2)(node* root, int data);
} rbt;
*/


#define insert(root,data) _Generic((data), \
    int: insert_int \
)(root, data)
/*    float: insert_float, \
    double: insert_double, \
    char: insert_char, \
    char*: insert_str, \
*/

#define in_order_travelsal(root) _Generic((root->data), \
    int: in_order_travelsal_int, \
    default: travelsal_error \
)(root)
    /* float: in_order_travelsal_float, \
    double: in_order_travelsal_double, \
    char: in_order_travelsal_char, \
*/
#define pre_order_travelsal(root) _Generic((root->data), \
    int: pre_order_travelsal_int, \
    default: travelsal_error \
)(root)
#define post_order_travelsal(root) _Generic((root->data), \
    int: post_order_travelsal_int, \
    default: travelsal_error \
)(root)


node* init(int data);
node* add(node* root, int data);//!Geri dönüşü node* olan bir ekleme fonksyonu

void insert_int(node** rootAdres, int data);//!Geri dönüşü void olan bir ekleme fonksyonu
void insert2(node* root, int data);

void delete(node** root, int key);

int minimum(node* root);
int maximum(node* root);

void travelsal_error(node* root);
void in_order_travelsal_int(node* root);
void pre_order_travelsal_int(node* root);
void post_order_travelsal_int(node* root);

int is_there(node* root, int data);

#endif // __RB__
