class Solution {
    public:
    int f(vector<int>&coins,int n, int target, vector<vector<int>>&dp) {
        if(n == 0) {
            if(target%coins[0] == 0)return target/coins[0];
            else return 1e9;
        }
        if(dp[n][target] != -1)return dp[n][target];
    
        int notTake = f(coins,n-1,target,dp);
        int take = INT_MAX;
        if(coins[n]<=target) {
            take = 1 + f(coins,n,target-coins[n],dp);
        }
    
        return dp[n][target] = min(take,notTake);
    }
    public:
        int coinChange(vector<int>& coins, int amount) {
            int n = coins.size();
            vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    
            int ans = f(coins,n-1,amount,dp);
            if(ans == 1e9)return -1;
            else return ans;
            
        }
    };