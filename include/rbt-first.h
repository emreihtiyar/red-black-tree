#if !defined(__RB__)
#define __RB__

typedef struct Node{
    int data;
    short color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} node;

node* add(node* root, int data);//!Geri dönüşü node* olan bir ekleme fonksyonu

void insert(node** rootAdres, int data);//!Geri dönüşü void olan bir ekleme fonksyonu

void delete(node** root, int key);

int minimum(node* root);
int maximum(node* root);

void inOrderTravel(node* root);
void preOrderTravel(node* root);
void postOrderTravel(node* root);

#endif // __RB__
