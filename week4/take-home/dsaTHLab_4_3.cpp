#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'closestNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<int> closestNumbers(vector<int> arr) {
    // Sort the input array in ascending order
    sort(arr.begin(), arr.end());  
    // Initialize an empty vector to store the pairs with minimum absolute difference
    vector<int> minPairs;  
    // Initialize the minimum absolute difference with the difference between the first two elements
    int minDiff = abs(arr[0] - arr[1]);  

    // Iterate through the sorted array to find pairs with minimum absolute difference
    for (size_t i=0; i<arr.size()-1; i++){  
        // Calculate the absolute difference between the current element and the next element
        int diff = abs(arr[i] - arr[i+1]);  
        // If the current absolute difference is greater than the minimum absolute difference found so far
        if ( diff > minDiff){  
            // Skip to the next iteration
            continue;  
        }
        // If the current absolute difference is less than the minimum absolute difference found so far
        else if (diff < minDiff){  
            // Clear the vector of pairs
            minPairs.clear();  
            // Update the minimum absolute difference
            minDiff = diff;  
        }
        // Add the current pair to the vector of pairs
        minPairs.push_back(arr[i]);  
        // Add the next element of the pair to the vector of pairs
        minPairs.push_back(arr[i+1]);  
    }
    // Return the vector containing pairs with minimum absolute difference
    return minPairs;  
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

    vector<int> result = closestNumbers(arr);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";

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
