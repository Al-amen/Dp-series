int f(vector<int>& arr, int ind, int k, vector<vector<int>>& dp, int m) {
    if (ind == 0) {
        if (k == 0 && arr[0] == 0) return 2; // include or exclude the 0
        if (k == 0 || arr[0] == k) return 1;
        return 0;
    }

    if (dp[ind][k] != -1) return dp[ind][k];

    int notTake = f(arr, ind - 1, k, dp, m) % m;
    int take = 0;
    if (arr[ind] <= k) {
        take = f(arr, ind - 1, k - arr[ind], dp, m) % m;
    }

    return dp[ind][k] = (take + notTake) % m;
}

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    int m = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(arr, n - 1, k, dp, m);
}