#include "symbol.h"
enum color {RED, BLACK};

typedef struct node *p_node;

/*Struct of a red/black balanced binary tree that stores a symbol
struct.*/
struct node {
    p_symbol symbol;
    enum color color;
    p_node left, right;
};

int is_red(p_node node);

int is_black(p_node node);

p_node left_rotation(p_node root);

p_node right_rotation(p_node root);

void move_red(p_node root);

p_node insert(p_node root, p_symbol symbol);

p_node search_tree(p_node root, char *key);

void inorder(p_node root);

void free_tree(p_node root);

