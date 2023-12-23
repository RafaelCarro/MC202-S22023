#include "balanced_tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Checks if a node of the binary tree is red.*/
int is_red(p_node node) {
    if (node == NULL)
        return 0;
    return node->color == RED;
}

/*Checks if a node of the binary tree is red.*/
int is_black(p_node node) {
    if (node == NULL)
        return 1;
    return node->color == BLACK;
}

/*Rotates a node to the left on the tree.*/
p_node left_rotation(p_node root) {
    p_node x = root->right;
    root->right = x->left;
    x->left = root;
    x->color = root->color;
    root->color = RED;
    return x;
}

/*Rotates a node to the right on the tree.*/
p_node right_rotation(p_node root) {
    p_node x = root->left;
    root->left = x->right;
    x->right = root;
    x->color = root->color;
    root->color = RED;
    return x;
}

/*Moves the color red one up on the tree.*/
void move_red(p_node root) {
    root->color = RED;
    root->left->color = BLACK;
    root->right->color = BLACK;
}

/*Inserts a symbol on the binary tree, if the tree is NULL,
create a root for it.*/
p_node insert(p_node root, p_symbol symbol) {
    p_node new;
    if (root == NULL) {
        new = malloc(sizeof(struct node));
        new->left = new->right = NULL;
        new->symbol = symbol;
        new->color = RED;
        return new;
    }

    //Inserts the new node on the left if it is first in the
    //alphanumeric order.
    if (strcmp(root->symbol->symbol, symbol->symbol) > 0)
        root->left = insert(root->left, symbol);
    else
        root->right = insert(root->right, symbol);
    
    //Correction part: checks for possible violations of the
    //red/black balanced tree pattern and corrects it.

    //If there is a red node on the right and a black on the
    //left, rotate the nodes to the correct positions.
    if (is_red(root->right) && is_black(root->left))
        root = left_rotation(root);
    //If there is two consecutive reds, rotate the root to
    //the right.
    if (is_red(root->left) && is_red(root->left->left))
        root = right_rotation(root);
    //If there are to red to the same parent, move the red
    //up.
    if (is_red(root->left) && is_red(root->right))
        move_red(root);
    return root;
}


/*Searchs the tree for a correspondent symbol and them returns
its pointer if there is one, or returns NULL if the symbol is not
on the tree.*/
p_node search_tree(p_node root, char key[]) {
    int size_key = strlen(key);
    key[size_key] = '\0';
    if (root != NULL) {
        int size_symbol = strlen(root->symbol->symbol);
        root->symbol->symbol[size_symbol] = '\0';
    }
    if (root == NULL || strcmp(root->symbol->symbol, key) == 0)
        return root;
    if (strcmp(root->symbol->symbol, key) > 0)
        return search_tree(root->left, key);
    else
        return search_tree(root->right, key);
}

/*Prints the tree inorder, resulting in alphabetical order.*/
void inorder(p_node root) {
    if (root != NULL) {
        inorder(root ->left);
        printf("%s %s\n", root->symbol->symbol,root->symbol->type);
        inorder(root->right);
    }
}

/*Frees the tree and it's symbols.*/
void free_tree(p_node root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root->symbol);
        free(root);
    }
}