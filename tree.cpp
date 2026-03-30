#include <iostream>
using namespace std;


struct Node {
    int val;
    int id;
    Node (int v, int i) {
        val = v;
        id = i;
        left = right = nullptr;
    }
    Node *left, *right;
};


int next_id = 0;

void insert(Node*& root, int val, int parent_id = -1, char dir = ' '){
    if (root == nullptr){
        root = new Node(val, next_id++);
        cout << "NODE " << root->id << " " << val << " " << parent_id << " " << dir << endl;
        return;
    }
    cout << "CMP " << root->id << " " << val << endl;
    if (val < root->val){
        insert(root->left, val, root->id, 'L');
    } else {
        insert(root->right, val, root->id, 'R');
    }
}


void inorder(Node* root){
    if (!root) return;

    inorder(root->left);
    cout << "ACT " << root->id << endl;
    inorder(root->right);
}

void preorder(Node* root){
    if (!root) return;
    cout << "ACT " << root->id << endl;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << "ACT " << root->id << endl;
}

int main(){
    Node* root = nullptr;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for(int x : arr) insert(root, x);
    
    // Commands for front-end to know which traversal is starting
    cout << "START_INORDER" << endl;
    inorder(root);
    cout << "START_PREORDER" << endl;
    preorder(root);
    cout << "START_POSTORDER" << endl;
    postorder(root);
    
    return 0;
}



