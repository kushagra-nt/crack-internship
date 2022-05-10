#include<bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int,int>m;
    m[0]++;
    int n=nums.size(),ans=0,sum=0;
    
    for(int i=0 ; i<n ; i++){
        
        sum = (sum+nums[i])%k;
        
        if(sum>0){
            ans += m[sum];
            ans += m[-(k-sum)];
        }
        else if(sum<0){
            ans += m[sum];
            ans += m[k+sum];
        }
        else{
            ans += m[sum];
        }
        
        m[sum]++;
        
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;

    vector<int>nums(n);

    for(int i=0 ; i<n ; i++)cin>>nums[i];

    cout<<subarraysDivByK(nums,k);

    return 0;
}