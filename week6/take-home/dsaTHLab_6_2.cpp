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
         // If the key is equal the current node's key, insert it into the right subtree
        else{
            node->right = insertNode(node->right, data);
        }
        // Return the node 
        return node;
    }

    void lca (Node *node, int v1, int v2){
        int nodeData;
        
        if (node == NULL){
            return ;
        }
        nodeData = node->data;

        // if ((v1 <= nodeData && nodeData <= v2)||(v1 >= nodeData && nodeData >= v2)){
        //     // if (elementFound(node->left, min(v1,v2)) && elementFound(node->right, max(v1,v2))){
        //     //     cout << nodeData << endl;
        //     //     return true;
        //     // }
        //     // else{
        //     //     return false;
        //     // }
        //     cout << nodeData << endl;
        // }
        if ((v1 < nodeData && nodeData > v2)){
             lca(node->left, v1, v2);
        }
        if ((v1 > nodeData && nodeData < v2)){
             lca(node->right, v1, v2);
        }
        cout << nodeData << endl;
        return;
    }

    bool elementFound(Node *node, int v){
        if (node == NULL){
            return false;
        }
        if (node->data == v){
           return true;
        }
        
        if (v < node->data) {
            return elementFound(node->left, v);
        }
        else{
            return elementFound(node->right, v);
        }

    }
};

int main() {
    Solution myTree;
    Node *root= NULL;
    int t, data, v1, v2;
    cin >> t;
    for (int i= 0; i<t; i++){
        cin >> data;
        root = myTree.insertNode(root,data);
    }
    cin >> v1 >> v2 ;
    // if (!myTree.lca(root,v1,v2)){
    //     cout << root->data << endl;
    // }
     myTree.lca(root, v1, v2);
    return 0;
}

/* 
6
4 2 3 1 7 6
1 7

4005,4103,4212,4330,4435,4506,4648,4767,4879,4913,4008,4135,4263,4319,4444,4556,4634,4715,4840,4975,4022,4126,4237,4314,4422,4519,4618,4737,4821,4938,4033,4154,4249,4339,4455,4567,4647,4751,4869,4986
4115 4426

*/