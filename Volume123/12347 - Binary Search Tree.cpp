#include <cstdio>

struct node {
    int val;
    node* left;
    node* right;
    node(int n, node* left=NULL, node* right=NULL):
        val(n), left(left), right(right) { }
};

void insert(node*& n, int val) {
    if(n == NULL) n = new node(val);
    else {
        if(n->val > val) insert(n->left, val);
        else insert(n->right, val);
    }
}

void preorder(node* n) {
    if(n == NULL) return;
    preorder(n->left);
    preorder(n->right);
    printf("%d\n", n->val);
}

int main() {
    int n;
    scanf("%d", &n);

    node* root = new node(n);

    while(scanf("%d", &n) == 1) {
        insert(root, n);
    }
    preorder(root);
}
