// Including necessary header files for input/output, strings, vectors, and conversions
#include <iostream> 
#include <string>  
#include <vector>   
#include <stdlib.h> 
#include <sstream>  

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

// Function to implement QuickSort algorithm
void quickSort(vector<int>& vect, int start, int end) {
    // Check the array have more than 1 element
    if (start < end) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(vect, start, end);
        // Recursively sort the sub-arrays before and after the pivot
        quickSort(vect, start, pivotIndex - 1);
        quickSort(vect, pivotIndex + 1, end);
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
