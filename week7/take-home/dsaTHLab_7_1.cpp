#include <bits/stdc++.h>

using namespace std;
void heapify(vector<int> &arr, int root){
    int n = arr.size();
    int maximumValueIndex = root;
    int leftChildIndIex = 2*root + 1;
    int rightChildndex = 2*root + 2;

    if (arr[leftChildIndIex] > arr[root] && leftChildIndIex < n){
        maximumValueIndex = leftChildIndIex;
    }

    if (arr[rightChildndex] > arr[root] && rightChildndex < n){
        maximumValueIndex = rightChildndex;
    }

    if (maximumValueIndex != root){
        swap(arr[root], arr[maximumValueIndex]);
        heapify(arr, maximumValueIndex);
    }
}

void insert(vector<int> &arr, int num){
    arr.push_back(num);
    int n = arr.size();
    int child = n -1;
    int parent = (n - 1) / 2;
    
    while (arr[parent] < num && parent >= 0){
        swap(arr[parent], arr[child]);
        child = parent;
        parent = (child - 1) / 2;
    }
}

void remove(vector<int> &arr, int num){
    auto it = find(arr.begin(), arr.end(), num);
    if (it != arr.end()){
        int index = it - arr.begin();
        swap(arr[index], arr[arr.size() - 1]);
        arr.pop_back();
        heapify(arr, index);
    }
    
}

void printMin(vector<int> arr){
    int minimum = arr[0];
    for (size_t i=0; i < arr.size(); i++){
        minimum = min(minimum, arr[i]);
    }
    cout << minimum << endl;
}

int main(){
    vector<int> numberVector;
    int quaries;
    cin >> quaries;
    for (int i = 0; i < quaries; i++){
        int operation;
        cin >> operation;
        if (operation == 1){
            int operand;
            cin >> operand;
            insert(numberVector, operand);
        }
        else if (operation == 2){
            int operand;
            cin >> operand;
            remove(numberVector, operand);
        }
        else if (operation == 3){
            printMin(numberVector);
        }
    }
}
/*
5
1 4
1 9
3
2 4
3 */