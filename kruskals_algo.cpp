#include<bits/stdc++.h>

using namespace std;

class DisJointSet{
    vector<int> parent;
    vector<int> rank;
    public:
        DisJointSet(int V){
            for(int i = 0; i < V; i++){
                parent.push_back(-1);
                rank.push_back(0);
            }
        }
        int findParent(int node){
            if(parent[node] == -1) return node;
            return parent[node] = findParent(parent[node]);
        }
        void unite(int x, int y){
            int s1 = findParent(x);
            int s2 = findParent(y);
            if(s1 == s2) return;
            if(rank[s1] > rank[s2]) parent[s2] = s1;
            else if(rank[s2] > rank[s1]) parent[s1] = s2;
            else {
                parent[s2] = s1;
                rank[s1]++;
            }
        }
};

void kruskalMST(vector<vector<int>> Graph, int &totalCost, vector<pair<pair<int, int>, int>> &path){
    int V = Graph.size();
    vector<vector<int>> edgeList;
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            if(Graph[i][j] != 0) edgeList.push_back({Graph[i][j], i, j}); // {weight, src, des}
    
    sort(edgeList.begin(), edgeList.end()); // acc to weight
    DisJointSet s(V);

    for(auto edge: edgeList){
        int src = edge[1], des = edge[2], weight = edge[0];
        if(s.findParent(src) != s.findParent(des)){
            s.unite(src, des);
            totalCost += weight;
            path.push_back({{src, des}, weight});
        }
    }
}

int main(){
    vector<vector<int>> Graph = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };
    int totalCost = 0;
    vector<pair<pair<int, int>, int>> path;
    kruskalMST(Graph, totalCost, path);
    cout << "The totalCost: " << totalCost << "\n";
    for(auto i:path) cout << i.first.first << " --> " << i.first.second << " == " << i.second << "\n";
}