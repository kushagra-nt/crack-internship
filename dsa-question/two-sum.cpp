#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>copy =nums;
    sort(nums.begin(),nums.end());
    int n = nums.size();
    
    int left=0,right=n-1,ans1=0,ans2=n-1;
    
    while(left<right){
        if(nums[left]+nums[right]==target){
            ans1 = nums[left],ans2=nums[right];
            break;
        }
        
        if(nums[left]+nums[right]<target)
            left++;
        else
            right--;
    }
    bool done1=true,done2=true;
    int index1,index2;
    for(int i=0 ; i<n ; i++){
        if(done1 && copy[i]==ans1){
            index1 = i;
            done1 = false;
        }
        else if(done2 && copy[i]==ans2){
            index2 =i;
            done2 = false;
        }
    }
    return vector<int>{index1,index2};
}

vector<int> twoSumUsingMap(vector<int>& nums, int target) {
    int n= nums.size();
    unordered_map<int,int>hash;
    
    hash[nums[0]] = 0;

    for(int i=1 ; i<n ; i++){
        if(hash.count(target-nums[i])!=0){
            return vector<int>{hash[target-nums[i]],i};
        }
        hash[nums[i]] = i;
    }
}

int main(){
    int n,target;
    cin>>n>>target;

    vector<int>nums(n);

    for(int i=0 ; i<n ; i++)cin>>nums[i];

    vector<int>ans = twoSumUsingMap(nums,target);

    cout<<ans[0]<<" "<<ans[1];

    return 0;

}