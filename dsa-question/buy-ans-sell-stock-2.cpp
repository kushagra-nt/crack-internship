#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit=0,n=prices.size(),lastPurchage=prices[0];
    
    for(int i=1 ; i<n ; i++){
        if(prices[i]>lastPurchage)
            profit += prices[i]-lastPurchage,lastPurchage = prices[i];
        lastPurchage = min(lastPurchage,prices[i]);
    }
    
    return profit;
}

int main(){

    int n;
    cin>>n;

    vector<int>prices(n);

    for(int i=0 ; i<n ; i++)cin>>prices[i];

    cout<<maxProfit(prices);
}