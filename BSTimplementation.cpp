#include <iostream>
#include <cmath>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int v = 0) {
        data = v;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* r, int val);
    void InOrderTraversal(Node* r);
    int notbalanced(Node* r);
};

int main(int argc, char const* argv[]) {
    BST t1;
    t1.insert(t1.root, 5);
    t1.insert(t1.root, 4);
    t1.insert(t1.root, 3);
//    t1.insert(t1.root, 2);
//    t1.insert(t1.root, 1);

    cout << "-----------------------" << endl;
    t1.InOrderTraversal(t1.root);
    cout << "-----------------------" << endl;

    int unbalancedCount = t1.notbalanced(t1.root);
    if (unbalancedCount > 0) {
        cout << "Number of unbalanced nodes: " << unbalancedCount << endl;
    }
    else {
        cout << "The tree is balanced." << endl;
    }

    return 0;
}

Node* BST::insert(Node* r, int val) {
    if (r == NULL) {
        Node* temp = new Node(val);
        if (r == root) {
            root = r = temp;
        }
        return temp;
    }
    else {
        if (r->data == val) {
            cout << "Already Exist" << endl;
        }
        else if (val < r->data)
            r->left = insert(r->left, val);
        else {
            r->right = insert(r->right, val);
        }
        return r;
    }
}

void BST::InOrderTraversal(Node* temp) {
    if (temp == NULL)
        return;

    InOrderTraversal(temp->left);
    cout << temp->data << endl;
    InOrderTraversal(temp->right);
}

int BST::notbalanced(Node* temp) {
    if (temp == NULL) {
        return 0;
    }
    int lh = notbalanced(temp->left);
    int rh = notbalanced(temp->right);
    if (abs(lh - rh) > 1) {
        return notbalanced(temp->left) + notbalanced(temp->right) + 1;
    }
    else {
        return notbalanced(temp->left) + notbalanced(temp->right);
    }
}
