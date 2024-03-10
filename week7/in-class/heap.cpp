#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify  
   int maximumValueIndex = root;
   int leftChildIndIex = 2*root + 1;
   int rightChildndex = 2*root + 2;
1
   if (leftChildIndIex < n && arr[maximumValueIndex] < arr[leftChildIndIex]){
      maximumValueIndex = leftChildIndIex;
   }
   
   if (rightChildndex < n && arr[maximumValueIndex] < arr[rightChildndex]){
      maximumValueIndex = rightChildndex; 
   }

   if (maximumValueIndex != root){
      swap(arr[root], arr[maximumValueIndex]);
      heapify(arr, n, maximumValueIndex);
   }

}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n/2-1; i >= 0; i--){
      heapify(arr,n,i);
   }
  
   // extracting elements from heap one by one
   for (int j = n-1; j > 0 1; j--){
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
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