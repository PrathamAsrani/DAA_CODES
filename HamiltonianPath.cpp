//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
N = 4, M = 4
Edges[][]= { {1,2}, {2,3}, {3,4}, {2,4} }

4 4
1 2 2 3 3 4 2 4

10 14
2 1 10 2 6 3 5 4 10 5 10 6 6 7 6 8 10 9 4 9 3 8 3 7 5 9 6 5
*/
class Solution
{
    public:
    bool check(int n,int m,vector<vector<int>> Edges)
    {
        vector<int> adjList[n+1];
        for(auto i: Edges) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        unordered_set<int> st;
        for(int i = 1; i <= n; i++) if(dfs(i, n, st, adjList)) return true;
        return false;
    }
    
    bool dfs(int node, int n, unordered_set<int> &st, vector<int> adjList[]){
        st.insert(node);
        if(st.size() == n){
            return true;
        }
        for(auto nei: adjList[node]){
            if(st.find(nei) == st.end() && dfs(nei, n, st, adjList)) {
                return true;
            }
        }
        
        st.erase(st.find(node));
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends