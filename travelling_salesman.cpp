#include <iostream>

using namespace std;

#define V 4
#define INF 999999

// Distance matrix representing the graph
int graph[V][V] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

bool visited[V];
int min_cost = INF;

void findTSP(int currCity, int count, int cost) {
    // Base Case: If all cities have been visited
    if (count == V) {
        // Add cost to return to the starting city (0)
        int final_cost = cost + graph[currCity][0];
        if (final_cost < min_cost) {
            min_cost = final_cost;
        }
        return;
    }

    // Try to visit every city
    for (int i = 0; i < V; i++) {
        // If city 'i' is not visited and there is a path
        if (!visited[i] && graph[currCity][i] > 0) {
            
            // Mark as visited
            visited[i] = true;
            
            // Recurse to move to the next city
            findTSP(i, count + 1, cost + graph[currCity][i]);
            
            // Backtrack: Unmark the city to allow other paths
            visited[i] = false;
        }
    }
}

int main() {
    // Initialize visited array to false
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Start from the first city (index 0)
    visited[0] = true;
    findTSP(0, 1, 0);

    cout << "Minimum TSP Cost: " << min_cost << endl;

    return 0;
}