#include <bits/stdc++.h> 
using namespace std;

int f(vector<int> &weight, vector<int> &value, int n, int maxWeight, vector<vector<int>> &dp) {
    if(n == 0) {
        if(weight[0] <= maxWeight) return value[0];
        else return 0;
    }
    if(dp[n][maxWeight] != -1) return dp[n][maxWeight];

    int notTake = f(weight, value, n-1, maxWeight, dp);
    int take = INT_MIN;
    if(weight[n] <= maxWeight) {
        take = value[n] + f(weight, value, n-1, maxWeight - weight[n], dp);
    }

    return dp[n][maxWeight] = max(take, notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return f(weight, value, n - 1, maxWeight, dp);
}
