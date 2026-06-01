#include <iostream>
using namespace std;

// Structure of a node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to insert nodes (Binary Tree - level order style)
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Left, Right, Root)
void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Function to find height of tree
int height(Node* root) {
    if (root == NULL)
        return -1; // return 0 if counting nodes instead of edges

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Main function
int main() {
    Node* root = NULL;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    cout << "\nHeight of tree: " << height(root);

    return 0;
}