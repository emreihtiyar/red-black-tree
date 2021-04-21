#if !defined(__RB__)
#define __RB__

enum COLOR {BLACK, RED};
enum TREE_TYPE {T_INT, T_FLOAT, T_DOUBLE, T_STR};

typedef struct Node{
    int data;
    enum COLOR color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} node;
typedef struct Node_float{
    float data;
    enum COLOR color;
    struct Node_float* left;
    struct Node_float* right;
    struct Node_float* parent;
} node_f;
typedef struct Node_double{
    double data;
    enum COLOR color;
    struct Node_double* left;
    struct Node_double* right;
    struct Node_double* parent;
} node_d;
typedef struct Node_string{
    char* data;
    enum COLOR color;
    struct Node_string* left;
    struct Node_string* right;
    struct Node_string* parent;
} node_s;


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


//! insert MACRO
#define insert(root,data) _Generic((data), \
    int: insert_int, \
    float: insert_float, \
    double: insert_double, \
    char*: insert_str \
)(root, data)

void insert_int(node* root, int data);
void insert_float(node_f* root, float data);
void insert_double(node_d* root, double data);
void insert_str(node_s* root, char* data);


//! Traversal Macro
#define in_order_travelsal(root) _Generic((root), \
    node*: in_order_travelsal_int, \
    node_f*: in_order_travelsal_float, \
    node_d*: in_order_travelsal_double, \
    node_s*: in_order_travelsal_string, \
    default: travelsal_error \
)(root)

#define pre_order_travelsal(root) _Generic((root->data), \
    int: pre_order_travelsal_int, \
    default: travelsal_error \
)(root)

#define post_order_travelsal(root) _Generic((root->data), \
    int: post_order_travelsal_int, \
    default: travelsal_error \
)(root)

void travelsal_error(node* root);
void in_order_travelsal_int(node* root);
void in_order_travelsal_float(node_f* root);
void in_order_travelsal_double(node_d* root);
void in_order_travelsal_string(node_s* root);
void pre_order_travelsal_int(node* root);
void post_order_travelsal_int(node* root);


/*
//! Rotates Macro
#define left_rotate(root, x) _Generic((root), \
    node*: left_rotate_int, \
    node_f*: left_rotate_float, \
    node_d*: left_rotate_double, \
    node_s*: left_rotate_str \
)(root, x)

void left_rotate_int(node* root, node* x);
void left_rotate_float(node_f* root, node_f* x);
void left_rotate_double(node_d* root, node_d* x);
void left_rotate_str(node_s* root, node_s* x);

#define right_rotate(root, x) _Generic((root), \
    node*: right_rotate_int, \
    node_f*: right_rotate_float, \
    node_d*: right_rotate_double, \
    node_s*: right_rotate_str \
)(root, x)

void right_rotate_int(node* root, node* x);
void right_rotate_float(node_f* root, node_f* x);
void right_rotate_double(node_d* root, node_d* x);
void right_rotate_str(node_s* root, node_s* x);
*/


int minimum(node* root);
int maximum(node* root);

//node* delete(node* root, int key);

int is_there(node* root, int data);

#endif // __RB__
