#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void generateCombinations(vector<long double>& nPowers, vector<long double>& temp, vector<vector<long double>>& combinations, int start) {
    if (temp.size() > 0) {
        combinations.push_back(temp);
    }

    for (size_t i = start; i < nPowers.size(); ++i) {
        temp.push_back(nPowers[i]);
        generateCombinations(nPowers, temp, combinations, i + 1);
        temp.pop_back();
    }
}

int powerSum(int X, int N) {
    vector<long double> nPowers;
    vector<vector<long double>> combinations;
    int count = 0;
    
    for (int i = 1; i <= X; ++i) {
        long double power = pow(i, N);
        if (power <= X) {
            nPowers.push_back(power);
        } else {
            break;
        }
    }
  
    vector<long double> temp;
    generateCombinations(nPowers, temp, combinations, 0);


    for (vector<long double>  combination : combinations) {
        double sum = 0;
        for (double power : combination) {
            sum += power;
        }
        if ((int)sum == X){
            count++;
        }
    }
    cout << count << endl;
    return count;
}

int main() {
    int x, n;
    cin >> x >> n;
    cout << powerSum(x, n) << endl;
    return 0;
}










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
