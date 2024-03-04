#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node (int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    public:

    void preOrder(Node *root){
        if (root == NULL){
            return;
        }
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    // Insert a node
    Node *insertNode(Node *node, int data) {
        // If the tree is empty, create a new node with the given key and assign the new node as the node
        if (node == NULL){
            Node * newNode = new Node(data);
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            node = newNode;
        }
        // If the key is greater than the current node's key, insert it into the right subtree
        else if (node->data < data)
        {
            node->right = insertNode(node->right, data);
        }
        // If the key is smaller than the current node's key, insert it into the left subtree
        else if (node->data > data)
        {
            node->left = insertNode(node->left, data);
        }
        else{
            node->right = insertNode(node->right, data);
        }
        // Return the node 
        return node;
    }
};

int main() {
    Solution myTree;
    Node *root= NULL;
    int t,data;
    cin >> t;
    for (int i= 0; i<t; i++){
        cin >> data;
        root = myTree.insertNode(root,data);
    }
    myTree.preOrder(root);
    return 0;
}


// 4 2 3 1 7 6
// 44 67 91 20 87 20 31 11 19 39 86 65 57 84 10 72 84 15 46