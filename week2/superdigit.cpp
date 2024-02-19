#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

// Define the superDigit function and pass 2 parameters
int superDigit(string n, int k) {
    // Initialize a new strin to store the passed srting to the function
    string concatenatedString = n;
    //concatenate the string for given k times
    for (int i = 0; i < k-1; i++){
        concatenatedString += n;
    }
    // Check if the concatanated string's length is 1 or not
    if (concatenatedString.size() == 1){
        //conver the string to digit 
        int finalDigit = concatenatedString[0] - '0';
        //print and return the concatenated string if its length is 1
        cout << finalDigit << endl;
        return finalDigit;
    }
    else{
        //initialize a new int to store the sum of the digits of the concatenated string
        int sum = 0;
        //increment the sum by adding the digits of the string
        for (char digit: concatenatedString){
            sum += digit - '0';
        }
        // Recursivly calling the super digit function and pass String sum and 1 as parameters
        return superDigit(to_string(sum), 1);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    string n = first_multiple_input[0];

    int k = stoi(first_multiple_input[1]);

    int result = superDigit(n, k);

    fout << result << "\n";

    fout.close();

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