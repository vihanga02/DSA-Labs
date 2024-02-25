#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

vector<int> returnArray(string inputLine)
{
    istringstream inputStream(inputLine);
    vector<int> array;
    int number;
    while (inputStream >> number)
    {
        array.push_back(number);
    }
    return array;
}

vector<int> merge(vector<int> array, int start, int center, int end){ //Merge the two arrays
    int leftArraySize = center - start + 1; //Size of the left array
    int rightArraySize = end - center; //Size of the right array
    vector<int> leftArray(leftArraySize); //Declare a vector to store the left array
    vector<int> rightArray(rightArraySize); //Declare a vector to store the right array

    for (int i =0; i < leftArraySize; ++i){ 
        leftArray[i] = array[start +i]; //Store the left array elements in the vector   
    }

    for (int j =0; j < rightArraySize; ++j){
        rightArray[j] = array[center + 1 +j]; //Store the right array elements in the vector
    }
    
    int i = 0, j = 0, k = start; //Declare variables to store the indices of the left and right arrays
    while (i < leftArraySize && j < rightArraySize) { 
        if (leftArray[i] <= rightArray[j]) { //If the left array element is less than or equal to the right array element
            array[k++] = leftArray[i++]; //Store the left array element in the array
        } else { //If the right array element is less than the left array element
            array[k++] = rightArray[j++]; //Store the right array element in the array
        }
    }

    while (i < leftArraySize) { //Store the remaining elements of the left array in the array
        array[k++] = leftArray[i++]; 
    }
    while (j < rightArraySize) { //Store the remaining elements of the right array in the array
        array[k++] = rightArray[j++];
    }
    return array; //Return the merged array
}

vector<int> mergeSort(vector<int> array, int start, int end){ //Sort the array using merge sort
    if (start < end){ //If the start index is less than the end index
        int center = (start + end) / 2; //Find the center index
        array = mergeSort(array, start, center); //Sort the left half of the array
        array = mergeSort(array, center + 1, end); //Sort the right half of the array
        array = merge(array, start, center, end); //Merge the sorted halves
    }    
    return array;
}

int main()
{
    ifstream inputFile("random arrrays.txt");  // Assuming your input file is named "input.txt"
    string inputLine;
    vector<int> timeArray;
    while (getline(inputFile, inputLine))
    {
        if (!inputLine.empty()){

        auto start = chrono::steady_clock::now();

        vector<int> array = returnArray(inputLine);
        array = mergeSort(array, 0, array.size() - 1);

        auto end = chrono::steady_clock::now();
        auto time = chrono::duration_cast<chrono::microseconds>(end - start);
        timeArray.push_back(time.count());
        }
    }
    cout << "[";
    for (size_t i = 0; i < timeArray.size(); ++i) {
        cout << timeArray[i];
        if (i < timeArray.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << std::endl;

    inputFile.close();

    return 0;
}
