#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  // Initialize the base case for the recursive approch
  if (root == NULL){
    return;
  }
  // Recursively traverse the left subtree
  traverseInOrder(root->left);
  // Print the key of the current node
  cout << root->key << " ";
  // Recursively traverse the right subtree
  traverseInOrder(root->right);
}


// Insert a node
struct node *insertNode(struct node *node, int key) {
  // If the tree is empty, create a new node with the given key and assign the new node as the node
  if (node == NULL){
    struct node * newNode = new struct node;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    node = newNode;
  }
  // If the key is greater than the current node's key, insert it into the right subtree
  else if (node->key < key)
  {
    node->right = insertNode(node->right, key);
  }
  // If the key is smaller than the current node's key, insert it into the left subtree
  else if (node->key > key)
  {
    node->left = insertNode(node->left, key);
  }
  // Return the node 
  return node;
}


// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // If the root is NULL, return the null root
  if (root == NULL){
    return root;
  }
  
  // If the key matches the root's key
  if (root->key == key){
    // If the root has no children, delete the root and free memory
    if (root->left == NULL && root->right == NULL){
      free(root);
      root = NULL;
    }
    // If the root has only one child, delete the root and replace it with its child and free memory
    else if (root->right == NULL){
      struct node *tempNode = root;
      root = root->left;
      free(tempNode);
    }
    else if (root->left == NULL){
      struct node *tempNode = root;
      root = root->right;
      free(tempNode);
    }
    // If the root has both left and right children
    else{
      // Cerat a new node to store the left sub tree
      struct node *leftNode = root->left;
      // Find the rightmost node in the left subtree
      while (leftNode->right != NULL)
      {
        leftNode = leftNode->right;
      }
      // Replace the root's key with the key of the rightmost node
      root->key = leftNode->key;
      // Delete the rightmost node
      root->left = deleteNode(root->left, leftNode->key);
    }
  }
  // If the key is smaller than the root's key, recursively delete from the left subtree
  else if (root->key > key){
    root->left = deleteNode(root->left, key);
  }
  // If the key is greater than the root's key, recursively delete from the right subtree
  else if (root->key < key){
    root->right = deleteNode(root->right, key);
  }

  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}


