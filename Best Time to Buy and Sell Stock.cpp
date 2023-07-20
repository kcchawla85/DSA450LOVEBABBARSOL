#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
     int mini=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++)
        {
            int diff=prices[i]-mini;
            profit=max(profit,diff);
            mini=min(mini,prices[i]);
        }
        return profit;
}
// link : https://www.youtube.com/watch?v=BSRTUtvJSIk
