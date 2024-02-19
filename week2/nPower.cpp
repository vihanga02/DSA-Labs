#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */


int powerSum(int X, int N) {
    // Define a lambda function to calculate the number of combinations
    function<int(int, int)> powerSumAux = [&](int remainingX, int num) {
        // Initialize count to keep track of valid combinations
        int count = 0;
    
        // Calculate the power of the current number raised to N
        int power = pow(num, N);
    
        // If power is greater than remainingX, return 0 (base case)
        if (power > remainingX) {
            return 0;
        }
    
        // If power is equal to remainingX, return 1 (base case)
        if (power == remainingX) {
            return 1;
        }
    
        // Recursively explore combinations including and excluding the current number
        count += powerSumAux(remainingX - power, num + 1); 
        count += powerSumAux(remainingX, num + 1);         
    
        // Return the total count of valid combinations
        return count;
    };
    
    // Call the auxiliary function with initial arguments
    int result = powerSumAux(X, 1);
    
    // Print the final count
    cout << result << endl;
    
    // Return the final count from the powerSum function
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string X_temp;
    getline(cin, X_temp);

    int X = stoi(ltrim(rtrim(X_temp)));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    int result = powerSum(X, N);

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
