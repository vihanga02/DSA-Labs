#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    // Initialize vectors to store distances from the start node to all other nodes adn store adjecent nodes
    vector<int> distance(n + 1, -1); 
    vector<vector<int>> adjList(n + 1);

    // Build the adjacency list using the given edges
    for (const auto& edge : edges) {
        adjList[edge[0]].push_back(edge[1]); 
        adjList[edge[1]].push_back(edge[0]); 
    }

    // Initialize a queue for BFS traversal
    queue<int> q; 
    // Enqueue the start node into the queue
    q.push(s); 
    // Set the distance to the start node as 0
    distance[s] = 0; 

    // Continue BFS traversal until the queue is empty
    while (!q.empty()) {
        // Get the front node of the queue
        int current = q.front(); 
        // Dequeue the front node
        q.pop(); 

        // Traverse all neighbors of the current node
        for (int neighbour : adjList[current]) {
            // If the neighbour has not been visited (distance is still -1), update its distance and enqueue it
            if (distance[neighbour] == -1) {
                // Enqueue the neighbour node
                q.push(neighbour); 
                // Update the distance to the neighbour node
                distance[neighbour] = distance[current] + 6; 
            }
        }
    }
    
    // Adjust the returned distance vector to exclude the distance to the start node and adjust for 1-based indexing
    distance.erase(distance.begin() + s); 
    distance.erase(distance.begin()); 
    
    // Return the distances from the start node to all other nodes
    return distance;
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

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
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
