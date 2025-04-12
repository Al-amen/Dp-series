#include <bits/stdc++.h>
using namespace std;

int M = 1e9 + 7;

int f(vector<int>& arr, int ind, int target, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (target == 0 && arr[0] == 0) return 2;  // include and exclude zero
        if (target == 0 || target == arr[0]) return 1;
        return 0;
    }

    if (dp[ind][target] != -1) return dp[ind][target];

    int notTake = f(arr, ind - 1, target, dp) % M;
    int take = 0;
    if (arr[ind] <= target) {
        take = f(arr, ind - 1, target - arr[ind], dp) % M;
    }

    return dp[ind][target] = (take + notTake) % M;
}

int countPartitions(int n, int d, vector<int>& arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    
    if ((total - d) < 0 || (total - d) % 2 != 0) return 0;
    
    int target = (total - d) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    
    return f(arr, n - 1, target, dp);
}
