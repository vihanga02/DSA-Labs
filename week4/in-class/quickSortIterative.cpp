// Including necessary header files for input/output, strings, vectors, and conversions
#include <iostream>   
#include <string>     
#include <vector>    
#include <stdlib.h>   
#include <sstream>    
#include <stack>     
#include <queue>

// Using the standard namespace for convenience
using namespace std; 

// Function to partition the array for QuickSort 
int partition(vector<int>& arr, int start, int end) {
    // Choose the pivot element as the end element of the array
    int pivot = arr[end]; 
    // Initialize the index of the smaller element
    int i = start - 1;    

    // Traverse the array from start to end
    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            // Increment the index of the smaller element
            i++; 
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i+1] and arr[end] (or pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;

    // Return the index of the pivot element
    return i + 1;
}
// Function to implement QuickSort algorithm iteratively using a stack
void quickSort(vector<int>& vect, int low, int high) 
{ 
    // // Create a stack to store subarray indices
    // stack<int> tempStack; 
    // // Push the starting index onto the stack
    // tempStack.push(low);  
    // // Push the ending index onto the stack
    // tempStack.push(high); 

    // // Iterate until the stack is empty
    // while (!tempStack.empty()) {
    //     // Retrieve the ending index from the stack
    //     high = tempStack.top(); 
    //     // Pop the ending index from the stack
    //     tempStack.pop();    
    //     // Retrieve the starting index from the stack    
    //     low = tempStack.top(); 
    //     // Pop the starting index from the stack
    //     tempStack.pop();        

    //     // Partition the vector and get the pivot index
    //     int pivotIndex = partition(vect, low, high);

    //     // If there are elements on the left side of the pivot, push their indices onto the stack
    //     if (pivotIndex - 1 > low) {
    //         tempStack.push(low);            
    //         tempStack.push(pivotIndex - 1); 
    //     }

    //     // If there are elements on the right side of the pivot, push their indices onto the stack
    //     if (pivotIndex + 1 < high) {
    //         tempStack.push(pivotIndex + 1);  
    //         tempStack.push(high);           
    //     }
    // }

    queue<pair<int, int>> subArrays; // Queue to store sub-arrays to be sorted
    subArrays.push({low, high}); // Push the initial sub-array to the queue

    while (!subArrays.empty()) {
        int left = subArrays.front().first;
        int right = subArrays.front().second;
        subArrays.pop();

        if (left < right) {
            int pivotIndex = partition(vect, left, right);
            subArrays.push({left, pivotIndex - 1}); // Push left sub-array
            subArrays.push({pivotIndex + 1, right}); // Push right sub-array
        }
    }
}

// Main function
int main() {
    // Vector to store input numbers
    vector<int> numberVector;
    int k = 0; // Counter variable to store the size of the input vector
    
    // Getting input from the user
    string input;
    getline(cin, input); // Read a line of input from the console
    
    // Parsing input string to extract numbers
    istringstream stream(input); // Initialize a string stream with the input string
    int number;
    // Store input numbers in the number vector
    while (stream >> number) {
        numberVector.push_back(number); // Add each number to the vector
        k++; // Increment the counter variable
    }
    
    // Sorting the vector using QuickSort algorithm
    quickSort(numberVector, 0, k - 1 );

    // Printing the sorted vector
    for (int a = 0; a < k; a++) {
        cout << numberVector[a] << " "; // Output each element of the vector
    }
    cout << endl; // Output a newline after printing the vector
    
    // Return statement indicating successful execution
    return 0;
}
