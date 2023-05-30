#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int height(Node *n) {
    if (n == NULL)
        return 0;
    return n->height;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
Node *RR(Node *r) {
    Node *n= r->left;
    Node *temp = n->right;

    n->right = r;
    r->left = temp;

    r->height = max(height(r->left), height(r->right)) + 1;
    n->height = max(height(n->left), height(n->right)) + 1;

    return n;
}

Node *LR(Node *r) {
    Node *n = r->right;
    Node *temp = n->left;

    n->left = r;
    r->right = temp;

    r->height = max(height(r->left), height(r->right)) + 1;
    n->height = max(height(n->left), height(n->right)) + 1;

    return n;
}

int getBalanceFactor(Node *r) {
    if (r == NULL)
        return 0;
    return height(r->left) - height(r->right);
}

Node *insert(Node *r, int data) {
    if (r == NULL)
        return new Node(data);

    if (data < r->data)
        r->left = insert(r->left, data);
    else if (data >r->data)
        r->right = insert(r->right, data);
    else
        return r;

    r->height = 1 + max(height(r->left), height(r->right));

    int balanceFactor = getBalanceFactor(r);

    if (balanceFactor > 1 && data < r->left->data)
        return RR(r);

    if (balanceFactor < -1 && data > r->right->data)
        return LR(r);

    if (balanceFactor > 1 && data > r->left->data) {
        r->left = LR(r->left);
        return RR(r);
    }

    if (balanceFactor < -1 && data < r->right->data) {
        r->right = RR(r->right);
        return LR(r);
    }

    return r;
}

void display(Node* root) {
    if (root == NULL)
        return;
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

int main() {
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
   

    cout << "This is an AVL tree: ";
    display(root);
	
    return 0;
}
