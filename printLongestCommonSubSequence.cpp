#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int lcs(string A, string B){
            int n = A.size(), m = B.size();
            vector<vector<int>> dp(n+1, vector<int>(m+1));
            for(int i = 0; i <= n; i++) dp[i][0] = 0;
            for(int j = 0; j <= m; j++) dp[0][j] = 0;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    if(A[i-1] == B[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                    else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
            int lenLCS = dp[n][m];
            int i = n, j = m, index = lenLCS-1;
            string ans(lenLCS, '$');
            while(i > 0 && j > 0){
                if(A[i-1] == B[j-1]){
                    ans[index--] = A[i-1];
                    i--, j--;
                }else if(dp[i-1][j] > dp[i][j-1]) i--;
                else j--;
            }
            cout << "LCS: " << ans << "\n";
            return lenLCS;
        }
};

int main(){
    string s1,s2;
    cin>>s1>>s2;
    Solution ob;
    cout << ob.lcs(s1, s2) << endl;
}