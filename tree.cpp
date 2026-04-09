#include <iostream>
using namespace std;


struct Node {
    int val;
    int id;
    Node(int v, int i) : val(v), id(i), left(nullptr), right(nullptr) {}
    Node *left, *right;
};


int next_id = 0;

void insert(Node*& root, int val, int parent_id = -1, char dir = ' ', bool verbose = true) {
    if (root == nullptr) {
        root = new Node(val, next_id++);
        if (verbose)
            cout << "NODE " << root->id << " " << val << " " << parent_id << " " << dir << endl;
        return;
    }
    if (verbose)
        cout << "CMP " << root->id << " " << val << endl;
    if (val < root->val)
        insert(root->left, val, root->id, 'L', verbose);
    else
        insert(root->right, val, root->id, 'R', verbose);
}


void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << "ACT " << root->id << endl;
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << "ACT " << root->id << endl;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << "ACT " << root->id << endl;
}


int main(int argc, char* argv[]) {
    Node* root = nullptr;
    string type = (argc > 1) ? argv[1] : "build";

    // For traversal types build silently (no output), only emit ACT steps
    bool verbose = (type == "build");

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr)
        insert(root, x, -1, ' ', verbose);

    if (type == "build") return 0;

    if (type == "inorder")   inorder(root);
    if (type == "preorder")  preorder(root);
    if (type == "postorder") postorder(root);

    return 0;
}
