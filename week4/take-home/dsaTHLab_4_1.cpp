// Include libraries
#include <iostream>  
#include <stab.h>    
#include <stdio.h>   
#include <vector>    

// Use the standard namespace
using namespace std;  

// Function to perform quick sort on a vector of integers
vector<int> quickSort(vector<int> arr){
    // Select the first element of the array as the pivot
    int privot = arr[0];
    
    // Initialize vectors to store elements less than, equal to, and greater than the pivot
    vector<int> minSet, maxSet, equalSet;
    
    // Iterate through the array and partition elements into the appropriate sets
    for (size_t k=0; k<arr.size(); k++){
        // If element is greater than pivot, add it to maxSet
        if (privot < arr[k]){         
            maxSet.push_back(arr[k]);
        }
        // If element is less than pivot, add it to minSet
        else if (privot > arr[k]){    
            minSet.push_back(arr[k]);
        }
        // If element is equal to pivot, add it to equalSet
        else{                         
            equalSet.push_back(arr[k]);
        }
    }

    // Clear the input array
    arr.clear();
    
    // Concatenate the minSet, equalSet, and maxSet into the input array
    for (int num:minSet){
        arr.push_back(num);
    }
    for (int num1:equalSet){
        arr.push_back(num1);
    }
    for (int num2:maxSet){
        arr.push_back(num2);
    }
    
    // Return the sorted array
    return arr;
}

int main(){
    int n;
    // Read the number of elements from input
    cin >> n;  
    // Initialize a vector to store the input numbers
    vector<int> numbers;  

    // Read the input numbers from standard input and store them in the vector
    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    // Call the quickSort function to sort the input numbers
    vector<int> result = quickSort(numbers);

    // Print the sorted numbers
    for (int j: result){
        cout << j << " ";
    }
    cout << endl;
}  
