#include<iostream>
#include<vector>
using namespace std;

int uniquePaths(int n, int m) {
    
    vector<int>dp(m,1);
    for(int i=n-2 ; i>=0 ; i--){
        for(int j=m-2 ; j>=0 ; j--)
            dp[j] += dp[j+1];
    }
    return dp[0];
}

int main(){
    
}