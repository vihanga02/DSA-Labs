#include <iostream>

using namespace std;

#define size 6

int getTHeMinimumEdge(int key[size],bool visited[size]){
    int min = __INT_MAX__;
    int minIndex;
    for (int i = 0; i < size; i++){
        if (!visited[i] && key[i] < min){
            minIndex = i;
            min = key[i];
        }
    }
    return minIndex;
}

void PrimMst(int Graph[size][size]){
    int parent[size];
    int key[size];
    bool isVisited[size];

    for (int i = 0; i < size; i++){
        key[i] = __INT_MAX__;
        isVisited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < size - 1; i++){
        int u = getTHeMinimumEdge(key, isVisited);
        isVisited[u] = true;

        for (int j = 0; j < size; j++){
            if (!isVisited[j] && Graph[u][j] && Graph[u][j]<key[j]){
                parent[j] = u;
                key[j] = Graph[u][j];
            }
        }
    }

    for(int i = 1; i < size; i++)
    {
        cout<<parent[i]<<"-"<<i<<" => "<<Graph[i][parent[i]]<<endl;
    }
}

int main(){
    //Adjacent matrix
    int Graph[size][size] =
    {
        {0,3,0,0,0,1},
        {3,0,2,1,10,0},
        {0,2,0,3,0,5},
        {0,1,3,0,5,0},
        {0,10,0,5,0,4},
        {1,0,5,0,4,0}
    };
    PrimMst(Graph);
    return 0;
}