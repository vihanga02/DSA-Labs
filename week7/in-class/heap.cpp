#include <iostream>

using namespace std;

void heapify(int arr[], int n, int root)
{
   // Initialize the maximum value index as the current root
   int maximumValueIndex = root;
   
   // Calculate the indices of the left and right child nodes
   int leftChildIndex = 2 * root + 1;
   int rightChildIndex = 2 * root + 2;
   
   // Update the maximum If the left child exists and its value is greater than the current maximum value
   if (leftChildIndex < n && arr[maximumValueIndex] < arr[leftChildIndex]){
      maximumValueIndex = leftChildIndex;
   }
   
   // Update the maximum If the right child exists and its value is greater than the current maximum value,
   if (rightChildIndex < n && arr[maximumValueIndex] < arr[rightChildIndex]){
      maximumValueIndex = rightChildIndex; 
   }

   // If the maximum value index has changed, swap the values between the parent and the maximum value index and recursively call heapify on the affected subtree
   if (maximumValueIndex != root){
      swap(arr[root], arr[maximumValueIndex]);
      heapify(arr, n, maximumValueIndex);
   }
}

// This function implements the heap sort algorithm
void heapSort(int arr[], int n)
{
   // Build the heap by heapifying each non-leaf node from bottom to top
   for (int i = n/2-1; i >= 0; i--){
      heapify(arr,n,i);
   }
  
   // After each extraction, the heap size is reduced, and the heap property is restored by heapifying the remaining elements.
   for (int j = n-1; j > 0 ; j--){
      // Move the current root to the end of the array
      swap(arr[0], arr[j]); 
      // Restore the heap property in the remaining heap
      heapify(arr, j, 0);   
   }
}

  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}