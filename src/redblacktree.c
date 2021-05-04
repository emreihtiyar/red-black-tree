#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "redblacktree.h"

rbt_i new_rbt(){
    rbt_i rbtree = (rbt_i)malloc(sizeof(rbt_i_t));
    rbtree->tree = NULL;
    rbtree->init = init_int;
    rbtree->insert = insert_int;
    rbtree->find = find_int;
    rbtree->max = maximum_int;
    rbtree->min = minimum_int;
    return rbtree;
}

rbt_i insert_rbt(rbt_i rbtree, int data){
    if (rbtree->tree == NULL)
        rbtree->tree = rbtree->init(data);
    else
        rbtree->insert(rbtree->tree, data);
    
    return rbtree;
}

int max_rbt(rbt_i rbtree){
    return rbtree->max(rbtree->tree);
}
int min_rbt(rbt_i rbtree){
    return rbtree->min(rbtree->tree);
}
int find_rbt(rbt_i rbtree, int data){
    return rbtree->find(rbtree->tree, data);
}