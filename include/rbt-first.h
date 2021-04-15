#if !defined(__RB__)
#define __RB__

enum COLOR {BLACK, RED};

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
typedef struct Node_double{
    double data;
    short color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} node_d;
typedef struct Node_string{
    char* data;
    short color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} node_s;

/*
typedef struct red_black_tree{
    node* tree;
    node* (*init)(int data);
    void (*insert)(node** root, int data);
    void (*insert2)(node* root, int data);
} rbt;
*/

//! insert MACRO
#define insert(root,data) _Generic((data), \
    int: insert_int \
)(root, data)
/*    float: insert_float, \
    double: insert_double, \
    char: insert_char, \
    char*: insert_str, \
*/

//! Traversal Macro
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


//! init MACRO
#define init(data) _Generic((data), \
    int: init_int, \
    float: init_float,\
    double: init_double, \
    char*: init_string \
)(data)
node* init_int(int data);
node_f* init_float(float data);
node_d* init_double(double data);
node_s* init_string(char* data);


void insert_int(node* root, int data);
node* delete(node* root, int key);

int minimum(node* root);
int maximum(node* root);

void travelsal_error(node* root);
void in_order_travelsal_int(node* root);
void pre_order_travelsal_int(node* root);
void post_order_travelsal_int(node* root);

int is_there(node* root, int data);

#endif // __RB__
