#if !defined(__REDBLACKTREE__)
#define __REDBLACKTREE__
#include "rbt.h"

typedef struct RBT_INT
{
    node_i* tree;
    node_i* (*init)();
    void (*insert)();
    int (*max)();
    int (*min)();
    int (*find)();
} *rbt_i, rbt_i_t;

rbt_i new_rbt();
rbt_i insert_rbt(rbt_i tree, int data);
int max_rbt(rbt_i rbtree);
int min_rbt(rbt_i rbtree);
int find_rbt(rbt_i rbtree, int data);
#endif