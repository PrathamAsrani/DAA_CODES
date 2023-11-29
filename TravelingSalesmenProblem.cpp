#include <bits/stdc++.h>

using namespace std;

int TravelingSalesmenProblem(int PossibilitesChecked, int currNode, int &totalPossibilities, vector<vector<int>> &dp, int &nodes, vector<vector<int>> &cost){
    if(PossibilitesChecked == totalPossibilities) return cost[currNode][0];
    if(dp[PossibilitesChecked][currNode] != -1) return dp[PossibilitesChecked][currNode];
    int ans = INT_MAX;
    for(int nextNode = 0; nextNode < nodes; nextNode++){
        if((PossibilitesChecked & (1 << nextNode)) == 0){
            // not visited
            int newAns =  cost[currNode][nextNode] + TravelingSalesmenProblem(PossibilitesChecked | (1 << nextNode), nextNode, totalPossibilities, dp, nodes, cost);
            ans = min(ans, newAns);
        }
    }
    return dp[PossibilitesChecked][currNode] = ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> cost = { 
        {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 13, 0, 12},
        {8, 8, 9, 0}
    }; // ans: 35
    vector<vector<int>> _cost = {
        {0, 20, 42, 25},
        {20, 0, 30, 25},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    }; // ans: 85
    int nodes = 4;
    int totalPossibilities = (1<<nodes)-1, PossibilitesChecked = 1;
    vector<vector<int>> dp((1 << nodes), vector<int>(nodes, -1));
    int minCost = TravelingSalesmenProblem(PossibilitesChecked, 0, totalPossibilities, dp, nodes, cost);
    cout << "minCost for Graph 1: " << minCost << "\n";

    for(int i = 0; i < (1 << nodes); i++) for(int j = 0; j < nodes; j++) dp[i][j] = -1;
    minCost = TravelingSalesmenProblem(PossibilitesChecked, 0, totalPossibilities, dp, nodes, _cost);
    cout << "minCost for Graph 2: " << minCost << "\n";
    return 0;
}
