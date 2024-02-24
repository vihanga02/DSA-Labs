// Include necessary libraries for input/output and handling vectors
#include <iostream>
#include <sstream>
#include <vector>
#include <limits>

// Using the standard namespace for cout and endl
using namespace std;

// Function to compute the maximum subarray sum that crosses the midpoint
int countSum(vector<int> &numVect, int start, int mid, int end){
    // Initialize variables to store the sum of the left and right subarrays
    int sum = 0;
    int leftsum = std::numeric_limits<int>::min(); // set initial leftsum to the minimum value of int

    // Loop through the elements of the left subarray (from mid to start)
    for (int i= mid; i >= start; i--){
        sum = sum + numVect[i]; // add current element to the sum
        if (sum > leftsum){ 
            leftsum = sum; 
        }
    }

    // Reset the sum variable for computing the sum of the right subarray
    sum = 0;
    int rightSum = std::numeric_limits<int>::min(); // set initial rightSum to the minimum value of int

    // Loop through the elements of the right subarray (from mid+1 to end)
    for (int i= mid+1; i <= end; i++){
        sum = sum + numVect[i]; // add current element to the sum
        if (sum > rightSum) { 
            rightSum = sum; 
        }
    }

    // Return the maximum of the three sums: leftSum, rightSum, and the sum crossing the midpoint
    return max(max(rightSum , leftsum) , leftsum + rightSum);
}

// Function to compute the maximum subarray sum using divide and conquer approach
int maxSum(vector<int> &numVect, int start, int end){
    // Base case: if start index is greater than end index, return minimum int value
    if (start > end) {
        return std::numeric_limits<int>::min();
    } 
    // Another base case: if start index equals end index, return the element at that index
    if (start == end){
        return numVect[end];
    }
    
    // Calculate the midpoint of the array
    int mid = (start + end)/2;

    // Recursively compute the maximum subarray sum of the left and right halves
    int leftSum = maxSum(numVect, start, mid);
    int rightSum = maxSum(numVect, mid + 1, end);

    // Compute the maximum subarray sum that crosses the midpoint
    int crossSum = countSum(numVect, start, mid, end);

    // Return the maximum of the three computed sums
    return max(max(leftSum, rightSum), crossSum);
}

// Main function to read input, call maxSum function, and output the result
int main(){    
    // Define a vector to store input numbers
    vector<int> numberVector;
    int k = 0;
    
    // Read a line of input containing space-separated numbers
    string input;
    getline(cin, input);
    
    // Create a string stream to extract numbers from the input line
    istringstream stream(input);
    int number;
    
    // Extract numbers from the string stream and add them to the vector
    while (stream >> number) {
        numberVector.push_back(number);
        k++;
    }

    // Call the maxSum function to compute the maximum subarray sum
    int output = maxSum(numberVector, 0, k-1);
    
    // Output the maximum subarray sum
    cout << output << endl;
}
