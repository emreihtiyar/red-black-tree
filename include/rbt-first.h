#if !defined(__RB__)
#define __RB__


typedef struct Node{
    int data;
    short color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} node;

node* add(node* root, int data);

node* rotationLeft(node* root);
node* rotationRight(node* root);
node* rotationRightLeft(node* root);
node* rotationLeftRight(node* root);

void inOrderTravel(node* root);
void preOrderTravel(node* root);
void postOrderTravel(node* root);

#endif // __RB__
