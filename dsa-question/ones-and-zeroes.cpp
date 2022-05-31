#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// do solution tabular
int findMaxForm(vector<string>& strs, int m, int n) {
    int size = strs.size(),i,j;
    vector<vector<int>>v(size,vector<int>(2,0));
    
    for(i=0 ; i<size ; i++){
        for(auto j:strs[i])
            v[i][j-'0']++;
    }

    vector<vector<int>>prev(m+1,vector<int>(n+1,0));

    for(int i=0 ; i<size ; i++){
        vector<vector<int>>curr(m+1,vector<int>(n+1,0));
        for(int j=0 ; j<=m ; j++){
            if(v[i][0]>j){
                curr[j] = prev[j];
                continue;
            }
            for(int k=0 ; k<=n ; k++){
                if(v[i][1]>k){
                    curr[j][k] = prev[j][k];
                    continue;
                }
                curr[j][k] = max(prev[j][k],prev[j-v[i][0]][k-v[i][1]]+1);
            }
        }
        prev = curr;
    }
    return prev[m][n];
}

//optimised dp approach
int findMaxForm(vector<string>& strs, int m, int n) {
    int size = strs.size();
    
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));

    for(int i=0 ; i<size ; i++){
        
        int zero = count(strs[i].begin(),strs[i].end(),'0');
        int ones = strs[i].length()-zero;
        
        for(int j=m ; j>=zero ; j--){
            for(int k=n ; k>=ones ; k--)
                dp[j][k] = max(dp[j][k],1+dp[j-zero][k-ones]);
        }
    }
    return dp[m][n];
}

int main(){
    
}