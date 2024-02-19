#include <iostream>
using namespace std;

int search(int arr[], int target, int start, int end) {
    if (start > end){
        return false;
    }
    else if (target == arr[start]){
        return true;
    }
    else{
        return search(arr, target, start+1, end);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    int target;
    cin >> target;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    bool found = search(arr, target, 0, n);
    if (found) {
        cout << "Element " << target << " found in the array." << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }
    return 0;
}