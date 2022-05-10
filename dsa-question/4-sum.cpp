#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>>ans;
    int n = nums.size();
    sort(nums.begin(),nums.end());
    
    for(int i=3 ; i<n ; i++){
        for(int j=2 ; j<i ; j++){
            int goal = target-nums[i]-nums[j];
            int left=0,right=j-1;
            while(left<right){
                if(nums[left]+nums[right]==goal){
                    ans.insert({nums[left],nums[right],nums[j],nums[i]});
                    while(left+1<right && nums[left+1]==nums[left])left++;
                    while(right-1>left && nums[right-1]==nums[right])right--;
                    left++,right--;
                    continue;
                }
                if(nums[left]+nums[right]<goal)left++;
                else right--;
            }
        }
    }
    vector<vector<int>>vans(ans.begin(),ans.end());
    
    return vans;
}

int main(){
    
}