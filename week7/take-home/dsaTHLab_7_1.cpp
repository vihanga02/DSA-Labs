#include <bits/stdc++.h> 

using namespace std; 

// Function to heapify the tree starting from a given root node
void heapify(vector<int> &arr, int root){
    // Get the size of the array
    int n = arr.size();
    // Calculate the indices of the left and right children of the root
    int maximumValueIndex = root;
    int leftChildIndex = 2*root + 1;
    int rightChildIndex = 2*root + 2;

    // Check if the left child exists and its value is greater than the root's value
    if (leftChildIndex < n && arr[leftChildIndex] > arr[maximumValueIndex]){
        maximumValueIndex = leftChildIndex;
    }

    // Check if the right child exists and its value is greater than the current maximum value
    if (rightChildIndex < n && arr[rightChildIndex] > arr[maximumValueIndex]){
        maximumValueIndex = rightChildIndex;
    }

    // If the maximum value index has changed, swap the root with the maximum value
    if (maximumValueIndex != root){
        swap(arr[root], arr[maximumValueIndex]);
        // Recursively call heapify on the affected subtree
        heapify(arr, maximumValueIndex);
    }
}

// Function to insert a new element into the heap
void insert(vector<int> &arr, int num){
    // Add the new element to the end of the vector
    arr.push_back(num);
    // Get the index of the newly added element and its parent
    int n = arr.size();
    int child = n - 1;
    int parent = (n - 1) / 2;
    
    // Move the newly added element up the heap until it satisfies the heap property
    while (arr[parent] < num && parent >= 0){
        swap(arr[parent], arr[child]);
        child = parent;
        parent = (child - 1) / 2;
    }
}

// Function to remove a specified element from the heap
void remove(vector<int> &arr, int num){
    // Find the index of the element to be removed
    auto it = find(arr.begin(), arr.end(), num);
    if (it != arr.end()){
        int index = it - arr.begin();
        // Swap the element with the last element and remove it from the heap
        swap(arr[index], arr[arr.size() - 1]);
        arr.pop_back();
        // Restore the heap property starting from the index of the removed element
        heapify(arr, index);
    }
}

// Function to print the minimum element in the heap
void printMin(vector<int> arr){
    // Find the minimum element in the heap
    int minimum = arr[0];
    for (size_t i=0; i < arr.size(); i++){
        minimum = min(minimum, arr[i]);
    }
    // Print the minimum element
    cout << minimum << endl;
}

// Main function
int main(){
    // Create a vector to store the elements of the heap
    vector<int> numberVector; 
    // Variable to store the number of queries
    int queries;
    cin >> queries;
    
    // Process each query
    for (int i = 0; i < queries; i++){
        // Variable to store the type of operation
        int operation; 
        cin >> operation; 
        if (operation == 1){ 
            // Variable to store the value to be inserted
            int operand; 
            cin >> operand; 
            // Insert the value into the heap
            insert(numberVector, operand); 
        }
        else if (operation == 2){ 
            // Variable to store the value to be removed
            int operand; 
            cin >> operand; 
            // Remove the value from the heap
            remove(numberVector, operand); 
        }
        else if (operation == 3){ 
            // Print the minimum element in the heap
            printMin(numberVector); 
        }
    }
}
