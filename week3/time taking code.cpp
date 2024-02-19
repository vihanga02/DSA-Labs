// Include necessary libraries for input/output, working with strings, vectors, file operations, time measurement, and plotting.
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <chrono>
#include "pbPlots.hpp"  // Library for plotting
#include "supportLib.hpp"  // Supporting library for plotting

// Using the standard namespace for convenience.
using namespace std;

// Function to generate a random array of integers given a size.
vector<int> randomArrayGenerator(int size)
{
    // Create an empty vector to store integers.
    vector<int> array(size); 
    // Define the maximum value for random numbers.
    int max = 100;
    // Loop through each element in the vector.
    for (int i = 0; i < size; ++i)
    {
        // Assign a random number modulo the maximum value to each element.
        array[i] = rand() % max;
    }
    // Return the generated array.
    return array;
}

// Function to merge two sorted sub-vectors into a single sorted vector.
vector<int> merge(vector<int> vect, int start, int mid, int end){ 
    // Calculate the sizes of the two sub-vectors.
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // Create separate vectors to store the left and right sub-vectors.
    vector<int> leftVect(n1);
    vector<int> rightVect(n2);

    // Copy elements from the original vector to the left sub-vector.
    for (int i=0; i < n1; i++){
        leftVect[i] = vect[start + i];
    }

    // Copy elements from the original vector to the right sub-vector.
    for (int j=0; j < n2; j++){
        rightVect[j] = vect[mid + 1 +j];
    }

    // Initialize variables to track indices in both sub-vectors and the main vector.
    int leftFlag = 0;
    int rightFlag = 0;
    int key = start;

    // Merge the left and right sub-vectors into the main vector.
    while ((leftFlag < n1) && (rightFlag < n2)){
        // Compare elements from both sub-vectors and merge them into the main vector.
        if (leftVect[leftFlag] >= rightVect[rightFlag]){
            vect[key] = rightVect[rightFlag];
            rightFlag++;
        } 
        else{
            vect[key] = leftVect[leftFlag];
            leftFlag++;
        }
        key++;
    }

    // Copy any remaining elements from the left sub-vector into the main vector.
    while (leftFlag < n1) {
        vect[key] = leftVect[leftFlag];
        leftFlag++;
        key++;
    }
    // Copy any remaining elements from the right sub-vector into the main vector.
    while (rightFlag < n2) {
        vect[key] = rightVect[rightFlag];
        rightFlag++;
        key++;
    }
    // Return the merged vector.
    return vect;
}

// Recursive function to perform merge sort on a vector.
vector<int> recursiveMergeSort(vector<int> vect, int start, int end){ 
    // Check if there are more than one element in the vector.
    if (start < end) {
        // Calculate the middle index.
        int mid = (start + end) / 2;
        
        // Recursively call merge sort on the left and right halves of the vector.
        vect = recursiveMergeSort(vect, start, mid);
        vect = recursiveMergeSort(vect, mid + 1, end);
        
        // Merge the sorted sub-vectors.
        vect = merge(vect, start, mid, end);
    }
    
    // Return the sorted vector.
    return vect;
}


// Function to perform iterative merge sort on a vector.
vector<int> iterativeMergeSort(vector<int> vect, int n){
    // Initialize the length of sub-arrays to 1.
    int len = 1;
    
    // Continue until the length is less than the size of the vector.
    while (len < n){
        // Initialize index variable for the start of each sub-array.
        int i = 0;
        
        // Continue until reaching the end of the vector.
        while (i < n){
            // Define indices for the first and second sub-arrays.
            int l1 = i; 
            int r1 = min(i + len - 1, n - 1); 
            int l2 = i + len; 
            int r2 = min(i + 2 * len - 1, n - 1); 
            
            // Check if the second sub-array exceeds the size of the vector and exit the loop if it does.
            if (l2 >= n){
                break; 
            }
            
            // Adjust the end index of the second sub-array if necessary.
            if (r2 > n){
                r2 = n - 1;
            }
            
            // Merge the two sub-arrays.
            vect = merge(vect, l1, r1, r2);
            
            // Move to the next pair of sub-arrays.
            i = i + 2 * len;
        }
        
        // Double the length for the next iteration.
        len = 2 * len;
    }
    
    // Return the sorted vector.
    return vect;
}

// Main function
int main()
{
    // Create variables to store time measurements and array lengths.
    int i = 1;    
    vector<double> recursiveTimeArray, iterativeTimeArray;
    
    // Loop over different array lengths.
    while (i <= 50)
    {   
        // Generate a random array of integers.
        vector<int> randomArray = randomArrayGenerator(i);
        vector<int> array1, array2;

        // Measure the execution time for recursive merge sort.
        auto start1 = chrono::steady_clock::now();
        for (int a = 0; a < 5; a++){
            array1 = recursiveMergeSort(randomArray, 0, randomArray.size() - 1);
        }
        auto end1 = chrono::steady_clock::now();
        auto time1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
        recursiveTimeArray.push_back(time1.count());

        // Measure the execution time for iterative merge sort.
        auto start2 = chrono::steady_clock::now();
        for (int a = 0; a < 5; a++){
            array2 = iterativeMergeSort(randomArray,  randomArray.size());
        }
        auto end2 = chrono::steady_clock::now();
        auto time2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);
        iterativeTimeArray.push_back(time2.count());

        // Increment the array size for the next iteration.
        i++;
    }

    // Create a vector to store array lengths.
    vector<double> arrayLength;

    // Populate the array length vector.
    for (int i = 1; i <= 50; ++i) {
        arrayLength.push_back(i);
    }

    // Output the execution times for recursive and iterative merge sort.
     cout << "[";
    for (size_t i = 0; i < recursiveTimeArray.size(); ++i) {
        cout << recursiveTimeArray[i];
        if (i < recursiveTimeArray.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << std::endl;

    cout << "[";
    for (size_t i = 0; i < iterativeTimeArray.size(); ++i) {
        cout << iterativeTimeArray[i];
        if (i < iterativeTimeArray.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << std::endl;

    return 0;
}
