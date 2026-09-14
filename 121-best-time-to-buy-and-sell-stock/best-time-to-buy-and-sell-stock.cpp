class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minprice=INT_MAX;
        int maxprice=0;
        for(int i=0;i<n;i++){
            minprice=min(prices[i],minprice);
            maxprice=max(prices[i]-minprice,maxprice);
        }
        return maxprice;
    }
};