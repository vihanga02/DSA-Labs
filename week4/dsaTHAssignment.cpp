#include <iostream>
#include <sstream>
#include <vector>
#include <limits>

using namespace std;

int countSum(vector<int> &numVect, int start, int mid, int end){
    int sum = 0;
    int leftsum = std::numeric_limits<int>::min(); 
    for (int i= mid; i >= start; i--){
        sum = sum + numVect[i]; 
        if (sum > leftsum){ 
            leftsum = sum; 
        }
    }

    sum = 0;
    int rightSum = std::numeric_limits<int>::min(); 
    for (int i= mid+1; i <= end; i++){
        sum = sum + numVect[i]; 
        if (sum > rightSum) {
            rightSum = sum; 
        }
    }
    cout << rightSum+leftsum << endl;
    return max(max(rightSum , leftsum) , leftsum + rightSum);
    //return leftsum + rightSum;
}

int maxSum(vector<int> &numVect, int start, int end){
    if (start > end) {
        return std::numeric_limits<int>::min();
    } 
    if (start == end){
        return numVect[end];
    }
    
    int mid = (start + end)/2;
    int leftSum = maxSum(numVect, start, mid);
    int rightSum = maxSum(numVect, mid + 1, end);
    int crossSum = countSum(numVect, start, mid, end);

    return max(max(leftSum, rightSum), crossSum);
}

int main(){    
    vector<int> numberVector;
    int k = 0;
    
    string input;
    getline(cin, input);
    
    istringstream stream(input);
    int number;
    
    while (stream >> number) {
        numberVector.push_back(number);
        k++;
    }
    int output = maxSum(numberVector, 0, k-1);
    cout << output << endl;
}


// -2 -5 6 -2 -3 1 5 -6