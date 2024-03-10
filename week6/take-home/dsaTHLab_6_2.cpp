// Include the necessary libraries for input/output and standard template library
#include <bits/stdc++.h>

// Use the standard namespace
using namespace std;

// Define a class for representing a node in a binary tree
class Node {
    public:
    // Data stored in the node
    int data; 
    // Pointer to the left child node and right
    Node *left; 
    Node *right; 
    // Constructor to initialize the node with data
    Node (int d){ 
        data = d; 
        left = NULL;
        right = NULL; 
    }
};

// Define a class for the solution
class Solution {
    public:
    // Function to insert a node into the binary tree
    Node *insertNode(Node *node, int data) {
        // If the tree is empty, create a new node with the given data and set it as the root
        if (node == NULL){
            Node * newNode = new Node(data);
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            node = newNode;
        }
        // If the data is greater than the current node's data, insert it into the right subtree
        else if (node->data < data)
        {
            node->right = insertNode(node->right, data);
        }
        // If the data is smaller than the current node's data, insert it into the left subtree
        else if (node->data > data)
        {
            node->left = insertNode(node->left, data);
        }
         // If the data is equal to the current node's data, insert it into the right subtree
        else{
            node->right = insertNode(node->right, data);
        }
        // Return the node 
        return node;
    }

    // Function to find the Lowest Common Ancestor (LCA) of two nodes in a binary tree
    bool lca(Node *node, int v1, int v2){
        int nodeData;
        
        // If the node is NULL, return false
        if (node == NULL){
            return false;
        }
        nodeData = node->data;

        // If both v1 and v2 are less than the current node's data, search in the left subtree
        if ((v1 < nodeData && nodeData > v2)){
             return lca(node->left, v1, v2);
        }
        // If both v1 and v2 are greater than the current node's data, search in the right subtree
        if ((v1 > nodeData && nodeData < v2)){
             return lca(node->right, v1, v2);
        }
        // Print the current node's data and return true
        cout << nodeData << endl;
        return true;
    }
};

// Main function
int main() {
    // Create an instance of the Solution class
    Solution myTree; 
    // Initialize the root node as NULL
    Node *root= NULL; 
    // Declare variables for input
    int t, data, v1, v2; 
    // Read the number of nodes in the tree
    cin >> t; 
    // Loop to read the data of each node and insert it into the tree
    for (int i= 0; i<t; i++){
        // Read the data of the current node and insert into the tree
        cin >> data; 
        root = myTree.insertNode(root,data); 
    }
    // Read the values of v1 and v2
    cin >> v1 >> v2 ; 

    // Call the function to find the Lowest Common Ancestor and print the root data if return false from lca function
    if (!myTree.lca(root, v1, v2)){
        cout << root->data << endl;
    }
    return 0; // Return 0 to indicate successful execution
}
