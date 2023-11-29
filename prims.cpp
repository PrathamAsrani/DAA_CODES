#include <bits/stdc++.h>

using namespace std;

void primsMST(int V, vector<vector<int>> cost, vector<pair<pair<int, int>, int>> &ans, long long &totalCost);
int minKey(vector<int> &near, vector<bool> &visited);

int main(){
    int n = 5;
    vector<pair<pair<int, int>, int>>ans;
    long long totalCost = 0;

    /*
    vector<vector<int>> cost(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> cost[i][j];
            if(cost[i][j] == 0) cost[i][j] = INT_MAX;
        }
    }
    */
    vector<vector<int>> cost = { { 0, 2, 0, 6, 0 },
                                 { 2, 0, 3, 8, 5 },
                                 { 0, 3, 0, 0, 7 },
                                 { 6, 8, 0, 0, 9 },
                                 { 0, 5, 7, 9, 0 } };
    primsMST(n, cost, ans, totalCost);
    for(auto i:ans) cout << i.first.first << " " << i.first.second << " = " << i.second << "\n";
    cout << "total cost: " << totalCost << "\n";
    return 0;
}

void primsMST(int V, vector<vector<int>> cost, vector<pair<pair<int, int>, int>> &ans, long long &totalCost){
    int mini = INT_MAX, k = 0, l = 0;
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(cost[i][j] != 0 && cost[i][j] < mini){
                mini = cost[i][j];
                k = i;
                l = j;
            }
            if(cost[i][j] == 0) cost[i][j] = INT_MAX;
        }
    }
    totalCost += mini;
    ans.push_back({{k, l}, mini});
    vector<int> near(V, INT_MAX);
    near[k] = near[l] = -1;
    for (int i = 0; i < V; i++)
    {
        if(near[i] != -1){
            if(cost[k][i] < cost[l][i]) near[i] = k;
            else near[i] = l;
        }
    }
    
    // print near
    // for(auto n:near) cout << n << " ";
    for(int i = 0; i < V-2; i++){
        // find mini in near
        int minIdx, minVal = INT_MAX;
        for(int j = 0; j < V; j++){
            if(near[j] != -1 && cost[j][near[j]] < minVal){
                minVal = cost[j][near[j]];
                minIdx = j;
            }
        }
        // push into ans
        ans.push_back({{minIdx, near[minIdx]}, cost[minIdx][near[minIdx]]});
        totalCost += cost[minIdx][near[minIdx]];
        near[minIdx] = -1;
        // update near
        for(int j = 0; j < V; j++){
            if(near[j] != -1){
                if(cost[minIdx][j] < cost[near[j]][j]){
                    near[j] = minIdx;
                }
            }
        }
    }
}
