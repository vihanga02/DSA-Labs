#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int lilysHomework(vector<int> arr) {
    // Make a backup copy of the input array
    vector<int> arr1 = arr;  
    vector<int> arr2 = arr;
    // Initialize a variable to count the number of swaps needed to sort the array in ascending and descending order
    int swapsInMin = 0;  
    int swapsInMax = 0; 
    // Iterate through the array to find the minimum element at each position
    for (size_t i=0; i<arr.size()-1; i++){  
        // Assume the current element is the minimum and the minimum
        int minimum = arr1[i]; 
        int maximum = arr2[i]; 
        // Initialize the index of the minimum and maximum element 
        size_t minIndex = i;  
        size_t maxIndex = i; 
        // Iterate through the remaining elements to find the minimum

        for (size_t j=i+1; j<arr.size(); j++){  
            // If the current element is smaller than the assumed minimum
            if (arr1[j] < minimum){  
                // Update the minimum value and index
                minimum = arr1[j];   
                minIndex = j;       
            }
            // If the current element is greater than the assumed maximum
            if (arr2[j] > maximum){  
                // Update the maximum value and index
                maximum = arr2[j];   
                maxIndex = j;      
            }
        }

        // If the minimum element is not at its correct position
        if (minIndex != i){  
             // Swap the minimum element with the current element
            swap(arr1[i],arr1[minIndex]); 
            // Increment the number of swaps
            swapsInMin++;  
        }

        // If the maximum element is not at its correct position
        if (maxIndex != i){  
            // Swap the maximum element with the current element
            swap(arr2[i],arr2[maxIndex]);  
            // Increment the number of swaps
            swapsInMax++;  
        }
    }
    // Return the minimum of swaps needed for sorting in ascending and descending order
    return min(swapsInMax,swapsInMin);  

}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
