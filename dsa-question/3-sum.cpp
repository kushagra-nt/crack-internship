#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    
    vector<vector<int>>ans;
    
    int freZero=0;
    int n=nums.size();
    if(n==0) return ans;
    
    sort(nums.begin(),nums.end());
    for(int i=0 ; i<n ; i++)freZero += (nums[i]==0);
    if(nums[0]!=0 && freZero>2)ans.push_back({0,0,0});
    
    for(int i=2 ; i<n ; i++){
        int left=0,right=i-1,target=-nums[i];
        
        while(left<right){
            if(nums[left]+nums[right]==target){
                ans.push_back({nums[left],nums[right],nums[i]});
                while(left+1<right && nums[left+1]==nums[left])left++;
                while(right-1>left && nums[right-1]==nums[right])right--;
                
                left++,right--;
                continue;
            }
            if(nums[left]+nums[right]<target)left++;
            else
                right--;
        }
        if(i+1<n && nums[i+1]==nums[i] && nums[i]!=0){
            int target = -(nums[i]+nums[i]);
            for(int j=0 ; j<i ; j++){
                if(nums[j]==target){
                    ans.push_back({nums[j],nums[i],nums[i]});
                    break;
                }
            }
        }
        while(i+1<n && nums[i+1]==nums[i])i++;
    }
    
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i=0 ; i<n ; i++)cin>>nums[i];

    vector<vector<int>>ans = threeSum(nums);

    for(int i=0 ; i<ans.size() ; i++){
        cout<<"[";
        for(int j=0 ; j<2 ; j++)cout<<ans[i][j]<<",";
        cout<<ans[i][2];
        cout<<"] ";
    }

    return 0;
}