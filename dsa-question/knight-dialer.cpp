#include<iostream>
#include<vector>
using namespace std;

int M = 1e9+7;

int fun(vector<vector<int>>&next,vector<vector<int>>&dp,int n,int x){
    if(n==1)return 1;
    if(x==5)return 0;
    if(dp[x][n]!=-1)return dp[x][n];

    int ans=0;
    for(int i=0 ; i<next[x].size() ; i++)
    ans = (ans+0ll+fun(next,dp,n-1,next[x][i]))%M;
    return dp[x][n] = ans;
}

int knightDialer(int n) {
    vector<vector<int>>next{{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};

    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

    int ans=0;
    for(int i=0 ; i<=9 ; i++)ans = (ans+0ll+fun(next,dp,n,i))%M;
    return ans;
}

int main(){
    
    cout<<knightDialer(3131);

    return 0;
}