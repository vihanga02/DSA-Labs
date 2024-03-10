#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */
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

// int remove(vector<int> &arr){
//     int lowest;
//     if (arr.size() > 0){
//         swap(arr[0], arr[arr.size() - 1]);
//         lowest = arr.back();
//         arr.pop_back();
//         heapify(arr, 0);
//     }
//     return lowest;
// }

int cookies(int k, vector<int> A) {
    //make_heap(A.begin(), A.end(), greater<int>());
    for (int i = k/2-1; i >= 0; i--){
        heapify(A,i);
   }
   int count = 0;
   while (A.size() >0 && A[0] < k){
        if (A.size() < 2) {
            // Not enough elements to combine
            return -1;
        }
        int lowestElement = A.front();
        swap(A[0], A[k-1]);
        heapify(A,0);
        A.pop_back();

        int secondLowestElement = A.front();
        swap(A[0], A[k-1]);
        heapify(A,0);
        A.pop_back();
    
        insert(A, lowestElement + 2*secondLowestElement);
        count++;
   }
    return A.empty() || A[0] < k ? -1 : count;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    int result = cookies(k, A);

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
