#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
             int mini = prices[0];
             int profit = 0;
    
             for(int i = 1; i< prices.size(); i++) {
                int cost = prices[i] - mini;
                profit = max(profit, cost);
                mini = min(mini,prices[i]);
             }
    
             return profit;
    
        }
    };