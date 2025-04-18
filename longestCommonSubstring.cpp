

int lcs(string &str1, string &str2){
    // Write your code here.

    int n = str1.size();
    int m = str2.size();
    int result = 0;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                result = max(result, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return result;

}