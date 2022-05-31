#include<iostream>
#include<vector>
using namespace std;

vector<int> countBits(int n) {
    
    if(n==0)return {0};
    if(n==1)return {0,1};
    
    vector<int>ans(n+1);
    ans[0] = 0,ans[1] = 1;
    int p=0;
    
    for(int i=2 ; i<=n ; i++){
        ans[i] = 1+ans[p];
        p++;
        if((i&(i+1))==0)
            p=0;
    }
    return ans;
}

int main(){
    
}