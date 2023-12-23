#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

/*Creates a tree node.*/
p_node create_tree(char x, p_node left, p_node right) {
    p_node r = malloc(sizeof(struct node));
    r->data = x;
    r->left = left;
    r->right = right;
    return r;
}

/*Counts how many nodes there are from the root.*/
int n_nodes(p_node root) {
    if (root == NULL)
        return 0;
    return n_nodes(root->left) + n_nodes(root->right) + 1;
}

/*Sets a binary tree from an expression.*/
p_node set_tree(char *input, int i) {
    p_node left, right;
    //Stops the tree when there are a numbers to calculate on.
    if ((input[i] >= 48 && input[i] <= 57) || (input[i] >= 97 && input[i] <= 122)) {
        return create_tree(input[i], NULL, NULL);
    }
    else {
        right = set_tree(input, i - 1);
        left = set_tree(input, i - n_nodes(right) - 1);
    }
    return create_tree(input[i], left, right);
}

/*Frees the tree from a root.*/
void free_tree(p_node root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

/*Auxiliary function to solve possible operation on the root of the expression tree.*/
void solve_root(p_node root) {
    if (root->data == '|')
        if (root->left->data == 'T' || root->right->data == 'T') {
            free_tree(root->left);
            free_tree(root->right);
            root->left = NULL, root->right = NULL;
            root->data = 'T';
        }
    if (root->data == '&') {
        if (root->left->data == 'F' || root->right->data == 'F') {
            free_tree(root->left);
            free_tree(root->right);
            root->left = NULL, root->right = NULL;
            root->data = 'F';
        }
    }
}

/*Solves the Expression Tree from the root.*/
void solve(p_node root) {
    if (root != NULL) {
        if (root->data == '|')
            if (root->left->data == 'T' || root->right->data == 'T') {
                free_tree(root->left);
                free_tree(root->right);
                root->left = NULL, root->right = NULL;
                root->data = 'T';

            }
            else {
                solve(root->left);
                solve(root->right);
            }
        else if (root->data == '&')
            if (root->left->data == 'F' || root->right->data == 'F') {
                free_tree(root->left);
                free_tree(root->right);
                root->left = NULL, root->right = NULL;
                root->data = 'F';
            }
            else {
                solve(root->left);
                solve(root->right);
            }
        else if (root->data == '{')
            if (root->left->data == root->right->data) {
                free_tree(root->left);
                free_tree(root->right);
                root->left = NULL, root->right = NULL;
                root->data = 'T';
            }
            else if (root->left->data == '0' || root->right->data == '9') {
                free_tree(root->left);
                free_tree(root->right);
                root->left = NULL, root->right = NULL;
                root->data = 'T';
            }
            else if ((root->left->data >= 48 && root->left->data <= 57) && (root->right->data >= 48 && root->right->data <= 57)) {
                if (root->left->data <= root->right->data) {
                    free_tree(root->left);
                    free_tree(root->right);
                    root->left = NULL, root->right = NULL;
                    root->data = 'T';
                }
                else {
                    free_tree(root->left);
                    free_tree(root->right);
                    root->left = NULL, root->right = NULL;
                    root->data = 'F';
                }
            }
            else {
                solve(root->left);
                solve(root->right);
            }
        else if (root->data == '}')
            if (root->left->data == root->right->data) {
                free_tree(root->left);
                free_tree(root->right);
                root->left = NULL, root->right = NULL;
                root->data = 'T';
            }
            else if (root->left->data == '9' || root->right->data == '0') {
                free_tree(root->left);
                free_tree(root->right);
                root->left = NULL, root->right = NULL;
                root->data = 'T';
            }
            else if ((root->left->data >= 48 && root->left->data <= 57) && (root->right->data >= 48 && root->right->data <= 57)) {
                if (root->left->data >= root->right->data) {
                    free_tree(root->left);
                    free_tree(root->right);
                    root->left = NULL, root->right = NULL;
                    root->data = 'T';
                }
                else {
                    free_tree(root->left);
                    free_tree(root->right);
                    root->left = NULL, root->right = NULL;
                    root->data = 'F';
                }
            }
            else {
                solve(root->left);
                solve(root->right);
            }
        else if (root->data == '>')
            if (root->left->data == root->right->data) {
                free_tree(root->left);
                free_tree(root->right);
                root->left = NULL, root->right = NULL;
                root->data = 'F';
            }
            else if (root->left->data == '0' || root->right->data == '9') {
                free_tree(root->left);
                free_tree(root->right);
                root->left = NULL, root->right = NULL;
                root->data = 'F';
            }
            else if ((root->left->data >= 48 && root->left->data <= 57) && (root->right->data >= 48 && root->right->data <= 57)) {
                if (root->left->data > root->right->data) {
                    free_tree(root->left);
                    free_tree(root->right);
                    root->left = NULL, root->right = NULL;
                    root->data = 'T';
                }
                else {
                    free_tree(root->left);
                    free_tree(root->right);
                    root->left = NULL, root->right = NULL;
                    root->data = 'F';
                }
            }
            else {
                solve(root->left);
                solve(root->right);
            }
        else if (root->data == '<')
            if (root->left->data == root->right->data) {
                free_tree(root->left);
                free_tree(root->right);
                root->left = NULL, root->right = NULL;
                root->data = 'F';
            }
            else if (root->left->data == '9' || root->right->data == '0') {
                free_tree(root->left);
                free_tree(root->right);
                root->left = NULL, root->right = NULL;
                root->data = 'F';
            }
            else if ((root->left->data >= 48 && root->left->data <= 57) && (root->right->data >= 48 && root->right->data <= 57)) {
                if (root->left->data < root->right->data) {
                    free_tree(root->left);
                    free_tree(root->right);
                    root->left = NULL, root->right = NULL;
                    root->data = 'T';
                }
                else {
                    free_tree(root->left);
                    free_tree(root->right);
                    root->left = NULL, root->right = NULL;
                    root->data = 'F';
                }
            }
            else {
                solve(root->left);
                solve(root->right);
            }
        else if (root->data == '=')
            if (((root->left->data >= 48 && root->left->data <= 57) || (root->left->data >= 97 && root->left->data <= 122)) && 
            ((root->right->data >= 48 && root->right->data <= 57) || (root->right->data >= 97 && root->right->data <= 122))) {
                if (root->left->data == root->right->data) {
                    free_tree(root->left);
                    free_tree(root->right);
                    root->left = NULL, root->right = NULL;
                    root->data = 'T';
                    solve(root->left);
                    solve(root->right);
                }
                else if ((root->left->data >= 48 && root->left->data <= 57) && (root->right->data >= 48 && root->right->data <= 57)){
                    free_tree(root->left);
                    free_tree(root->right);
                    root->left = NULL, root->right = NULL;
                    root->data = 'F';
                }
            }
            else {
                solve(root->left);
                solve(root->right);
            }
        else if (root->data == '!') {
            if (((root->left->data >= 48 && root->left->data <= 57) || (root->left->data >= 97 && root->left->data <= 122)) && 
            ((root->right->data >= 48 && root->right->data <= 57) || (root->right->data >= 97 && root->right->data <= 122))) {
                if (root->left->data == root->right->data) {
                    free_tree(root->left);
                    free_tree(root->right);
                    root->left = NULL, root->right = NULL;
                    root->data = 'F';
                    solve(root->left);
                    solve(root->right);
                }
                else if ((root->left->data >= 48 && root->left->data <= 57) && (root->right->data >= 48 && root->right->data <= 57)){
                    free_tree(root->left);
                    free_tree(root->right);
                    root->left = NULL, root->right = NULL;
                    root->data = 'T';
                }
            }
            else if ((root->left->data == 'T' || root->left->data == 'F') && (root->right->data == 'F' || root->right->data == 'T')) {
                if (root->left->data == root->right->data) {
                    free_tree(root->left);
                    free_tree(root->right);
                    root->left = NULL, root->right = NULL;
                    root->data = 'F';
                    solve(root->left);
                    solve(root->right);
                }
                else {
                    free_tree(root->left);
                    free_tree(root->right);
                    root->left = NULL, root->right = NULL;
                    root->data = 'T';
                }
            }
            else {
                solve(root->left);
                solve(root->right);
            }
        }
        solve_root(root);
    }
}

/*Prints the tree inorder.*/
void inorder(p_node root, int l_r) {
    if (root != NULL) {
        if (l_r < 0)
            printf("(");
        inorder(root ->left, -1);
        if ((root->data >= 48 && root->data <= 57) || (root->data >= 97 && root->data <= 122) || root->data == 'T' || root->data == 'F')
            printf("%c", root->data);
        else
            printf(" %c ", root->data);
        inorder(root->right, 1);
        if (l_r > 0)
            printf(")");
    }
}
