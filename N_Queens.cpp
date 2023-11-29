#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> nQueens(int n);
void solve(int col, int n, vector<vector<int>> &board, vector<vector<int>> &ans);
void addSolution(int n, vector<vector<int>> &board, vector<vector<int>> &ans);
bool isSafe(int row, int col, int n, vector<vector<int>> &board);

int main(){
    int n;
    n = 4;
    vector<vector<int>> ans = nQueens(n);
    for(auto i:ans){
        for(auto j:i) cout << j << " ";
        cout << "\n";
    }
}

vector<vector<int>> nQueens(int n){
    vector<vector<int>> ans, board(n, vector<int>(n, 0));
    solve(0, n, board, ans);
    return ans;
}

void solve(int col, int n, vector<vector<int>> &board, vector<vector<int>> &ans){
    if(col == n){
        addSolution(n, board, ans);
        return ;
    }
    for(int row = 0; row < n; row++){
        if(isSafe(row, col, n, board)){
            board[row][col] = 1;
            solve(col+1, n, board, ans);
            board[row][col] = 0;
        }
    }
}

void addSolution(int n, vector<vector<int>> &board, vector<vector<int>> &ans){
    vector<int> sol;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(board[i][j]) sol.push_back(j+1);
    ans.push_back(sol);
}

bool isSafe(int row, int col, int n, vector<vector<int>> &board){
    for(int i = 0; i < n; i++) if(board[i][col] == 1) return false; // check row
    for(int i = 0; i < n; i++) if(board[row][i] == 1) return false; // check col
    int x = row, y = col;
    while(x >= 0 && y >= 0){
        if(board[x--][y--] == 1) return false; // check diagonal left up
    }
    x = row, y = col;
    while(x < n && y < n){
        if(board[x++][y++] == 1) return false; // check diagonal right down
    }
    x = row, y = col;
    while(x >= 0 && y < n){
        if(board[x--][y++] == 1) return false; // check diagonal left down
    }
    x = row, y = col;
    while(x < n && y >= 0){
        if(board[x++][y--] == 1) return false; // check diagonal right up
    }
    return true;
}