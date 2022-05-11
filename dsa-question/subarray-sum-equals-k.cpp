#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n=nums.size();
    
    vector<int>sum(n);
    sum[0] = nums[0];
    
    for(int i=1 ; i<n ; i++)sum[i] = sum[i-1]+nums[i];
    
    int ans=0;
    
    unordered_map<int,int>mp;
    mp[0]++;
    
    for(int i=0 ; i<n ; i++){
        ans += mp[sum[i]-k];
        mp[sum[i]]++;
    }
    
    return ans;
}

int main(){
    
}