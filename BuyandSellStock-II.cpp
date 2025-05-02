#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    
    long long f(int ind,int n, int buy, vector<int>&prices, vector<vector<int>>&dp) {
    
        if(n == ind)return 0;
        if(dp[n][buy] != -1)return dp[n][buy];
    
        long long profit = 0;
    
        if(buy) {
            profit =  max((-prices[ind] + f(ind+1,n,0,prices,dp)), (0+f(ind+1,n,1,prices,dp)));
                             
        }
        else {
            profit = max((prices[ind] + f(ind+1,n,1,prices,dp)), (0+f(ind+1,n,0,prices,dp)));
        }
        return dp[ind][buy] = profit;
    
    
    
    }
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    
            dp[n][0] = dp[n][1] = 0;
    
            for (int ind = n - 1; ind >= 0; ind--) {
                for (int buy = 0; buy < 2; buy++) {
                    int profit = 0;
                    if (buy) {
                        profit = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                    } else {
                        profit = max(prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);
                    }
                    dp[ind][buy] = profit;
                }
            }
    
            return dp[0][1];  // Start at day 0 with buying allowed
        }
    };