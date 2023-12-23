typedef struct node *p_node;

struct node {
    char data;
    p_node left, right;
};

p_node create_tree(char x, p_node left, p_node right);

int n_nodes(p_node root);

p_node set_tree(char *input, int i);

void free_tree(p_node root);

void solve_root(p_node root);

void solve(p_node root);

void inorder(p_node root, int l_r);