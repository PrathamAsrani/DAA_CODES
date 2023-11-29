//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisJointSet{
    public:
    vector<int> parent, rank;
    DisJointSet(int V){
        for(int i = 0; i < V; i++){
            parent.push_back(-1);
            rank.push_back(0);
        }
    }
    int findParent(int i){
        if(parent[i] == -1) return i;
        return parent[i] = findParent(parent[i]);
    }
    void unite(int x, int y){
        int s1 = findParent(x), s2 = findParent(y);
        if(s1 == s2) return ;
        if(rank[s1] > rank[s2]) parent[s2] = s1;
        else if(rank[s1] < rank[s2]) parent[s1] = s2;
        else {
            parent[s2] = s1;
            rank[s1]++;
        }
    }
};

class Solution
{
	public:
	void kruskalMST(vector<vector<int>> &Graph, int V, int &tv, vector<pair<pair<int, int>, int>> &ans){
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
                tv += weight;
                ans.push_back({{src, des}, weight});
            }
        }
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	void primsMst(vector<vector<int>> cost, int V, int &tv, vector<pair<pair<int, int>, int>> &ans){
	    int k = 0, l = 0, mini = INT_MAX;
	    for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(cost[i][j] != 0 && mini > cost[i][j]){
                    k = i, l = j, mini = cost[i][j];
                }
                if(cost[i][j] == 0) cost[i][j] = INT_MAX;
            }
        }
        ans.push_back({{k, l}, mini});
        tv += mini;
        // cout << mini << "\n";
        vector<int> near(V, INT_MAX);
        near[k] = near[l] = -1; // visited
        for(int i = 0; i < V; i++){
            if(near[i] != -1){
                if(cost[k][i] < cost[l][i]){
                    near[i] = k;
                }else near[i] = l;
            }
        }
        for(int i = 0; i < V-2; i++){
            // find mini in near
            int minIdx, minVal = INT_MAX;
            for(int j = 0; j < V; j++){
                if(near[j] != -1 && cost[j][near[j]] < minVal){
                    minIdx = j;
                    minVal = cost[j][near[j]];  
                }
            }
            ans.push_back({{minIdx, near[minIdx]}, cost[minIdx][near[minIdx]]});
            tv += cost[minIdx][near[minIdx]];
            // update near
            for(int j = 0; j < V; j++){
                if(near[j] != -1){
                    if(cost[j][minIdx] < cost[j][near[j]]) near[j] = minIdx;
                }
            }
            near[minIdx] = -1;
        }
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int totalValue = 0;
        vector<vector<int>> cost(V, vector<int>(V, 0));
        for(int itr = 0; itr < V; itr++){
            for(auto it:adj[itr]){
                cost[itr][it[0]] = it[1];
            }
        }
        // for(int i = 0; i < V; i++){
        //     for(int j = 0; j < V; j++){
        //         cout << cost[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        vector<pair<pair<int, int>, int>> ans;
        
        // primsMst(cost, V, totalValue, ans);
        kruskalMST(cost, V, totalValue, ans);
        return totalValue;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends