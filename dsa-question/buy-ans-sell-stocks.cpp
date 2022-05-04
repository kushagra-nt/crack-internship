#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    
    int ans=0,n=prices.size(),lowestPrice=prices[0];
    
    for(int i=1 ; i<n ; i++){
        ans = max(ans,prices[i]-lowestPrice);
        lowestPrice = min(lowestPrice,prices[i]);
    }
    
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int>prices(n);

    for(int i=0 ; i<n ; i++)cin>>prices[i];

    cout<<maxProfit(prices);

    return 0;
}