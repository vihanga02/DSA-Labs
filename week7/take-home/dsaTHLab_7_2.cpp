#include <bits/stdc++.h>

using namespace std;

void heapify(vector<int> &arr, int root){
    int n = arr.size();
    int minValueIndex = root;
    int leftChildIndIex = 2*root + 1;
    int rightChildndex = 2*root + 2;

    if (arr[leftChildIndIex] < arr[minValueIndex] && leftChildIndIex < n){
        minValueIndex = leftChildIndIex;
    }

    if (arr[rightChildndex] < arr[minValueIndex] && rightChildndex < n){
        minValueIndex = rightChildndex;
    }

    if (minValueIndex != root){
        swap(arr[root], arr[minValueIndex]);
        heapify(arr, minValueIndex);
    }
}

void insert(vector<int> &arr, int num){
    arr.push_back(num);
    int n = arr.size();
    int child = n -1;
    int parent = (n - 1) / 2;
    
    while (arr[parent] > num && parent >= 0){
        swap(arr[parent], arr[child]);
        child = parent;
        parent = (child - 1) / 2;
    }
}

int remove(vector<int> &arr){
    int lowest;
    if (arr.size() > 0){
        swap(arr[0], arr[arr.size() - 1]);
        lowest = arr.back();
        arr.pop_back();
        heapify(arr, 0);
    }
    return lowest;
}

int main(){
    vector<int> numberVector;
    int arraySize, k;
    cin >> arraySize >> k;
    for (int i = 0; i < arraySize; i++){
        int num;
        cin >> num;
        numberVector.push_back(num);
    }
    for (int i = arraySize/2-1; i >= 0; i--){
      heapify(numberVector,i);
   }
   int count = 0;
   while (true){
        int lowestElement = remove(numberVector);
        int secondLowestElement = remove(numberVector);
        insert(numberVector, lowestElement + 2*secondLowestElement);
        count++;
        if (numberVector[0] >= k){
            cout << count << endl;
            break;
        } 
   }
}