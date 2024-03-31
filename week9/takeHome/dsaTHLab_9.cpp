#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */

// Define the function to calculate the minimum cost to provide library access to all citizens
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    // Create an adjacency list to represent connections between cities
    vector<vector<int>> adjacent(n);
    // Create a boolean array to track visited cities
    vector<bool> isVisited(n , false);

    // Populate the adjacency list based on the input cities
    for (vector<int> city : cities){
        // Adjust indices to 0-based indexing and add connections for bidirectional roads
        adjacent[city[0]-1].push_back(city[1]-1);
        adjacent[city[1]-1].push_back(city[0]-1);
    }

    // Initialize counts for roads and libraries
    int roadCount = 0;
    int libraryCount = 0;

    // Iterate through each city
    for (size_t i = 0; i < isVisited.size(); i++){
         // If the city is not visited, it represents a new connected component
         if (!isVisited[i]) {
            stack<int> st;
            st.push(i); // Start DFS from this city
            isVisited[i] = true; // Mark the city as visited
            libraryCount++; // Each connected component requires one library

            // Perform DFS traversal to explore connected cities
            while (!st.empty()) {
                int node = st.top();
                st.pop();
                // Visit each neighbor of the current city
                for (int neighbor : adjacent[node]) {
                    if (!isVisited[neighbor]) {
                        st.push(neighbor); // Add unvisited neighbor to the stack
                        isVisited[neighbor] = true; // Mark neighbor as visited
                        roadCount++; // Increment road count for each road traversed
                    }
                }
            }
        }
    }
    
    // If building a library is cheaper than building a road, adjust the cost
    if (c_lib < c_road){
        c_road = c_lib;
    }

    // Calculate the total cost by multiplying the counts with their respective costs
    return roadCount * c_road + libraryCount * c_lib;
}


int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int c_lib = stoi(first_multiple_input[2]);

        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);

        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);

            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int cities_row_item = stoi(cities_row_temp[j]);

                cities[i][j] = cities_row_item;
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        cout << result << "\n";
    }

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
