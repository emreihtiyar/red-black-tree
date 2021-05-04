#if !defined(__RBT__)
#define __RBT__

enum COLOR {BLACK, RED};
enum TREE_TYPE {T_INT, T_FLOAT, T_DOUBLE, T_STR};

typedef struct Node_int{
    int data;
    enum COLOR color;
    struct Node_int* left;
    struct Node_int* right;
    struct Node_int* parent;
} node_i;
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

/*
//! init MACRO
#define init(data) _Generic((data), \
    int: init_int, \
    float: init_float,\
    double: init_double, \
    char*: init_string \
)(data)
*/
node_i* init_int(int data);
node_f* init_float(float data);
node_d* init_double(double data);
node_s* init_string(char* data);

/*
//! insert MACRO
#define insert(root,data) _Generic((data), \
    int: insert_int, \
    float: insert_float, \
    double: insert_double, \
    char*: insert_str \
)(root, data)
*/
void insert_int(node_i* root, int data);
void insert_float(node_f* root, float data);
void insert_double(node_d* root, double data);
void insert_str(node_s* root, char* data);

/*
//! Traversal Macro
#define in_order_travelsal(root) _Generic((root), \
    node_i*: in_order_travelsal_int, \
    node_f*: in_order_travelsal_float, \
    node_d*: in_order_travelsal_double, \
    node_s*: in_order_travelsal_string, \
    default: travelsal_error \
)(root)
*/

void travelsal_error(node_i* root);
void in_order_travelsal_int(node_i* root);
void in_order_travelsal_float(node_f* root);
void in_order_travelsal_double(node_d* root);
void in_order_travelsal_string(node_s* root);
void pre_order_travelsal_int(node_i* root);
void post_order_travelsal_int(node_i* root);
/*
#define min(root) _Generic((root), \
    node_i*: minimum_int, \
    node_f*: minimum_float, \
    node_d*: minimum_double, \
    node_s*: minimum_str \
)(root)
*/
int minimum_int(node_i* root);
float minimum_float(node_f* root);
double minimum_double(node_d* root);
char* minimum_str(node_s* root);
/*
#define max(root) _Generic((root), \
    node_i*: maximum_int, \
    node_f*: maximum_float, \
    node_d*: maximum_double, \
    node_s*: maximum_str \
)(root)
*/
int maximum_int(node_i* root);
float maximum_float(node_f* root);
double maximum_double(node_d* root);
char* maximum_str(node_s* root);
/*
#define find(root, data) _Generic((root), \
    node_i*: find_int, \
    node_f*: find_float, \
    node_d*: find_double, \
    node_s*: find_str \
)(root,data)
*/
int find_int(node_i* root, int data);
int find_float(node_f* root, float data);
int find_double(node_d* root, double data);
int find_str(node_s* root, char* data);


#endif // __RBT__
