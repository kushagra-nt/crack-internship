#include<iostream>
#include<vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    if(!amount)
        return 0;
    int n= coins.size();
    
    vector<int>dp(amount+1,0);
    
    for(int i=0 ; i<n ; i++){
        for(int j=1 ; j<=amount ; j++){
            if(j==coins[i])dp[j] = 1;
            else if(j>coins[i] && dp[j-coins[i]]){
                if(dp[j])dp[j] = min(dp[j],dp[j-coins[i]]+1);
                else
                    dp[j] = dp[j-coins[i]]+1;
            }
        }
    }
    if(dp[amount])return dp[amount];
    return -1;
}

int main(){
    
}