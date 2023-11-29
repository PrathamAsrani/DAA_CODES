#include <bits/stdc++.h>

using namespace std;

bool hasCycle;

void hamCycle(vector<vector<int>> &graph, int V);
void FindHamCycle(vector<vector<int>> &graph, int node, vector<int> &path, vector<bool> &visited, int V);
bool isSafe(int v, vector<vector<int>> &graph, vector<int> &path, int node);

int main(){
    // Print all Hamiltonian Cycles in an Undirected Graph
    vector<vector<int>> graph = {
        { 0, 1, 1, 0, 0, 1 },
        { 1, 0, 1, 0, 1, 1 },
        { 1, 1, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 0, 1 },
        { 1, 1, 0, 0, 1, 0 }
    };
    hamCycle(graph, graph.size());
}

void hamCycle(vector<vector<int>> &graph, int V){
    hasCycle = false;
    vector<int> path;
    path.push_back(0);
    vector<bool> visited(V, false);
    visited[0] = true;

    FindHamCycle(graph, 1, path, visited, V);
}

void FindHamCycle(vector<vector<int>> &graph, int node, vector<int> &path, vector<bool> &visited, int V){
    if(node == V && graph[path[path.size()-1]][path[0]] != 0){
        // If all vertices are included in Hamiltonian Cycle, and If there is an edge from the last vertex to the source vertex
        path.push_back(0);
        for(int i = 0; i < path.size(); i++) cout << path[i] << " ";
        cout << "\n";

        // backtrack remove src from last
        path.pop_back();

        hasCycle = true;
        return;
    }

    for(int v = 0; v < V; v++) {
        // try diff vertices
        if(isSafe(v, graph, path, node) && !visited[v]){
            path.push_back(v);
            visited[v] = true;
            FindHamCycle(graph, node+1, path, visited, V);
            visited[v] = false;
            path.pop_back();
        }
    }

    return ;
}

bool isSafe(int v, vector<vector<int>> &graph, vector<int> &path, int node){
    if(graph[v][node-1] == 0) return false; // check edge between v and node-1

    // check if vertex v already included in path or not?
    if(find(path.begin(), path.end(), v) != path.end()) return false;

    return true;
}