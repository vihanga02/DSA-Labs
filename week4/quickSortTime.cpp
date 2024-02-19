// Include necessary libraries for input/output, working with strings, vectors, file operations, time measurement, and plotting.
#include <iostream>     
#include <vector>       
#include <fstream>      
#include <sstream>      
#include <chrono>       
#include <stack>        
#include <queue>        
#include "gnuplot-iostream.h"  

// Using the standard namespace for convenience.
using namespace std::chrono;
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

// Partition function for quicksort
int partition(vector<int>& arr, int start, int end) {
    // Choose the pivot element (in this implementation, it's the last element)
    int pivot = arr[end];
    // Initialize the index of the smaller element
    int i = start - 1;

    // Iterate through the array from start to end-1
    for (int j = start; j < end; j++) {
        // If the current element is less than the pivot
        if (arr[j] < pivot) {
            // Increment the index of the smaller element
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i+1] and arr[high] (or pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;

    // Return the partition index
    return i + 1;
}

// Iterative implementation of quicksort
void quickSortIterative(vector<int>& vect, int low, int high) { 
    // Create a stack for storing subarray indices
    stack<int> tempStack;
    // Push initial values of low and high to the stack
    tempStack.push(low);
    tempStack.push(high);

    // Continue until the stack is empty
    while (!tempStack.empty()) {
        // Pop values of low and high from the stack
        high = tempStack.top();
        tempStack.pop();
        low = tempStack.top();
        tempStack.pop();

        // Partition the array and get pivot index
        int pivotIndex = partition(vect, low, high);

        // If there are elements on the left side of pivot, push indices to stack
        if (pivotIndex - 1 > low) {
            tempStack.push(low);
            tempStack.push(pivotIndex - 1);
        }

        // If there are elements on the right side of pivot, push indices to stack
        if (pivotIndex + 1 < high) {
            tempStack.push(pivotIndex + 1);
            tempStack.push(high);
        }
    }
}

// Recursive function to perform quicksort
void quickSortRecursive(vector<int> &vect, int start, int end) {
    // Base case: if start is less than end
    if (start < end) {
        // Partition the array and get pivot index
        int pivotIndex = partition(vect, start, end);
        // Recursively call quicksort on subarrays
        quickSortRecursive(vect, start, pivotIndex - 1);
        quickSortRecursive(vect, pivotIndex + 1, end);
    }  
}

// Main function
int main()
{
    // Create variables to store time measurements and array lengths.
    int i = 1;    
    vector<double> recursiveTimeArray, iterativeTimeArray;

    // Create output files for storing time measurements.
    ofstream datafile1("recursiveQuickSort.txt");
    datafile1 << "# Input Size Time(ms)" << endl;

    ofstream datafile2("iterativeQuickSort.txt");
    datafile2 << "# Input Size Time(ms)" << endl;

    // Loop over different array lengths.
    while (i <= 100)
    {   
        // Generate a random array of integers.
        vector<int> array = randomArrayGenerator(i);
        vector<int> array1 = array;
        vector<int> array2 = array;

        // Measure the execution time for recursive quicksort.
        auto start1 = chrono::steady_clock::now();
        quickSortRecursive(array1, 0, array1.size() - 1);
        auto end1 = chrono::steady_clock::now();
        double time1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count();

        // Measure the execution time for iterative quicksort.
        auto start2 = chrono::steady_clock::now();
        quickSortIterative(array2, 0, array2.size() - 1);
        auto end2 = chrono::steady_clock::now();
        double time2 = chrono::duration_cast<chrono::microseconds>(end2 - start2).count();

        // Write the time measurements to the respective output files.
        datafile1 << i << " " << time1 << endl;
        datafile2 << i << " " << time2 << endl;

        // Increment the array size for the next iteration.
        i++;
    }
    // Close the output files.
    datafile1.close();
    datafile2.close();

    // Plot the data using gnuplot.
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "set title 'Quick Sort: Input Size vs Time Taken'\n");
    fprintf(gnuplotPipe, "set xlabel 'Input Size'\n");
    fprintf(gnuplotPipe, "set ylabel 'Time Taken (microseconds)'\n");
    fprintf(gnuplotPipe, "plot 'recursiveQuickSort.txt' with linespoints title 'Quick Sort Recursive', 'iterativeQuickSort.txt' with linespoints title 'Quick Sort Iterative'\n");
    fflush(gnuplotPipe);

    return 0;
}
